// Define the array of GPIO pins wired to the HDMI connector
int gpioPins[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 22, 26, 27 };
int numPins = sizeof(gpioPins) / sizeof(gpioPins[0]);

// ADC pin (GP28)
const int adcPin = 28;

void setup() {
  // Initialize serial communication
  Serial.begin(115200);

  for (int i = 0; i < numPins; i++) {
    pinMode(gpioPins[i], OUTPUT);
    digitalWrite(gpioPins[i], HIGH);
  }

  // Initialize the ADC pin
  pinMode(adcPin, INPUT);
}

void loop() {
  for (int i = 0; i < numPins; i++) {
    digitalWrite(gpioPins[i], LOW);

    // Wait for a few seconds
    delay(2000);

    // Measure the ADC value from GP28 (ADC2)
    int adcValue = analogRead(adcPin);

    // Print the ADC value to the serial console
    Serial.print("GPIO Pin ");
    Serial.print(gpioPins[i]);
    Serial.print(" ADC2 Value: ");
    Serial.println(adcValue);

    digitalWrite(gpioPins[i], HIGH);

    // Wait for a short period before moving to the next pin
    delay(500);
  }
}
