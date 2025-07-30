// Copyright (c) 2004-2020 Microchip Technology Inc. and its subsidiaries.
// SPDX-License-Identifier: MIT

#include <microchip/ethernet/phy/api.h>
#include <mepa_driver.h>
#include <mepa_ts_driver.h>
#include <stdio.h>

#include "dp83869_registers.h"

#include "dp83869_private.h"

//extern mepa_ts_driver_t indy_ts_drivers;

static mepa_rc ti_conf_set(mepa_device_t *dev, const mepa_conf_t *config);
static mepa_rc ti_sgmii_aneg(mepa_device_t *dev, mepa_bool_t ena);
static mepa_rc ti_event_enable_set(mepa_device_t *dev, mepa_event_t event, mepa_bool_t enable);

mepa_rc ti_direct_reg_rd(mepa_device_t *dev, uint16_t addr, uint16_t *value)
{
    phy_data_t *data = (phy_data_t *)dev->data;
    mepa_port_no_t iport = data->port_no;
	switch(iport)
	{
		case 0:
		    (void)mesa_gpio_write(NULL, 0, 24, 1);
		    (void)mesa_gpio_write(NULL, 0, 25, 0);
		    (void)mesa_gpio_write(NULL, 0, 26, 0);
		    (void)mesa_gpio_write(NULL, 0, 27, 0);
		    break;
		case 1:
		    (void)mesa_gpio_write(NULL, 0, 24, 1);
		    (void)mesa_gpio_write(NULL, 0, 25, 0);
		    (void)mesa_gpio_write(NULL, 0, 26, 1);
		    (void)mesa_gpio_write(NULL, 0, 27, 0);
		    break;
		case 2:
		    (void)mesa_gpio_write(NULL, 0, 24, 1);
		    (void)mesa_gpio_write(NULL, 0, 25, 0);
		    (void)mesa_gpio_write(NULL, 0, 26, 0);
		    (void)mesa_gpio_write(NULL, 0, 27, 1);
		    break;
		case 3:
		    (void)mesa_gpio_write(NULL, 0, 24, 1);
		    (void)mesa_gpio_write(NULL, 0, 25, 0);
		    (void)mesa_gpio_write(NULL, 0, 26, 1);
		    (void)mesa_gpio_write(NULL, 0, 27, 1);
		    break;
		case 4:
		    (void)mesa_gpio_write(NULL, 0, 24, 0);
		    (void)mesa_gpio_write(NULL, 0, 25, 1);
		    (void)mesa_gpio_write(NULL, 0, 26, 0);
		    (void)mesa_gpio_write(NULL, 0, 27, 0);
		    break;
		case 5:
		    (void)mesa_gpio_write(NULL, 0, 24, 0);
		    (void)mesa_gpio_write(NULL, 0, 25, 1);
		    (void)mesa_gpio_write(NULL, 0, 26, 1);
		    (void)mesa_gpio_write(NULL, 0, 27, 0);
		    break;
		case 6:
		    (void)mesa_gpio_write(NULL, 0, 24, 0);
		    (void)mesa_gpio_write(NULL, 0, 25, 1);
		    (void)mesa_gpio_write(NULL, 0, 26, 0);
		    (void)mesa_gpio_write(NULL, 0, 27, 1);
		    break;
		case 7:
		    (void)mesa_gpio_write(NULL, 0, 24, 0);
		    (void)mesa_gpio_write(NULL, 0, 25, 1);
		    (void)mesa_gpio_write(NULL, 0, 26, 1);
		    (void)mesa_gpio_write(NULL, 0, 27, 1);
		    break;
		default:
		    break;		
	}
    if (dev->callout->miim_read(dev->callout_ctx, addr, value) != MESA_RC_OK) {
        T_E(MEPA_TRACE_GRP_GEN, "Port %d miim read failed\n", dev->numeric_handle);
    }
    return MEPA_RC_OK;
}
mepa_rc ti_direct_reg_wr(mepa_device_t *dev, uint16_t addr, uint16_t value, uint16_t mask)
{
    phy_data_t *data = (phy_data_t *)dev->data;
    mepa_port_no_t iport = data->port_no;
	switch(iport)
	{
		case 0:
		    (void)mesa_gpio_write(NULL, 0, 24, 1);
		    (void)mesa_gpio_write(NULL, 0, 25, 0);
		    (void)mesa_gpio_write(NULL, 0, 26, 0);
		    (void)mesa_gpio_write(NULL, 0, 27, 0);
		    break;
		case 1:
		    (void)mesa_gpio_write(NULL, 0, 24, 1);
		    (void)mesa_gpio_write(NULL, 0, 25, 0);
		    (void)mesa_gpio_write(NULL, 0, 26, 1);
		    (void)mesa_gpio_write(NULL, 0, 27, 0);
		    break;
		case 2:
		    (void)mesa_gpio_write(NULL, 0, 24, 1);
		    (void)mesa_gpio_write(NULL, 0, 25, 0);
		    (void)mesa_gpio_write(NULL, 0, 26, 0);
		    (void)mesa_gpio_write(NULL, 0, 27, 1);
		    break;
		case 3:
		    (void)mesa_gpio_write(NULL, 0, 24, 1);
		    (void)mesa_gpio_write(NULL, 0, 25, 0);
		    (void)mesa_gpio_write(NULL, 0, 26, 1);
		    (void)mesa_gpio_write(NULL, 0, 27, 1);
		    break;
		case 4:
		    (void)mesa_gpio_write(NULL, 0, 24, 0);
		    (void)mesa_gpio_write(NULL, 0, 25, 1);
		    (void)mesa_gpio_write(NULL, 0, 26, 0);
		    (void)mesa_gpio_write(NULL, 0, 27, 0);
		    break;
		case 5:
		    (void)mesa_gpio_write(NULL, 0, 24, 0);
		    (void)mesa_gpio_write(NULL, 0, 25, 1);
		    (void)mesa_gpio_write(NULL, 0, 26, 1);
		    (void)mesa_gpio_write(NULL, 0, 27, 0);
		    break;
		case 6:
		    (void)mesa_gpio_write(NULL, 0, 24, 0);
		    (void)mesa_gpio_write(NULL, 0, 25, 1);
		    (void)mesa_gpio_write(NULL, 0, 26, 0);
		    (void)mesa_gpio_write(NULL, 0, 27, 1);
		    break;
		case 7:
		    (void)mesa_gpio_write(NULL, 0, 24, 0);
		    (void)mesa_gpio_write(NULL, 0, 25, 1);
		    (void)mesa_gpio_write(NULL, 0, 26, 1);
		    (void)mesa_gpio_write(NULL, 0, 27, 1);
		    break;
		default:
		    break;		
	}
    uint16_t reg_val = value;
    mesa_rc rc;

    rc = dev->callout->miim_read(dev->callout_ctx, addr, &reg_val);
    if (rc == MESA_RC_OK) {
        if (mask != TI_DEF_MASK) {
            reg_val = (reg_val & ~mask) | (value & mask);
        } else {
            reg_val = value;
        }
        rc = dev->callout->miim_write(dev->callout_ctx, addr, reg_val);
        if (rc != MESA_RC_OK) {
            T_E(MEPA_TRACE_GRP_GEN, "Port %d miim write failed\n", dev->numeric_handle);
        }
    } else {
        T_E(MEPA_TRACE_GRP_GEN, "Port %d miim write failed\n", dev->numeric_handle);
    }
    return MEPA_RC_OK;
}

// Extended page read and write functions
// Extended page numbers range : 0 - 31
/*mepa_rc indy_ext_reg_rd(mepa_device_t *dev, uint16_t page, uint16_t addr, uint16_t *value)
{
    // Set-up to access extended page register.
    MEPA_RC(indy_direct_reg_wr(dev, INDY_EXT_PAGE_ACCESS_CTRL, page, INDY_DEF_MASK));
    MEPA_RC(indy_direct_reg_wr(dev, INDY_EXT_PAGE_ACCESS_ADDR_DATA, addr, INDY_DEF_MASK));
    MEPA_RC(indy_direct_reg_wr(dev, INDY_EXT_PAGE_ACCESS_CTRL,
                               INDY_F_EXT_PAGE_ACCESS_CTRL_EP_FUNC | page, INDY_DEF_MASK));

    // Read the value
    MEPA_RC(indy_direct_reg_rd(dev, INDY_EXT_PAGE_ACCESS_ADDR_DATA, value));
    return MEPA_RC_OK;
}
mepa_rc indy_ext_reg_wr(mepa_device_t *dev, uint16_t page, uint16_t addr, uint16_t value, uint16_t mask)
{
    // Set-up to access extended page register.
    MEPA_RC(indy_direct_reg_wr(dev, INDY_EXT_PAGE_ACCESS_CTRL, page, INDY_DEF_MASK));
    MEPA_RC(indy_direct_reg_wr(dev, INDY_EXT_PAGE_ACCESS_ADDR_DATA, addr, INDY_DEF_MASK));
    MEPA_RC(indy_direct_reg_wr(dev, INDY_EXT_PAGE_ACCESS_CTRL,
                               INDY_F_EXT_PAGE_ACCESS_CTRL_EP_FUNC | page, INDY_DEF_MASK));

    // write the value
    MEPA_RC(indy_direct_reg_wr(dev, INDY_EXT_PAGE_ACCESS_ADDR_DATA, value, mask));
    return MEPA_RC_OK;
}*/

// MMD read and write functions
// MMD device range : 0 - 31
mepa_rc ti_mmd_reg_rd(mepa_device_t *dev, uint16_t mmd, uint16_t addr, uint16_t *value)
{

    // Set-up to MMD register.
    MEPA_RC(ti_direct_reg_wr(dev, TI_MMD_ACCESS_CTRL, 0x001F, TI_DEF_MASK));
    MEPA_RC(ti_direct_reg_wr(dev, TI_MMD_ACCESS_ADDR_DATA, addr, TI_DEF_MASK));
    MEPA_RC(ti_direct_reg_wr(dev, TI_MMD_ACCESS_CTRL, 0x401F, TI_DEF_MASK));

    // Read the value
    MEPA_RC(ti_direct_reg_rd(dev, TI_MMD_ACCESS_ADDR_DATA, value));
    // Set-up to MMD register.
    /*MEPA_RC(ti_direct_reg_wr(dev, TI_MMD_ACCESS_CTRL, 0x001F, TI_DEF_MASK));
    MEPA_RC(ti_direct_reg_wr(dev, TI_MMD_ACCESS_ADDR_DATA, addr, TI_DEF_MASK));
    MEPA_RC(ti_direct_reg_wr(dev, TI_MMD_ACCESS_CTRL, 0x401F, TI_DEF_MASK));

    // Read the value
    MEPA_RC(ti_direct_reg_rd(dev, TI_MMD_ACCESS_ADDR_DATA, value));*/
    return MEPA_RC_OK;
}

