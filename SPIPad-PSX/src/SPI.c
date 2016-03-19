#include "SPI.h"

//W
#define JOY_TX_DATA(x) *((unsigned char*)(0x1f801040 + (x<<4)))
#define JOY_RX_DATA(x) *((unsigned char*)(0x1f801040 + (x<<4)))
//R
#define JOY_STAT(x)	*((unsigned short*)(0x1f801044 + (x<<4)))
#define JOY_MODE(x)	*((unsigned short*)(0x1f801048 + (x<<4)))
//R/W
#define JOY_CTRL(x)	*((unsigned short*)(0x1f80104a + (x<<4)))
#define JOY_BAUD(x)	*((unsigned short*)(0x1f80104e + (x<<4)))

