/**
 ******************************************************************************
 * @file           : aw9523.c
 * @brief          : AW9523 Driver source
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2024-2025 Lars Boegild Thomsen <lbthomsen@gmail.com>
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */

#include "aw9523.h"

AW9423_StatusTypeDef aw9523_write(AW9523_HandleTypeDef *aw9523_handle, uint8_t addr, uint8_t *data, uint16_t length) {
    AW9523_DBG("aw9523_write %d bytes\n", length);

    if (HAL_I2C_Mem_Write(aw9523_handle->i2c, (aw9523_handle->i2c_address << 1), addr, 1, data, length, HAL_MAX_DELAY) != HAL_OK) {
    	return AW9523_Err;
    }

    return AW9523_Ok;
}

AW9423_StatusTypeDef aw9523_read(AW9523_HandleTypeDef *aw9523_handle, uint8_t addr, uint8_t *data, uint16_t length) {
    AW9523_DBG("aw9523_read %d bytes\n", length);

    if (HAL_I2C_Mem_Read(aw9523_handle->i2c, (aw9523_handle->i2c_address << 1), addr, 1, data, length, HAL_MAX_DELAY) != HAL_OK) {
    	return AW9523_Err;
    }

    return AW9523_Ok;
}

AW9423_StatusTypeDef aw9523_write_register(AW9523_HandleTypeDef *aw9523_handle, uint8_t register_pointer, uint8_t register_value) {
    AW9523_DBG("aw9523_write_register %d = %d\n", register_pointer, register_value);

    if (aw9523_write(aw9523_handle, register_pointer, &register_value, 1) != AW9523_Ok) {
        return AW9523_Err;
    }

    return AW9523_Ok;
}

AW9423_StatusTypeDef aw9523_read_register(AW9523_HandleTypeDef *aw9523_handle, uint8_t register_pointer, uint8_t *register_value) {
    AW9523_DBG("aw9523_read_register %d = %d\n", register_pointer, *register_value);

    if (aw9523_read(aw9523_handle, register_pointer, register_value, 1) != AW9523_Ok) {
        return AW9523_Err;
    }

    return AW9523_Ok;
}

//AW9423_StatusTypeDef aw9523_write_register(AW9523_HandleTypeDef *aw9523_handle, uint8_t register_pointer, uint8_t register_value) {
//
//    uint8_t data[2];
//    data[0] = register_pointer;
//    data[1] = register_value;
//
//    if (HAL_I2C_Master_Transmit(aw9523_handle->i2c, (aw9523_handle->i2c_address << 1), data, 2, HAL_MAX_DELAY) != HAL_OK) {
//        return AW9523_Err;
//    }
//
//    return AW9523_Ok;
//}

AW9423_StatusTypeDef aw9523_init(AW9523_HandleTypeDef *aw9523_handle, I2C_HandleTypeDef *i2c, uint8_t i2c_address, GPIO_TypeDef *rst_port, uint16_t rst_pin) {

    AW9523_DBG("Initializing aw9523\n");

    aw9523_handle->i2c = i2c;
    aw9523_handle->i2c_address = i2c_address;
    aw9523_handle->rst_port = rst_port;
    aw9523_handle->rst_pin = rst_pin;

    // Reset device
    HAL_GPIO_WritePin(rst_port, rst_pin, GPIO_PIN_RESET);
    HAL_Delay(1);
    HAL_GPIO_WritePin(rst_port, rst_pin, GPIO_PIN_SET);
    HAL_Delay(10);

    uint8_t device_id = 0;

    if (aw9523_read_register(aw9523_handle, 0x10, &device_id) != AW9523_Ok) {
        return AW9523_Err;
    }

    AW9523_DBG("Device ID = 0x%02x\n", device_id);

    if (device_id != 0x23) {
        AW9523_DBG("Unsupported device\n");
        return AW9523_Err;
    }

    return AW9523_Ok;

}
