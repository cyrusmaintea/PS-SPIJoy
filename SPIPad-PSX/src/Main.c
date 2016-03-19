
#include "System.h"
#include "SPI.h"
#include "SIO.h"

#define BPS 115200
#define RED 125
#define GREEN 125
#define BLUE 125

u_long pad;
char version[] = "0.0.1";

void Menu(void);			//
void clearScreen(void);		//		Proto's
void init(void);			//
void sysExit(void);			//

int main() {
	
	InitSIO(BPS);
	
	printf("\nMain\nVersion %s\n", version);
	
	init();
	PadInit(0);
	
	clearScreen();
	FntPrint("\n	Version %s\n		GamePad SPI", version);
	FntPrint("\n  			Press X\n");
	FntFlush(0);
	
	while(1) {
		
		pad = PadRead(0);
		VSync(0);
		
		if (pad & PADRdown) {
			break;
		}
	}
	
	while(1) {
		
		pad = PadRead(0);
		VSync(0);
		
		if (!(pad & PADRdown)) {
			clearScreen();
			Menu();
		}
		
	}
	
	return 0;
}

void Menu(void) {
	
	FntPrint("\nPress O To EXIT\n");
	FntPrint("\nWaiting for Trigger...\n");
	FntPrint("\nCheck Command With X\n");
	FntFlush(0);
	
	printf("Menu\nPress O To Quit\n");
	
	
	
	while(1) {
		
		pad = PadRead(0);
		VSync(0);

		if (pad & PADRright) {
			printf("**************************\nJump Called;\nInitSIO Reload\n**************************\n");
			sysExit();
			__asm__("j 0x801ecd94");
		}
		/*
		if (pad & PADRdown) {
			
			checkCmd();
			
		}
		*/
	}	
}

void clearScreen(void) {
	
	RECT	clearRect = { 0, 0, 320, 240 };
	
	VSync(0);
	ClearImage(&clearRect, RED, GREEN, BLUE);
	
	printf("clearScreen\nCleared Screen\n");
	
}

void init(void) {
	
	DISPENV	disp;
	DRAWENV draw;
	
	ResetGraph(0);
	
	SetDefDispEnv(&disp, 0, 0, 320, 240);
	disp.isinter = 0;	disp.isrgb24=0;
	SetDefDrawEnv(&draw, 0, 0, 320, 240);
	
	VSync(0);
	PutDispEnv(&disp);
	PutDrawEnv(&draw);
	clearScreen();
	SetDispMask(1);
	
	FntLoad(960, 0);
	FntOpen(0, 0, 320, 240, 0, 512);
	
	printf("Display Initialised\n");
	
}

void sysExit(void) {
	clearScreen();
	PadStop();
	ResetGraph(3);
	StopCallback();
	printf("sysExit\nProgram Quit\n");
	DelSIO();
}