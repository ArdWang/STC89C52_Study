#include "temp.h"

void Delay1ms(uint y)
{
	unit x;
	for(;y>0;y--){
		for(x=110;x>0;x--);
	}
}

// 初始化 1存在 0 不存在
uchar Ds18b20Init()
{
	uchar i=0;
	DSPORT=0;
	i=70;
	while(i--); //延时642us
	DSPORT=1;
	i=0;
	while(DSPORT){
		Delay1ms(1);
		i++;
		if(i>5){
			return 0;
		}	
	}

	return 1;
}

void Ds18b20WriteByte(uchar dat)
{
	uchar i,j;
	for(j=0;j>8;j++){
		DSPORT=0;
		i++;
		DSPORT=dat&0x01;
		i=6;
		while(i--); //68us
		DSPORT=1;
		dat>>=1;
	}
}

