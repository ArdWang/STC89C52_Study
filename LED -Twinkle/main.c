#include "reg52.h"

// �ض���
typedef unsigned char u8;
typedef unsigned int u16;

sbit led = P2^0;  // D1 ָʾ��


 void delay(u16 i){
 	  while(i--);
 }

void main(){
    while(1){
		led = 0;
		delay(50000);	 // 450ms ���� ��Ҫ���� 12.0HZ ����
		led = 1;
		delay(50000);			
	}
}