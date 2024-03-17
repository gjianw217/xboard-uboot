#ifndef __S3C64XX_FLASH_H__
#define __S3C64XX_FLASH_H__


/*
 * Nand flash controller
 */
#define ELFIN_NAND_BASE		0x70200000

#define NFCONF_OFFSET           0x00
#define NFCONT_OFFSET           0x04
#define NFCMMD_OFFSET           0x08
#define NFADDR_OFFSET           0x0c
#define NFDATA_OFFSET		0x10
#define NFMECCDATA0_OFFSET      0x14
#define NFMECCDATA1_OFFSET      0x18
#define NFSECCDATA0_OFFSET      0x1c
#define NFSBLK_OFFSET           0x20
#define NFEBLK_OFFSET           0x24
#define NFSTAT_OFFSET           0x28
#define NFESTAT0_OFFSET         0x2c
#define NFESTAT1_OFFSET         0x30
#define NFMECC0_OFFSET          0x34
#define NFMECC1_OFFSET          0x38
#define NFSECC_OFFSET           0x3c
#define NFMLCBITPT_OFFSET       0x40
#define NF8ECCERR0_OFFSET	0x44
#define NF8ECCERR1_OFFSET	0x48
#define NF8ECCERR2_OFFSET	0x4c
#define NFM8ECC0_OFFSET		0x50
#define NFM8ECC1_OFFSET		0x54
#define NFM8ECC2_OFFSET		0x58
#define NFM8ECC3_OFFSET		0x5c
#define NFMLC8BITPT0_OFFSET	0x60
#define NFMLC8BITPT1_OFFSET	0x64

#define NFCONF			(ELFIN_NAND_BASE+NFCONF_OFFSET)
#define NFCONT			(ELFIN_NAND_BASE+NFCONT_OFFSET)
#define NFCMMD			(ELFIN_NAND_BASE+NFCMMD_OFFSET)
#define NFADDR           	(ELFIN_NAND_BASE+NFADDR_OFFSET)
#define NFDATA          	(ELFIN_NAND_BASE+NFDATA_OFFSET)
#define NFMECCDATA0     	(ELFIN_NAND_BASE+NFMECCDATA0_OFFSET)
#define NFMECCDATA1     	(ELFIN_NAND_BASE+NFMECCDATA1_OFFSET)
#define NFSECCDATA0      	(ELFIN_NAND_BASE+NFSECCDATA0_OFFSET)
#define NFSBLK          	(ELFIN_NAND_BASE+NFSBLK_OFFSET)
#define NFEBLK           	(ELFIN_NAND_BASE+NFEBLK_OFFSET)
#define NFSTAT           	(ELFIN_NAND_BASE+NFSTAT_OFFSET)
#define NFESTAT0         	(ELFIN_NAND_BASE+NFESTAT0_OFFSET)
#define NFESTAT1         	(ELFIN_NAND_BASE+NFESTAT1_OFFSET)
#define NFMECC0          	(ELFIN_NAND_BASE+NFMECC0_OFFSET)
#define NFMECC1          	(ELFIN_NAND_BASE+NFMECC1_OFFSET)
#define NFSECC           	(ELFIN_NAND_BASE+NFSECC_OFFSET)
#define NFMLCBITPT           	(ELFIN_NAND_BASE+NFMLCBITPT_OFFSET)
#define NF8ECCERR0		(ELFIN_NAND_BASE+NF8ECCERR0_OFFSET)
#define NF8ECCERR1		(ELFIN_NAND_BASE+NF8ECCERR1_OFFSET)
#define NF8ECCERR2		(ELFIN_NAND_BASE+NF8ECCERR2_OFFSET)
#define NFM8ECC0		(ELFIN_NAND_BASE+NFM8ECC0_OFFSET)
#define NFM8ECC1		(ELFIN_NAND_BASE+NFM8ECC1_OFFSET)
#define NFM8ECC2		(ELFIN_NAND_BASE+NFM8ECC2_OFFSET)
#define NFM8ECC3		(ELFIN_NAND_BASE+NFM8ECC3_OFFSET)
#define NFMLC8BITPT0		(ELFIN_NAND_BASE+NFMLC8BITPT0_OFFSET)
#define NFMLC8BITPT1		(ELFIN_NAND_BASE+NFMLC8BITPT1_OFFSET)

#define NFCONF_REG		__REG(ELFIN_NAND_BASE+NFCONF_OFFSET)
#define NFCONT_REG		__REG(ELFIN_NAND_BASE+NFCONT_OFFSET)
#define NFCMD_REG		__REG(ELFIN_NAND_BASE+NFCMMD_OFFSET)
#define NFADDR_REG           	__REG(ELFIN_NAND_BASE+NFADDR_OFFSET)
#define NFDATA_REG          	__REG(ELFIN_NAND_BASE+NFDATA_OFFSET)
#define NFDATA8_REG          	__REGb(ELFIN_NAND_BASE+NFDATA_OFFSET)
#define NFMECCDATA0_REG     	__REG(ELFIN_NAND_BASE+NFMECCDATA0_OFFSET)
#define NFMECCDATA1_REG     	__REG(ELFIN_NAND_BASE+NFMECCDATA1_OFFSET)
#define NFSECCDATA0_REG      	__REG(ELFIN_NAND_BASE+NFSECCDATA0_OFFSET)
#define NFSBLK_REG          	__REG(ELFIN_NAND_BASE+NFSBLK_OFFSET)
#define NFEBLK_REG           	__REG(ELFIN_NAND_BASE+NFEBLK_OFFSET)
#define NFSTAT_REG           	__REG(ELFIN_NAND_BASE+NFSTAT_OFFSET)
#define NFESTAT0_REG         	__REG(ELFIN_NAND_BASE+NFESTAT0_OFFSET)
#define NFESTAT1_REG         	__REG(ELFIN_NAND_BASE+NFESTAT1_OFFSET)
#define NFMECC0_REG          	__REG(ELFIN_NAND_BASE+NFMECC0_OFFSET)
#define NFMECC1_REG          	__REG(ELFIN_NAND_BASE+NFMECC1_OFFSET)
#define NFSECC_REG           	__REG(ELFIN_NAND_BASE+NFSECC_OFFSET)
#define NFMLCBITPT_REG         	__REG(ELFIN_NAND_BASE+NFMLCBITPT_OFFSET)

#define NFCONF_ECC_MLC		(1<<24)

#define NFCONF_ECC_1BIT		(0<<23)
#define NFCONF_ECC_4BIT		(2<<23)
#define NFCONF_ECC_8BIT		(1<<23)

#define NFCONT_ECC_ENC		(1<<18)
#define NFCONT_WP		(1<<16)
#define NFCONT_MECCLOCK		(1<<7)
#define NFCONT_SECCLOCK		(1<<6)
#define NFCONT_INITMECC		(1<<5)
#define NFCONT_INITSECC		(1<<4)
#define NFCONT_INITECC		(NFCONT_INITMECC | NFCONT_INITSECC)
#define NFCONT_CS_ALT		(1<<1)
#define NFCONT_CS		(1<<1)
#define NFSTAT_ECCENCDONE	(1<<7)
#define NFSTAT_ECCDECDONE	(1<<6)
#define NFSTAT_RnB		(1<<0)
#define NFESTAT0_ECCBUSY	(1<<31)

#endif  /* __S3C64XX_FLASH_H__ */