#include<LPC21xx.h>
void delayms(void);
int main()
{
	PINSEL0=0x00000000;
	IODIR0=0x00000001;
	while(1)
	{
		IOSET0=0x00000001;
		delayms();
		IOCLR0=0x00000001;
		delayms();
	}
}
void delayms()
{
	T0TCR=0x02;
	T0MR0=50;
	T0PR=100;
	T0PC=T0TC=0;
	T0MCR=0x03;
	T0TCR=0x01;
	while(T0IR==0x00);
	T0IR=0x01;
}