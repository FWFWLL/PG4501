#define POTENTIOMETER_PIN A0
#define LED_PIN 9

int sensorValue = 0;
int outputValue = 0;

void setup() {
	Serial.begin(9600);

	pinMode(POTENTIOMETER_PIN, INPUT);
	pinMode(LED_PIN, OUTPUT);
}

void loop() {
	sensorValue = analogRead(POTENTIOMETER_PIN);

	outputValue = map(sensorValue, 0, 1023, 0, 255);
	analogWrite(LED_PIN, outputValue);

	Serial.print(sensorValue);
	Serial.print(" - ");
	Serial.println(outputValue);

	delay(2);
}
