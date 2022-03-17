#include<LPC214x.h>
#define RS (1<<13)
#define RW (1<<14)
#define EN (1<<15)
void delay(int);
void lcdinit(void);
void lcdcmd(unsigned int);
void lcddata(unsigned char);
void adcinit(void);
unsigned long int adcdata(void);
int main()
{
	int rec,digit1,digit2,digit3,digit4;
	PINSEL0=0x00000000;
	PINSEL1=0x01000000;
	IODIR0=0xefffffff;
	lcdinit();
	adcinit();
	while(1)
	{
		rec=adcdata();
		digit1=(rec/1000);
		digit2=((rec-digit1*1000)/100);
		digit3=((rec-(digit1*1000+digit2*100))/10);
		digit4=(rec-(digit1*1000+digit2*100+digit3*10));
		lcdcmd(0x80);
		lcddata(digit1+0x30);
		lcddata(digit2+0x30);
		lcddata(digit3+0x30);
		lcddata(digit4+0x30);
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
void lcdinit()
{
	lcdcmd(0x38);
	lcdcmd(0x01);
	lcdcmd(0x06);
	lcdcmd(0x0c);
}
void lcdcmd(unsigned int comm)
{
	IOPIN0&=(0xff0000ff);
	IOPIN0|=comm<<16;
	IOCLR0=RS;
	IOCLR0=RW;
	IOSET0=EN;
	delay(100);
	IOCLR0=EN;
}
void lcddata(unsigned char data)
{
	IOPIN0&=(0xff0000ff);
	IOPIN0|=data<<16;
	IOSET0=RS;
	IOCLR0=RW;
	IOSET0=EN;
	delay(100);
	IOCLR0=EN;
}
void adcinit()
{
	AD0CR=0x00200802;
}
unsigned long int adcdata()
{
	unsigned int rec;
	AD0CR|=(1<<24);
	while(AD0GDR==0x00000000);
	rec=AD0GDR;
	AD0CR=0x00200802;
	rec>>=6;
	rec&=0x3ff;
	return rec;
}