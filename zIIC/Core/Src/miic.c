#include "miic.h"

/*scl为高电平期间，sda由高电平变为低电平*/
void iic_start()
{
    SCL_SET();
    SDA_SET();
    delay_us(2);
    SDA_RESET();
    delay_us(2);
    SCL_RESET(); /*scl拉低，钳住总线*/
    delay_us(4);
}

/*scl为高电平期间，sda由低电平变为高电平*/
void iic_stop()
{
    SCL_RESET();
    SDA_RESET();
    delay_us(2);
    SCL_SET();
    delay_us(2);
    SDA_SET();
    delay_us(2);
}

/*等待应答信号*/
unsigned char iic_wait_ack()
{
    unsigned char cnt = 0;
		SDA_SET();
	  delay_us(2);
    SCL_SET();
    delay_us(2);
		
//  	__HAL_RCC_GPIOB_CLK_ENABLE();
//	  GPIO_InitTypeDef GPIO_InitStruct = {0};
//		GPIO_InitStruct.Pin = SDA_Pin;
//		GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
//		GPIO_InitStruct.Pull = GPIO_NOPULL;
//		GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
//		HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);
	
    while (HAL_GPIO_ReadPin(SDA_GPIO_Port, SDA_Pin))
    {
        if (++cnt >= 200)
        {
//            iic_stop();
            return 0;
        }
    }

    SCL_RESET();
    return 1;
}

/*产生应答信号*/
void iic_ack()
{
    SCL_RESET();
    SDA_RESET();
    delay_us(2);
    SCL_SET();
    delay_us(2);
    SCL_RESET();
}

/*产生不应答信号*/
void iic_nack()
{
    SCL_RESET();
    SDA_SET();
    delay_us(2);
    SCL_SET();
    delay_us(2);
    SCL_RESET();
}

void iic_write_byte(unsigned char data)
{
    SCL_RESET();
    delay_us(1);
    for (size_t i = 0; i < 8; i++)
    {
        if (((data & 0x80) >> 7) == 1)
        {
            SDA_SET();
        }
        else
        {
            SDA_RESET();
        }
        data <<= 1;
        delay_us(1);
        SCL_SET();
        delay_us(1);
        SCL_RESET();
        delay_us(1);
    }
}








































