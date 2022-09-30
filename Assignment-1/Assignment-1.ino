#define MAX_SPEED 255

const int button = 2;

const int en1 = 5;
const int in1 = 4;
const int in2 = 3;

int buttonState;

void setup() {
	Serial.begin(9600);
	
	// Inputs
	pinMode(button, INPUT);

	// Outputs
	pinMode(en1, OUTPUT);
	pinMode(in1, OUTPUT);
	pinMode(in2, OUTPUT);
}

void loop() {
	analogWrite(en1, MAX_SPEED);
	buttonState = digitalRead(button);

	if(buttonState == HIGH) {
		Serial.println("Clockwise");

		digitalWrite(in1, LOW);
		digitalWrite(in2, HIGH);
	} else {
		Serial.println("Counter-Clockwise");

		digitalWrite(in1, HIGH);
		digitalWrite(in2, LOW);
	}
}