mepa_rc ti_mmd_reg_wr(mepa_device_t *dev, uint16_t mmd, uint16_t addr, uint16_t value, uint16_t mask)
{

    // Set-up to MMD register.
    MEPA_RC(ti_direct_reg_wr(dev, TI_MMD_ACCESS_CTRL, 0x001F, TI_DEF_MASK));
    MEPA_RC(ti_direct_reg_wr(dev, TI_MMD_ACCESS_ADDR_DATA, addr, TI_DEF_MASK));
    MEPA_RC(ti_direct_reg_wr(dev, TI_MMD_ACCESS_CTRL, 0x401F, TI_DEF_MASK));

    // write the value
    MEPA_RC(ti_direct_reg_wr(dev, TI_MMD_ACCESS_ADDR_DATA, value, mask));
    return MEPA_RC_OK;
}

static mepa_rc ti_delete(mepa_device_t *dev)
{
    return mepa_delete_int(dev);
}

static mepa_rc ti_get_device_info(mepa_device_t *dev)
{
    phy_data_t *data = (phy_data_t *)dev->data;
    uint16_t id;

    RD(dev, TI_DEVICE_ID_2, &id);

    data->dev.model = TI_X_DEV_ID_MODEL(id);
    data->dev.rev = TI_X_DEV_ID_REV(id);
	printf("DEV_ID_MODEL: %02X\n",TI_X_DEV_ID_MODEL(id));
	printf("DEV_ID_REV: %02X\n",TI_X_DEV_ID_REV(id));
    T_I(MEPA_TRACE_GRP_GEN, "model 0x%x rev %d\n", data->dev.model, data->dev.rev);

    return MEPA_RC_OK;
}

static void ti_phy_deb_pr_reg (mepa_device_t *dev,
                                const mepa_debug_print_t pr,
                                uint16_t mmd, uint16_t addr,
                                const char *str, uint16_t *value)
{
    mepa_rc rc = MEPA_RC_OK;
    phy_data_t *data = (phy_data_t *)dev->data;
    mepa_port_no_t port_no = data->port_no;
    uint16_t id=0;

    if (mmd) {
        id = mmd;
        rc = ti_mmd_reg_rd(dev, mmd, addr, value);
    } else {
        rc = ti_direct_reg_rd(dev, addr, value);
    }
    if(pr && (MEPA_RC_OK == rc)) {
        pr("%-45s:  0x%02x  0x%02x   0x%04x     0x%08x\n", str, to_u32(port_no), id, addr, *value);
    }
}

static mepa_rc ti_reg_dump(struct mepa_device *dev,
                             const mepa_debug_print_t pr)
{
    uint16_t val = 0;
    //uint16_t id = 0;

    //Direct registers
    pr("%-45s   PORT_NO REG_ADDR   VALUE\n", "REG_NAME");
    pr("Main Page Registers\n");
    ti_phy_deb_pr_reg(dev, pr, 0, 0, "Basic Mode Control Register", &val);
    ti_phy_deb_pr_reg(dev, pr, 0, 1, "Basic Mode Status Register", &val);
    ti_phy_deb_pr_reg(dev, pr, 0, 2, "PHY Identifier Register #1", &val);
    ti_phy_deb_pr_reg(dev, pr, 0, 3, "PHY Identifier Register #2 ", &val);
    ti_phy_deb_pr_reg(dev, pr, 0, 4, "Auto-Negotiation Advertisement Register", &val);
    ti_phy_deb_pr_reg(dev, pr, 0, 5, "Auto-Negotiation Link Partner Ability Register", &val);
    ti_phy_deb_pr_reg(dev, pr, 0, 6, "Auto-Negotiate Expansion Register", &val);
    ti_phy_deb_pr_reg(dev, pr, 0, 7, "Auto-Negotiation Next Page Transmit Register", &val);
    ti_phy_deb_pr_reg(dev, pr, 0, 8, "Auto-Negotiation Link Partner Next Page Receive Register", &val);
    ti_phy_deb_pr_reg(dev, pr, 0, 9, "Configuration Register 1 ", &val);
    ti_phy_deb_pr_reg(dev, pr, 0, 10, "Status Register 1", &val);
    ti_phy_deb_pr_reg(dev, pr, 0, 13, "Register Control Register", &val);
    ti_phy_deb_pr_reg(dev, pr, 0, 14, "Address or Data Register", &val);
    ti_phy_deb_pr_reg(dev, pr, 0, 15, "1000BASE-T Status Register", &val);
    ti_phy_deb_pr_reg(dev, pr, 0, 16, "PHY Control Register", &val);
    ti_phy_deb_pr_reg(dev, pr, 0, 17, "PHY Status Register", &val);
    ti_phy_deb_pr_reg(dev, pr, 0, 18, "MII Interrupt Control Register", &val);
    ti_phy_deb_pr_reg(dev, pr, 0, 19, "Interrupt Status Register", &val);
    ti_phy_deb_pr_reg(dev, pr, 0, 20, "Configuration Register 2", &val);
    ti_phy_deb_pr_reg(dev, pr, 0, 21, "RX_ERR_CNT", &val);
    ti_phy_deb_pr_reg(dev, pr, 0, 22, "BIST Control Register", &val);
    ti_phy_deb_pr_reg(dev, pr, 0, 23, "Status Register 2", &val);
    ti_phy_deb_pr_reg(dev, pr, 0, 24, "LED Configuration Register 1", &val);
    ti_phy_deb_pr_reg(dev, pr, 0, 25, "LED Configuration Register 2 ", &val);
    ti_phy_deb_pr_reg(dev, pr, 0, 26, "LED Configuration Register 3 ", &val);
    ti_phy_deb_pr_reg(dev, pr, 0, 30, "Configuration Register 3", &val);
    ti_phy_deb_pr_reg(dev, pr, 0, 31, "Control Register", &val);
    /*ti_phy_deb_pr_reg(dev, pr, 0, 29, "Digital Debug Control 2 Register", &val);
    ti_phy_deb_pr_reg(dev, pr, 0, 30, "Reserved Register", &val);
    ti_phy_deb_pr_reg(dev, pr, 0, 31, "Control Register", &val);*/

    //Extended page-0,1,2,3,4,5,7,28,29,31 registers
   /* pr("Extended Page-0 Registers\n");
    indy_phy_deb_pr_reg(dev, pr, 0, 1, 0, "Debug-Mode First-Level-Select Register", &val);
    indy_phy_deb_pr_reg(dev, pr, 0, 1, 1, "Debug-Mode Second-Level-Select for DIGITOP Part 1 Register", &val);
    indy_phy_deb_pr_reg(dev, pr, 0, 1, 2, "Debug-Mode Second-Level-Select for DIGITOP Part 2 Register", &val);
    indy_phy_deb_pr_reg(dev, pr, 0, 1, 3, "Auto-Negotiation Timer Register 1", &val);
    indy_phy_deb_pr_reg(dev, pr, 0, 1, 4, "Auto-Negotiation Timer Register 2", &val);
    indy_phy_deb_pr_reg(dev, pr, 0, 1, 5, "Auto-Negotiation Timer Register 3", &val);
    indy_phy_deb_pr_reg(dev, pr, 0, 1, 6, "Auto-Negotiation Timer Register 4", &val);
    indy_phy_deb_pr_reg(dev, pr, 0, 1, 7, "Auto-Negotiation Timer Register 5", &val);
    indy_phy_deb_pr_reg(dev, pr, 0, 1, 8, "Auto-Negotiation Timer Register 6", &val);
    indy_phy_deb_pr_reg(dev, pr, 0, 1, 9, "Auto-Negotiation Timer Register 7", &val);
    indy_phy_deb_pr_reg(dev, pr, 0, 1, 10, "MDIX Select Register", &val);
    indy_phy_deb_pr_reg(dev, pr, 0, 1, 11, "Max-Timer for 1.24 Millisecond Register", &val);
    indy_phy_deb_pr_reg(dev, pr, 0, 1, 12, "Auto-Negotiation Wait Timer Register", &val);
    indy_phy_deb_pr_reg(dev, pr, 0, 1, 13, "Max Link Timer Register", &val);
    indy_phy_deb_pr_reg(dev, pr, 0, 1, 14, "Debug Bus Option Register", &val);
    indy_phy_deb_pr_reg(dev, pr, 0, 1, 15, "Fast Link Fail (FLF) Configuration and Status Register", &val);
    indy_phy_deb_pr_reg(dev, pr, 0, 1, 16, "Link Partner Force FD Override Register", &val);

    pr("Extended Page-1 Registers\n");
    for(id = 0; id < 239; id++) {
        indy_phy_deb_pr_reg(dev, pr, 0, 2, id, "Extended Page 1 Registers", &val);
    }

    pr("Extended Page-2 Registers\n");
    for(id = 0; id < 111; id++) {
        indy_phy_deb_pr_reg(dev, pr, 0, 3, id, "Extended Page 2 Registers", &val);
    }

    pr("Extended Page-3 Registers\n");
    for(id = 0; id < 28; id++) {
        indy_phy_deb_pr_reg(dev, pr, 0, 4, id, "Extended Page 3 Registers", &val);
    }

    pr("Extended Page-4 Registers\n");
    for(id = 0; id < 772; id++) {
        indy_phy_deb_pr_reg(dev, pr, 0, 5, id, "Extended Page 4 Registers", &val);
    }

    pr("Extended Page-5 Registers\n");
    for(id = 0; id < 708; id++) {
        indy_phy_deb_pr_reg(dev, pr, 0, 6, id, "Extended Page 5 Registers", &val);
    }

    pr("Extended Page-7 Registers\n");
    indy_phy_deb_pr_reg(dev, pr, 0, 8, 58, "EP7 Register 58", &val);
    indy_phy_deb_pr_reg(dev, pr, 0, 8, 59, "EP7 Register 59", &val);
    indy_phy_deb_pr_reg(dev, pr, 0, 8, 62, "EEE Link Partner Ability Override Register", &val);
    indy_phy_deb_pr_reg(dev, pr, 0, 8, 63, "EEE Message Code Register", &val);

    pr("Extended Page-28 Registers\n");
    for(id = 0; id < 80; id++) {
        indy_phy_deb_pr_reg(dev, pr, 0, 29, id, "Extended Page 28 Registers", &val);
    }

    pr("Extended Page-29 Registers\n");
    for(id = 0; id < 80; id++) {
        indy_phy_deb_pr_reg(dev, pr, 0, 30, id, "Extended Page 29 Registers", &val);
    }

    pr("Extended Page-31 Registers\n");
    indy_phy_deb_pr_reg(dev, pr, 0, 32, 0, "Speed Mode with TESTBUS Control Register", &val);
    indy_phy_deb_pr_reg(dev, pr, 0, 32, 8, "Clock Management Mode 0", &val);
    indy_phy_deb_pr_reg(dev, pr, 0, 32, 9, "Clock Management Mode 1", &val);
    indy_phy_deb_pr_reg(dev, pr, 0, 32, 10, "Clock Management Mode 2", &val);
    indy_phy_deb_pr_reg(dev, pr, 0, 32, 11, "Clock Management Mode 3", &val);
    indy_phy_deb_pr_reg(dev, pr, 0, 32, 12, "Clock Management Mode 4", &val);
    indy_phy_deb_pr_reg(dev, pr, 0, 32, 13, "Clock Management Mode 5", &val);
    indy_phy_deb_pr_reg(dev, pr, 0, 32, 14, "Clock Management Mode 6", &val);
    indy_phy_deb_pr_reg(dev, pr, 0, 32, 15, "Clock Management Mode 7", &val);
    indy_phy_deb_pr_reg(dev, pr, 0, 32, 16, "Clock Management Mode 8", &val);
    indy_phy_deb_pr_reg(dev, pr, 0, 32, 17, "Clock Management Mode 9", &val);

    //MMD-3,7 registers
    pr("%-45s   PORT_NO DEV_ID REG_ADDR   VALUE\n", "REG_NAME");
    pr("MMD-3 Registers\n");
    indy_phy_deb_pr_reg(dev, pr, 3, 0x0, 0, "PCS Control 1 Register", &val);
    indy_phy_deb_pr_reg(dev, pr, 3, 0x0, 1, "PCS Status 1 Register", &val);
    indy_phy_deb_pr_reg(dev, pr, 3, 0x0, 20,"EEE Control and Capability Register", &val);

    pr("MMD-7 Registers\n");
    indy_phy_deb_pr_reg(dev, pr, 7, 0x0, 60,"EEE Advertisement Register", &val);
    indy_phy_deb_pr_reg(dev, pr, 7, 0x0, 61,"EEE Link Partner Ability Register", &val);*/

    return MEPA_RC_OK;
}

