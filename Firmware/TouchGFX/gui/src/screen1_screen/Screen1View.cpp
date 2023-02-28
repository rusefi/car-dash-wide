#include <gui/screen1_screen/Screen1View.hpp>
#include <touchgfx/Color.hpp>

#include "main.h"
#include "extern.h"

Screen1View::Screen1View() {

}

void Screen1View::setupScreen() {
	Screen1ViewBase::setupScreen();

	Unicode::UnicodeChar buffer[32];

	for (uint8_t i = 0; i < 8; ++i) {

		switch (i) {
			case 0:
				Unicode::strncpy(buffer, Current_Status.SCREEN_FIELDS[i].Label.Label, 32);
				Unicode::snprintf(label_0Buffer, 32, "%s", buffer);
				label_0.setXY(Current_Status.SCREEN_FIELDS[i].Label.X, Current_Status.SCREEN_FIELDS[i].Label.Y);
				label_0.setWidthHeight(Current_Status.SCREEN_FIELDS[i].Label.Width, Current_Status.SCREEN_FIELDS[i].Label.Height);
				label_0.resizeToCurrentTextWithAlignment();
				label_0.invalidate();

				Unicode::strncpy(buffer, Current_Status.SCREEN_FIELDS[i].Unit.Label, 32);
				Unicode::snprintf(unit_0Buffer, 32, "%s", buffer);
				unit_0.setXY(Current_Status.SCREEN_FIELDS[i].Unit.X, Current_Status.SCREEN_FIELDS[i].Unit.Y);
				//unit_0.setWidth(Current_Status.SCREEN_FIELDS[i].Unit.Width);
				//unit_0.setHeight(Current_Status.SCREEN_FIELDS[i].Unit.Height);
				unit_0.resizeToCurrentTextWithAlignment();
				unit_0.invalidate();

				Unicode::snprintfFloat(buffer, 32, "%.0f", (float)(Current_Status.SCREEN_FIELDS[i].ValueDefault));
				Unicode::snprintf(value_0Buffer, 32, "%s", buffer);
				value_0.setXY(Current_Status.SCREEN_FIELDS[i].Value.X, Current_Status.SCREEN_FIELDS[i].Value.Y);
				//value_0.setWidth(Current_Status.SCREEN_FIELDS[i].Value.Width);
				//value_0.setHeight(Current_Status.SCREEN_FIELDS[i].Value.Height);
				value_0.resizeToCurrentTextWithAlignment();
				value_0.invalidate();
				break;
			case 1:
				Unicode::strncpy(buffer, Current_Status.SCREEN_FIELDS[i].Label.Label, 32);
				Unicode::snprintf(label_1Buffer, 32, "%s", buffer);
				label_1.setXY(Current_Status.SCREEN_FIELDS[i].Label.X, Current_Status.SCREEN_FIELDS[i].Label.Y);
				label_1.setWidthHeight(Current_Status.SCREEN_FIELDS[i].Label.Width, Current_Status.SCREEN_FIELDS[i].Label.Height);
				label_1.resizeToCurrentTextWithAlignment();
				label_1.invalidate();

				Unicode::strncpy(buffer, Current_Status.SCREEN_FIELDS[i].Unit.Label, 32);
				Unicode::snprintf(unit_1Buffer, 32, "%s", buffer);
				unit_1.setXY(Current_Status.SCREEN_FIELDS[i].Unit.X, Current_Status.SCREEN_FIELDS[i].Unit.Y);
				//unit_0.setWidth(Current_Status.SCREEN_FIELDS[i].Unit.Width);
				//unit_0.setHeight(Current_Status.SCREEN_FIELDS[i].Unit.Height);
				unit_1.resizeToCurrentTextWithAlignment();
				unit_1.invalidate();

				Unicode::snprintfFloat(buffer, 32, "%.0f", (float)(Current_Status.SCREEN_FIELDS[i].ValueDefault));
				Unicode::snprintf(value_1Buffer, 32, "%s", buffer);
				value_1.setXY(Current_Status.SCREEN_FIELDS[i].Value.X, Current_Status.SCREEN_FIELDS[i].Value.Y);
				//value_0.setWidth(Current_Status.SCREEN_FIELDS[i].Value.Width);
				//value_0.setHeight(Current_Status.SCREEN_FIELDS[i].Value.Height);
				value_1.resizeToCurrentTextWithAlignment();
				value_1.invalidate();
				break;
			case 2:
				Unicode::strncpy(buffer, Current_Status.SCREEN_FIELDS[i].Label.Label, 32);
				Unicode::snprintf(label_2Buffer, 32, "%s", buffer);
				label_2.setXY(Current_Status.SCREEN_FIELDS[i].Label.X, Current_Status.SCREEN_FIELDS[i].Label.Y);
				label_2.setWidthHeight(Current_Status.SCREEN_FIELDS[i].Label.Width, Current_Status.SCREEN_FIELDS[i].Label.Height);
				label_2.resizeToCurrentTextWithAlignment();
				label_2.invalidate();

				Unicode::strncpy(buffer, Current_Status.SCREEN_FIELDS[i].Unit.Label, 32);
				Unicode::snprintf(unit_2Buffer, 32, "%s", buffer);
				unit_2.setXY(Current_Status.SCREEN_FIELDS[i].Unit.X, Current_Status.SCREEN_FIELDS[i].Unit.Y);
				//unit_0.setWidth(Current_Status.SCREEN_FIELDS[i].Unit.Width);
				//unit_0.setHeight(Current_Status.SCREEN_FIELDS[i].Unit.Height);
				unit_2.resizeToCurrentTextWithAlignment();
				unit_2.invalidate();

				Unicode::snprintfFloat(buffer, 32, "%.0f", (float)(Current_Status.SCREEN_FIELDS[i].ValueDefault));
				Unicode::snprintf(value_2Buffer, 32, "%s", buffer);
				value_2.setXY(Current_Status.SCREEN_FIELDS[i].Value.X, Current_Status.SCREEN_FIELDS[i].Value.Y);
				//value_0.setWidth(Current_Status.SCREEN_FIELDS[i].Value.Width);
				//value_0.setHeight(Current_Status.SCREEN_FIELDS[i].Value.Height);
				value_2.resizeToCurrentTextWithAlignment();
				value_2.invalidate();
				break;
			case 3:
				Unicode::strncpy(buffer, Current_Status.SCREEN_FIELDS[i].Label.Label, 32);
				Unicode::snprintf(label_3Buffer, 32, "%s", buffer);
				label_3.setXY(Current_Status.SCREEN_FIELDS[i].Label.X, Current_Status.SCREEN_FIELDS[i].Label.Y);
				label_3.setWidthHeight(Current_Status.SCREEN_FIELDS[i].Label.Width, Current_Status.SCREEN_FIELDS[i].Label.Height);
				label_3.resizeToCurrentTextWithAlignment();
				label_3.invalidate();

				Unicode::strncpy(buffer, Current_Status.SCREEN_FIELDS[i].Unit.Label, 32);
				Unicode::snprintf(unit_3Buffer, 32, "%s", buffer);
				unit_3.setXY(Current_Status.SCREEN_FIELDS[i].Unit.X, Current_Status.SCREEN_FIELDS[i].Unit.Y);
				//unit_0.setWidth(Current_Status.SCREEN_FIELDS[i].Unit.Width);
				//unit_0.setHeight(Current_Status.SCREEN_FIELDS[i].Unit.Height);
				unit_3.resizeToCurrentTextWithAlignment();
				unit_3.invalidate();

				Unicode::snprintfFloat(buffer, 32, "%.0f", (float)(Current_Status.SCREEN_FIELDS[i].ValueDefault));
				Unicode::snprintf(value_3Buffer, 32, "%s", buffer);
				value_3.setXY(Current_Status.SCREEN_FIELDS[i].Value.X, Current_Status.SCREEN_FIELDS[i].Value.Y);
				//value_0.setWidth(Current_Status.SCREEN_FIELDS[i].Value.Width);
				//value_0.setHeight(Current_Status.SCREEN_FIELDS[i].Value.Height);
				value_3.resizeToCurrentTextWithAlignment();
				value_3.invalidate();
				break;
			case 4:
				Unicode::strncpy(buffer, Current_Status.SCREEN_FIELDS[i].Label.Label, 32);
				Unicode::snprintf(label_4Buffer, 32, "%s", buffer);
				label_4.setXY(Current_Status.SCREEN_FIELDS[i].Label.X, Current_Status.SCREEN_FIELDS[i].Label.Y);
				label_4.setWidthHeight(Current_Status.SCREEN_FIELDS[i].Label.Width, Current_Status.SCREEN_FIELDS[i].Label.Height);
				label_4.resizeToCurrentTextWithAlignment();
				label_4.invalidate();

				Unicode::strncpy(buffer, Current_Status.SCREEN_FIELDS[i].Unit.Label, 32);
				Unicode::snprintf(unit_4Buffer, 32, "%s", buffer);
				unit_4.setXY(Current_Status.SCREEN_FIELDS[i].Unit.X, Current_Status.SCREEN_FIELDS[i].Unit.Y);
				//unit_0.setWidth(Current_Status.SCREEN_FIELDS[i].Unit.Width);
				//unit_0.setHeight(Current_Status.SCREEN_FIELDS[i].Unit.Height);
				unit_4.resizeToCurrentTextWithAlignment();
				unit_4.invalidate();

				Unicode::snprintfFloat(buffer, 32, "%.0f", (float)(Current_Status.SCREEN_FIELDS[i].ValueDefault));
				Unicode::snprintf(value_4Buffer, 32, "%s", buffer);
				value_4.setXY(Current_Status.SCREEN_FIELDS[i].Value.X, Current_Status.SCREEN_FIELDS[i].Value.Y);
				//value_0.setWidth(Current_Status.SCREEN_FIELDS[i].Value.Width);
				//value_0.setHeight(Current_Status.SCREEN_FIELDS[i].Value.Height);
				value_4.resizeToCurrentTextWithAlignment();
				value_4.invalidate();
				break;
			case 5:
				Unicode::strncpy(buffer, Current_Status.SCREEN_FIELDS[i].Label.Label, 32);
				Unicode::snprintf(label_5Buffer, 32, "%s", buffer);
				label_5.setXY(Current_Status.SCREEN_FIELDS[i].Label.X, Current_Status.SCREEN_FIELDS[i].Label.Y);
				label_5.setWidthHeight(Current_Status.SCREEN_FIELDS[i].Label.Width, Current_Status.SCREEN_FIELDS[i].Label.Height);
				label_5.resizeToCurrentTextWithAlignment();
				label_5.invalidate();

				Unicode::strncpy(buffer, Current_Status.SCREEN_FIELDS[i].Unit.Label, 32);
				Unicode::snprintf(unit_5Buffer, 32, "%s", buffer);
				unit_5.setXY(Current_Status.SCREEN_FIELDS[i].Unit.X, Current_Status.SCREEN_FIELDS[i].Unit.Y);
				//unit_0.setWidth(Current_Status.SCREEN_FIELDS[i].Unit.Width);
				//unit_0.setHeight(Current_Status.SCREEN_FIELDS[i].Unit.Height);
				unit_5.resizeToCurrentTextWithAlignment();
				unit_5.invalidate();

				Unicode::snprintfFloat(buffer, 32, "%.0f", (float)(Current_Status.SCREEN_FIELDS[i].ValueDefault));
				Unicode::snprintf(value_5Buffer, 32, "%s", buffer);
				value_5.setXY(Current_Status.SCREEN_FIELDS[i].Value.X, Current_Status.SCREEN_FIELDS[i].Value.Y);
				//value_0.setWidth(Current_Status.SCREEN_FIELDS[i].Value.Width);
				//value_0.setHeight(Current_Status.SCREEN_FIELDS[i].Value.Height);
				value_5.resizeToCurrentTextWithAlignment();
				value_5.invalidate();
				break;
			case 6:
				Unicode::strncpy(buffer, Current_Status.SCREEN_FIELDS[i].Label.Label, 32);
				Unicode::snprintf(label_6Buffer, 32, "%s", buffer);
				label_6.setXY(Current_Status.SCREEN_FIELDS[i].Label.X, Current_Status.SCREEN_FIELDS[i].Label.Y);
				label_6.setWidthHeight(Current_Status.SCREEN_FIELDS[i].Label.Width, Current_Status.SCREEN_FIELDS[i].Label.Height);
				label_6.resizeToCurrentTextWithAlignment();
				label_6.invalidate();

				Unicode::strncpy(buffer, Current_Status.SCREEN_FIELDS[i].Unit.Label, 32);
				Unicode::snprintf(unit_6Buffer, 32, "%s", buffer);
				unit_6.setXY(Current_Status.SCREEN_FIELDS[i].Unit.X, Current_Status.SCREEN_FIELDS[i].Unit.Y);
				//unit_0.setWidth(Current_Status.SCREEN_FIELDS[i].Unit.Width);
				//unit_0.setHeight(Current_Status.SCREEN_FIELDS[i].Unit.Height);
				unit_6.resizeToCurrentTextWithAlignment();
				unit_6.invalidate();

				Unicode::snprintfFloat(buffer, 32, "%.0f", (float)(Current_Status.SCREEN_FIELDS[i].ValueDefault));
				Unicode::snprintf(value_6Buffer, 32, "%s", buffer);
				value_6.setXY(Current_Status.SCREEN_FIELDS[i].Value.X, Current_Status.SCREEN_FIELDS[i].Value.Y);
				//value_0.setWidth(Current_Status.SCREEN_FIELDS[i].Value.Width);
				//value_0.setHeight(Current_Status.SCREEN_FIELDS[i].Value.Height);
				value_6.resizeToCurrentTextWithAlignment();
				value_6.invalidate();
				break;
			case 7:
				Unicode::strncpy(buffer, Current_Status.SCREEN_FIELDS[i].Label.Label, 32);
				Unicode::snprintf(label_7Buffer, 32, "%s", buffer);
				label_7.setXY(Current_Status.SCREEN_FIELDS[i].Label.X, Current_Status.SCREEN_FIELDS[i].Label.Y);
				label_7.setWidthHeight(Current_Status.SCREEN_FIELDS[i].Label.Width, Current_Status.SCREEN_FIELDS[i].Label.Height);
				label_7.resizeToCurrentTextWithAlignment();
				label_7.invalidate();

				Unicode::strncpy(buffer, Current_Status.SCREEN_FIELDS[i].Unit.Label, 32);
				Unicode::snprintf(unit_7Buffer, 32, "%s", buffer);
				unit_7.setXY(Current_Status.SCREEN_FIELDS[i].Unit.X, Current_Status.SCREEN_FIELDS[i].Unit.Y);
				//unit_0.setWidth(Current_Status.SCREEN_FIELDS[i].Unit.Width);
				//unit_0.setHeight(Current_Status.SCREEN_FIELDS[i].Unit.Height);
				unit_7.resizeToCurrentTextWithAlignment();
				unit_7.invalidate();

				Unicode::snprintfFloat(buffer, 32, "%.0f", (float)(Current_Status.SCREEN_FIELDS[i].ValueDefault));
				Unicode::snprintf(value_7Buffer, 32, "%s", buffer);
				value_7.setXY(Current_Status.SCREEN_FIELDS[i].Value.X, Current_Status.SCREEN_FIELDS[i].Value.Y);
				//value_0.setWidth(Current_Status.SCREEN_FIELDS[i].Value.Width);
				//value_0.setHeight(Current_Status.SCREEN_FIELDS[i].Value.Height);
				value_7.resizeToCurrentTextWithAlignment();
				value_7.invalidate();
				break;
			default:
				break;
		}

	}
}

