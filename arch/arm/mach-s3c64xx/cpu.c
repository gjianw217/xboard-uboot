/*
 * (C) Copyright 2004 Texas Insturments
 *
 * (C) Copyright 2002
 * Sysgo Real-Time Solutions, GmbH <www.elinos.com>
 * Marius Groeger <mgroeger@sysgo.de>
 *
 * (C) Copyright 2002
 * Gary Jennejohn, DENX Software Engineering, <gj@denx.de>
 *
 * See file CREDITS for list of people who contributed to this
 * project.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston,
 * MA 02111-1307 USA
 */

/*
 * CPU specific code
 */

#include <common.h>
#include <command.h>
#include <asm/arch/cpu.h>
#include <asm/arch/clock-regs.h>

#ifdef CONFIG_USE_IRQ
DECLARE_GLOBAL_DATA_PTR;
#endif

/* read co-processor 15, register #1 (control register) */
static unsigned long read_p15_c1 (void)
{
	unsigned long value;

	__asm__ __volatile__(
						"mrc	p15, 0, %0, c1, c0, 0   @ read control reg\n"
						: "=r" (value)
						:
						: "memory");
	return value;
}

/* write to co-processor 15, register #1 (control register) */
static void write_p15_c1 (unsigned long value)
{
	__asm__ __volatile__(
						"mcr	p15, 0, %0, c1, c0, 0   @ write it back\n"
						:
						: "r" (value)
						: "memory");

	read_p15_c1 ();
}

static void cp_delay (void)
{
	volatile int i;

	/* Many OMAP regs need at least 2 nops  */
	for (i = 0; i < 100; i++);
}

/* See also ARM Ref. Man. */
#define C1_MMU		(1<<0)		/* mmu off/on */
#define C1_ALIGN	(1<<1)		/* alignment faults off/on */
#define C1_DC		(1<<2)		/* dcache off/on */
#define C1_WB		(1<<3)		/* merging write buffer on/off */
#define C1_BIG_ENDIAN	(1<<7)	/* big endian off/on */
#define C1_SYS_PROT	(1<<8)		/* system protection */
#define C1_ROM_PROT	(1<<9)		/* ROM protection */
#define C1_BRANCH	(1<<11)		/* branch prediction off/on */
#define C1_IC		(1<<12)		/* icache off/on */
#define C1_HIGH_VECTORS	(1<<13)	/* location of vectors: low/high addresses */
#define RESERVED_1	(0xf << 3)	/* must be 111b for R/W */



/* * reset the cpu by setting up the watchdog timer and let him time out */
void reset_cpu(ulong ignored)
{
	printf("reset... \n\n\n");

	SW_RST_REG = 0x6410;

	/* loop forever and wait for reset to happen */
	while (1)
	{
		if (serial_tstc())
		{
			serial_getc();
			break;
		}
	}
	/*NOTREACHED*/
}


void branch_enable (void)
{
	ulong reg;

	reg = read_p15_c1 ();
	cp_delay ();
	write_p15_c1 (reg | C1_BRANCH);
}

void branch_disable (void)
{
	ulong reg;

	reg = read_p15_c1 ();
	cp_delay ();
	reg &= ~C1_BRANCH;
	write_p15_c1 (reg);
}

int branch_status (void)
{
	return (read_p15_c1 () & C1_BRANCH) != 0;
}

