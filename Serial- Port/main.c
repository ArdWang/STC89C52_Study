#include "reg52.h"

// �ض���
typedef unsigned char u8;
typedef unsigned int u16;

//��ʼ������
void UsartInit(){
	TMOD=0X20;
	TH1=0xF3; // ����ѡ��F9
	TL1=0xF3;

	PCON=0x80;		 //4800
	TR1=1;
	SCON=0x50;

	ES=1;
	EA=1;
}


void main(){
	UsartInit();
    while(1);
}

void Usart() interrupt 4{
   u8 receiveData;
   receiveData=SBUF;
   RI=0;
   SBUF=receiveData;
   while(!TI);
   TI=0;	
}


