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
// 3 ������ͬʱ����
	IT0=1;
	EX0=1;
	EA=1; //CPU���ж�	
}

void Int1Init(){
	IT1=1;
	EX1=1;
	EA=1; //CPU���ж�	
}

// �жϺ�	  �ⲿ�ж�0������0��
void Int0() interrupt 0{
	delay(1000); //��ʱ10ms
	if(k3==0){
		led=~led;
	}
}

// �ⲿ�ж�1 ������2��
void Int1() interrupt 2{
	delay(1000); //��ʱ10ms
	if(k4==0){
		led=~led;
	}
}


void main(){
	Int0Init();
	Int1Init();
	while(1);
}