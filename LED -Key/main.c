#include "reg52.h"

// �ض���
typedef unsigned char u8;
typedef unsigned int u16;

sbit led = P2^0;  // D1 ָʾ��
sbit k1 = P3^1; //�������� P31�Ŀ���


 void delay(u16 i){
 	  while(i--);
 }


 void keypros(){
 	 if(k1==0){
	 	// �Ի�����ͬѧ��������
	 	delay(1000); //10ms
		if(k1==0){
	 		led = ~led;	 //ȡ��
		}
		// �����ɿ�
		while(!k1);
	 }
 }

void main(){
    while(1){
		keypros();			
	}
}

