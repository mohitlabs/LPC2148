#include<LPC21xx.h>
int main()
{
	PINSEL2=0x00000000;
	IO1DIR=0x00fe0000;
	while(1)
	{
		if((IOPIN1&0x00010000)==0x00000000)
		{
			IO1CLR=0x00fe0000;
		}
		else
		{
			IO1SET=0x00fe0000;
		}
	}
}