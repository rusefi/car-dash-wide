/*
 * ft5336.h
 *
 *  Created on: 19 Jan 2022
 *      Author: Ben
 */

#ifndef INC_FT5336_H_
#define INC_FT5336_H_


#define TS_SWAP_NONE ((uint8_t) 0x01)

#define TS_SWAP_X ((uint8_t) 0x02)

#define TS_SWAP_Y ((uint8_t) 0x04)

#define TS_SWAP_XY ((uint8_t) 0x08)

//------------------------------------------

#define TS_I2C_ADDRESS ((uint16_t)0x70)

#define FT5336_ID_VALUE ((uint8_t)0x51)

#define FT5336_TD_STAT_REG ((uint8_t)0x02)

#define FT5336_GMODE_REG ((uint8_t)0xA4)

#define FT5336_CHIP_ID_REG ((uint8_t)0xA8)

#define FT5336_G_MODE_INTERRUPT_POLLING ((uint8_t)0x00)

#define FT5336_G_MODE_INTERRUPT_MASK ((uint8_t)0x03)

#define FT5336_TD_STAT_MASK ((uint8_t)0x0F)

#define FT5336_G_MODE_INTERRUPT_SHIFT ((uint8_t)0x00)

#define FT5336_GEST_ID_REG ((uint8_t)0x01)

//------------------------------------------

/* Possible values of FT5336_GEST_ID_REG */

#define FT5336_GEST_ID_NO_GESTURE ((uint8_t)0x00)

#define FT5336_GEST_ID_MOVE_UP ((uint8_t)0x10)

#define FT5336_GEST_ID_MOVE_RIGHT ((uint8_t)0x14)

#define FT5336_GEST_ID_MOVE_DOWN ((uint8_t)0x18)

#define FT5336_GEST_ID_MOVE_LEFT ((uint8_t)0x1C)

#define FT5336_GEST_ID_SINGLE_CLICK ((uint8_t)0x20)

#define FT5336_GEST_ID_DOUBLE_CLICK ((uint8_t)0x22)

#define FT5336_GEST_ID_ROTATE_CLOCKWISE ((uint8_t)0x28)

#define FT5336_GEST_ID_ROTATE_C_CLOCKWISE ((uint8_t)0x29)

#define FT5336_GEST_ID_ZOOM_IN ((uint8_t)0x40)

#define FT5336_GEST_ID_ZOOM_OUT ((uint8_t)0x49)

#define FT5336_I2C_NOT_INITIALIZED ((uint8_t)0x00)

#define FT5336_I2C_INITIALIZED ((uint8_t)0x01)

#define FT5336_MAX_DETECTABLE_TOUCH ((uint8_t)0x05)

//------------------------------------------

#define FT5336_TOUCH_POS_MSB_MASK ((uint8_t)0x0F)

#define FT5336_TOUCH_POS_MSB_SHIFT ((uint8_t)0x00)

#define FT5336_TOUCH_POS_LSB_MASK ((uint8_t)0xFF)

#define FT5336_TOUCH_POS_LSB_SHIFT ((uint8_t)0x00)

//------------------------------------------

#define FT5336_P1_XH_REG ((uint8_t)0x03)

#define FT5336_P1_XL_REG ((uint8_t)0x04)

#define FT5336_P1_YH_REG ((uint8_t)0x05)

#define FT5336_P1_YL_REG ((uint8_t)0x06)

#define FT5336_P2_XH_REG ((uint8_t)0x09)

#define FT5336_P2_XL_REG ((uint8_t)0x0A)

#define FT5336_P2_YH_REG ((uint8_t)0x0B)

#define FT5336_P2_YL_REG ((uint8_t)0x0C)

#define FT5336_P3_XH_REG ((uint8_t)0x0F)

#define FT5336_P3_XL_REG ((uint8_t)0x10)

#define FT5336_P3_YH_REG ((uint8_t)0x11)

#define FT5336_P3_YL_REG ((uint8_t)0x12)

#define FT5336_P4_XH_REG ((uint8_t)0x15)

#define FT5336_P4_XL_REG ((uint8_t)0x16)

#define FT5336_P4_YH_REG ((uint8_t)0x17)

#define FT5336_P4_YL_REG ((uint8_t)0x18)

#define FT5336_P5_XH_REG ((uint8_t)0x1B)

#define FT5336_P5_XL_REG ((uint8_t)0x1C)

