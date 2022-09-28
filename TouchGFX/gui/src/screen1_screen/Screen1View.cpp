#include <gui/screen1_screen/Screen1View.hpp>

#include "main.h"
#include "extern.h"

Screen1View::Screen1View() {

}

void Screen1View::setupScreen() {
	Screen1ViewBase::setupScreen();

	Unicode::UnicodeChar buffer[10];

	//.................UNITS.................

	Unicode::strncpy(buffer, "kPa", 10);
	Unicode::snprintf(map_unitsBuffer, 10, "%s", buffer);
	map_units.resizeToCurrentTextWithAlignment();
	map_units.invalidate();

	Unicode::strncpy(buffer, "Lambda", 10);
	Unicode::snprintf(lambda_unitsBuffer, 10, "%s", buffer);
	map_units.resizeToCurrentTextWithAlignment();
	lambda_units.invalidate();

	Unicode::strncpy(buffer, "kPa", 10);
	Unicode::snprintf(oilp_unitsBuffer, 10, "%s", buffer);
	oilp_units.resizeToCurrentTextWithAlignment();
	oilp_units.invalidate();

	Unicode::strncpy(buffer, "kPa", 10);
	Unicode::snprintf(fuelp_unitsBuffer, 10, "%s", buffer);
	fuelp_units.resizeToCurrentTextWithAlignment();
	fuelp_units.invalidate();

	Unicode::strncpy(buffer, "°C", 10);
	Unicode::snprintf(ect_unitsBuffer, 10, "%s", buffer);
	fuelp_units.resizeToCurrentTextWithAlignment();
	fuelp_units.invalidate();

	Unicode::strncpy(buffer, "°C", 10);
	Unicode::snprintf(iat_unitsBuffer, 10, "%s", buffer);
	fuelp_units.resizeToCurrentTextWithAlignment();
	fuelp_units.invalidate();

	Unicode::strncpy(buffer, "V", 10);
	Unicode::snprintf(batt_unitsBuffer, 10, "%s", buffer);
	fuelp_units.resizeToCurrentTextWithAlignment();
	fuelp_units.invalidate();

	Unicode::strncpy(buffer, "%", 10);
	Unicode::snprintf(tps_unitsBuffer, 10, "%s", buffer);
	fuelp_units.resizeToCurrentTextWithAlignment();
	fuelp_units.invalidate();

	//.................LABELS.................

	Unicode::strncpy(buffer, "MAP", 10);
	Unicode::snprintf(map_labelBuffer, 10, "%s", buffer);
	map_units.resizeToCurrentTextWithAlignment();
	map_units.invalidate();

	Unicode::strncpy(buffer, "AFP", 10);
	Unicode::snprintf(lambda_labelBuffer, 10, "%s", buffer);
	map_units.resizeToCurrentTextWithAlignment();
	lambda_units.invalidate();

	Unicode::strncpy(buffer, "OIL P", 10);
	Unicode::snprintf(oilp_labelBuffer, 10, "%s", buffer);
	oilp_units.resizeToCurrentTextWithAlignment();
	oilp_units.invalidate();

	Unicode::strncpy(buffer, "FUEL P", 10);
	Unicode::snprintf(fuelp_labelBuffer, 10, "%s", buffer);
	fuelp_units.resizeToCurrentTextWithAlignment();
	fuelp_units.invalidate();

	Unicode::strncpy(buffer, "ECT", 10);
	Unicode::snprintf(ect_labelBuffer, 10, "%s", buffer);
	fuelp_units.resizeToCurrentTextWithAlignment();
	fuelp_units.invalidate();

	Unicode::strncpy(buffer, "IAT", 10);
	Unicode::snprintf(iat_labelBuffer, 10, "%s", buffer);
	fuelp_units.resizeToCurrentTextWithAlignment();
	fuelp_units.invalidate();

	Unicode::strncpy(buffer, "BATTERY", 10);
	Unicode::snprintf(batt_labelBuffer, 10, "%s", buffer);
	fuelp_units.resizeToCurrentTextWithAlignment();
	fuelp_units.invalidate();

	Unicode::strncpy(buffer, "TPS", 10);
	Unicode::snprintf(tps_labelBuffer, 10, "%s", buffer);
	fuelp_units.resizeToCurrentTextWithAlignment();
	fuelp_units.invalidate();

}

