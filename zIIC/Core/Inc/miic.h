#ifndef __MIIC_H
#define __MIIC_H

#include "main.h"
#include "tim.h"
#include "usart.h"
#include "gpio.h"

#define SCL_SET() HAL_GPIO_WritePin(SCL_GPIO_Port, SCL_Pin, GPIO_PIN_SET)     /*scl设置为高*/
#define SCL_RESET() HAL_GPIO_WritePin(SCL_GPIO_Port, SCL_Pin, GPIO_PIN_RESET) /*scl设置为低*/
#define SDA_SET() HAL_GPIO_WritePin(SDA_GPIO_Port, SDA_Pin, GPIO_PIN_SET)     /*sda设置为高*/
#define SDA_RESET() HAL_GPIO_WritePin(SDA_GPIO_Port, SDA_Pin, GPIO_PIN_RESET) /*sda设置为低*/

void iic_start(void);
void iic_stop(void);
unsigned char iic_wait_ack(void);
void iic_ack(void);
void iic_nack(void);
void iic_write_byte(unsigned char data);

#endif
