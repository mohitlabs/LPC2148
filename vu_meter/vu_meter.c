#include<LPC214x.h>
#define pin0 0x00000000
#define pin1 0x00010000
#define pin2 0x00030000
#define pin3 0x00070000
#define pin4 0x000f0000
#define pin5 0x001f0000
#define pin6 0x003f0000
#define pin7 0x007f0000
#define pin8 0x00ff0000
#define pin9 0x01ff0000
#define pin10 0x03ff0000
void delay(int);
void adcinit(void);
unsigned long int adcdata(void);
int main()
{
	int rec,digit1,digit2,digit3,digit4;
	PINSEL1=0x01000000;
	PINSEL2=0x00000000;
	IODIR0=0xefffffff;
	IODIR1=0xffffffff;
	adcinit();
	while(1)
	{
		rec=adcdata();
		if(rec==0)
		{
			IOPIN1=~pin0;
		}
		if((rec>0)&&(rec<100))
		{
			IOPIN1=~pin1;
		}
		if((rec>100)&&(rec<200))
		{
			IOPIN1=~pin2;
		}
		if((rec>200)&&(rec<300))
		{
			IOPIN1=~pin3;
		}
		if((rec>300)&&(rec<400))
		{
			IOPIN1=~pin4;
		}
		if((rec>400)&&(rec<500))
		{
			IOPIN1=~pin5;
		}
		if((rec>500)&&(rec<600))
		{
			IOPIN1=~pin6;
		}
		if((rec>600)&&(rec<700))
		{
			IOPIN1=~pin7;
		}
		if((rec>700)&&(rec<800))
		{
			IOPIN1=~pin8;
		}
		if((rec>800)&&(rec<900))
		{
			IOPIN1=~pin9;
		}
		if((rec>900)&&(rec<1024))
		{
			IOPIN1=~pin10;
		}
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