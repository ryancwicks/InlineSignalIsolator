/**
 * RS485 buffer logic. 
 * 
 * It reads on one port, and sends on another.
 * 
 */
const int SERIAL1_DE = 2;
const int SERIAL2_DE = 11;
const int LED = 13;

void setup() {
  // put your setup code here, to run once:
  Serial1.begin (115200);
  Serial2.begin (115200);

  pinMode(SERIAL1_DE, OUTPUT);
  digitalWrite(SERIAL1_DE, LOW);
  pinMode(SERIAL2_DE, OUTPUT);
  digitalWrite(SERIAL2_DE, LOW);
  pinMode(LED, OUTPUT);
  digitalWrite(LED, HIGH);
}

void loop() {
  if (Serial1.available() > 0) {
    delayMicroseconds(100);
    digitalWrite(SERIAL2_DE, HIGH);
    digitalWrite(LED, LOW);
    while(Serial1.available() > 0) {
      Serial2.write(Serial1.read());
    }
    Serial2.flush();
    delayMicroseconds(100);
    digitalWrite(LED, HIGH);
    digitalWrite(SERIAL2_DE, LOW);
  }

  if (Serial2.available() > 0) {
    delayMicroseconds(100);
    digitalWrite(SERIAL1_DE, HIGH);
    digitalWrite(LED, LOW);
    while (Serial2.available() > 0) {
      Serial1.write(Serial2.read());
    }
    Serial1.flush();
    delayMicroseconds(100);
    digitalWrite(LED, HIGH);
    digitalWrite(SERIAL1_DE, LOW);
  }
}
