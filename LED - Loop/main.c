#include "reg52.h"
#include <intrins.h>

typedef unsigned char u8;
typedef unsigned int u16;

#define led P2

//延时函数
void delay(u16 i){
	while(i--);	
}


void main(){
	u8 i = 0;
	
	led = 0xfe; // 1111 1110
	delay(50000);
	// 大的循环体里面 无线循环
    while(1){
		//u8 j = 0;
		for(i=0;i<7;i++){
			if(i%2!=0){
				led=_crol_(led,1);  //0xfe 1111 1110 -> 1111 1101
				delay(50000);
			}else{
				led=_cror_(led,1);  //0xfe 1111 1110 -> 1111 1101
				delay(50000);	
			}
		}

		/*for(i=0;i<7;i++){
			if(i%2 == 0){
				led=_cror_(led,2);  //0xfe 0111 1111 -> 1011 1111
				delay(50000);
			}
		}*/						
	}
}