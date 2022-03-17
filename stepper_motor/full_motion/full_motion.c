#include<LPC21xx.h>
void delay(int);
unsigned int pattern[]={
	0x00030000,0x00060000,0x000c0000,0x00090000
};
int main()
{
	unsigned int k;
	PINSEL2=0x00000000;
	IODIR1=0xffffffff;
	for(k=0;1;k++)
	{
        if(k>3)
		{
			k=0;
		}
		IOPIN1=pattern[k];
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