static mepa_rc ti_debug_info_dump(struct mepa_device *dev,
                                    const mepa_debug_print_t pr,
                                    const mepa_debug_info_t   *const info)
{
    mepa_rc rc = MEPA_RC_OK;

    //PHY Debugging
    switch(info->group)
    {
        case MEPA_DEBUG_GROUP_ALL:
        case MEPA_DEBUG_GROUP_PHY:
        {
            MEPA_ENTER(dev);
            rc = ti_reg_dump(dev, pr);
            MEPA_EXIT(dev);
        }
        break;
        default:
            rc = MEPA_RC_OK;
    }

    //PHY_TS Debugging
    //ti_ts_debug_info_dump(dev, pr, info);

    return rc;
}



static mepa_rc ti_init_conf(mepa_device_t *dev)
{
    phy_data_t *data = (phy_data_t *) dev->data;
    uint16_t val;

    ti_get_device_info(dev);

    // Set config only for base port of phy.
    //if (data->dev.model == 0x26) {
        /*if (data->packet_idx == 0) {
            //EP_WR(dev, INDY_CHIP_HARD_RESET, 1);
            MEPA_MSLEEP(1);

            if (!data->qsgmii_phy_aneg_dis) {
                // Disable QSGMII auto-negotiation common for 4 ports.
                WRM(dev, TI_GEN_CFG2, 0, TI_F_SGMII_AUTONEG_EN);
                data->qsgmii_phy_aneg_dis = TRUE;
            }
        }*/
    //}

    // Enable Fast link config
    //val = INDY_FLF_CFG_STAT_LINK_DOWN | INDY_FLF_CFG_STAT_FLF_ENABLE;
    //EP_WRM(dev, INDY_FLF_CONFIG_STATUS, val, val);

    // Clear all GPHY interrupts during initialisation
    WR(dev, TI_INTERRUPT_MASK, 0);
    //WRM(dev, INDY_PTP_TSU_INT_EN, 0, INDY_DEF_MASK);
    RD(dev, TI_INTR_STATUS, &val);
    // Enable chip level interrupt
    //EP_WRM(dev, INDY_INTR_CTRL, INDY_INTR_CTRL_CHIP_LVL_ENA, INDY_INTR_CTRL_CHIP_LVL_ENA);*/
    return MEPA_RC_OK;
}

// Configure qsgmii aneg advertisement capabilities
static void ti_sgmii_tx_abilities(mepa_device_t *dev, mepa_port_speed_t speed, mepa_bool_t duplex)
{
    uint16_t value = 0x1; // default disable EEE enable & EEE clock stop
    uint16_t eee_val;

    MMD_RD(dev, TI_GEN_STATUS1, &eee_val);
    /*if (speed == MEPA_SPEED_1G) {
        value |= (eee_val & TI_F_GEN_STATUS1_1000_T_FULL_DUP) ? 0x180 : 0;
    } else if (speed == MEPA_SPEED_100M) {
        value |= (eee_val & INDY_F_LP_EEE_ABILITY_100_BT) ? 0x180 : 0;
    }
    if (duplex) {
        value |= INDY_BIT(12);
    }
    value |= (speed == MEPA_SPEED_1G) ? INDY_BIT(10) : (speed == MEPA_SPEED_100M) ? INDY_BIT(9) : 0;
    value |= INDY_BIT(14);
    EP_WR(dev, INDY_QSGMII_PCS1G_ANEG_TX_ADVERTISE_CAP, value);

    EP_WRM(dev, INDY_QSGMII_PCS1G_ANEG_CONFIG, INDY_F_QSGMII_PCS1G_ANEG_CONFIG_ANEG_RESTART, INDY_F_QSGMII_PCS1G_ANEG_CONFIG_ANEG_RESTART);*/
        WRM(dev, TI_FX_CTRL,TI_CTRL0_RESTART_AN, TI_CTRL0_RESTART_AN);
}

static mepa_rc ti_sgmii_aneg(mepa_device_t *dev, mepa_bool_t ena)
{
    phy_data_t *data = (phy_data_t *) dev->data;
	printf("ti_sgmii_aneg 1\n");
    if (data->dev.model != 0x0F) {
	//printf("MODEL_NUM(if) = %02X\n",data->dev.model);
        return MEPA_RC_OK;
    }
	printf("MODEL_NUM = %02X\n",data->dev.model);

    T_I(MEPA_TRACE_GRP_GEN, "sgmii aneg ena %d", ena);
    if (!ena) {
        // Disable SGMII auto-negotiation
	printf("Disable SGMII auto-negotiation\n");
        WRM(dev, TI_GEN_CFG2, 0,TI_F_SGMII_AUTONEG_EN);
        WRM(dev, TI_GEN_CFG2,TI_F_SGMII_SOFT_RESET, TI_F_SGMII_SOFT_RESET);
    } else {
        // Enable SGMII auto-negotiation.
	printf("Enable SGMII auto-negotiation.\n");
        WRM(dev, TI_GEN_CFG2,TI_F_SGMII_AUTONEG_EN, TI_F_SGMII_AUTONEG_EN);
        WRM(dev, TI_GEN_CFG2,TI_F_SGMII_SOFT_RESET, TI_F_SGMII_SOFT_RESET);

    }
        //WRM(dev, TI_GEN_CFG2,TI_F_SGMII_AUTONEG_EN, TI_F_SGMII_AUTONEG_EN);
        //WRM(dev, TI_GEN_CFG2,TI_F_SGMII_SOFT_RESET, TI_F_SGMII_SOFT_RESET);
    return MEPA_RC_OK;
}

/*static mepa_rc indy_rev_workaround(mepa_device_t *dev)
{
    phy_data_t *data = (phy_data_t *) dev->data;
    uint16_t val;

    // work-arounds applicable for both models 0x26 & 0x27
    do {
        // work-around for Rev C done.
        if (data->dev.rev >= 2) {
            break;
        }
        // MDI-X setting for swap A,B transmit
        EP_WRM(dev, INDY_ALIGN_SWAP, INDY_F_ALIGN_TX_A_B_SWAP, INDY_M_ALIGN_TX_SWAP);
    } while (0);
    // work-around for model 0x27 only
    if (data->dev.model == 0x27 && data->dev.rev <= 2) {
        // In Indy internal phy clock generation stops when link goes down.
        EP_WR(dev, INDY_CLOCK_MANAGEMENT_MODE_5, 0x27e);
        EP_RD(dev, INDY_LINK_QUALITY_MONITOR_SETTING, &val);
    }
    // work-around for model 0x27 done.
    if (data->dev.model != 0x26) {
        return MEPA_RC_OK;
    }
    // work-arounds applicable for only model 0x26
    // Rev A, B, C
    // PLL trim
    EP_WR(dev, INDY_ANALOG_CONTROL_1, 0x40);
    EP_WR(dev, INDY_ANALOG_CONTROL_10, 0x1);

    // Rev C work-around done.
    if (data->dev.rev >= 2) {
        return MEPA_RC_OK;
    }
    // Rev B work-around done.
    if (data->dev.rev >= 1) {
        return MEPA_RC_OK;
    }
    EP_WR(dev, INDY_OPERATION_MODE_STRAP_LOW, 0x2);
    EP_WR(dev, INDY_OPERATION_MODE_STRAP_HIGH, 0xc001);

    T_D(MEPA_TRACE_GRP_GEN, "rev A work-around configured");
    return MEPA_RC_OK;
}*/

