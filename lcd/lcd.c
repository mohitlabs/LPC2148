#include<LPC21xx.h>
#define RS (1<<25)
#define RW (1<<26)
#define EN (1<<27)
void delay(int);
void lcdinit(void);
void lcdcmd(unsigned int);
void lcddata(unsigned char);
void lcdcmddata(unsigned int,unsigned char*);
int main()
{
	PINSEL0=0x00000000;
	PINSEL1=0x00000000;
	IODIR0=0xffffffff;
	lcdinit();
	while(1)
	{
		lcdcmddata(0x80,"DSPL");
		lcdcmddata(0xc0,"India");
		delay(200);
		lcdcmd(0x01);
		delay(200);
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
void lcdcmddata(unsigned int comm,unsigned char *data)
{
	lcdcmd(comm);
	while(*data)
	{
		lcddata(*data++);
	}
}