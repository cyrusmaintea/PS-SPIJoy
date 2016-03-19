/*
 *   Looking at the Memory Card:
 *   _________________
 *   |_ _|_ _ _|_ _ _|
 *    1 2 3 4 5 6 7 8
 *    
 *    1 DATA 
 *    2 CMD
 *    3 7.6V - N/C
 *    4 GND
 *    5 3.6V - N/C
 *    6 ATT
 *    7 CLK
 *    8 N/C
 *    9 ACK
 */

#include "simpletools.h"

//      SPI
//SPI1
#define spiMO1    1
#define spiMI1    2
#define spiSC1    3
#define spiCE1    4
//SPI2
#define spiMO2    5
#define spiMI2    6
#define spiSC2    7 
#define spiCE2    8

//      PSPI
//PSPI On Memory Port
#define pspiDAT   9
#define pspiCMD   10
#define pspiATT   11
#define pspiCLK   12
#define pspiACK   13

#define pspiClock 0x7F //250kHz
#define pspiBaud  38400

#define sramRD    0x03
#define sramWR    0x02
#define sramRDMR  0x05
#define sramWRMR  0x01

#define ID        "PSPI"

#define GETID     0xF0
#define PSPIRD    0xF2
#define PSPIWR    0xF3

#define SPI1RD    0xE0
#define SPI1WR    0xE1  

#define SPI2RD    0xD0
#define SPI2WR    0xD1

#define ERROR0    0xA0
#define ERROR1    0xA1
#define ERROR2    0xA2

signed char inputBuffer;

void initSPI();
void initPSPI();
void stopSPI(int n);
int writeSPI(int n, int size, int bytes, signed char data);

int main()
{
  print("PSX-SPIPAD\n");
  
  while(1)
  { 
    
  }
  
}

void startSPI(int n)
{
  /*
  output(spiMO1);
  input(spiMI1);
  output(spiCE1);
  output(spiSC1);
  
  output(spiMO2);
  input(spiMI2);
  output(spiCE2);
  output(spiSC2);
  */
  
  if(n == 1)
  {
    low(spiMO1);
    low(spiCE1);
    high(spiSC1);
  } else if(n == 2)
  {
    low(spiMO2);
    low(spiSC2);
    high(spiCE2);
  }
}

void initPSPI()
{
  /*
  input(pspiDAT);
  output(pspiCMD);
  output(pspiATT);
  output(pspiCLK);
  input(pspiACK);
  */
  //settings
  
  high(pspiDAT);
  low(pspiCMD);
  high(pspiATT);
  high(pspiCLK);
  high(pspiACK);
}    

void stopSPI(int n)
{
  if(n == 1)
  {
    high(spiCE1);
  } else if(n == 2)
  {
    high(spiCE2);
  }
  pause(1);    
}

int writeSPI(int n, int size, int bytes, signed char data)
{
  if(n == 1)
  {
    shift_out(spiMO1, size, LSBFIRST, bytes, data);
  } else if(n == 2)
  {
    shift_out(spiMO2, size, LSBFIRST, bytes, data);
  }  
  return -1;
}  