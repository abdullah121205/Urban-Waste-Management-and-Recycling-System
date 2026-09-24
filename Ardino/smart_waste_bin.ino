#define TRIG 5
#define ECHO 18
#define IR_PIN 4
#define MOISTURE_PIN 34

int mode = 0; 

void setup() {
  Serial.begin(115200);

  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);
  pinMode(IR_PIN, INPUT);

  Serial.println("Type 'm' for Monitor, 'p' for Plotter");
}

void loop() {

  if (Serial.available()) {
    char input = Serial.read();

    if (input == 'm') {
      mode = 0;
      Serial.println("Switched to MONITOR mode");
    }
    else if (input == 'p') {
      mode = 1;
      Serial.println("Switched to PLOTTER mode");
    }
  }

  int ir = digitalRead(IR_PIN);

  if (ir == LOW) {

    // -------- ULTRASONIC --------
    long duration;
    float distance;

    digitalWrite(TRIG, LOW);
    delayMicroseconds(2);

    digitalWrite(TRIG, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIG, LOW);

    duration = pulseIn(ECHO, HIGH);
    distance = duration * 0.034 / 2;

    // -------- MOISTURE --------
    int moisture = analogRead(MOISTURE_PIN);

    // -------- OUTPUT --------
    if (mode == 0) {

      Serial.println("Waste Detected!");

      Serial.print("Distance: ");
      Serial.print(distance);
      Serial.println(" cm");

      if (distance < 10) {
        Serial.println("Bin Status: FULL");
      }
      else {
        Serial.println("Bin Status: AVAILABLE");
      }

      Serial.print("Moisture Value: ");
      Serial.println(moisture);

      if (moisture < 2000) {
        Serial.println("Type: WET WASTE");
      }
      else {
        Serial.println("Type: DRY WASTE");
      }

      Serial.println("======================");
    }

    else {

      Serial.print(distance);
      Serial.print(" ");
      Serial.print(moisture);
      Serial.print(" ");
      Serial.println(ir);
    }

    delay(3000);
  }

  else {

    if (mode == 0) {
      Serial.println("Waiting for waste...");
    }

    delay(500);
  }
}
