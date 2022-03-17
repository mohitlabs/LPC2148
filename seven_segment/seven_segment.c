#include<LPC21xx.h>
void delay(int);
unsigned int hex[]={
	0x00c00000,0x00f90000,0x00a40000,0x00b00000,
	0x00990000,0x00920000,0x00820000,0x00f80000,
	0x00800000,0x00900000
};
int main()
{
	int k;
	PINSEL2=0x00000000;
	IO1DIR=0x00ff0000;
	for(k=0;1;k++)
	{
		if(k>9)
		{
			k=0;
		}
		IO1CLR=0xffffffff;
		IO1SET=hex[k];
		delay(1000);
	}
}
void delay(int a)
{
	int i,j;
	for(i=0;i<a;i++)
	{
		for(j=0;j<100;j++);
	}
}