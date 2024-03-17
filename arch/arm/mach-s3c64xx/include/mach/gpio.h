/* arch/arm/mach-s3c6400/include/mach/gpio.h
 *
 * Copyright 2008 Openmoko, Inc.
 * Copyright 2008 Simtec Electronics
 *	http://armlinux.simtec.co.uk/
 *	Ben Dooks <ben@simtec.co.uk>
 *
 * S3C6400 - GPIO lib support
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
*/

#ifndef __S3C64XX_GPIO_H__
#define __S3C64XX_GPIO_H__

/* Pin configurations */
#define S3C_GPIO_INPUT	0x0
#define S3C_GPIO_OUTPUT	0x1
#define S3C_GPIO_IRQ	0xf
#define S3C_GPIO_FUNC(x)	((x) & 0xF)

/* Pull mode */
#define S3C_GPIO_PULL_NONE	0x0
#define S3C_GPIO_PULL_DOWN	0x1
#define S3C_GPIO_PULL_UP	0x2


/* GPIO bank sizes */
#define S3C64XX_GPIO_A_NR	(8)
#define S3C64XX_GPIO_B_NR	(7)
#define S3C64XX_GPIO_C_NR	(8)
#define S3C64XX_GPIO_D_NR	(5)
#define S3C64XX_GPIO_E_NR	(5)
#define S3C64XX_GPIO_F_NR	(16)
#define S3C64XX_GPIO_G_NR	(7)
#define S3C64XX_GPIO_H_NR	(10)
#define S3C64XX_GPIO_I_NR	(16)
#define S3C64XX_GPIO_J_NR	(12)
#define S3C64XX_GPIO_K_NR	(16)
#define S3C64XX_GPIO_L_NR	(15)
#define S3C64XX_GPIO_M_NR	(6)
#define S3C64XX_GPIO_N_NR	(16)
#define S3C64XX_GPIO_O_NR	(16)
#define S3C64XX_GPIO_P_NR	(15)
#define S3C64XX_GPIO_Q_NR	(9)


/*  define  for  s3c gpio  flags*/
#define	GPIO_FLAGS_CON_DOUBLE   (1<<3)
#define	GPIO_FLAGS_SLP_MODE       (1<<2)
#define	GPIO_FLAGS_CFG_2BIT        (1<<1)
#define	GPIO_FLAGS_CFG_4BIT        (1<<0)

#define S3C64XX_GPIO_A_FLAGS	(GPIO_FLAGS_CFG_4BIT | GPIO_FLAGS_SLP_MODE)
#define S3C64XX_GPIO_B_FLAGS	(GPIO_FLAGS_CFG_4BIT | GPIO_FLAGS_SLP_MODE)
#define S3C64XX_GPIO_C_FLAGS	(GPIO_FLAGS_CFG_4BIT | GPIO_FLAGS_SLP_MODE)
#define S3C64XX_GPIO_D_FLAGS	(GPIO_FLAGS_CFG_4BIT | GPIO_FLAGS_SLP_MODE)
#define S3C64XX_GPIO_E_FLAGS	(GPIO_FLAGS_CFG_4BIT | GPIO_FLAGS_SLP_MODE)
#define S3C64XX_GPIO_F_FLAGS	(GPIO_FLAGS_CFG_2BIT | GPIO_FLAGS_SLP_MODE)
#define S3C64XX_GPIO_G_FLAGS	(GPIO_FLAGS_CFG_4BIT | GPIO_FLAGS_SLP_MODE)
#define S3C64XX_GPIO_H_FLAGS	(GPIO_FLAGS_CFG_4BIT | GPIO_FLAGS_SLP_MODE | GPIO_FLAGS_CON_DOUBLE)
#define S3C64XX_GPIO_I_FLAGS	(GPIO_FLAGS_CFG_2BIT | GPIO_FLAGS_SLP_MODE)
#define S3C64XX_GPIO_J_FLAGS	(GPIO_FLAGS_CFG_2BIT | GPIO_FLAGS_SLP_MODE)
#define S3C64XX_GPIO_K_FLAGS	(GPIO_FLAGS_CFG_4BIT | GPIO_FLAGS_CON_DOUBLE)
#define S3C64XX_GPIO_L_FLAGS	(GPIO_FLAGS_CFG_4BIT | GPIO_FLAGS_CON_DOUBLE)
#define S3C64XX_GPIO_M_FLAGS	(GPIO_FLAGS_CFG_4BIT)
#define S3C64XX_GPIO_N_FLAGS	(GPIO_FLAGS_CFG_2BIT)
#define S3C64XX_GPIO_O_FLAGS	(GPIO_FLAGS_CFG_2BIT | GPIO_FLAGS_SLP_MODE)
#define S3C64XX_GPIO_P_FLAGS	(GPIO_FLAGS_CFG_2BIT | GPIO_FLAGS_SLP_MODE)
#define S3C64XX_GPIO_Q_FLAGS	(GPIO_FLAGS_CFG_2BIT | GPIO_FLAGS_SLP_MODE)

