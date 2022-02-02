/*
 * Fourier.c
 *
 *  Created on: Dec 10, 2021
 *      Author: richa
 */

#include "main.h"
#include "usart.h"
#include "gpio.h"
#include "math.h"
#include "arm_math.h"

UART_HandleTypeDef huart2;

float Fourier_Function(float32_t Initial_Array[])
{
		 //Length used for Input and output array for Fourier transform
		  uint16_t Length = 2048;

		  //Input and output array for Fourier transform
		  //float32_t Input_Array[Length];
		  float32_t Output_Array[Length];

		  //Array to hold the complex magnitudes
		  float32_t Mag_Array[Length/2];

		  //Variables to hold the max value and the max value index.
		  float32_t maxValue;
		  int32_t maxValueIndex;

		  //Variables for UART output
		  char uartBuffer[55];
		  int uartBufferLength;

		  //Setup arm_rfft_fast_instance_f32 instance
		  static arm_rfft_fast_instance_f32 FFT_Instance;

		  //Instantiate arm_rfft_fast_instance_f32 instance
		  arm_rfft_fast_init_f32(&FFT_Instance, Length);

		  //Call the arm_rfft_fast_f32 function to perform Fourier transform
		  arm_rfft_fast_f32(&FFT_Instance, Initial_Array, &Output_Array, 0);

		  // - calculates mangnitude of each bin
		  arm_cmplx_mag_f32(Output_Array, Mag_Array, Length/2);

		  //Remove DC
		  Mag_Array[0] = 0;

		  // Remove indexes 0 to 10 by setting Output
		  // Remove maybe 1000+

		  //arm_max_f32 - returns index of largest amplitude bin
		  arm_max_f32(Mag_Array, Length/2, &maxValue, &maxValueIndex);
		  float Peak_Freq;
		  Peak_Freq=(maxValueIndex*10000)/Length;
		  //UART stuff to output
		  //uartBufferLength = sprintf(uartBuffer, "Max Value: %i\n",maxValueIndex);
		  //HAL_UART_Transmit(&huart2, (uint8_t *)uartBuffer, uartBufferLength, 100);

		  //Calculate velocity from freq value referred to by the index (Mag_Array is ordered in 1Hz steps)
		  //So the index value is the same as the freq value.
		  float Velocity = (3*Peak_Freq)/(2*10.587*10);

		  return Velocity;
}
