#include <gui/screen2_screen/Screen2View.hpp>

#include "main.h"
#include "extern.h"

Screen2View::Screen2View() {

}

void Screen2View::setupScreen() {
	Screen2ViewBase::setupScreen();
}

void Screen2View::tearDownScreen() {
	Screen2ViewBase::tearDownScreen();
}

void Screen2View::handleTickEvent() {
	Unicode::UnicodeChar buffer[16];

	cell_0.setValues(0);
	cell_1.setValues(1);
	cell_2.setValues(2);
	cell_3.setValues(3);
	cell_4.setValues(4);
	cell_5.setValues(5);

	//total voltage
	battery_voltage.invalidate();
	Unicode::snprintfFloat(buffer, 16, "%.2f V",
			(float) (Current_Status.BATTERY_VOLTAGE / 1000.0));
	Unicode::snprintf(battery_voltageBuffer, 16, "%s", buffer);
	battery_voltage.resizeToCurrentTextWithAlignment();
	battery_voltage.invalidate();
}
