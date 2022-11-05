#include "pitches.h"
#include <Adafruit_GFX.h>
#include <Adafruit_ST7789.h>

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

	// 240x135 TFT BEGIN
	Serial.print("Initializing 240x135 TFT...");

	tft.init(135, 240);

	tft.fillScreen(ST77XX_BLACK);

	drawText(xivPasta, ST77XX_WHITE);

	Serial.println(" Finished");
	// 240x135 TFT END

	pinMode(BUZZER, OUTPUT);
}

#define arrlen(a) sizeof(a) / sizeof(a[0])

void loop(void) {
}

void drawText(const char* text, const uint16_t color) {
	tft.setCursor(0, 0);
	tft.setTextColor(color);
	tft.setTextWrap(true);
	tft.print(text);
}

void amogus(void) {
	for(int note = 0; note < arrlen(notes); note++) {
		tone(BUZZER, notes[note], durations[note] / 2);
		delay(durations[note]);
	}
}
