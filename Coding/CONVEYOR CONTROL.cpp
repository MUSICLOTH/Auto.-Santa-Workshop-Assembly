
#define MORTOR_PIN27
#define SENSOR_PIN 33

void setup() {
    pinMode (MORTOR_PIN27, OUTPUT);
    pinMode (SENSOR_PIN, INPUT);
}

void loop () {
    if (digitalRead(SENSOR_PIN) == LOW) {
        digitalWrite(MOTOR_PIN, HIGH);
        delay(800);
        digitalWrite(MOTOR_PIN, LOW);
        delay(1000);
    }
}