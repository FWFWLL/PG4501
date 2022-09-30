void setup() {
	Serial.begin(9600);
	pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
	Serial.println("光");
	digitalWrite(LED_BUILTIN, HIGH);
	delay(1000);

	Serial.println("闇");
	digitalWrite(LED_BUILTIN, HIGH);
	delay(1000);
}
