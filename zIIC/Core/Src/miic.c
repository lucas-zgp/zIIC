#include "miic.h"
#include "main.h"

void delay_us(unsigned int us_cnt)
{

    for (unsigned n = 0; n < us_cnt; n++)
        for (unsigned i = 0; i < 38; i++)
            ;
}

/*scl为高电平期间，sda由高电平变为低电平*/
void iic_start()
{
    SCL_SET();
    SDA_SET();
    delay_us(1);
    SDA_RESET();
    delay_us(1);
    SCL_RESET(); /*scl拉低，钳住总线*/
    delay_us(1);
}

/*scl为高电平期间，sda由低电平变为高电平*/
void iic_stop()
{
    SCL_RESET();
    SDA_RESET();
    delay_us(1);
    SCL_SET();
    delay_us(1);
    SDA_SET();
    delay_us(1);
}

/*等待应答信号，释放SCL及SDA线，检测SDA线电平 1:未等到应答 0:等到应答*/
unsigned char iic_wait_ack()
{
    unsigned char cnt = 0;
    SDA_SET();
    delay_us(1);
    SCL_SET();
    delay_us(1);

    while (HAL_GPIO_ReadPin(SDA_GPIO_Port, SDA_Pin))
    {
        if (++cnt >= 200)
        {
            iic_stop();
            return 0;
        }
        cnt = 0; /*后面取消掉*/
    }

    SCL_RESET();
    delay_us(1);
    return 1;
}

/*产生应答信号 第九个脉冲的低电平期间，将数据线拉低，并在时钟线高电平期间保持*/
void iic_ack()
{
    SCL_RESET();
    SDA_RESET();
    delay_us(1);
    SCL_SET();
    delay_us(1);
    SCL_RESET();
}

/*产生不应答信号 第九个脉冲的低电平期间，将数据线拉高，并在时钟线高电平期间保持*/
void iic_nack()
{
    SCL_RESET();
    SDA_SET();
    delay_us(1);
    SCL_SET();
    delay_us(1);
    SCL_RESET();
}

/*写一个字节 低电平期间将数据准备好，高电平发送*/
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
        delay_us(2);
        SCL_SET();
        delay_us(2);
        SCL_RESET();
        delay_us(2);
    }
}

/*读一个字节 在时钟线高电平期间读取1bit数据线信号*/
unsigned char iic_read_byte(unsigned char ack_flag)
{
    unsigned char read_data = 0;

    for (size_t i = 0; i < 8; i++)
    {
        SCL_RESET();
        delay_us(1);
        SCL_SET();
        read_data <<= 1;
        read_data += HAL_GPIO_ReadPin(SDA_GPIO_Port, SDA_Pin);
        delay_us(1);
    }

    if (ack_flag == 1)
    {
        iic_ack();
    }
    else
    {
        iic_nack();
    }

    return read_data;
}

void at24c02_write_one_byte(unsigned short int addr, unsigned char data)
{
    /*写入数据*/
    iic_start();
    iic_write_byte(0xa0);
    iic_wait_ack();
    iic_write_byte(addr);
    iic_wait_ack();

    iic_write_byte(data);
    iic_wait_ack();
    iic_stop();
    HAL_Delay(10);
}

void at24c02_write_multi_byte(unsigned short int addr, unsigned char *buf, unsigned short int num)
{
    while (num--)
    {
        at24c02_write_one_byte(addr, *buf);
        addr++;
        buf++;
    }
}

unsigned char at24c02_read_one_byte(unsigned short int addr)
{
    /*读一个数据*/
    unsigned char temp = 0;
    iic_start();
    iic_write_byte(0xa0);
    iic_wait_ack();
    iic_write_byte(addr);
    iic_wait_ack();

    iic_start();
    iic_write_byte(0xa1);
    iic_wait_ack();

    temp = iic_read_byte(0);
    iic_stop();

    return temp;
}

void at24c02_read_multi_byte(unsigned short int addr, unsigned char *buf, unsigned short int num)
{
    while (num--)
    {
        *buf = at24c02_read_one_byte(addr);
        addr++;
        buf++;
    }
}
