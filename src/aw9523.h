/**
 ******************************************************************************
 * @file           : aw9523.h
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

#ifndef AW9523_H_
#define AW9523_H_

#include "main.h"

typedef struct {
    I2C_HandleTypeDef *i2c;
    uint8_t i2c_address;
} AW9523_HandleTypeDef;

typedef enum {
    AW9523_Ok,
    AW9523_Err
} AW9423_StatusTypeDef;

AW9423_StatusTypeDef aw9523_init(AW9523_HandleTypeDef *aw9523_handle, I2C_HandleTypeDef *i2c, uint8_t i2c_address);

#endif /* AW9523_H_ */
