#include<LPC21xx.h>
#define RS (1<<25)
#define RW (1<<26)
#define EN (1<<27)
#define r1 (1<<16)
#define r2 (1<<17)
#define r3 (1<<18)
#define r4 (1<<19)
#define c1 (1<<20)
#define c2 (1<<21)
#define c3 (1<<22)
#define c4 (1<<23)
void delay(int);
void lcdinit(void);
void lcdcmd(unsigned int);
void lcddata(unsigned char);
void keypadinit(void);
char getkey(void);
char keypaddata(void);
int main()
{
	PINSEL0=0x00000000;
	PINSEL1=0x00000000;
	PINSEL2=0x00000000;
	IODIR0=0xffffffff;
	IODIR1=0x000f0000;
	lcdinit();
	keypadinit();
	while(1)
	{
		lcddata(keypaddata());
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
	delay(10);
	IOCLR0=EN;
}
void lcddata(unsigned char data)
{
	IOPIN0&=(0xff0000ff);
	IOPIN0|=data<<16;
	IOSET0=RS;
	IOCLR0=RW;
	IOSET0=EN;
	delay(10);
	IOCLR0=EN;
}
void keypadinit()
{
	IOPIN1&=0xff00ffff;
}
char getkey(void)
{
	IOCLR1=r1;
	IOSET1=r2;
	IOSET1=r3;
	IOSET1=r4;
	if((IOPIN1&c1)==0)
	{
		delay(10);
		while((IOPIN1&c1)==0);
		return'7';
	}
	if((IOPIN1&c2)==0)
	{
		delay(10);
		while((IOPIN1&c2)==0);
		return'8';
	}
	if((IOPIN1&c3)==0)
	{
		delay(10);
		while((IOPIN1&c3)==0);
		return'9';
	}
	if((IOPIN1&c4)==0)
	{
		delay(10);
		while((IOPIN1&c4)==0);
		return'/';
	}
	IOSET1=r1;
	IOCLR1=r2;
	IOSET1=r3;
	IOSET1=r4;
	if((IOPIN1&c1)==0)
	{
		delay(10);
		while((IOPIN1&c1)==0);
		return'4';
	}
	if((IOPIN1&c2)==0)
	{
		delay(10);
		while((IOPIN1&c2)==0);
		return'5';
	}
	if((IOPIN1&c3)==0)
	{
		delay(10);
		while((IOPIN1&c3)==0);
		return'6';
	}
	if((IOPIN1&c4)==0)
	{
		delay(10);
		while((IOPIN1&c4)==0);
		return'X';
	}
	IOSET1=r1;
	IOSET1=r2;
	IOCLR1=r3;
	IOSET1=r4;
	if((IOPIN1&c1)==0)
	{
		delay(10);
		while((IOPIN1&c1)==0);
		return'1';
	}
	if((IOPIN1&c2)==0)
	{
		delay(10);
		while((IOPIN1&c2)==0);
		return'2';
	}
	if((IOPIN1&c3)==0)
	{
		delay(10);
		while((IOPIN1&c3)==0);
		return'3';
	}
	if((IOPIN1&c4)==0)
	{
		delay(10);
		while((IOPIN1&c4)==0);
		return'-';
	}
	IOSET1=r1;
	IOSET1=r2;
	IOSET1=r3;
	IOCLR1=r4;
	if((IOPIN1&c1)==0)
	{
		delay(10);
		while((IOPIN1&c1)==0);
		return'C';
	}
	if((IOPIN1&c2)==0)
	{
		delay(10);
		while((IOPIN1&c2)==0);
		return'0';
	}
	if((IOPIN1&c3)==0)
	{
		delay(10);
		while((IOPIN1&c3)==0);
		return'=';
	}
	if((IOPIN1&c4)==0)
	{
		delay(10);
		while((IOPIN1&c4)==0);
		return'+';
	}
	else
	{
		return 'n';
	}
}
char keypaddata(void)
{
	char key='n';
	while(key=='n')
	{
		key=getkey();
	}
	return key;
}