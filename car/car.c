#include<LPC21xx.h>
#define swforward (1<<28)
#define swleft (1<<29)
#define swright (1<<30)
#define swbackward (1<<31)
#define moveforward 0x00060000
#define moveleft 0x00040000
#define moveright 0x00020000
#define movebackward 0x00090000
#define stop 0x00000000
int main()
{
	PINSEL1=0x00000000;
	PINSEL2=0x00000000;
	IODIR0=0x0fffffff;
	IODIR1=0xffffffff;
	while(1)
	{
		if((IOPIN0&swforward)||(IOPIN0&swright)||(IOPIN0&swleft)||(IOPIN0&swbackward)==0)
		{
			if((IOPIN0&swforward)==0)
			{
				while((IOPIN0&swforward)==0)
				{
					IOPIN1=moveforward;
				}
			}
			if((IOPIN0&swleft)==0)
			{
				while((IOPIN0&swleft)==0)
				{
					IOPIN1=moveleft;
				}
			}
			if((IOPIN0&swright)==0)
			{
				while((IOPIN0&swright)==0)
				{
					IOPIN1=moveright;
				}
			}
			if((IOPIN0&swbackward)==0)
			{
				while((IOPIN0&swbackward)==0)
				{
					IOPIN1=movebackward;
				}
			}
		}
		IOPIN1=stop;
	}
}