/*static mepa_rc indy_workaround_after_reset(mepa_device_t *dev)
{
    // Improve cable reach beyond 130m
    EP_WR(dev, INDY_PD_CONTROLS, 0x248b);
    EP_WR(dev, INDY_DFE_INIT2_100, 0x3c30);
    EP_WR(dev, INDY_PGA_TABLE_1G_ENTRY_0, 0x10a);
    EP_WR(dev, INDY_PGA_TABLE_1G_ENTRY_1, 0xed);
    EP_WR(dev, INDY_PGA_TABLE_1G_ENTRY_2, 0xd3);
    EP_WR(dev, INDY_PGA_TABLE_1G_ENTRY_3, 0xbc);
    EP_WR(dev, INDY_PGA_TABLE_1G_ENTRY_4, 0xa8);
    EP_WR(dev, INDY_PGA_TABLE_1G_ENTRY_5, 0x96);
    EP_WR(dev, INDY_PGA_TABLE_1G_ENTRY_6, 0x85);
    EP_WR(dev, INDY_PGA_TABLE_1G_ENTRY_7, 0x77);
    EP_WR(dev, INDY_PGA_TABLE_1G_ENTRY_8, 0x6a);
    EP_WR(dev, INDY_PGA_TABLE_1G_ENTRY_9, 0x5e);
    EP_WR(dev, INDY_PGA_TABLE_1G_ENTRY_10, 0x54);
    EP_WR(dev, INDY_PGA_TABLE_1G_ENTRY_11, 0x4b);
    EP_WR(dev, INDY_PGA_TABLE_1G_ENTRY_12, 0x43);
    EP_WR(dev, INDY_PGA_TABLE_1G_ENTRY_13, 0x3c);
    EP_WR(dev, INDY_PGA_TABLE_1G_ENTRY_14, 0x35);
    EP_WR(dev, INDY_PGA_TABLE_1G_ENTRY_15, 0x2f);
    EP_WR(dev, INDY_PGA_TABLE_1G_ENTRY_16, 0x2a);
    EP_WR(dev, INDY_PGA_TABLE_1G_ENTRY_17, 0x26);

    // Set Rx-clk to avoid crc errors in near-end loopback
    WRM(dev, INDY_UNH_TEST, INDY_F_TEST_RX_CLK, INDY_F_TEST_RX_CLK);

    // Magjack center tapped ports
    EP_WR(dev, INDY_POWER_MGMT_MODE_3, 0x6677);
    EP_WR(dev, INDY_POWER_MGMT_MODE_4, 0x6677);
    EP_WR(dev, INDY_POWER_MGMT_MODE_5, 0x6677);
    EP_WR(dev, INDY_POWER_MGMT_MODE_6, 0x6677);
    EP_WR(dev, INDY_POWER_MGMT_MODE_7, 0x0077);
    EP_WR(dev, INDY_POWER_MGMT_MODE_8, 0x4377);
    EP_WR(dev, INDY_POWER_MGMT_MODE_9, 0x4377);
    EP_WR(dev, INDY_POWER_MGMT_MODE_10, 0x6777);
    EP_WR(dev, INDY_POWER_MGMT_MODE_11, 0x0777);
    EP_WR(dev, INDY_POWER_MGMT_MODE_12, 0x0777);
    EP_WR(dev, INDY_POWER_MGMT_MODE_13, 0x6777);
    EP_WR(dev, INDY_POWER_MGMT_MODE_14, 0x6777);

    return MEPA_RC_OK;
}*/

/*static mepa_rc ti_reset(mepa_device_t *dev, const mepa_reset_param_t *rst_conf)
{
    //uint32_t status;
    phy_data_t *data = (phy_data_t *) dev->data;
    MEPA_ENTER(dev);
    if (!data->init_done) {
        ti_init_conf(dev);
        ti_sgmii_aneg(dev, FALSE);
        data->init_done = TRUE;
    }
        //WRM(dev, TI_GEN_CTRL, TI_F_SW_RESET, TI_F_SW_RESET);
        //WRM(dev, TI_GEN_CTRL, TI_F_SW_RESTART, TI_F_SW_RESTART);
	printf("ti_reset\n");
    if (rst_conf->reset_point == MEPA_RESET_POINT_DEFAULT) {
        //WRM(dev, TI_BMCR, TI_F_BMCR_SOFT_RESET, TI_F_BMCR_SOFT_RESET);
	WRM(dev, TI_GEN_CTRL, TI_F_SW_RESET, TI_F_SW_RESET);
    } else if (rst_conf->reset_point == MEPA_RESET_POINT_POST_MAC) {
        // To avoid qsgmii serdes and Gphy blocks settling in different speeds, use qsgmii soft reset and restart aneg.
        // This must be applied after Mac serdes is configured.
        //if (data->dev.model == 0x26) {
            WR(dev, TI_F_SGMII_SOFT_RESET, 0x1);
            WRM(dev, TI_BMCR, TI_F_BMCR_RESTART_ANEG, TI_F_BMCR_RESTART_ANEG);
        //}
    }

    MEPA_MSLEEP(1);
    // Some of the work-around registers get cleared after reset. So, they are called here
    // after every reset.
    //indy_workaround_after_reset(dev);


    MEPA_EXIT(dev);
    T_I(MEPA_TRACE_GRP_GEN, "Reconfiguring the phy after reset");
    // Reconfigure the phy after reset
    if (rst_conf->reset_point == MEPA_RESET_POINT_DEFAULT) {
        ti_conf_set(dev, &data->conf);
        if (data->events) {
            ti_event_enable_set(dev, data->events, TRUE);
        }
    }
    return MEPA_RC_OK;
}*/
static mepa_rc ti_reset(mepa_device_t *dev, const mepa_reset_param_t *rst_conf)
{
    phy_data_t *data = (phy_data_t *) dev->data;
    MEPA_ENTER(dev);
	WRM(dev, TI_GEN_CTRL, TI_F_SW_RESET, TI_F_SW_RESET);
        MEPA_MSLEEP(10);
	ti_conf_set(dev, &data->conf);
    MEPA_EXIT(dev);
}

static mepa_rc ti_poll(mepa_device_t *dev, mepa_status_t *status)
{
    uint16_t val, val2 = 0;
    phy_data_t *data = (phy_data_t *) dev->data;
//printf("ti_poll\n");

    MEPA_ENTER(dev);
    RD(dev, TI_BMSR, &val);
    status->link = (val & TI_F_BMSR_LINK_STATUS) ? 1 : 0;

    /*if (data->loopback.near_end_ena == TRUE) {
        // loops back to Mac. Ignore Line side status to Link partner.
        status->link = 1;
    }*/
    if (data->conf.speed == MEPA_SPEED_AUTO || data->conf.speed == MEPA_SPEED_1G) {
        uint16_t lp_sym_pause = 0, lp_asym_pause = 0;
        // Default values
        status->speed = MEPA_SPEED_1G;
        status->fdx = 1;
        // check if auto-negotiation is completed or not.
        if (status->link && !(val & TI_F_BMSR_ANEG_COMPLETE)) {
            T_I(MEPA_TRACE_GRP_GEN, "Aneg is not completed for port %d", data->port_no);
            status->link = 0;
            status->speed = MEPA_SPEED_1G;
        } else if (data->loopback.near_end_ena) {
            status->speed = MEPA_SPEED_1G;
        }
        if (!status->link || data->loopback.near_end_ena) {
            // No need to read aneg values when link is down or when near-end loopback enabled.
            goto end;
        }
        // Obtain speed and duplex from link partner's advertised capability.
        RD(dev, TI_ALNPAR_LP_BASE, &val);
        RD(dev, TI_GEN_STATUS1, &val2);
        // 1G half duplex is not supported. Refer direct register - 9
        if ((val2 & TI_F_GEN_STATUS1_1000_T_FULL_DUP) &&
            data->conf.aneg.speed_1g_fdx) {
            status->speed = MEPA_SPEED_1G;
            status->fdx = 1;
        } else if ((val & TI_F_ALNPAR_LP_BASE_100_X_FULL_DUP) &&
                   data->conf.aneg.speed_100m_fdx) {
            status->speed = MEPA_SPEED_100M;
            status->fdx = 1;
        } else if ((val & TI_F_ALNPAR_LP_BASE_100_X_HALF_DUP) &&
                   data->conf.aneg.speed_100m_hdx) {
            status->speed = MEPA_SPEED_100M;
            status->fdx = 0;
        } else if ((val & TI_F_ALNPAR_LP_BASE_10_T_FULL_DUP) &&
                   data->conf.aneg.speed_10m_fdx) {
            status->speed = MEPA_SPEED_10M;
            status->fdx = 1;
        } else if ((val & TI_F_ALNPAR_LP_BASE_10_T_HALF_DUP) &&
                   data->conf.aneg.speed_10m_hdx) {
            status->speed = MEPA_SPEED_10M;
            status->fdx = 0;
        }
        // Get flow control status
        lp_sym_pause = (val & TI_F_ALNPAR_LP_BASE_SYM_PAUSE) ? 1 : 0;
        lp_asym_pause = (val & TI_F_ALNPAR_LP_BASE_ASYM_PAUSE) ? 1 : 0;
        status->aneg.obey_pause = data->conf.flow_control && (lp_sym_pause || lp_asym_pause);
        status->aneg.generate_pause = data->conf.flow_control && lp_sym_pause;
    } else {
        uint8_t speed;
        // Forced speed
        RD(dev, TI_BMCR, &val2);
        speed = (!!(val2 & TI_F_BMCR_SPEED_SEL_BIT_0)) |
                (!!(val2 & TI_F_BMCR_SPEED_SEL_BIT_1) << 1);
        status->speed = (speed == 0) ? MEPA_SPEED_10M :
                        (speed == 1) ? MEPA_SPEED_100M :
                        (speed == 2) ? MEPA_SPEED_1G : MEPA_SPEED_UNDEFINED;
        status->fdx = !!(val2 & TI_F_BMCR_DUP_MODE);
        //check that aneg is not enabled.
        if (val2 & TI_F_BMCR_ANEG_ENA) {
            T_W(MEPA_TRACE_GRP_GEN, "Aneg is enabled for forced speed config on port %d", data->port_no);
        }
    }

end:
    if ( data->conf.speed == MEPA_SPEED_AUTO &&
        data->conf.mac_if_aneg_ena) {
        if (status->link && status->link != data->link_status) {
            // copy the capabilities on host side
            ti_sgmii_tx_abilities(dev, status->speed, status->fdx);
        }
    }
    data->link_status = status->link;
    MEPA_EXIT(dev);
    T_D(MEPA_TRACE_GRP_GEN, "port %d status link %d, speed %d, fdx %d", data->port_no, status->link, status->speed, status->fdx);
    return MEPA_RC_OK;
}


