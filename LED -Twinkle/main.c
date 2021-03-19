#include "reg52.h"

// 重定义
typedef unsigned char u8;
typedef unsigned int u16;

sbit led = P2^0;  // D1 指示灯


 void delay(u16 i){
 	  while(i--);
 }

void main(){
    while(1){
		led = 0;
		delay(50000);	 // 450ms 左右 需要设置 12.0HZ 晶振
		led = 1;
		delay(50000);			
	}
}