void Screen1View::tearDownScreen() {
	Screen1ViewBase::tearDownScreen();
}

void Screen1View::handleTickEvent() {
	Unicode::UnicodeChar buffer[16];
	if(Current_Status.SCREEN_FIELDS_CHANGED == true)
	{
		setupScreen();
		Current_Status.SCREEN_FIELDS_CHANGED = false;
	}
//	map_value.invalidate();
//	Unicode::snprintfFloat(buffer, 16, "%.1f", (float)(Current_Status.MAP / 10.0));
//	Unicode::snprintf(map_valueBuffer, 16, "%s", buffer);
//	map_value.resizeToCurrentTextWithAlignment();
//	map_value.invalidate();
//
//	batt_value.invalidate();
//	Unicode::snprintfFloat(buffer, 16, "%.1f", (float)(Current_Status.BATT / 100.0));
//	Unicode::snprintf(batt_valueBuffer, 16, "%s", buffer);
//	batt_value.resizeToCurrentTextWithAlignment();
//	batt_value.invalidate();
//
	Unicode::snprintfFloat(buffer, 16, "%.0f", (float)(Current_Status.TPS / 10.0));
	Unicode::snprintf(value_6Buffer, 16, "%s", buffer);
	value_6.resizeToCurrentTextWithAlignment();
	value_6.invalidate();
//
//	lambda_value.invalidate();
//	Unicode::snprintfFloat(buffer, 16, "%.2f", (float)(Current_Status.LAMBDA1 / 1000.0));
//	Unicode::snprintf(lambda_valueBuffer, 16, "%s", buffer);
//	lambda_value.resizeToCurrentTextWithAlignment();
//	lambda_value.invalidate();
//
//	ect_value.invalidate();
	Unicode::snprintfFloat(buffer, 16, "%.0f", (float)(Current_Status.ECT / 10.0));
	Unicode::snprintf(value_5Buffer, 16, "%s", buffer);
	value_5.resizeToCurrentTextWithAlignment();
	value_5.invalidate();
//
//	iat_value.invalidate();
	Unicode::snprintfFloat(buffer, 16, "%.0f", (float)(Current_Status.IAT / 10.0));
	Unicode::snprintf(value_4Buffer, 16, "%s", buffer);
	value_4.resizeToCurrentTextWithAlignment();
	value_4.invalidate();
//
//	oilp_value.invalidate();
//	Unicode::snprintfFloat(buffer, 16, "%.1f", (float)(Current_Status.OILP / 10.0));
//	Unicode::snprintf(oilp_valueBuffer, 16, "%s", buffer);
//	oilp_value.resizeToCurrentTextWithAlignment();
//	oilp_value.invalidate();
//
//	fuelp_value.invalidate();
//	Unicode::snprintfFloat(buffer, 16, "%.1f", (float)(Current_Status.FUELP / 10.0));
//	Unicode::snprintf(fuelp_valueBuffer, 16, "%s", buffer);
//	fuelp_value.resizeToCurrentTextWithAlignment();
//	fuelp_value.invalidate();

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



	alert_R1.setVisible(false);
	if(Current_Status.OK_R1 == true)
	{
		alert_R1.setColor(touchgfx::Color::getColorFromRGB(0, 255, 0));
		alert_R1.setVisible(true);
	}
	else if(Current_Status.WARNING_R1 == true)
	{
		alert_R1.setColor(touchgfx::Color::getColorFromRGB(255, 140, 0));
		alert_R1.setVisible(true);
	}
	else if(Current_Status.ALERT_R1 == true)
	{
		alert_R1.setColor(touchgfx::Color::getColorFromRGB(255, 0, 0));
		alert_R1.setVisible(true);
	}
	alert_R1.invalidate();

	alert_R2.setVisible(false);
	if(Current_Status.OK_R2 == true)
	{
		alert_R2.setColor(touchgfx::Color::getColorFromRGB(0, 255, 0));
		alert_R2.setVisible(true);
	}
	else if(Current_Status.WARNING_R2 == true)
	{
		alert_R2.setColor(touchgfx::Color::getColorFromRGB(255, 140, 0));
		alert_R2.setVisible(true);
	}
	else if(Current_Status.ALERT_R2 == true)
	{
		alert_R2.setColor(touchgfx::Color::getColorFromRGB(255, 0, 0));
		alert_R2.setVisible(true);
	}
	alert_R2.invalidate();

	alert_R3.setVisible(false);
	if(Current_Status.OK_R3 == true)
	{
		alert_R3.setColor(touchgfx::Color::getColorFromRGB(0, 255, 0));
		alert_R3.setVisible(true);
	}
	else if(Current_Status.WARNING_R3 == true)
	{
		alert_R3.setColor(touchgfx::Color::getColorFromRGB(255, 140, 0));
		alert_R3.setVisible(true);
	}
	else if(Current_Status.ALERT_R3 == true)
	{
		alert_R3.setColor(touchgfx::Color::getColorFromRGB(255, 0, 0));
		alert_R3.setVisible(true);
	}
	alert_R3.invalidate();

	alert_R4.setVisible(false);
	if(Current_Status.OK_R4 == true)
	{
		alert_R4.setColor(touchgfx::Color::getColorFromRGB(0, 255, 0));
		alert_R4.setVisible(true);
	}
	else if(Current_Status.WARNING_R4 == true)
	{
		alert_R4.setColor(touchgfx::Color::getColorFromRGB(255, 140, 0));
		alert_R4.setVisible(true);
	}
	else if(Current_Status.ALERT_R4 == true)
	{
		alert_R4.setColor(touchgfx::Color::getColorFromRGB(255, 0, 0));
		alert_R4.setVisible(true);
	}
	alert_R4.invalidate();

	alert_L1.setVisible(false);
	if(Current_Status.OK_L1 == true)
	{
		alert_L1.setColor(touchgfx::Color::getColorFromRGB(0, 255, 0));
		alert_L1.setVisible(true);
	}
	else if(Current_Status.WARNING_L1 == true)
	{
		alert_L1.setColor(touchgfx::Color::getColorFromRGB(255, 140, 0));
		alert_L1.setVisible(true);
	}
	else if(Current_Status.ALERT_L1 == true)
	{
		alert_L1.setColor(touchgfx::Color::getColorFromRGB(255, 0, 0));
		alert_L1.setVisible(true);
	}
	alert_L1.invalidate();

	alert_L2.setVisible(false);
	if(Current_Status.OK_L2 == true)
	{
		alert_L2.setColor(touchgfx::Color::getColorFromRGB(0, 255, 0));
		alert_L2.setVisible(true);
	}
	else if(Current_Status.WARNING_L2 == true)
	{
		alert_L2.setColor(touchgfx::Color::getColorFromRGB(255, 140, 0));
		alert_L2.setVisible(true);
	}
	else if(Current_Status.ALERT_L2 == true)
	{
		alert_L2.setColor(touchgfx::Color::getColorFromRGB(255, 0, 0));
		alert_L2.setVisible(true);
	}
	alert_L2.invalidate();

	alert_L3.setVisible(false);
	if(Current_Status.OK_L3 == true)
	{
		alert_L3.setColor(touchgfx::Color::getColorFromRGB(0, 255, 0));
		alert_L3.setVisible(true);
	}
	else if(Current_Status.WARNING_L3 == true)
	{
		alert_L3.setColor(touchgfx::Color::getColorFromRGB(255, 140, 0));
		alert_L3.setVisible(true);
	}
	else if(Current_Status.ALERT_L3 == true)
	{
		alert_L3.setColor(touchgfx::Color::getColorFromRGB(255, 0, 0));
		alert_L3.setVisible(true);
	}
	alert_L3.invalidate();

	alert_L4.setVisible(false);
	if(Current_Status.OK_L4 == true)
	{
		alert_L4.setColor(touchgfx::Color::getColorFromRGB(0, 255, 0));
		alert_L4.setVisible(true);
	}
	else if(Current_Status.WARNING_L4 == true)
	{
		alert_L4.setColor(touchgfx::Color::getColorFromRGB(255, 140, 0));
		alert_L4.setVisible(true);
	}
	else if(Current_Status.ALERT_L4 == true)
	{
		alert_L4.setColor(touchgfx::Color::getColorFromRGB(255, 0, 0));
		alert_L4.setVisible(true);
	}
	alert_L4.invalidate();
	//gauge1.set
	//gauge1.invalidate();

}
