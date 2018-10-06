/*
 * \file
 *
 * \brief Empty user application template
 *
 */

/**
 * \mainpage User Application template doxygen documentation
 *
 * \par Empty user application template
 *
 * Bare minimum empty user application template
 *
 * \par Content
 *
 * -# Include the ASF header files (through asf.h)
 * -# "Insert system clock initialization code here" comment
 * -# Minimal main function that starts with a call to board_init()
 * -# "Insert application code here" comment
 *
 */

/*
 * Include header files for all drivers that have been imported from
 * Atmel Software Framework (ASF).
 */
/*
 * Support and FAQ: visit <a href="https://www.microchip.com/support/">Microchip Support</a>
 */
#include <asf.h>
#include <adc.h>
#include <math.h>
#include <Drivers/uart.h>

void TCC0_init(uint16_t period);

int main (void)
{	/* Insert system clock initialization code here (sysclk_init()). */

	board_init();

	/* Insert application code here, after the board has been initialized. */
	PORTQ.DIR = 0x08;
	PORTQ.OUT = 0x00;
	TCC0_init(62499);
	uart_terminal_init();
	
	while (1)
	
	{
		PORTQ.OUT = 0x00;
		delay_ms(500); // creates  0.5 sec delay
		PORTQ.OUT  = 0x008; 
		
		
		
		
	}
	
}


void TCC0_init(uint16_t period)
{
	sysclk_enable_peripheral_clock(&TCC0);
	sysclk_enable_module(SYSCLK_PORT_C, SYSCLK_HIRES);
			TCC0.CTRLA = 0x07;
			TCC0.CTRLB = 0x03;
			TCC0.PER = period;
			TCC0.CCA = TCE0.PER - (TCC0.PER/10);
}