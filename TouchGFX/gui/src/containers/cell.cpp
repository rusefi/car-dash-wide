#include <gui/containers/cell.hpp>
#include <touchgfx/Color.hpp>

#include "main.h"
#include "extern.h"

cell::cell() {

}

void cell::initialize() {
	cellBase::initialize();
}

void cell::setValues(uint8_t cellID) {

	ModuleDef cell = Current_Status.BATTERY_MODULES[cellID];

	Unicode::UnicodeChar buffer[16];

	touchgfx::colortype idColor = cell.ENABLED ? touchgfx::Color::getColorFromRGB(0, 255, 0) : touchgfx::Color::getColorFromRGB(105,105,105);
	touchgfx::colortype valueColor = cell.ENABLED ? touchgfx::Color::getColorFromRGB(255, 255, 255) : touchgfx::Color::getColorFromRGB(105,105,105);
	touchgfx::colortype maxColor = cell.ENABLED ? touchgfx::Color::getColorFromRGB(0,128,0) : touchgfx::Color::getColorFromRGB(255, 255, 255);
	touchgfx::colortype minColor = cell.ENABLED ? touchgfx::Color::getColorFromRGB(255,0,0) : touchgfx::Color::getColorFromRGB(255, 255, 255);

	id.invalidate();
	Unicode::snprintfFloat(buffer, 16, "BMS %.0f", (float) (cellID + 1));
	Unicode::snprintf(idBuffer, 16, "%s", buffer);
	id.resizeToCurrentTextWithAlignment();
	id.setColor(idColor);
	id.invalidate();

	total.invalidate();
	Unicode::snprintfFloat(buffer, 16, "%.2f V", (float) (cell.VOLTAGE / 1000.0));
	Unicode::snprintf(totalBuffer, 16, "%s", buffer);
	total.resizeToCurrentTextWithAlignment();
	total.setColor(idColor);
	total.invalidate();
	//0
	cell_0_voltage.invalidate();
	Unicode::snprintfFloat(buffer, 16, "%.2f V", (float) (cell.CELLS[0] / 1000.0));
	Unicode::snprintf(cell_0_voltageBuffer, 16, "%s", buffer);
	cell_0_voltage.resizeToCurrentTextWithAlignment();
	cell_0_voltage.setColor(cell.HIGHEST_CELL_ID == 0 ? maxColor : cell.LOWEST_CELL_ID == 0 ? minColor : valueColor);
	cell_0_voltage.invalidate();
	//1
	cell_1_voltage.invalidate();
	Unicode::snprintfFloat(buffer, 16, "%.2f V",
			(float) (cell.CELLS[1] / 1000.0));
	Unicode::snprintf(cell_1_voltageBuffer, 16, "%s", buffer);
	cell_1_voltage.resizeToCurrentTextWithAlignment();
	cell_1_voltage.setColor(cell.HIGHEST_CELL_ID == 1 ? maxColor : cell.LOWEST_CELL_ID == 1 ? minColor : valueColor);
	cell_1_voltage.invalidate();
	//2
	cell_2_voltage.invalidate();
	Unicode::snprintfFloat(buffer, 16, "%.2f V",
			(float) (cell.CELLS[2] / 1000.0));
	Unicode::snprintf(cell_2_voltageBuffer, 16, "%s", buffer);
	cell_2_voltage.resizeToCurrentTextWithAlignment();
	cell_2_voltage.setColor(cell.HIGHEST_CELL_ID == 2 ? maxColor : cell.LOWEST_CELL_ID == 2 ? minColor : valueColor);
	cell_2_voltage.invalidate();
	//3
	cell_3_voltage.invalidate();
	Unicode::snprintfFloat(buffer, 16, "%.2f V",
			(float) (cell.CELLS[4] / 1000.0));
	Unicode::snprintf(cell_3_voltageBuffer, 16, "%s", buffer);
	cell_3_voltage.resizeToCurrentTextWithAlignment();
	cell_3_voltage.setColor(cell.HIGHEST_CELL_ID == 3 ? maxColor : cell.LOWEST_CELL_ID == 3 ? minColor : valueColor);
	cell_3_voltage.invalidate();

	//4
	cell_4_voltage.invalidate();
	Unicode::snprintfFloat(buffer, 16, "%.2f V",
			(float) (cell.CELLS[4] / 1000.0));
	Unicode::snprintf(cell_4_voltageBuffer, 16, "%s", buffer);
	cell_4_voltage.resizeToCurrentTextWithAlignment();
	cell_4_voltage.setColor(cell.HIGHEST_CELL_ID == 4 ? maxColor : cell.LOWEST_CELL_ID == 4 ? minColor : valueColor);
	cell_4_voltage.invalidate();

	//5
	cell_5_voltage.invalidate();
	Unicode::snprintfFloat(buffer, 16, "%.2f V",
			(float) (cell.CELLS[5] / 1000.0));
	Unicode::snprintf(cell_5_voltageBuffer, 16, "%s", buffer);
	cell_5_voltage.resizeToCurrentTextWithAlignment();
	cell_5_voltage.setColor(cell.HIGHEST_CELL_ID == 5 ? maxColor : cell.LOWEST_CELL_ID == 5 ? minColor : valueColor);
	cell_5_voltage.invalidate();

	//6
	cell_6_voltage.invalidate();
	Unicode::snprintfFloat(buffer, 16, "%.2f V",
			(float) (cell.CELLS[6] / 1000.0));
	Unicode::snprintf(cell_6_voltageBuffer, 16, "%s", buffer);
	cell_6_voltage.resizeToCurrentTextWithAlignment();
	cell_6_voltage.setColor(cell.HIGHEST_CELL_ID == 6 ? maxColor : cell.LOWEST_CELL_ID == 6 ? minColor : valueColor);
	cell_6_voltage.invalidate();

	//7
	cell_7_voltage.invalidate();
	Unicode::snprintfFloat(buffer, 16, "%.2f V",
			(float) (cell.CELLS[7] / 1000.0));
	Unicode::snprintf(cell_7_voltageBuffer, 16, "%s", buffer);
	cell_7_voltage.resizeToCurrentTextWithAlignment();
	cell_7_voltage.setColor(cell.HIGHEST_CELL_ID == 7 ? maxColor : cell.LOWEST_CELL_ID == 7 ? minColor : valueColor);
	cell_7_voltage.invalidate();

	//8
	cell_8_voltage.invalidate();
	Unicode::snprintfFloat(buffer, 16, "%.2f V",
			(float) (cell.CELLS[8] / 1000.0));
	Unicode::snprintf(cell_8_voltageBuffer, 16, "%s", buffer);
	cell_8_voltage.resizeToCurrentTextWithAlignment();
	cell_8_voltage.setColor(cell.HIGHEST_CELL_ID == 8 ? maxColor : cell.LOWEST_CELL_ID == 8 ? minColor : valueColor);
	cell_8_voltage.invalidate();

	//9
	cell_9_voltage.invalidate();
	Unicode::snprintfFloat(buffer, 16, "%.2f V",
			(float) (cell.CELLS[9] / 1000.0));
	Unicode::snprintf(cell_9_voltageBuffer, 16, "%s", buffer);
	cell_9_voltage.resizeToCurrentTextWithAlignment();
	cell_9_voltage.setColor(cell.HIGHEST_CELL_ID == 9 ? maxColor : cell.LOWEST_CELL_ID == 8 ? minColor : valueColor);
	cell_9_voltage.invalidate();

	//10
	cell_10_voltage.invalidate();
	Unicode::snprintfFloat(buffer, 16, "%.2f V",
			(float) (cell.CELLS[10] / 1000.0));
	Unicode::snprintf(cell_10_voltageBuffer, 16, "%s", buffer);
	cell_10_voltage.resizeToCurrentTextWithAlignment();
	cell_10_voltage.setColor(cell.HIGHEST_CELL_ID == 10 ? maxColor : cell.LOWEST_CELL_ID == 10 ? minColor : valueColor);
	cell_10_voltage.invalidate();

	//11
	cell_11_voltage.invalidate();
	Unicode::snprintfFloat(buffer, 16, "%.2f V",
			(float) (cell.CELLS[11] / 1000.0));
	Unicode::snprintf(cell_11_voltageBuffer, 16, "%s", buffer);
	cell_11_voltage.resizeToCurrentTextWithAlignment();
	cell_11_voltage.setColor(cell.HIGHEST_CELL_ID == 11 ? maxColor : cell.LOWEST_CELL_ID == 11 ? minColor : valueColor);
	cell_11_voltage.invalidate();

	//12
	cell_12_voltage.invalidate();
	Unicode::snprintfFloat(buffer, 16, "%.2f V",
			(float) (cell.CELLS[12] / 1000.0));
	Unicode::snprintf(cell_12_voltageBuffer, 16, "%s", buffer);
	cell_12_voltage.resizeToCurrentTextWithAlignment();
	cell_12_voltage.setColor(cell.HIGHEST_CELL_ID == 12 ? maxColor : cell.LOWEST_CELL_ID == 12 ? minColor : valueColor);
	cell_12_voltage.invalidate();

	//13
	cell_13_voltage.invalidate();
	Unicode::snprintfFloat(buffer, 16, "%.2f V",
			(float) (cell.CELLS[13] / 1000.0));
	Unicode::snprintf(cell_13_voltageBuffer, 16, "%s", buffer);
	cell_13_voltage.resizeToCurrentTextWithAlignment();
	cell_13_voltage.setColor(cell.HIGHEST_CELL_ID == 13 ? maxColor : cell.LOWEST_CELL_ID == 13 ? minColor : valueColor);
	cell_13_voltage.invalidate();

	//14
	cell_14_voltage.invalidate();
	Unicode::snprintfFloat(buffer, 16, "%.2f V",
			(float) (cell.CELLS[14] / 1000.0));
	Unicode::snprintf(cell_14_voltageBuffer, 16, "%s", buffer);
	cell_14_voltage.resizeToCurrentTextWithAlignment();
	cell_14_voltage.setColor(cell.HIGHEST_CELL_ID == 14 ? maxColor : cell.LOWEST_CELL_ID == 14 ? minColor : valueColor);
	cell_14_voltage.invalidate();

	//15
	cell_15_voltage.invalidate();
	Unicode::snprintfFloat(buffer, 16, "%.2f V",
			(float) (cell.CELLS[15] / 1000.0));
	Unicode::snprintf(cell_15_voltageBuffer, 16, "%s", buffer);
	cell_15_voltage.resizeToCurrentTextWithAlignment();
	cell_15_voltage.setColor(cell.HIGHEST_CELL_ID == 15 ? maxColor : cell.LOWEST_CELL_ID == 15 ? minColor : valueColor);
	cell_15_voltage.invalidate();

	//temp 0
	temp_0.invalidate();
	Unicode::snprintfFloat(buffer, 16, "%.1f °C",
			(float) (cell.TEMPS[0]));
	Unicode::snprintf(temp_0Buffer, 16, "%s", buffer);
	temp_0.resizeToCurrentTextWithAlignment();
	temp_0.setColor(valueColor);
	temp_0.invalidate();

	//temp 1
	temp_1.invalidate();
	Unicode::snprintfFloat(buffer, 16, "%.1f °C",
			(float) (cell.TEMPS[1]));
	Unicode::snprintf(temp_1Buffer, 16, "%s", buffer);
	temp_1.resizeToCurrentTextWithAlignment();
	temp_1.setColor(valueColor);
	temp_1.invalidate();

	//temp 2
	temp_2.invalidate();
	Unicode::snprintfFloat(buffer, 16, "%.1f °C",
			(float) (cell.TEMPS[2]));
	Unicode::snprintf(temp_2Buffer, 16, "%s", buffer);
	temp_2.resizeToCurrentTextWithAlignment();
	temp_2.setColor(valueColor);
	temp_2.invalidate();

}
