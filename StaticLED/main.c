#include "reg52.h"

typedef unsigned char u8;
typedef unsigned int u16;

sbit LSA=P2^2;
sbit LSB=P2^3;
sbit LSC=P2^4;
//code
u8 smgduan[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07
,0x7f,0x6f,0x77,0x7c,0x39,0x5e,0x79,0x71};

delay(u16 i){
	while(i--);
}

void main(){
	while(1){
		int i=0;
		LSA=0;
		LSB=0;
		LSC=0;
		for(i=0;i<sizeof(smgduan);i++){
			P0=smgduan[i];
			delay(50000);
		}
	//while(1);
	}
}