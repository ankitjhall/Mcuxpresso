/*
===============================================================================
 Name        : project_ankit
 Author      : $(author)
 Version     :
 Copyright   : $(copyright)
 Description : main definition
===============================================================================
*/

#if defined (__USE_LPCOPEN)
#if defined(NO_BOARD_LIB)
#include "chip.h"
#else
#include "board.h"
#endif
#endif

#include <cr_section_macros.h>
void Delayfunc(uint32_t value);
// TODO: insert other include files here

// TODO: insert other definitions and declarations here

int main(void) {

#if defined (__USE_LPCOPEN)
    // Read clock settings and update SystemCoreClock variable
    SystemCoreClockUpdate();
#if !defined(NO_BOARD_LIB)
    // Set up and initialize all required blocks and
    // functions related to the board hardware
    Board_Init();
    // Set the LED to the state of "On"
    bool off_l = true;
    bool on_l = false;

    Board_LED_Set(0, on_l);
    Board_LED_Set(1, on_l);
    Board_LED_Set(2, on_l);


#endif
#endif

    // TODO: insert code here

    // Force the counter to be placed into memory
    volatile static int i = 0 ;
    // Enter an infinite loop, just incrementing a counter
    while(1) {
    	Board_LED_Toggle(0);
    	Delayfunc(2097151);
    	i++ ;

    	Board_LED_Toggle(1);
    	Delayfunc(2097151);
    	i++ ;

        Board_LED_Toggle(2);
    	Delayfunc(2097151);
    	i++ ;
    }
    return 0 ;
}
void Delayfunc(uint32_t value)
{
	for(uint32_t j=0;j<value;j++);
}


