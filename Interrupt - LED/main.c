#include "reg52.h"

typedef unsigned char u8;
typedef unsigned int u16;

sbit led=P2^0;
sbit k3=P3^2;
sbit k4=P3^3;

void delay(u16 i){
	while(i--);
}

void Int0Init(){
// 3 个条件同时满足
	IT0=1;
	EX0=1;
	EA=1; //CPU总中断	
}

void Int1Init(){
	IT1=1;
	EX1=1;
	EA=1; //CPU总中断	
}

// 中断号	  外部中断0连接在0口
void Int0() interrupt 0{
	delay(1000); //延时10ms
	if(k3==0){
		led=~led;
	}
}

// 外部中断1 连接在2口
void Int1() interrupt 2{
	delay(1000); //延时10ms
	if(k4==0){
		led=~led;
	}
}


void main(){
	Int0Init();
	Int1Init();
	while(1);
}