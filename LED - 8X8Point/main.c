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
* �� �� ��         : delay
* ��������		   : ��ʱ������i=1ʱ����Լ��ʱ10us
*******************************************************************************/
void delay(u16 i)
{
	while(i--);	
}

/*******************************************************************************
* ������         : Hc595SendByte(u8 dat)
* ��������		   : ��74HC595����һ���ֽڵ�����
* ����           : ��
* ���         	 : ��
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
* �� �� ��       : main
* ��������		 : ������
* ��    ��       : ��
* ��    ��    	 : ��
*******************************************************************************/
void main()
{			
	u8 i;
	while(1)
	{
		P0=0x7f;
		for(i=0;i<8;i++)
		{
			P0=ledwei[i];		  //λѡ
			Hc595SendByte(ledduan[i]);	//���Ͷ�ѡ����
			delay(100);		   //��ʱ
			Hc595SendByte(0x00);  //����
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
	 _nop_(); //Ϊ�˱������ ��ʱ
	 _nop_();
	 SRCLK=0;
  }
  
  RCLK=1;
  _nop_(); //Ϊ�˱������ ��ʱ
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