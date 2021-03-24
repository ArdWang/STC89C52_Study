#include "reg52.h"

// 重定义
typedef unsigned char u8;
typedef unsigned int u16;

sbit led = P2^0;  // D1 指示灯
sbit k1 = P3^1; //按键接在 P31的口子


 void delay(u16 i){
 	  while(i--);
 }


 void keypros(){
 	 if(k1==0){
	 	// 对基础的同学消抖处理
	 	delay(1000); //10ms
		if(k1==0){
	 		led = ~led;	 //取反
		}
		// 按键松开
		while(!k1);
	 }
 }

void main(){
    while(1){
		keypros();			
	}
}

