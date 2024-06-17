#include <8051.h> 
void main() 
{
	int i,j;
	char xdata *ptr; 
	char test, nabor;
	nabor = 0x0AA; 
	ptr = (char xdata *) 0x800;
	P1=0x0;
	for(i=0; i<1024;i++) {
		*ptr=nabor; 
		test=*ptr;
		if(test!=nabor)
		{
			P10=1;
			for(j=0;j<5;j++);
		}
		ptr++;
		P10 = 0;
	}
}