static mepa_rc ti_conf_get(mepa_device_t *dev, mepa_conf_t *const config)
{
    phy_data_t *data = (phy_data_t *)dev->data;
//printf("ti_conf_get\n");
    MEPA_ENTER(dev);
    *config = data->conf;
    MEPA_EXIT(dev);
    T_D(MEPA_TRACE_GRP_GEN, "returning phy config on port %d", data->port_no);
    return MEPA_RC_OK;
}

static mepa_rc ti_conf_set(mepa_device_t *dev, const mepa_conf_t *config)
{
    phy_data_t *data = (phy_data_t *)dev->data;
    uint16_t new_value, mask, old_value,new_reg_value;
    uint16_t status1,status2,status3,status4,status5,status6;
    int phy_ctrl_val;
    uint16_t val,val1;
    mepa_bool_t restart_aneg = FALSE;
    mepa_bool_t sgmii_aneg = config->speed != MEPA_SPEED_AUTO ? FALSE : config->mac_if_aneg_ena;
    MEPA_ENTER(dev);
	/* Force speed optimization for the PHY even if it strapped */
        //WRM(dev, TI_GEN_CFG2, TI_F_SPEED_OPT_EN, TI_F_SPEED_OPT_EN);
	/*Configure mode*/
	WRM(dev, TI_OP_MODE_DECODE, TI_SGMII_COPPER_ETHERNET, TI_SGMII_COPPER_ETHERNET);
	WRM(dev, TI_BMCR, TI_DP83869_BMCR_DEFAULT,TI_DP83869_BMCR_DEFAULT);
	phy_ctrl_val = (TI_F_RX_FIFO_DEPTH | TI_F_TX_FIFO_DEPTH | DP83869_PHY_CTRL_DEFAULT);
	printf("TI_PHY_CONTROL-%02X\n",phy_ctrl_val);
	WRM(dev, TI_PHY_CONTROL , phy_ctrl_val,phy_ctrl_val);
	WRM(dev, TI_GEN_CFG1 , TI_CFG1_DEFAULT, TI_CFG1_DEFAULT);
	RD(dev, TI_GEN_CFG1, &val);
	printf("TI_GEN_CFG1-%02X\n",val);
	WRM(dev, TI_FX_CTRL , TI_FX_CTRL_DEFAULT, TI_FX_CTRL_DEFAULT);
	WRM(dev, TI_GEN_CTRL , TI_F_SW_RESTART,TI_F_SW_RESTART);

	/* Enable Interrupt output INT_OE in CFG4 register */
	//RD(dev, TI_GEN_CFG4, &val);
	//val |= DP83869_INT_OE;
	WRM(dev, TI_GEN_CFG4, TI_F_INT_OE,TI_F_INT_OE);

    ti_direct_reg_wr(dev, TI_MMD_ACCESS_CTRL, 0x001F, TI_DEF_MASK);
    ti_direct_reg_wr(dev, TI_MMD_ACCESS_ADDR_DATA, TI_GEN_CFG3, TI_DEF_MASK);
    ti_direct_reg_wr(dev, TI_MMD_ACCESS_CTRL, 0x401F, TI_DEF_MASK);
    ti_direct_reg_rd(dev, TI_MMD_ACCESS_ADDR_DATA, &val1);
    printf("AUTONEG : %08X\n",val1);
    printf("AUTONEG TIME A: %02X\n",TI_SGMII_AUTONEG_TIME(val1));
    ti_direct_reg_wr(dev, TI_MMD_ACCESS_CTRL, 0x001F, TI_DEF_MASK);
    ti_direct_reg_wr(dev, TI_MMD_ACCESS_ADDR_DATA, TI_GEN_CFG3, TI_DEF_MASK);
    ti_direct_reg_wr(dev, TI_MMD_ACCESS_CTRL, 0x401F, TI_DEF_MASK);
    ti_direct_reg_wr(dev, TI_MMD_ACCESS_ADDR_DATA, 0x1090,TI_DEF_MASK);

    ti_direct_reg_wr(dev, TI_MMD_ACCESS_CTRL, 0x001F, TI_DEF_MASK);
    ti_direct_reg_wr(dev, TI_MMD_ACCESS_ADDR_DATA, TI_GEN_CFG3, TI_DEF_MASK);
    ti_direct_reg_wr(dev, TI_MMD_ACCESS_CTRL, 0x401F, TI_DEF_MASK);
    ti_direct_reg_rd(dev, TI_MMD_ACCESS_ADDR_DATA, &val1);
    printf("AUTONEG : %08X\n",val1);
    printf("AUTONEG TIME B: %02X\n",TI_SGMII_AUTONEG_TIME(val1));

	/*WRM(dev, TI_GEN_CFG3 , DP83867_CFG3_SGMII_ANEG_MASK, 0x00);
	RD(dev, TI_GEN_CFG3, &val1);
	printf("TI_GEN_CFG3-%02X\n",val1);*/

	/* Clock output selection if muxing property is set */
	//WRM(dev, TI_IO_MUX_CFG, DP83869_IO_MUX_CFG_CLK_O_SEL_MASK , DP83869_IO_MUX_CFG_CLK);

    /*if (config->admin.enable) {
        if (sgmii_aneg != data->conf.mac_if_aneg_ena) {
            ti_sgmii_aneg(dev, sgmii_aneg);
    		printf("sgmii_aneg != data->conf.mac_if_aneg_ena\n");
        }
        if (config->speed == MEPA_SPEED_AUTO || config->speed == MEPA_SPEED_1G) {
    		printf("config->speed == MEPA_SPEED_AUTO || config->speed == MEPA_SPEED_1G\n");
            RD(dev, TI_GEN_CFG1, &new_value);
            new_reg_value = 0;
            if (config->aneg.speed_1g_fdx) {
                new_reg_value |= TI_F_GEN_CFG1_G_1000BT_FD_ADV;
		printf("man_neg\n");
                new_reg_value |= TI_F_GEN_CFG1_G_PORT_TYPE;
                new_reg_value |= TI_F_GEN_CFG1_CFG_MAN_CFG_VAL;
            }
            mask = TI_F_GEN_CFG1_G_1000BT_FD_ADV;
            if (config->aneg.speed_1g_hdx) {
                new_reg_value |= TI_F_GEN_CFG1_G_1000BT_HD_ADV;
            }
            if (config->man_neg) {
		printf("config->man_neg\n");
                new_reg_value |= TI_F_GEN_CFG1_CFG_MAN_CFG_ENA;
                new_reg_value |= config->man_neg == MEPA_MANUAL_NEG_REF ? TI_F_GEN_CFG1_CFG_MAN_CFG_VAL : 0;
            }
            mask |= (TI_F_GEN_CFG1_CFG_MAN_CFG_VAL | TI_F_GEN_CFG1_CFG_MAN_CFG_ENA);
            WRM(dev, TI_GEN_CFG1, new_reg_value, mask);

            // Set up auo-negotiation advertisement in register 4
            new_value = (((config->aneg.tx_remote_fault ? 1 : 0) << 13) |
                         ((config->flow_control ? 1 : 0) << 11) |
                         ((config->flow_control ? 1 : 0) << 10) |
                         ((config->aneg.speed_100m_fdx ? 1 : 0) << 8) |
                         ((config->aneg.speed_100m_hdx ? 1 : 0) << 7) |
                         ((config->aneg.speed_10m_fdx ? 1 : 0) << 6) |
                         ((config->aneg.speed_10m_hdx ? 1 : 0) << 5) |
                         (1 << 0)); // default selector field - 1
            RD(dev, TI_ANEG_ADVERTISEMENT, &old_value);
            WR(dev, TI_ANEG_ADVERTISEMENT, new_value);
            // Enable & restart auto-negotiation
            new_value = TI_F_BMCR_ANEG_ENA;
            WRM(dev, TI_BMCR, new_value, new_value | TI_F_BMCR_SOFT_POW_DOWN);
            if (restart_aneg) {
		printf("restart_aneg\n");
                T_I(MEPA_TRACE_GRP_GEN, "Aneg restarted on port %d", data->port_no);
                WRM(dev, TI_BMCR, TI_F_BMCR_RESTART_ANEG, TI_F_BMCR_RESTART_ANEG);
            }
        } else if (config->speed != MEPA_SPEED_UNDEFINED) {
    		printf("config->speed != MEPA_SPEED_UNDEFINED\n");
            T_I(MEPA_TRACE_GRP_GEN, "forced speed %d configured\n", config->speed);
            new_value = ((config->speed == MEPA_SPEED_100M ? 1 : 0) << 13) | (0 << 12) |
                        ((config->fdx ? 1 : 0) << 8) |
                        ((config->speed == MEPA_SPEED_1G ? 1 : 0) << 6);
            mask = TI_BIT(13) | TI_BIT(12) | TI_BIT(8) | TI_BIT(6) | TI_F_BMCR_SOFT_POW_DOWN | TI_F_BMCR_ANEG_ENA;
            WRM(dev, TI_BMCR, new_value, mask);
        }
    } else {
    		printf("else power down\n");
        T_I(MEPA_TRACE_GRP_GEN, "set power down\n");
        // set soft power down bit
        WRM(dev, TI_BMCR, TI_F_BMCR_SOFT_POW_DOWN, TI_F_BMCR_SOFT_POW_DOWN);
    }*/
    data->conf = *config;
    data->conf.mac_if_aneg_ena = sgmii_aneg;
    MEPA_EXIT(dev);

    return MEPA_RC_OK;
}


/*static mepa_rc mas_if_set(mepa_device_t *dev,
                           mepa_port_interface_t mac_if)
{
    if (mac_if != MESA_PORT_INTERFACE_SGMII) {
        return MEPA_RC_ERROR;
    }
    return MEPA_RC_OK;
}

static mepa_rc mas_if_get(mepa_device_t *dev, mepa_port_speed_t speed,
                          mepa_port_interface_t *mac_if)
{
    *mac_if = MESA_PORT_INTERFACE_SGMII;
    return MEPA_RC_OK;
}*/


