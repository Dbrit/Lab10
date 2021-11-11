#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "../inc/CortexM.h"
#include "../inc/tm4c123gh6pm.h"
#include <stdint.h>


//Initialize the Controller
void Controller_Init(void);

//Start running the Controller
void Controller_Start(void);

//Stop running the Controller
void Controller_Stop(void);

//Adjust the PWM and settings based on feedback
void Controller_Adjust(void);

//Timer Init for Controller adjust
void Timer1_Init(void);

//Timer Handler for Controller adjust
void Timer1A_Handler(void);

#endif
