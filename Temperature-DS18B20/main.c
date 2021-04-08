#include "reg52.h"
#include "temp.h"

// 重定义
typedef unsigned char u8;
typedef unsigned int u16;


sbit LSA=P2^2;
sbit LSB=P2^3;
sbit LSC=P2^4;


u8 code smgduan[10]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07
,0x7f,0x6f};   //0-9的值

u8 num=0, DisplayData[8];

void delay(u16 i){
	while(i--);
}


void Datapros(int temp){
	float tp;
   	if(temp<0){	//-号显示
		DisplayData[0]=0x40; //数码管 - 号
		temp=temp-1;
		temp=~temp;
		tp=temp;
		temp=tp*0.0625*100+0.5;	
	}
	else{
		DisplayData[0]=0x00; // 不显示符号位
		tp = temp;
		temp=tp*0.0625*100+0.5;
	}

	DisplayData[1]=smgduan[temp/10000];	//1200 2
	DisplayData[2]=smgduan[temp%10000/1000];
	DisplayData[3]=smgduan[temp%1000/100]|0x80; //小数点
	DisplayData[4]=smgduan[temp%100/10]; //		后面2位
	DisplayData[5]=smgduan[temp%10]; //	
}

void DigDisplay(){
	u8 i;
	for(i=0; i<6;i++){
		switch(i){
			case 0:	//0 最后一位显示
			  LSA=0;
			  LSB=0;
			  LSC=0;
			break;

			case 1:
			  LSA=1;
			  LSB=0;
			  LSC=0;
			break;

			case 2:
			  LSA=0;
			  LSB=1;
			  LSC=0;
			break;

			case 3:
			  LSA=1;
			  LSB=1;
			  LSC=0;
			break;

			case 4:
			  LSA=0;
			  LSB=0;
			  LSC=1;
			break;

			case 5:
			  LSA=1;
			  LSB=0;
			  LSC=1;
			break;
		}

		P0=DisplayData[5-i]; //发送断码
		delay(100); //1ms
		//消隐 不然显示错误
		P0=0x00;
	}
} 

void main(){
	
    while(1){
	
		Datapros(Ds18b20ReadTemp());
		DigDisplay();
	}
}



