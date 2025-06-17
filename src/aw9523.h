/**
 ******************************************************************************
 * @file           : aw9523.h
 * @brief          : AW9523 Driver header
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

#ifndef AW9523_H_
#define AW9523_H_

#include "main.h"

#ifdef xxxDEBUG
#define AW9523_DBG(...)    printf(__VA_ARGS__)
#else
#define AW9523_DBG(...)
#endif

// Default address when both a0 and a1 are pulled high
#define AW9523_DEFAULT_ADDR 0x5b

// All the aw9523 i2c registers
#define AW9523_IP0		0x00
#define AW9523_IP1      0x01
#define AW9523_OP0		0x02
#define AW9523_OP1      0x03
#define AW9523_CP0      0x04
#define AW9523_CP1      0x05
#define AW9523_INT_P0   0x06
#define AW9523_INT_P1   0x07
#define AW9523_ID       0x10
#define AW9523_CTL      0x11
#define AW9523_LP0      0x12
#define AW9523_LP1      0x13
#define AW9523_DIM0     0x20
#define AW9523_DIM1     0x21
#define AW9523_DIM2     0x22
#define AW9523_DIM3     0x23
#define AW9523_DIM4     0x24
#define AW9523_DIM5     0x25
#define AW9523_DIM6     0x26
#define AW9523_DIM7     0x27
#define AW9523_DIM8     0x28
#define AW9523_DIM9     0x29
#define AW9523_DIM10    0x2a
#define AW9523_DIM11    0x2b
#define AW9523_DIM12    0x2c
#define AW9523_DIM13    0x2d
#define AW9523_DIM14    0x2e
#define AW9523_DIM15    0x2f
#define AW9523_RST      0x7f

typedef struct {
    I2C_HandleTypeDef *i2c;
    uint8_t i2c_address;
    GPIO_TypeDef *rst_port;
    uint16_t rst_pin;
} AW9523_HandleTypeDef;

typedef enum {
    AW9523_Ok,
    AW9523_Err
} AW9423_StatusTypeDef;

AW9423_StatusTypeDef aw9523_init(AW9523_HandleTypeDef *aw9523_handle, I2C_HandleTypeDef *i2c, uint8_t i2c_address, GPIO_TypeDef *rst_port, uint16_t rst_pin);
AW9423_StatusTypeDef aw9523_write_register(AW9523_HandleTypeDef *aw9523_handle, uint8_t register_pointer, uint8_t register_value);
AW9423_StatusTypeDef aw9523_read_register(AW9523_HandleTypeDef *aw9523_handle, uint8_t register_pointer, uint8_t *register_value);

#endif /* AW9523_H_ */
