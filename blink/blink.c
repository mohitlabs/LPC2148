#include<LPC21xx.h>
void delay(int);
int main()
{
	PINSEL2=0x00000000;
	IO1DIR=0x00ff0000;
	while(1)
	{
		IO1CLR=0x00ff0000;
		delay(500);
		IO1SET=0x00ff0000;
		delay(500);
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