static mepa_rc ti_if_get(mepa_device_t *dev, mepa_port_speed_t speed,
                           mepa_port_interface_t *mac_if)
{

    MEPA_ENTER(dev);
    *mac_if = MESA_PORT_INTERFACE_SGMII;
    MEPA_EXIT(dev);
    return MEPA_RC_OK;
}

static mepa_rc ti_if_set(mepa_device_t *dev,
                           mepa_port_interface_t mac_if)
{
    if (mac_if == MESA_PORT_INTERFACE_SGMII) {
	mac_if = MESA_PORT_INTERFACE_SGMII;
        //return MEPA_RC_ERROR;
    }

    return MEPA_RC_OK;
}


// wait in loop while cable diagnostics is running.
/*static mepa_bool_t indy_wait_for_cable_diagnostics(mepa_device_t *dev)
{
    uint8_t cnt = 0;
    uint16_t value;
    mepa_bool_t ret = FALSE;

    while (cnt < 100) { // wait for utmost 1 second
        RD(dev, INDY_CABLE_DIAG, &value);
        if (value & INDY_F_CABLE_DIAG_TEST_ENA) {
            MEPA_MSLEEP(10);
            cnt++;
        } else {
            ret = TRUE;
            break;
        }
    }
    T_D(MEPA_TRACE_GRP_GEN, "ret = %d cnt= %d value=0x%x\n", ret, cnt, value);
    return ret;
}*/
//Before starting cable diagnostics, do necessary phy configuration like reset speed config.
/*static mepa_rc indy_cab_diag_enter_config(mepa_device_t *dev)
{
    WRM(dev, TI_BMCR, INDY_F_BASIC_CTRL_SOFT_RESET, INDY_F_BASIC_CTRL_SOFT_RESET);
    MEPA_MSLEEP(1);
    WR(dev, TI_BMCR, 0x140);
    MEPA_MSLEEP(50);
    return MEPA_RC_OK;
}*/
// After exiting cable diagnostics, restore phy configuration.
/*static mepa_rc indy_cab_diag_exit_config(mepa_device_t *dev)
{
    mepa_reset_param_t rst_cfg = {};

    rst_cfg.reset_point = MEPA_RESET_POINT_DEFAULT;
    // Restore configuration after cable diagnostics.
    indy_reset(dev, &rst_cfg);
    return MEPA_RC_OK;
}*/
// Indy phy dignostics is calculated only when there is no remote link partner for the port.
// For mode values {0,1} corresponding to {VTSS_PHY_MODE_ANEG, VTSS_PHY_MODE_FORCED}, diagnostics is calculated.
// For power down mode(2), diagnostics is not calculated.
/*static mepa_rc indy_cab_diag_start(mepa_device_t *dev, int mode)
{
    phy_data_t *data = (phy_data_t *)dev->data;
    uint16_t value, mask = 0, pair, status;
    mepa_cable_diag_result_t *res = &data->cable_diag;

    T_I(MEPA_TRACE_GRP_GEN, "port=%d mode=%d\n", data->port_no, mode);
    MEPA_ENTER(dev);
    // Initialize diagnostics
    for (pair = 0; pair < 4; pair++) {
        res->status[pair] = MEPA_CABLE_DIAG_STATUS_UNKNOWN;
        res->length[pair] = 0;
        res->link = FALSE;
    }
    // return for power down mode
    if (mode == INDY_CABLE_MODE_POWER_DOWN) {
        MEPA_EXIT(dev);
        return MEPA_RC_ERROR;
    }
    indy_cab_diag_enter_config(dev);
    for (pair = 0; pair < 4; pair++) {
        // clear diag test ena before starting
        WRM(dev, INDY_CABLE_DIAG, 0, INDY_F_CABLE_DIAG_TEST_ENA);

        value = mask = status = 0;
        value |= INDY_F_CABLE_DIAG_TEST_ENA;
        value |= INDY_F_CABLE_TEST_PAIR(pair);
        mask |= INDY_F_CABLE_DIAG_TEST_ENA | INDY_M_CABLE_TEST_PAIR;
        WRM(dev, INDY_CABLE_DIAG, value, mask);
        if (indy_wait_for_cable_diagnostics(dev)) {
            RD(dev, INDY_CABLE_DIAG, &value);
            status = INDY_X_CABLE_DIAG_STATUS(value);
            if ((status == INDY_CABLE_OPEN) || (status == INDY_CABLE_SHORT)) {
                res->status[pair] = (status == INDY_CABLE_SHORT) ? MEPA_CABLE_DIAG_STATUS_SHORT : MEPA_CABLE_DIAG_STATUS_OPEN;
                res->length[pair] = 0.8 * (INDY_X_CABLE_DIAG_DATA(value) - 22);
                res->link = TRUE;
                T_I(MEPA_TRACE_GRP_GEN, "pair=%d status=%d length=%d\n", pair, res->status[pair], res->length[pair]);
            } else if (status == INDY_CABLE_FAIL) {
                res->status[pair] = MEPA_CABLE_DIAG_STATUS_ABNORM;
                res->link = FALSE;
                T_I(MEPA_TRACE_GRP_GEN, "link status failed for pair %d \n", pair);
            } else { // status as INDY_CABLE_NORMAL
                res->link = TRUE;
                T_I(MEPA_TRACE_GRP_GEN, "pair=%d status=%d \n", pair, status);
            }
        }
    }
    MEPA_EXIT(dev);
    indy_cab_diag_exit_config(dev);
    return MEPA_RC_OK;
}
static mepa_rc indy_cab_diag_get(mepa_device_t *dev, mepa_cable_diag_result_t *res)
{
    phy_data_t *data = (phy_data_t *)dev->data;
    MEPA_ENTER(dev);
    *res = data->cable_diag;
    MEPA_EXIT(dev);
    return MEPA_RC_OK;
}*/

static mepa_rc ti_aneg_status_get(mepa_device_t *dev, mepa_aneg_status_t *status)
{
//printf("ti_aneg_status_get\n");
    uint16_t val;

    MEPA_ENTER(dev);
    RD(dev, TI_GEN_STATUS1, &val);
    status->master_cfg_fault = (val & TI_F_GEN_STATUS1_CFG_FAULT) ? TRUE : FALSE;
    status->master = val & TI_F_GEN_STATUS1_CFG_RES ? TRUE : FALSE;
    MEPA_EXIT(dev);
    T_I(MEPA_TRACE_GRP_GEN, "aneg status get mstr %d", status->master);
    return MEPA_RC_OK;
}

// read direct registers for debugging
static mepa_rc ti_direct_reg_read(mepa_device_t *dev, uint32_t address, uint16_t *const value)
{
    mepa_rc rc;
    uint16_t addr = address & 0x1f;
//printf("ti_direct_reg_read\n");
    MEPA_ENTER(dev);
    rc = ti_direct_reg_rd(dev, addr, value);
    MEPA_EXIT(dev);
    return rc;
}

// write direct registers. Used for debugging.
static mepa_rc ti_direct_reg_write(mepa_device_t *dev, uint32_t address, uint16_t value)
{
    mepa_rc rc;
    uint16_t addr = address & 0x1f;
//printf("ti_direct_reg_write\n");
    MEPA_ENTER(dev);
    rc = ti_direct_reg_wr(dev, addr, value, 0xFFFF);
    MEPA_EXIT(dev);
    return rc;
}

// read extended page/mmd register for debugging
static mepa_rc ti_mmd_reg_read(mepa_device_t *dev, uint32_t address, uint16_t *const value)
{
    mepa_rc rc;
    phy_data_t *data = (phy_data_t *)dev->data;
    mepa_port_no_t port_no = data->port_no;
    uint16_t page_mmd = (address >> 16) & 0xffff;
    uint16_t addr = address & 0xffff;
    uint16_t mmd = (page_mmd >> 11);
//printf("ti_mmd_reg_read\n");
    MEPA_ENTER(dev);
    //if (mmd) {
        rc = ti_mmd_reg_rd(dev, mmd, addr, value);
	//printf("ti_mmd_reg_read");
    //} /*else {
        //rc = indy_ext_reg_rd(dev, page_mmd, addr, value);
    //}
    MEPA_EXIT(dev);
    return rc;
}

// write extended page/mmd register. Used for debugging.
static mepa_rc ti_mmd_reg_write(mepa_device_t *dev, uint32_t address, uint16_t value)
{
    mepa_rc rc;
    phy_data_t *data = (phy_data_t *)dev->data;
    mepa_port_no_t port_no = data->port_no;
    uint16_t page_mmd = (address >> 16) & 0xffff;
    uint16_t addr = address & 0xffff;
    uint16_t mmd = (page_mmd >> 11);
//printf("ti_mmd_reg_write\n");
    MEPA_ENTER(dev);
    //if (mmd) {
        rc = ti_mmd_reg_wr(dev, mmd, addr, value, 0xFFFF);
    //} 
     /*else {
        rc = indy_ext_reg_wr(dev, page_mmd, addr, value, 0xFFFF);
    }*/
    MEPA_EXIT(dev);
    return rc;
}

// Get current enabled events
static mepa_rc ti_event_enable_get(mepa_device_t *dev, mepa_event_t *const event)
{
//printf("ti_event_enable_get\n");
    mepa_rc rc = MEPA_RC_OK;
    phy_data_t *data = (phy_data_t *)dev->data;
    MEPA_ENTER(dev);
    *event = data->events;
    MEPA_EXIT(dev);
    return rc;
}

// Enable events
static mepa_rc ti_event_enable_set(mepa_device_t *dev, mepa_event_t event, mepa_bool_t enable)
{
    mepa_rc rc = MEPA_RC_OK;
    uint16_t ev_mask = 0, i;
    phy_data_t *data = (phy_data_t *)dev->data;
    data->events = enable ? (data->events | event) :
                   (data->events & ~event);
//printf("ti_event_enable_set\n");
    MEPA_ENTER(dev);
    for (i = 0; i < sizeof(mepa_event_t) * 8; i++) {
        switch (event & (1 << i)) {
        case MEPA_LINK_LOS:
            ev_mask = ev_mask | TI_F_INTERRUPT_MASK_LINK_STATUS;
            break;
        /*case MEPA_FAST_LINK_FAIL:
            ev_mask = ev_mask | INDY_F_GPHY_INTR_ENA_FLF_INTR;
            break;*/
        default:
            // Not yet implemented
            break;
        }
    }
    WRM(dev, TI_INTERRUPT_MASK, enable ? ev_mask : 0, ev_mask);
    T_I(MEPA_TRACE_GRP_GEN, "events enabled 0x%x \n", data->events);
    MEPA_EXIT(dev);
    return rc;
}



