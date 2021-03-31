#include "reg52.h"

// 重定义
typedef unsigned char u8;
typedef unsigned int u16;

sbit led = P2^0;  // D1 指示灯

void Timer0Init(){		 // Timer1Init
	TMOD|=0x01;	 // TMOD|0x01;	 TMOD|=0x10;   |是改变干扰
	TH0 = 0xFC;		  // TL1 ET1 TH1
	TL0 = 0x18;
	ET0=1;
	EA=1;
	TR0=1;

}


void main(){
	Timer0Init();	// Timer1Init
    while(1);
}

void Timer0() interrupt 1{	// Timer1 3
	static u16 i;
	TH0 = 0xFC;		// TH1 TL1
	TL0 = 0x18;
	i++;
	if(i==1000){    //累加1000次 1s
		i=0;
		led=~led;	
	}
}