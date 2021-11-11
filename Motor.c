#include "Motor.h"

// Init PB6 as PWM0, setting period and initial duty cycle
void PWM0A_Init(uint16_t period, uint16_t duty);

// Initialize PB6 as the PWM0 signal to control the motor
void Motor_Init(void) {
	PWM0A_Init(40000, 30000);  // 1000 Hz, 75% duty
}

// Init PB6 as PWM0, setting period and initial duty cycle
void PWM0A_Init(uint16_t period, uint16_t duty) {
	SYSCTL_RCGCPWM_R |= 0x01;          	    // 1) activate PWM0
  SYSCTL_RCGCGPIO_R |= 0x02;             // 2) activate port B
  while((SYSCTL_PRGPIO_R&0x02) == 0){};
  GPIO_PORTB_AFSEL_R |= 0x40;            // alt funct on PB6
  GPIO_PORTB_PCTL_R = 
   (GPIO_PORTB_PCTL_R&0xF0FFFFFF)+0x04000000; // PWM0
  GPIO_PORTB_AMSEL_R &= ~0x40;           // disable analog on PB6
  GPIO_PORTB_DEN_R |= 0x40;              // enable digital I/O on PB6
  SYSCTL_RCC_R = 0x00100000 |            // 3) use PWM divider
      (SYSCTL_RCC_R & (~0x000E0000));    //  1/2 divider
  PWM0_0_CTL_R = 0;                      // 4) re-loading down-counting mode
  PWM0_0_GENA_R = 0xC8;                  // low on LOAD, high on CMPA down
  PWM0_0_LOAD_R = period - 1;            // 5) cycles count down to 0
  PWM0_0_CMPA_R = duty - 1;              // 6) count value output rises
  PWM0_0_CTL_R |= 0x00000001;            // 7) start PWM0
  PWM0_ENABLE_R |= 0x00000001;           // enable PB6/M0PWM0

}

// Change motor duty cycle
void PWM0A_Duty(uint16_t duty) {
	PWM0_0_CMPA_R = duty - 1;      // count value output rises
}