// Poll the status of currently enabled events
static mepa_rc ti_event_status_poll(mepa_device_t *dev, mepa_event_t *const status)
{
    uint16_t val;
    mepa_rc rc = MEPA_RC_OK;
    phy_data_t *data = (phy_data_t *)dev->data;
    *status = 0;
//printf("ti_event_status_poll\n");
    MEPA_ENTER(dev);
    rc = RD(dev, TI_INTR_STATUS, &val);
    if (val & TI_F_INTERRUPT_MASK_LINK_STATUS) {
        *status |= data->events & MEPA_LINK_LOS;
    }
    /*if (val & INDY_F_GPHY_INTR_ENA_FLF_INTR) {
        *status |= data->events & MEPA_FAST_LINK_FAIL;
    }*/
    MEPA_EXIT(dev);
    T_I(MEPA_TRACE_GRP_GEN, " port %d events polled 0x%x val %x\n", data->port_no, *status, val);
    return rc;
}

// Set loopback modes in phy
/*static mepa_rc ti_loopback_set(mepa_device_t *dev, const mepa_loopback_t *loopback)
{
    phy_data_t *data = (phy_data_t *)dev->data;
//printf("ti_loopback_set\n");
    if ((loopback->mac_serdes_input_ena == TRUE) || (loopback->mac_serdes_facility_ena == TRUE) ||
        (loopback->mac_serdes_equip_ena == TRUE) || (loopback->media_serdes_input_ena == TRUE) ||
        (loopback->media_serdes_facility_ena == TRUE) || (loopback->media_serdes_equip_ena == TRUE)) {
        // Not supported on Indy
        return MEPA_RC_NOT_IMPLEMENTED;
    }
    MEPA_ENTER(dev);
    if (loopback->near_end_ena == TRUE) {
        WRM(dev, TI_BMCR, TI_F_BMCR_LOOPBACK, TI_F_BMCR_LOOPBACK);
        if (data->conf.speed == MEPA_SPEED_AUTO || data->conf.speed == MEPA_SPEED_1G) {
            // Set 1000mbps speed for loopback when there is auto-negotiation mode. While removing loopback, restore the original mode.
            // Disable auto-negotiation
            WRM(dev, TI_BMCR, 0, TI_F_BMCR_ANEG_ENA);
            // Set 1000mbps speed
            WRM(dev, TI_BMCR, TI_F_BMCR_SPEED_SEL_BIT_1, TI_F_BMCR_SPEED_SEL_BIT_1 | TI_F_BMCR_SPEED_SEL_BIT_0);
        }
    } else if (data->loopback.near_end_ena == TRUE) {
        WRM(dev, TI_BMCR, 0, TI_F_BMCR_LOOPBACK);
        if (data->conf.speed == MEPA_SPEED_AUTO || data->conf.speed == MEPA_SPEED_1G) {
            // Remove 1000mbps config applied while setting loopback.
            WRM(dev, TI_GEN_CFG1, 0, TI_F_GEN_CFG1_CFG_MAN_CFG_ENA |
                TI_F_GEN_CFG1_CFG_MAN_CFG_VAL);
            // Enable aneg
            WRM(dev, TI_BMCR, TI_F_BMCR_ANEG_ENA | TI_F_BMCR_RESTART_ANEG,
                TI_F_BMCR_ANEG_ENA | TI_F_BMCR_RESTART_ANEG);
        }
    }
    data->loopback = *loopback;
    MEPA_EXIT(dev);
    T_I(MEPA_TRACE_GRP_GEN, "loopback enabled\n");
    return MEPA_RC_OK;
}
{
    phy_data_t *data = (phy_data_t *) dev->data;
//printf("ti_loopback_get\n");
    MEPA_ENTER(dev);
    *loopback = data->loopback;
    MEPA_EXIT(dev);
    return MEPA_RC_OK;
}*/
// Returns gpio using port number and led number
/*static uint8_t led_num_to_gpio_mapping(mepa_device_t *dev, mepa_led_num_t led_num)
{
    phy_data_t *data = (phy_data_t *) dev->data;
    uint8_t gpio = 11;// port 0 as default.
    switch (data->packet_idx) {
    case 0:
        gpio = led_num == MEPA_LED0 ? 11 : 12;
        break;
    case 1:
        gpio = led_num == MEPA_LED0 ? 17 : 18;
        break;
    case 2:
        gpio = led_num == MEPA_LED0 ? 19 : 20;
        break;
    case 3:
        gpio = led_num == MEPA_LED0 ? 13 : 14;
        break;
    default:
        // invalid.
        break;
    }
    T_I(MEPA_TRACE_GRP_GEN, "gpio mapped %d\n", gpio);
    return gpio;
}
static uint8_t led_mepa_mode_to_indy(mepa_gpio_mode_t mode)
{
    uint8_t ret = 0;
    switch (mode) {
    case MEPA_GPIO_MODE_LED_LINK_ACTIVITY:
        ret = 0;
        break;
    case MEPA_GPIO_MODE_LED_LINK1000_ACTIVITY:
        ret = 1;
        break;
    case MEPA_GPIO_MODE_LED_LINK100_ACTIVITY:
        ret = 2;
        break;
    case MEPA_GPIO_MODE_LED_LINK10_ACTIVITY:
        ret = 3;
        break;
    case MEPA_GPIO_MODE_LED_LINK100_1000_ACTIVITY:
        ret = 4;
        break;
    case MEPA_GPIO_MODE_LED_LINK10_1000_ACTIVITY:
        ret = 5;
        break;
    case MEPA_GPIO_MODE_LED_LINK10_100_ACTIVITY:
        ret = 6;
        break;
    case MEPA_GPIO_MODE_LED_DUPLEX_COLLISION:
        ret = 8;
        break;
    case MEPA_GPIO_MODE_LED_COLLISION:
        ret = 9;
        break;
    case MEPA_GPIO_MODE_LED_ACTIVITY:
        ret = 10;
        break;
    case MEPA_GPIO_MODE_LED_AUTONEGOTIATION_FAULT:
        ret = 12;
        break;
    case MEPA_GPIO_MODE_LED_FORCE_LED_OFF:
        ret = 14;
        break;
    case MEPA_GPIO_MODE_LED_FORCE_LED_ON:
        ret = 15;
        break;
    case MEPA_GPIO_MODE_LED_DISABLE_EXTENDED:
        ret = 0xf0;
        break;
    default:
        ret = 0xff; // Not valid for indy
        break;
    }
    return ret;
}
// In Indy, LED0 of software Api maps to LED1 of hardware,
//          LED1 of software Api maps to LED2 of hardware.
static mepa_rc indy_led_mode_set(mepa_device_t *dev, mepa_gpio_mode_t led_mode, mepa_led_num_t led_num)
{
    uint16_t mode;

    // Indy supports only LED0 and LED1
    if ((led_num != MEPA_LED0) && (led_num != MEPA_LED1)) {
        T_W(MEPA_TRACE_GRP_GEN, "8814 supports only leds 0 & 1\n");
        return MEPA_RC_NOT_IMPLEMENTED;
    }
    if ((mode = led_mepa_mode_to_indy(led_mode)) == 0xff) {// Not valid
        T_W(MEPA_TRACE_GRP_GEN, "Not valid led mode");
        return MEPA_RC_NOT_IMPLEMENTED;
    }
    if (mode == MEPA_GPIO_MODE_LED_DISABLE_EXTENDED) {
        // Normal operation
        EP_WRM(dev, INDY_LED_CONTROL_REG1, INDY_F_LED_CONTROL_KSZ_LED_MODE, INDY_F_LED_CONTROL_KSZ_LED_MODE);
    } else { // extended mode
        EP_WRM(dev, INDY_LED_CONTROL_REG1, 0, INDY_F_LED_CONTROL_KSZ_LED_MODE);
        EP_WRM(dev, INDY_LED_CONTROL_REG2, INDY_ENCODE_BITFIELD(mode, led_num * 4, 4), INDY_ENCODE_BITMASK(led_num * 4, 4));
    }
    return MEPA_RC_OK;
}
static mepa_rc indy_gpio_mode_private(mepa_device_t *dev, const mepa_gpio_conf_t *data)
{
    uint16_t gpio_en = 0, dir, val = 0, gpio_no = data->gpio_no;
    mepa_gpio_mode_t mode = data->mode;

    if (mode == MEPA_GPIO_MODE_OUT || mode == MEPA_GPIO_MODE_IN) {
        gpio_en = 1;
        dir = mode == MEPA_GPIO_MODE_OUT ? 1 : 0;
    } else if (mode >= MEPA_GPIO_MODE_LED_LINK_ACTIVITY && mode <= MEPA_GPIO_MODE_LED_DISABLE_EXTENDED) {
        MEPA_RC(indy_led_mode_set(dev, mode, data->led_num));
        // Enable alternative gpio mode for led.
        gpio_no = led_num_to_gpio_mapping(dev, data->led_num);
    } else if (mode == MEPA_GPIO_MODE_RCVRD_CLK_OUT1 || mode == MEPA_GPIO_MODE_RCVRD_CLK_OUT2) {
        gpio_no = mode == MEPA_GPIO_MODE_RCVRD_CLK_OUT1 ? 9 : 10;
    }
    if (gpio_no < 16) {
        val = 1 << gpio_no;
        dir = dir << gpio_no;
        EP_WRM(dev, INDY_GPIO_EN2, gpio_en ? val : 0, val);
        if (gpio_en) {
            EP_WRM(dev, INDY_GPIO_DIR2, dir, val);
        }
    } else if (gpio_no < 24) {
        val = 1 << (gpio_no - 16);
        dir = dir << (gpio_no - 16);
        EP_WRM(dev, INDY_GPIO_EN1, gpio_en ? val : 0, val);
        if (gpio_en) {
            EP_WRM(dev, INDY_GPIO_DIR1, dir, val);
        }
    } else {
        // Not supported. Illegal for Indy.
        T_W(MEPA_TRACE_GRP_GEN, "Not valid gpio on 8814 phy");
    }
    return MEPA_RC_OK;
}

// Set gpio mode to input, output or alternate function
static mepa_rc indy_gpio_mode_set(mepa_device_t *dev, const mepa_gpio_conf_t *gpio_conf)
{
    mepa_rc rc = MEPA_RC_OK;

    // Indy has 0-23 gpios.
    if (gpio_conf->gpio_no > 23) {
        T_W(MEPA_TRACE_GRP_GEN, "Not valid gpio on 8814 phy");
        return MEPA_RC_NOT_IMPLEMENTED;
    }
    MEPA_ENTER(dev);
    rc = indy_gpio_mode_private(dev, gpio_conf);
    MEPA_EXIT(dev);
    return rc;
}*/

