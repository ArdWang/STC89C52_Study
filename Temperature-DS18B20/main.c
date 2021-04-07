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

u8 num=0, disp[4];

void delay(u16 i){
	while(i--);
}


void Datapros(){
	disp[0]=smgduan[num/1000];	//1200 2
	disp[1]=smgduan[num%1000/100];
	disp[2]=smgduan[num%1000%100/10]; //10位
	disp[3]=smgduan[num%1000%100%10]; //个位	
}

void DigDisplay(){
	u8 i;
	for(i=0; i<4;i++){
		switch(i){
			case 0:	//0
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
		}

		P0=disp[3-i]; //发送断码
		delay(100); //1ms
		//消隐 不然显示错误
		P0=0x00;
	}
} 

void main(){
	
    while(1){
	
		Datapros();
		DigDisplay();
	}
}