#define FT5336_P5_YH_REG ((uint8_t)0x1D)

#define FT5336_P5_YL_REG ((uint8_t)0x1E)

#define FT5336_P6_XH_REG ((uint8_t)0x21)

#define FT5336_P6_XL_REG ((uint8_t)0x22)

#define FT5336_P6_YH_REG ((uint8_t)0x23)

#define FT5336_P6_YL_REG ((uint8_t)0x24)

#define FT5336_P7_XH_REG ((uint8_t)0x27)

#define FT5336_P7_XL_REG ((uint8_t)0x28)

#define FT5336_P7_YH_REG ((uint8_t)0x29)

#define FT5336_P7_YL_REG ((uint8_t)0x2A)

#define FT5336_P8_XH_REG ((uint8_t)0x2D)

#define FT5336_P8_XL_REG ((uint8_t)0x2E)

#define FT5336_P8_YH_REG ((uint8_t)0x2F)

#define FT5336_P8_YL_REG ((uint8_t)0x30)

#define FT5336_P9_XH_REG ((uint8_t)0x33)

#define FT5336_P9_XL_REG ((uint8_t)0x34)

#define FT5336_P9_YH_REG ((uint8_t)0x35)

#define FT5336_P9_YL_REG ((uint8_t)0x36)

#define FT5336_P10_XH_REG ((uint8_t)0x39)

#define FT5336_P10_XL_REG ((uint8_t)0x3A)

#define FT5336_P10_YH_REG ((uint8_t)0x3B)

#define FT5336_P10_YL_REG ((uint8_t)0x3C)

//------------------------------------------

#define FT5336_P1_WEIGHT_REG ((uint8_t)0x07)

#define FT5336_P1_MISC_REG ((uint8_t)0x08)

#define FT5336_P2_WEIGHT_REG ((uint8_t)0x0D)

#define FT5336_P2_MISC_REG ((uint8_t)0x0E)

#define FT5336_P3_WEIGHT_REG ((uint8_t)0x13)

#define FT5336_P3_MISC_REG ((uint8_t)0x14)

#define FT5336_P4_WEIGHT_REG ((uint8_t)0x19)

#define FT5336_P4_MISC_REG ((uint8_t)0x1A)

#define FT5336_P5_WEIGHT_REG ((uint8_t)0x1F)

#define FT5336_P5_MISC_REG ((uint8_t)0x20)

#define FT5336_P6_WEIGHT_REG ((uint8_t)0x25)

#define FT5336_P6_MISC_REG ((uint8_t)0x26)

#define FT5336_P7_WEIGHT_REG ((uint8_t)0x2B)

#define FT5336_P7_MISC_REG ((uint8_t)0x2C)

#define FT5336_P8_WEIGHT_REG ((uint8_t)0x31)

#define FT5336_P8_MISC_REG ((uint8_t)0x32)

#define FT5336_P9_WEIGHT_REG ((uint8_t)0x37)

#define FT5336_P9_MISC_REG ((uint8_t)0x38)

#define FT5336_P10_WEIGHT_REG ((uint8_t)0x3D)

#define FT5336_P10_MISC_REG ((uint8_t)0x3E)

//------------------------------------------

#define FT5336_TOUCH_EVT_FLAG_PRESS_DOWN ((uint8_t)0x00)

#define FT5336_TOUCH_EVT_FLAG_LIFT_UP ((uint8_t)0x01)

#define FT5336_TOUCH_EVT_FLAG_CONTACT ((uint8_t)0x02)

#define FT5336_TOUCH_EVT_FLAG_NO_EVENT ((uint8_t)0x03)

//------------------------------------------

#define FT5336_TOUCH_EVT_FLAG_SHIFT ((uint8_t)0x06)

#define FT5336_TOUCH_EVT_FLAG_MASK ((uint8_t)(3 << FT5336_TOUCH_EVT_FLAG_SHIFT))

#define FT5336_TOUCH_WEIGHT_MASK ((uint8_t)0xFF)

#define FT5336_TOUCH_WEIGHT_SHIFT ((uint8_t)0x00)

#define FT5336_TOUCH_AREA_MASK ((uint8_t)(0x04 << 4))

#define FT5336_TOUCH_AREA_SHIFT ((uint8_t)0x04)

//------------------------------------------

#define TS_MAX_NB_TOUCH ((uint32_t) FT5336_MAX_DETECTABLE_TOUCH)


#endif /* INC_FT5336_H_ */
