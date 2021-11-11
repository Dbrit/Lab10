#ifndef MOTOR_H
#define MOTOR_H

#include <stdint.h>
#include "../inc/tm4c123gh6pm.h"
#include "../inc/LaunchPad.h"
#include "../inc/CortexM.h"

// Initialize PB6 as the PWM0 signal to control the motor
void Motor_Init(void);

// Change motor duty cycle
void PWM0A_Duty(uint16_t duty);


#endif

