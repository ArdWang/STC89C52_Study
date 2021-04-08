#include "temp.h"

void Delay1ms(uint y)
{
	uint x;
	for(;y>0;y--){
		for(x=110;x>0;x--);
	}
}

// ��ʼ�� 1���� 0 ������
uchar Ds18b20Init()
{
	uchar i;
	DSPORT = 0;			 //����������480us~960us
	i = 70;	
	while(i--);//��ʱ642us
	DSPORT = 1;			//Ȼ���������ߣ����DS18B20������Ӧ�Ὣ��15us~60us����������
	i = 0;
	while(DSPORT)	//�ȴ�DS18B20��������
	{
		Delay1ms(1);
		i++;
		if(i>5)//�ȴ�>5MS
		{
			return 0;//��ʼ��ʧ��
		}
	
	}
	return 1;//��ʼ���ɹ�
}

void Ds18b20WriteByte(uchar dat)
{
	uint i, j;

	for(j=0; j<8; j++)
	{
		DSPORT = 0;	     	  //ÿд��һλ����֮ǰ�Ȱ���������1us
		i++;
		DSPORT = dat & 0x01;  //Ȼ��д��һ�����ݣ������λ��ʼ
		i = 6;
		while(i--); //��ʱ68us������ʱ������60us
		DSPORT = 1;	//Ȼ���ͷ����ߣ�����1us�����߻ָ�ʱ����ܽ���д��ڶ�����ֵ
		dat >>= 1;
	}
}

uchar Ds18b20ReadByte()
{
	uint i,j;
	uchar bi,byte;
	for(j=8;j>0;j--){
		DSPORT=0;
		i++; //��ʱ
		DSPORT=1;
		i++;
		i++;  //6us	   // 1   1000 0000	= 0100 0001
		bi=DSPORT;	 //0
		byte=(byte>>1)|(bi<<7);
		i=4;
		while(i--); //����45us

	}
	return byte;
}


void Ds18b20ChangeTemp()
{
	Ds18b20Init();
	Delay1ms(1);  //1ms
	Ds18b20WriteByte(0xcc);
	Ds18b20WriteByte(0x44);
}


void Ds18b20ReadTempCom()
{
	Ds18b20Init();
	Delay1ms(1);  //1ms
	Ds18b20WriteByte(0xcc);
	Ds18b20WriteByte(0xbe);	
}

int Ds18b20ReadTemp()
{
	int temp=0;
	uchar tmh,tml;
	Ds18b20ChangeTemp();
	Ds18b20ReadTempCom();
	tml=Ds18b20ReadByte();
	tmh=Ds18b20ReadByte();
	temp=tmh;
	temp<<=8;
	temp|=tml;
	return temp;
}
