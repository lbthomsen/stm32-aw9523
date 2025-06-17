/**
 ******************************************************************************
 * @file           : aw9523.c
 * @brief          : AW9523 LED Demos source
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

#include "aw9523.h"
#include "aw9523_led_demos.h"

const uint8_t led_values[][5][3] = {
        {
                { 0, 0, 0 },
                { 0, 0, 0 },
                { 0, 0, 0 },
                { 0, 0, 0 },
                { 0, 0, 0 }
        }, {
                { 10, 0, 0 },
                { 0, 10, 0 },
                { 0, 0, 10 },
                { 10, 0, 10 },
                { 10, 10, 10 }
        }, {
                { 0, 10, 0 },
                { 0, 0, 10 },
                { 10, 0, 10 },
                { 10, 10, 10 },
                { 10, 0, 0 }
        }, {
                { 0, 0, 10 },
                { 10, 0, 10 },
                { 10, 10, 10 },
                { 10, 0, 0 },
                { 0, 10, 0 }
        }, {
                { 10, 0, 10 },
                { 10, 10, 10 },
                { 10, 0, 0 },
                { 0, 10, 0 },
                { 0, 0, 10 }
        }, {
                { 10, 10, 10 },
                { 10, 0, 0 },
                { 0, 10, 0 },
                { 0, 0, 10 },
                { 10, 0, 10 }
        }, {
                { 1, 0, 1 },
                { 10, 0, 10 },
                { 20, 0, 20 },
                { 40, 0, 40 },
                { 100, 0, 100 }
        }, {
                { 1, 0, 1 },
                { 1, 0, 1 },
                { 1, 0, 1 },
                { 1, 0, 1 },
                { 1, 0, 1 }
        }, {
                { 10, 0, 10 },
                { 10, 0, 10 },
                { 10, 0, 10 },
                { 10, 0, 10 },
                { 10, 0, 10 }
        }, {
                { 20, 0, 20 },
                { 20, 0, 20 },
                { 20, 0, 20 },
                { 20, 0, 20 },
                { 20, 0, 20 }
        }, {
                { 40, 0, 40 },
                { 40, 0, 40 },
                { 40, 0, 40 },
                { 40, 0, 40 },
                { 40, 0, 40 }
        }
};

static uint8_t led_idx = 0;

static uint8_t demo = 0;

static uint32_t tick_cnt = 0;

void aw9523_led_demo_tick(AW9523_HandleTypeDef *aw9523_handle) {

    switch (demo) {

    case 0:

        if (tick_cnt % 20 == 0) {

            for (int a = 0; a < 5; ++a) {
                for (int b = 0; b < 3; ++b) {
                    aw9523_write_register(aw9523_handle, led_mapping[a][b], led_values[led_idx][a][b]);
                }
            }

            ++led_idx;
            if (led_idx >= sizeof(led_values) / sizeof(led_values[0]))
                led_idx = 0;

        }

        break;

    default:

        printf("Unknown demo\n");

    }

    ++tick_cnt;

}
