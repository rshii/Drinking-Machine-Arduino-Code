#include "Arduino.h"
#include "PumpControl.h"
#include "PinLayout.h"

// ELEC 3907: cpp file to get pumps going in skeleton
// Seth Thompson: 101031310

// 

pumpControl::pumpControl() 
{
  PinLayout pinLayout;
  pinLayout.setup();
}

// 4 UNITS MAKE ONE TOTAL DRINK
void pumpControl::dispense (int unitsOfA, int unitsOfB) {
	if (unitsOfA != 0) {
		digitalWrite(motorSetAFor, HIGH);
		delay(FLOW_TOTAL_LENGTH_TIME_A);
		delay(UNIT_OF_LIQUID_A * unitsOfA);
		digitalWrite(motorSetAFor, LOW);
		// can reverse here to clear pipe
	}
	if (unitsOfB != 0) {
		digitalWrite(motorSetBFor, HIGH);
		delay(FLOW_TOTAL_LENGTH_TIME_B);
		delay(UNIT_OF_LIQUID_B * unitsOfB);
		digitalWrite(motorSetBFor, LOW);
		// can reverse here to clear pipe
	}
}