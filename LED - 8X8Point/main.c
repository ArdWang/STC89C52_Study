#include "reg51.h"
#include "intrins.h"

typedef unsigned char u8;
typedef unsigned int u16;

sbit SRCLK=P3^6;
sbit RCLK=P3^5;
sbit SER=P3^4;


u8 ledduan[]={0x00,0x00,0x3e,0x41,0x41,0x41,0x3e,0x00};
u8 ledwei[]={0x7f,0xbf,0xdf,0xef,0xf7,0xfb,0xfd,0xfe};
/*******************************************************************************
* 函 数 名         : delay
* 函数功能		   : 延时函数，i=1时，大约延时10us
*******************************************************************************/
void delay(u16 i)
{
	while(i--);	
}

/*******************************************************************************
* 函数名         : Hc595SendByte(u8 dat)
* 函数功能		   : 向74HC595发送一个字节的数据
* 输入           : 无
* 输出         	 : 无
*******************************************************************************/
void Hc595SendByte(u8 dat)
{
	u8 a;
	SRCLK=0;
	RCLK=0;
	for(a=0;a<8;a++)
	{
		SER=dat>>7;
		dat<<=1;

		SRCLK=1;
		_nop_();
		_nop_();
		SRCLK=0;	
	}

	RCLK=1;
	_nop_();
	_nop_();
	RCLK=0;
}

/*******************************************************************************
* 函 数 名       : main
* 函数功能		 : 主函数
* 输    入       : 无
* 输    出    	 : 无
*******************************************************************************/
void main()
{			
	u8 i;
	while(1)
	{
		P0=0x7f;
		for(i=0;i<8;i++)
		{
			P0=ledwei[i];		  //位选
			Hc595SendByte(ledduan[i]);	//发送段选数据
			delay(100);		   //延时
			Hc595SendByte(0x00);  //消隐
		}	
	}		
}

/*
u8 ledduan[]={0x00,0x00,0x3e,0x41,0x41,0x41,0x3e,0x00};
u8 ledwei[]={0x7f,0xbf,0xdf,0xef,0xf7,0xfb,0xfd,0xfe};


void delay(u16 i){
	while(i--);
}


void Hc595SendByte(u8 dat){
  u8 a;
  SRCLK=0;
  RCLK=0;
  for(a=0;a<8;a++){
	 SER=dat>>7;
	 dat<<=1; // 1001 1001 >>7=1  1001 1001 <<1 = 0011 0010
	 SRCLK=1;
	 _nop_(); //为了保险起见 延时
	 _nop_();
	 SRCLK=0;
  }
  
  RCLK=1;
  _nop_(); //为了保险起见 延时
  _nop_();
  RCLK=0;
  	
}


void main(){
    u8 i;
	while(1){
		P0=0x7f;
		for(i=0;i<8;i++){
			P0=ledwei[i];
			Hc595SendByte(ledduan[i]);
			delay(100);
			Hc595SendByte(0x00);
		}
	}
}  */