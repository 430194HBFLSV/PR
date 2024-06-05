#include <8051.h>

int flag = 0;
interrupt void isr_ex0(void)
{
	if (flag == 0) flag = 1;
 	else flag = 0;
}
void main()
{
	IT0 = 1;
	EX0 = 1;
	EA = 1;
	P1 = 0x0;
	P2 = 0x80;
	P3 = 0x0;
	while(1)
	{
		P36 = 1;
		P36 = 0;
		while (P37 == 1);
		if (flag == 1) P2 = P1;
		else P2 = P1 + 0x10;
	}
}
