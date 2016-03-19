#include "System.h"
#include "SIO.h"

#define BPS 115200

int i;
char *tempChar;
char *tempStr;

void InitSIO(int baud) {
	
	AddSIO(baud);
	
}

void readSIO(void) {
	
	*tempChar = getchar();
	gets(tempStr);
	putchar(*tempChar);

	checkCmd();
	
	printf("readSIO();\n");
	
}

void checkCmd(void) {
			
	if (tempStr == "debug") {
		
		printf("\n\n:Debug Function:\n\n");
		
	} else if (tempStr == "test") {
		
		printf("\n\n:Test Function:\n\n");
		
	} else {
		printf("ERROR");
	}
	
}

