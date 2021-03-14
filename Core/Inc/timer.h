#ifndef __TIMER_H
#define __TIMER_H
//--------------------------------------------------
#include "stm32f1xx_hal.h"
#include <string.h>
#include <stdlib.h>
#include <stdint.h>

#include "i2c-lcd.h"
//--------------------------------------------------
//Define Button pins
#define RB_GPIO_PORT GPIOC
#define RB_PIN GPIO_PIN_14
#define GB_GPIO_PORT GPIOC
#define GB_PIN GPIO_PIN_15
#define BB_GPIO_PORT GPIOA
#define BB_PIN GPIO_PIN_12
#define WB_GPIO_PORT GPIOA
#define WB_PIN GPIO_PIN_11
//Define RST pins
#define RSTR_GPIO_PORT GPIOB
#define RSTR_PIN GPIO_PIN_15
#define LISTENR() HAL_GPIO_ReadPin(RSTR_GPIO_PORT, RSTR_PIN)
#define RSTG_GPIO_PORT GPIOB
#define RSTG_PIN GPIO_PIN_14
#define LISTENG() HAL_GPIO_ReadPin(RSTG_GPIO_PORT, RSTG_PIN)
#define RSTB_GPIO_PORT GPIOB
#define RSTB_PIN GPIO_PIN_13
#define LISTENB() HAL_GPIO_ReadPin(RSTB_GPIO_PORT, RSTB_PIN)
#define RSTW_GPIO_PORT GPIOB
#define RSTW_PIN GPIO_PIN_12
#define LISTENW() HAL_GPIO_ReadPin(RSTW_GPIO_PORT, RSTW_PIN)
//Define LED strip pins
#define LEDR_GPIO_PORT GPIOA
#define LEDR_PIN GPIO_PIN_3
#define LEDR_ON() HAL_GPIO_WritePin(LEDR_GPIO_PORT, LEDR_PIN, GPIO_PIN_SET)
#define LEDR_OFF() HAL_GPIO_WritePin(LEDR_GPIO_PORT, LEDR_PIN, GPIO_PIN_RESET)
#define LEDG_GPIO_PORT GPIOA
#define LEDG_PIN GPIO_PIN_4
#define LEDG_ON() HAL_GPIO_WritePin(LEDG_GPIO_PORT, LEDG_PIN, GPIO_PIN_SET)
#define LEDG_OFF() HAL_GPIO_WritePin(LEDG_GPIO_PORT, LEDG_PIN, GPIO_PIN_RESET)
#define LEDB_GPIO_PORT GPIOA
#define LEDB_PIN GPIO_PIN_5
#define LEDB_ON() HAL_GPIO_WritePin(LEDB_GPIO_PORT, LEDB_PIN, GPIO_PIN_SET)
#define LEDB_OFF() HAL_GPIO_WritePin(LEDB_GPIO_PORT, LEDB_PIN, GPIO_PIN_RESET)
//Define button light pin
#define LIGHT_GPIO_PORT GPIOC
#define LIGHT_PIN GPIO_PIN_13
#define LIGHT() HAL_GPIO_TogglePin(LIGHT_GPIO_PORT, LIGHT_PIN)
//--------------------------------------------------
void timer_ini(void);
void rst_red(void);
void rst_green(void);
void rst_blue(void);
void rst_white(void);
void timer_rst(void);
void red_team(void);
void green_team(void);
void blue_team(void);
void white_team(void);
//--------------------------------------------------
#endif /* __TIMER_H */
