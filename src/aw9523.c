/**
 ******************************************************************************
 * @file           : aw9523.c
 * @brief          : AW9523 Driver
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2024 Lars Boegild Thomsen <lbthomsen@gmail.com>
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */

#include "aw9523.h"

AW9423_StatusTypeDef aw9523_init(AW9523_HandleTypeDef *aw9523_handle, I2C_HandleTypeDef *i2c, uint8_t i2c_address) {

    DBG("Initializing aw9523\n");

    aw9523_handle->i2c = i2c;
    aw9523_handle->i2c_address = i2c_address;

    return AW9523_Ok;

}
