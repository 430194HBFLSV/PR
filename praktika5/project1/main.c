#include <8051.h>

void main() {
	int i;
	char keys[3][5] = {{'A', 'B', 'C', 'D'},
						  {'E', 'F', 'G', 'H'},
						  {'I', 'J', 'K', ' '}};
	P0 = 0x38;
	P2 = 0x1;
	P2 = 0x0;
	P0 = 0x80;
	P2 = 0x1;
	P2 = 0x0;
	P3 = 0x0;
	
	while(1) {
		P10 = 0;
		if (P13 == 0) {P0 = keys[0][3]; P2 = 0x3; P2 = 0x2; while(P13 == 0);}
		if (P14 == 0) {P0 = keys[0][2]; P2 = 0x3; P2 = 0x2; while(P14 == 0);}
		if (P15 == 0) {P0 = keys[0][1]; P2 = 0x3; P2 = 0x2; while(P15 == 0);}
		if (P16 == 0) {P0 = keys[0][0]; P2 = 0x3; P2 = 0x2; while(P16 == 0);}
		P10 = 1;

		P11 = 0;
		if (P13 == 0) {P0 = keys[1][3]; P2 = 0x3; P2 = 0x2; while(P13 == 0);}
		if (P14 == 0) {P0 = keys[1][2]; P2 = 0x3; P2 = 0x2; while(P14 == 0);}
		if (P15 == 0) {P0 = keys[1][1]; P2 = 0x3; P2 = 0x2; while(P15 == 0);}
		if (P16 == 0) {P0 = keys[1][0]; P2 = 0x3; P2 = 0x2; while(P16 == 0);}
		P11 = 1;

		P12 = 0;
		if (P13 == 0) {P0 = 0x01; P2 = 0x1; P2 = 0x0; while(P13 == 0);}
		if (P14 == 0) {P0 = keys[2][2]; P2 = 0x3; P2 = 0x2; while(P14 == 0);}
		if (P15 == 0) {P0 = keys[2][1]; P2 = 0x3; P2 = 0x2; while(P15 == 0);}
		if (P16 == 0) {P0 = keys[2][0]; P2 = 0x3; P2 = 0x2; while(P16 == 0);}
		P12 = 1;
	}
}