void Screen1View::tearDownScreen() {
	Screen1ViewBase::tearDownScreen();
}

void Screen1View::handleTickEvent() {
	Unicode::UnicodeChar buffer[16];

	map_value.invalidate();
	Unicode::snprintfFloat(buffer, 16, "%.1f", (float)(Current_Status.MAP / 10.0));
	Unicode::snprintf(map_valueBuffer, 16, "%s", buffer);
	map_value.resizeToCurrentTextWithAlignment();
	map_value.invalidate();

	batt_value.invalidate();
	Unicode::snprintfFloat(buffer, 16, "%.1f", (float)(Current_Status.BATT / 100.0));
	Unicode::snprintf(batt_valueBuffer, 16, "%s", buffer);
	batt_value.resizeToCurrentTextWithAlignment();
	batt_value.invalidate();

	tps_value.invalidate();
	Unicode::snprintfFloat(buffer, 16, "%.0f", (float)(Current_Status.TPS / 10.0));
	Unicode::snprintf(tps_valueBuffer, 16, "%s", buffer);
	tps_value.resizeToCurrentTextWithAlignment();
	tps_value.invalidate();

	lambda_value.invalidate();
	Unicode::snprintfFloat(buffer, 16, "%.2f", (float)(Current_Status.LAMBDA1 / 1000.0));
	Unicode::snprintf(lambda_valueBuffer, 16, "%s", buffer);
	lambda_value.resizeToCurrentTextWithAlignment();
	lambda_value.invalidate();

	ect_value.invalidate();
	Unicode::snprintfFloat(buffer, 16, "%.0f", (float)(Current_Status.ECT / 10.0));
	Unicode::snprintf(ect_valueBuffer, 16, "%s", buffer);
	ect_value.resizeToCurrentTextWithAlignment();
	ect_value.invalidate();

	iat_value.invalidate();
	Unicode::snprintfFloat(buffer, 16, "%.0f", (float)(Current_Status.IAT / 10.0));
	Unicode::snprintf(iat_valueBuffer, 16, "%s", buffer);
	iat_value.resizeToCurrentTextWithAlignment();
	iat_value.invalidate();

	oilp_value.invalidate();
	Unicode::snprintfFloat(buffer, 16, "%.1f", (float)(Current_Status.OILP / 10.0));
	Unicode::snprintf(oilp_valueBuffer, 16, "%s", buffer);
	oilp_value.resizeToCurrentTextWithAlignment();
	oilp_value.invalidate();

	fuelp_value.invalidate();
	Unicode::snprintfFloat(buffer, 16, "%.1f", (float)(Current_Status.FUELP / 10.0));
	Unicode::snprintf(fuelp_valueBuffer, 16, "%s", buffer);
	fuelp_value.resizeToCurrentTextWithAlignment();
	fuelp_value.invalidate();

//	map_units.invalidate();
//	Unicode::snprintfFloat(buffer, 16, "%.0f", (float)(Current_Status.BARO / 10.0));
//	Unicode::snprintf(map_unitsBuffer, 16, "%s", buffer);
//	map_units.resizeToCurrentTextWithAlignment();
//	map_units.invalidate();

	indLeft.setVisible(Current_Status.IND_LEFT);
	indLeft.invalidate();

	indHigh.setVisible(Current_Status.IND_HIGH);
	indHigh.invalidate();

	indFuel.setVisible(Current_Status.IND_FUEL);
	indFuel.invalidate();

	indOil.setVisible(Current_Status.IND_OIL);
	indOil.invalidate();

	indBatt.setVisible(Current_Status.IND_BATT);
	indBatt.invalidate();

	indPark.setVisible(Current_Status.IND_PARK);
	indPark.invalidate();

	indDTC.setVisible(Current_Status.IND_DTC);
	indDTC.invalidate();

	indECT.setVisible(Current_Status.IND_ECT);
	indECT.invalidate();

	indLow.setVisible(Current_Status.IND_LOW);
	indLow.invalidate();

	indRight.setVisible(Current_Status.IND_RIGHT);
	indRight.invalidate();
	gauge1.updateValue(Current_Status.RPM, 0);
	//gauge1.set
	//gauge1.invalidate();

}
