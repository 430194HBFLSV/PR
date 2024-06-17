#include <8051.h> 

void move_left() {
	P0 = 0x04;
	P2 = 0x1;  
	P2 = 0x0;
}

void move_right() {
	P0 = 0x06;
	P2 = 0x1;  
	P2 = 0x0;
}

void print_char(char ch) {
	P0 = ch;
	P2 = 0x3;
	P2 = 0x2;
}

void move_cursor(unsigned int position) {
	P0 = position; 
	P2 = 0x1; 
	P2 = 0x0;
}

void print(const char* str, unsigned int size, unsigned int position, unsigned int absolute_pos) {
	unsigned int i, j;

	move_cursor(0x80 + position); 

	if (absolute_pos >= size) {
    	for (i=size; i>0; i--) {
      		print_char(str[i-1]);
      		if (size - position == i) {
        		move_cursor(0x90);
      		}
    	}
  	}
	else {
		for (j = size; j > 0; j--) {
			if (absolute_pos >= size - j) {
				print_char(str[j-1]);
			}
		}
	}
}
 
void main() {  
	unsigned int i, j, len1, len2;  
	const char *str1 = " \xAB\xA0\xB3\xC0"; 
	const char *str2 = "\xAB\xB4\xAC\xC0\xA1\xA9\xAE\xA0";
	for (len1=0; str1[len1] != '\0'; ++len1);
	for (len2=0; str2[len2] != '\0'; ++len2);

	move_right();
	move_cursor(0xC0+4);

	for (i=0; i<len2; i++) 
	{
		print_char(str2[i]);
	} 
 
	move_left();
	move_cursor(0x80);
	j = 0;

	while(1) {
		for (i=0; i<16; i++) {
			print(str1, len1, i, j);
			j++;
		}
	}
}
