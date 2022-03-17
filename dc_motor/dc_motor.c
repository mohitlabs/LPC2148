#include<LPC21xx.h>
void delay(int);
unsigned int k,pattern[]={
	0x000a0000,0x00000000,0x00050000,0x00000000,
	0x00090000,0x00000000,0x00060000,0x00000000
};
int main()
{
	PINSEL2=0x00000000;
	IODIR1=0xffffffff;
	for(k=0;1;k++)
	{
        if(k>7)
		{
			k=0;
		}
		IOPIN1=pattern[k];
		delay(1000);
	}
}
void delay(int a)
{
	unsigned int i,j;
	for(i=0;i<a;i++)
	{
		for(j=0;j<100;j++);
	}
}