/* GPIO bank numbes */
#if CONFIG_IS_ENABLED(DM_GPIO) 

#define NROFFSET       (0) /* should be to 0 in uboot,due to gpio_renumber() */
#ifndef __DTS_S3C6410_PINCTRL__

/* define gpio number base of  banks*/
#define S3C64XX_GPIO_NEXT(__gpio) \
	((__gpio##_START) + (__gpio##_NR) + NROFFSET)

enum  {
	S3C64XX_GPIO_A_START =  0,
	S3C64XX_GPIO_B_START =  S3C64XX_GPIO_NEXT(S3C64XX_GPIO_A),
	S3C64XX_GPIO_C_START =  S3C64XX_GPIO_NEXT(S3C64XX_GPIO_B),
	S3C64XX_GPIO_D_START =  S3C64XX_GPIO_NEXT(S3C64XX_GPIO_C),
	S3C64XX_GPIO_E_START =  S3C64XX_GPIO_NEXT(S3C64XX_GPIO_D),
	S3C64XX_GPIO_F_START =  S3C64XX_GPIO_NEXT(S3C64XX_GPIO_E),
	S3C64XX_GPIO_G_START =  S3C64XX_GPIO_NEXT(S3C64XX_GPIO_F),
	S3C64XX_GPIO_H_START =  S3C64XX_GPIO_NEXT(S3C64XX_GPIO_G),
	S3C64XX_GPIO_I_START =  S3C64XX_GPIO_NEXT(S3C64XX_GPIO_H),
	S3C64XX_GPIO_J_START =  S3C64XX_GPIO_NEXT(S3C64XX_GPIO_I),
	S3C64XX_GPIO_K_START =  S3C64XX_GPIO_NEXT(S3C64XX_GPIO_J),
	S3C64XX_GPIO_L_START =  S3C64XX_GPIO_NEXT(S3C64XX_GPIO_K),
	S3C64XX_GPIO_M_START =  S3C64XX_GPIO_NEXT(S3C64XX_GPIO_L),
	S3C64XX_GPIO_N_START =  S3C64XX_GPIO_NEXT(S3C64XX_GPIO_M),
	S3C64XX_GPIO_O_START =  S3C64XX_GPIO_NEXT(S3C64XX_GPIO_N),
	S3C64XX_GPIO_P_START =  S3C64XX_GPIO_NEXT(S3C64XX_GPIO_O),
	S3C64XX_GPIO_Q_START =  S3C64XX_GPIO_NEXT(S3C64XX_GPIO_P),
};
#else  /*  __DTS_S3C6410_PINCTRL__ */

#define	S3C64XX_GPIO_A_START  0
#define	S3C64XX_GPIO_B_START  ((0) + (8))//S3C64XX_GPIO_NEXT(S3C64XX_GPIO_A)
#define	S3C64XX_GPIO_C_START  ((8) + (7)) //S3C64XX_GPIO_NEXT(S3C64XX_GPIO_B)
#define	S3C64XX_GPIO_D_START  ((15) + (8)) //S3C64XX_GPIO_NEXT(S3C64XX_GPIO_C)
#define	S3C64XX_GPIO_E_START  ((23) + (5)) //S3C64XX_GPIO_NEXT(S3C64XX_GPIO_D)
#define	S3C64XX_GPIO_F_START  ((28) + (5)) //S3C64XX_GPIO_NEXT(S3C64XX_GPIO_E)
#define	S3C64XX_GPIO_G_START  ((33) + (16)) //S3C64XX_GPIO_NEXT(S3C64XX_GPIO_F)
#define	S3C64XX_GPIO_H_START  ((49) + (7)) //S3C64XX_GPIO_NEXT(S3C64XX_GPIO_G)
#define	S3C64XX_GPIO_I_START  ((56) + (10)) //S3C64XX_GPIO_NEXT(S3C64XX_GPIO_H)
#define	S3C64XX_GPIO_J_START  ((66) + (16)) //S3C64XX_GPIO_NEXT(S3C64XX_GPIO_I)
#define	S3C64XX_GPIO_K_START  ((82) + (12)) //S3C64XX_GPIO_NEXT(S3C64XX_GPIO_J)
#define	S3C64XX_GPIO_L_START  ((94) + (16)) //S3C64XX_GPIO_NEXT(S3C64XX_GPIO_K)
#define	S3C64XX_GPIO_M_START  ((110) + (15)) //S3C64XX_GPIO_NEXT(S3C64XX_GPIO_L)
#define	S3C64XX_GPIO_N_START  ((125) + (6)) //S3C64XX_GPIO_NEXT(S3C64XX_GPIO_M)
#define	S3C64XX_GPIO_O_START  ((131) + (16)) //S3C64XX_GPIO_NEXT(S3C64XX_GPIO_N)
#define	S3C64XX_GPIO_P_START  ((147) + (16)) //S3C64XX_GPIO_NEXT(S3C64XX_GPIO_O)
#define	S3C64XX_GPIO_Q_START  ((163) + (15)) //S3C64XX_GPIO_NEXT(S3C64XX_GPIO_P)

#endif /*  __DTS_S3C6410_PINCTRL__ */

/* S3C64XX GPIO number definitions. */

#define S3C64XX_GPA(_nr)	(S3C64XX_GPIO_A_START + (_nr))
#define S3C64XX_GPB(_nr)	(S3C64XX_GPIO_B_START + (_nr))
#define S3C64XX_GPC(_nr)	(S3C64XX_GPIO_C_START + (_nr))
#define S3C64XX_GPD(_nr)	(S3C64XX_GPIO_D_START + (_nr))
#define S3C64XX_GPE(_nr)	(S3C64XX_GPIO_E_START + (_nr))
#define S3C64XX_GPF(_nr)	(S3C64XX_GPIO_F_START + (_nr))
#define S3C64XX_GPG(_nr)	(S3C64XX_GPIO_G_START + (_nr))
#define S3C64XX_GPH(_nr)	(S3C64XX_GPIO_H_START + (_nr))
#define S3C64XX_GPI(_nr)	(S3C64XX_GPIO_I_START + (_nr))
#define S3C64XX_GPJ(_nr)	(S3C64XX_GPIO_J_START + (_nr))
#define S3C64XX_GPK(_nr)	(S3C64XX_GPIO_K_START + (_nr))
#define S3C64XX_GPL(_nr)	(S3C64XX_GPIO_L_START + (_nr))
#define S3C64XX_GPM(_nr)	(S3C64XX_GPIO_M_START + (_nr))
#define S3C64XX_GPN(_nr)	(S3C64XX_GPIO_N_START + (_nr))
#define S3C64XX_GPO(_nr)	(S3C64XX_GPIO_O_START + (_nr))
#define S3C64XX_GPP(_nr)	(S3C64XX_GPIO_P_START + (_nr))
#define S3C64XX_GPQ(_nr)	(S3C64XX_GPIO_Q_START + (_nr))

/* the end of the S3C64XX specific gpios */
#define S3C64XX_GPIO_END	(S3C64XX_GPQ(S3C64XX_GPIO_Q_NR) + 1)
#define S3C_GPIO_END		S3C64XX_GPIO_END

/* define the number of gpios we need to the one after the GPQ() range */
#define GPIO_BOARD_START (S3C64XX_GPQ(S3C64XX_GPIO_Q_NR) + 1)

#define BOARD_NR_GPIOS	(16)

#define ARCH_NR_GPIOS	(GPIO_BOARD_START + BOARD_NR_GPIOS)

#else  /* #if !CONFIG_IS_ENABLED(DM_GPIO) */

#define S3C64XX_GPIO_BANK_START(__gpio,__bank,_nr) \
	(((__gpio##_FLAGS) <<24) |  \
	      ((__gpio##_NR) <<16) |  \
	      ((__bank)<<8) | (_nr))

#define S3C64XX_GPA(_nr)	S3C64XX_GPIO_BANK_START(S3C64XX_GPIO_A, 'A', _nr)
#define S3C64XX_GPB(_nr)	S3C64XX_GPIO_BANK_START(S3C64XX_GPIO_B, 'B', _nr)
#define S3C64XX_GPC(_nr)	S3C64XX_GPIO_BANK_START(S3C64XX_GPIO_C, 'C', _nr)
#define S3C64XX_GPD(_nr)	S3C64XX_GPIO_BANK_START(S3C64XX_GPIO_D, 'D', _nr)
#define S3C64XX_GPE(_nr)	S3C64XX_GPIO_BANK_START(S3C64XX_GPIO_E, 'E', _nr)
#define S3C64XX_GPF(_nr)	S3C64XX_GPIO_BANK_START(S3C64XX_GPIO_F, 'F', _nr)
#define S3C64XX_GPG(_nr)	S3C64XX_GPIO_BANK_START(S3C64XX_GPIO_G, 'G', _nr)
#define S3C64XX_GPH(_nr)	S3C64XX_GPIO_BANK_START(S3C64XX_GPIO_H, 'H', _nr)
#define S3C64XX_GPI(_nr)	S3C64XX_GPIO_BANK_START(S3C64XX_GPIO_I, 'I', _nr)
#define S3C64XX_GPJ(_nr)	S3C64XX_GPIO_BANK_START(S3C64XX_GPIO_J, 'J', _nr)
#define S3C64XX_GPK(_nr)	S3C64XX_GPIO_BANK_START(S3C64XX_GPIO_K, 'K', _nr)
#define S3C64XX_GPL(_nr)	S3C64XX_GPIO_BANK_START(S3C64XX_GPIO_L, 'L', _nr)
#define S3C64XX_GPM(_nr)	S3C64XX_GPIO_BANK_START(S3C64XX_GPIO_M, 'M', _nr)
#define S3C64XX_GPN(_nr)	S3C64XX_GPIO_BANK_START(S3C64XX_GPIO_N, 'N', _nr)
#define S3C64XX_GPO(_nr)	S3C64XX_GPIO_BANK_START(S3C64XX_GPIO_O, 'O', _nr)
#define S3C64XX_GPP(_nr)	S3C64XX_GPIO_BANK_START(S3C64XX_GPIO_P, 'P', _nr)
#define S3C64XX_GPQ(_nr)	S3C64XX_GPIO_BANK_START(S3C64XX_GPIO_Q, 'Q', _nr)

/***************************************************/
#define  S3C64XX_BANK_NR_MAX    ('Q' - 'A' +1)

#define  GPIO_GET_FLAGS(x)   ((x) >>24)
#define  GPIO_GET_COUNT(x)  (((x) >>16) & 0xFF)
#define  GPIO_GET_BANK(x)    ((((x) >>8) & 0xFF) - 'A')
#define  GPIO_GET_OFFSET(x)   ((x) & 0xFF)

#endif  /* CONFIG_IS_ENABLED(DM_GPIO) */

#endif  //__S3C64XX_GPIO_H__

