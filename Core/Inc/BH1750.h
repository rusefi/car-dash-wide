/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __BH1750_H
#define __BH1750_H

#ifdef __cplusplus
extern "C" {
#endif

//Device Address
//Please note that arduino uses 7 bit addresses, STM32 uses 8
#define BH1750_NO_GROUND_ADDR_WRITE     (0xB9 + 0)
#define BH1750_NO_GROUND_ADDR_READ      (0xB9 + 1)
#define BH1750_GROUND_ADDR_WRITE        (0x46 + 0)
#define BH1750_GROUND_ADDR_READ     (0x46 + 1)

//instructions
//datasheet ref http://cpre.kmutnb.ac.th/esl/learning/bh1750-light-sensor/bh1750fvi-e_datasheet.pdf
#define CMD_POWER_DOWN          0x00
#define CMD_POWER_ON            0x01
#define CMD_RESET               0x03
#define CMD_H_RES_MODE          0x10
#define CMD_H_RES_MODE2         0x11
#define CMD_L_RES_MODE          0x13
#define CMD_ONE_H_RES_MODE      0x20
#define CMD_ONE_H_RES_MODE2     0x21
#define CMD_ONE_L_RES_MODE      0x23
#define CMD_CNG_TIME_HIGH       0x30    // 3 LSB set time
#define CMD_CNG_TIME_LOW        0x60    // 5 LSB set time

typedef struct BH1750_device BH1750_device_t;

struct BH1750_device{
    char* name;

    I2C_HandleTypeDef* i2c_handle;
    uint8_t address_r;
    uint8_t address_w;

    uint16_t value;

    uint8_t buffer[2];

    uint8_t mode;

    void (* poll)(BH1750_device_t*);
};

HAL_StatusTypeDef BH1750_read_dev(BH1750_device_t* dev);
HAL_StatusTypeDef BH1750_init_i2c(I2C_HandleTypeDef* i2c_handle);
BH1750_device_t* BH1750_init_dev_struct(I2C_HandleTypeDef* i2c_handle, char* name, int addr_grounded);
HAL_StatusTypeDef BH1750_init_dev(BH1750_device_t* dev);
HAL_StatusTypeDef BH1750_get_lumen(BH1750_device_t* dev);

#endif // __BH1750_H
