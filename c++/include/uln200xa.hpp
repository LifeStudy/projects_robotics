#pragma once
#include <stdint.h>
#include <sys/time.h>
#include <mraa/gpio.h>
#include <mraa/pwm.h>

namespace upm {

	class ULN200XA {
		public:
		typedef enum {
		DIR_CW   = 0x01,
		DIR_CCW  = 0x02
	} ULN200XA_DIRECTION_T;

ULN200XA(int stepsPerRev, int i1, int i2, int i3, int i4);

	~ULN200XA();

	uint32_t getMillis();

	void initClock();

	void setSpeed(int speed);

	void setDirection(ULN200XA_DIRECTION_T dir);

	void stepperSteps(unsigned int steps);

	void release();

	private:
	struct timeval m_startTime;

	// stepper (4-wire)
	mraa_gpio_context m_stepI1;
	mraa_gpio_context m_stepI2;
	mraa_gpio_context m_stepI3;
	mraa_gpio_context m_stepI4;

	// steps per revolution
	int m_stepsPerRev;
	int m_currentStep;
	uint32_t m_stepDelay;

	void stepperStep();

	int m_stepDirection;
	};
}