// Set Isolate mode
static mepa_rc ti_isolate_mode_conf(mepa_device_t *dev, const mepa_bool_t iso_en)
{
//printf("ti_isolate_mode_conf\n");
    MEPA_ENTER(dev);

    if (iso_en == TRUE) {
        WRM(dev, TI_BMCR, TI_F_BMCR_ISO_MODE_EN, TI_F_BMCR_ISO_MODE_EN);
    } else {
        WRM(dev, TI_BMCR, 0, TI_F_BMCR_ISO_MODE_EN);
    }

    MEPA_EXIT(dev);
    return MEPA_RC_OK;
}

/*static mepa_rc indy_gpio_out_set(mepa_device_t *dev, uint8_t gpio_no, mepa_bool_t value)
{
    uint16_t val = 0;

    // Indy has 0-23 gpios.
    if (gpio_no > 23) {
        return MEPA_RC_NOT_IMPLEMENTED;
    }
    MEPA_ENTER(dev);
    if (gpio_no < 16) {
        val = 1 << gpio_no;
        EP_WRM(dev, INDY_GPIO_DATA2, value ? val : 0, val);
    } else if (gpio_no < 24) {
        val = 1 << (gpio_no - 16);
        EP_WRM(dev, INDY_GPIO_DATA1, value ? val : 0, val);
    } else {
        // Not supported. Illegal for Indy.
        T_W(MEPA_TRACE_GRP_GEN, "Not valid gpio on 8814 phy");
    }

    MEPA_EXIT(dev);
    return MEPA_RC_OK;
}
static mepa_rc indy_gpio_in_get(mepa_device_t *dev, uint8_t gpio_no, mepa_bool_t *const value)
{
    uint16_t val = 0;

    // Indy has 0-23 gpios.
    if (gpio_no > 23) {
        T_W(MEPA_TRACE_GRP_GEN, "Not valid gpio on 8814 phy");
        return MEPA_RC_NOT_IMPLEMENTED;
    }
    MEPA_ENTER(dev);
    if (gpio_no < 16) {
        EP_RD(dev, INDY_GPIO_DATA2, &val);
        *value = (val >> gpio_no) & 0x1 ? TRUE : FALSE;
    } else if (gpio_no < 24) {
        EP_RD(dev, INDY_GPIO_DATA1, &val);
        *value = ((val >> (gpio_no - 16)) & 0x1) ? TRUE : FALSE;
    }
    MEPA_EXIT(dev);
    return MEPA_RC_OK;
}*/

/*static mepa_rc indy_recovered_clk_set(mepa_device_t *dev, const mepa_synce_clock_conf_t *conf)
{
    phy_data_t *data = (phy_data_t *) dev->data;
    mepa_gpio_conf_t gpio_conf;
    uint16_t divider = 1;
    uint16_t clkout_src = 7;
    mepa_rc rc = MEPA_RC_OK;

    MEPA_ENTER(dev);
    // Enable recovered clock outputs in gpio
    gpio_conf.mode = (conf->dst == MEPA_SYNCE_CLOCK_DST_1) ? MEPA_GPIO_MODE_RCVRD_CLK_OUT1 : MEPA_GPIO_MODE_RCVRD_CLK_OUT2;
    rc = indy_gpio_mode_private(dev, &gpio_conf);

    switch (conf->freq) {
    case MEPA_FREQ_25M:
        divider = 5; // 125Mhz/25Mhz = 5
        break;
    case MEPA_FREQ_31_25M:
        divider = 4; // 125Mhz/31.25Mhz = 4
        break;
    case MEPA_FREQ_125M:
    default:
        divider = 1; // 125Mhz/125Mhz = 1
        break;
    }
    switch (conf->src) {
    case MEPA_SYNCE_CLOCK_SRC_DISABLED:
        clkout_src = 7; // Forces Recovered Clock Output to 0
        break;
    case MEPA_SYNCE_CLOCK_SRC_COPPER_MEDIA:
        clkout_src = data->packet_idx % 4;
        break;
    case MEPA_SYNCE_CLOCK_SRC_CLOCK_IN_1:
        clkout_src = 0b100; // Recovered Clock Input 1
        break;
    case MEPA_SYNCE_CLOCK_SRC_CLOCK_IN_2:
        clkout_src = 0b101; // Recovered Clock Input 2
        break;
    case MEPA_SYNCE_CLOCK_SRC_SERDES_MEDIA:
    default:
        T_W(MEPA_TRACE_GRP_GEN, "Invalid valid clock source, port-no : %d\n", dev->numeric_handle);
        break;
    }
    T_I(MEPA_TRACE_GRP_GEN, "port_ena %d divider %d\n", clkout_src, divider);
    if (conf->dst == MEPA_SYNCE_CLOCK_DST_1) {
        EP_WR(dev, INDY_RCVRD_CLK_OUT_SEL_1, clkout_src);
        EP_WR(dev, INDY_RCVRD_CLK_OUT_DIV_1, divider);
    } else if (conf->dst == MEPA_SYNCE_CLOCK_DST_2) {
        EP_WR(dev, INDY_RCVRD_CLK_OUT_SEL_2, clkout_src);
        EP_WR(dev, INDY_RCVRD_CLK_OUT_DIV_2, divider);
    }

    MEPA_EXIT(dev);

    data->synce_conf = *conf;
    return rc;
}*/
// Link the base port
static mepa_rc ti_link_base_port(mepa_device_t *dev, mepa_device_t *base_dev, uint8_t packet_idx)
{
    phy_data_t *data = (phy_data_t *)dev->data;
//printf("ti_link_base_port\n");
    MEPA_ENTER(dev);
    data->base_dev = base_dev;
    data->packet_idx = packet_idx;

    MEPA_EXIT(dev);
    return MEPA_RC_OK;
}

static mepa_device_t *ti_probe(mepa_driver_t *drv,
                                 const mepa_callout_t    MEPA_SHARED_PTR *callout,
                                 struct mepa_callout_ctx MEPA_SHARED_PTR *callout_ctx,
                                 struct mepa_board_conf              *board_conf)
{
    mepa_device_t *dev;
    phy_data_t *data;

    dev = mepa_create_int(drv, callout, callout_ctx, board_conf, sizeof(phy_data_t));
    if (!dev) {
        return 0;
    }

    data = dev->data;
    data->port_no = board_conf->numeric_handle;
    data->events = 0;

#ifdef REG_DBG
    (void) ti_reg_dump(dev);
#endif

       (void) ti_init_conf(dev);
       (void) ti_conf_set(dev, &data->conf);

    T_I(MEPA_TRACE_GRP_GEN, "ti driver probed for port %d", data->port_no);
    return dev;
}

static mepa_rc ti_info_get(mepa_device_t *dev, mepa_phy_info_t *const phy_info)
{
    phy_data_t *data = (phy_data_t *)(dev->data);
    phy_data_t *base_data = data->base_dev ? ((phy_data_t *)(data->base_dev->data)) : NULL;
//printf("ti_info_get\n");
    phy_info->cap = 0;
    phy_info->part_number = dev->drv->id;
    phy_info->revision = dev->drv->id & 0xF;
    phy_info->cap |= MEPA_CAP_SPEED_MASK_1G;
    phy_info->cap |= MEPA_CAP_TS_MASK_NONE;
    phy_info->ts_base_port = base_data ? base_data->port_no : 0;

    return MEPA_RC_OK;
}

mepa_drivers_t mepa_dp83869_driver_init()
{
    static const int nr_ti_drivers = 1;
    static mepa_driver_t ti_drivers[] = {
        {
            .id = 0x2000a0f1,  // DP83869 standalone PHY
            .mask = 0xfffff0,
            .mepa_driver_delete = ti_delete,
            .mepa_driver_reset = ti_reset,
            .mepa_driver_poll = ti_poll,
            .mepa_driver_conf_get = ti_conf_get,
            .mepa_driver_conf_set = ti_conf_set,
            .mepa_driver_if_get = ti_if_get,
            .mepa_driver_if_set = ti_if_set,
            //.mepa_driver_cable_diag_start = indy_cab_diag_start,
            //.mepa_driver_cable_diag_get = indy_cab_diag_get,
            .mepa_driver_probe = ti_probe,
            .mepa_driver_aneg_status_get = ti_aneg_status_get,
            .mepa_driver_clause22_read = ti_direct_reg_read,
            .mepa_driver_clause22_write = ti_direct_reg_write,
            .mepa_driver_clause45_read  = ti_mmd_reg_read,
            .mepa_driver_clause45_write = ti_mmd_reg_write,
            .mepa_driver_event_enable_get = ti_event_enable_get,
            .mepa_driver_event_enable_set = ti_event_enable_set,
            //.mepa_driver_event_poll = ti_event_status_poll,
            //.mepa_driver_loopback_set = ti_loopback_set,
            //.mepa_driver_loopback_get = ti_loopback_get,
            //.mepa_driver_gpio_mode_set = indy_gpio_mode_set,
            //.mepa_driver_gpio_out_set = indy_gpio_out_set,
            //.mepa_driver_gpio_in_get = indy_gpio_in_get,
            .mepa_driver_link_base_port = ti_link_base_port,
            //.mepa_ts = &indy_ts_drivers,
            //.mepa_driver_synce_clock_conf_set = indy_recovered_clk_set,
            .mepa_driver_phy_info_get = ti_info_get,
            .mepa_driver_isolate_mode_conf = ti_isolate_mode_conf,
            .mepa_debug_info_dump = ti_debug_info_dump,
        },

    };

    mepa_drivers_t result;
    result.phy_drv = ti_drivers;
    result.count = nr_ti_drivers;

    return result;
}
