#include "pitches.h"
#include <Time.h>
#include <TimeLib.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ST7789.h>

#define TIME_HEADER "T"
#define TIME_REQUEST 7

#define TFT_CS 10
#define TFT_RST 9
#define TFT_DC 8

Adafruit_ST7789 tft(TFT_CS, TFT_DC, TFT_RST);

#define BUZZER 2

const char* xivPasta = "Have you heard of the critically acclaimed MMORPG Final Fantasy XIV? With an expanded free trial which you can play through the entirety of A Realm Reborn and the award winning Heavensward expansion up to level 60 for free with no restrictions on playtime.";

int notes[] = {
	NOTE_C6,
	NOTE_DS6,
	NOTE_F6,
	NOTE_FS6,
	NOTE_F6,
	NOTE_DS6,
	NOTE_C6,
	NOTE_AS5,
	NOTE_D6,
	NOTE_C6,
};

int durations[] = {
	400,
	400,
	400,
	400,
	400,
	400,
	1200,
	200,
	300,
	1200,
};

void setup(void) {
	Serial.begin(9600);

	Serial.println("Assignment 2: Intruder Alarm");

	Serial.print("Compiled: ");
	Serial.print(__DATE__);
	Serial.print(" - ");
	Serial.println(__TIME__);

	set_time_to_compile_time();

	tft.init(135, 240);

	pinMode(BUZZER, OUTPUT);
}

void loop(void) {
	if(timeStatus() != timeNotSet) {
		drawTime();
	}

	// amogus();
	delay(1000);
}

const char month_names[] = "JanFebMarAprMayJunJulAugSepOctNovDec";

// Function to set time to compile time using compiler macros
void set_time_to_compile_time(void) {
	// TIME
	int hr, min, sec;
	sscanf(__TIME__, "%d:%d:%d", &hr, &min, &sec);

	// DATE
	char s_month[5];
	int day, yr;
	sscanf(__DATE__, "%s %d %d", s_month, &day, &yr);

	int month = 1 + (strstr(month_names, s_month) - month_names) / 3;

	setTime(hr, min, sec, day, month, yr);
}

void drawText(const char* text, const int size, const uint16_t color) {
	tft.setCursor(0, 0);
	tft.setTextSize(size);
	tft.setTextColor(color);
	tft.setTextWrap(true);
	tft.print(text);
}

void drawTime(void) {
	tft.fillScreen(ST77XX_BLACK);

	tft.setTextColor(ST77XX_WHITE);
	tft.setCursor(0, 0);
	tft.setTextSize(10);
	tft.setTextWrap(false);

	tft.println(hour());
	drawDigits(minute());
	drawDigits(second());
}

void drawDigits(int digits) {
	if(digits < 10)
		tft.print("0");

	tft.println(digits);
}

void amogus(void) {
	for(int note = 0; note < sizeof(notes) / sizeof(notes[0]); note++) {
		tone(BUZZER, notes[note], durations[note] / 2);
		delay(durations[note]);
	}
}
