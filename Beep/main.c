#include "reg52.h"

typedef unsigned char u8;
typedef unsigned int u16;

sbit beep=P1^5;

//��ʱ����
void delay(u16 i){
	while(i--);	
}


void main(){
	while(1){
		// ��ƽȡ��
		beep=~beep;
		delay(5000); //100us
	}
}