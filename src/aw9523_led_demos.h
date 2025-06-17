/**
 ******************************************************************************
 * @file           : aw9523_led_demos.h
 * @brief          : AW9523 LED Demos header
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2025 Lars Boegild Thomsen <lbthomsen@gmail.com>
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */

#ifndef AW9523_LED_DEMOS_H_
#define AW9523_LED_DEMOS_H_

#include "aw9523.h"

extern const uint8_t led_mapping[5][3];

void aw9523_led_demo_tick(AW9523_HandleTypeDef *aw9523_handle);

#endif /* AW9523_LED_DEMOS_H_ */
