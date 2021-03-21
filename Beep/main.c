#include "reg52.h"

typedef unsigned char u8;
typedef unsigned int u16;

sbit beep=P1^5;

//延时函数
void delay(u16 i){
	while(i--);	
}


void main(){
	while(1){
		// 电平取反
		beep=~beep;
		delay(5000); //100us
	}
}