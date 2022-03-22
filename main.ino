int sensor = A1;
int UV = 5;
int motor = 9;
float avg = 0;
bool on = false;

void setup() {
  pinMode(sensor, INPUT);
  pinMode(UV, OUTPUT);
  pinMode(motor, OUTPUT);
  Serial.begin(9600);
  analogWrite(UV, 200);
  avg = (float) analogRead(sensor);
}

void loop() {
  int a = analogRead(sensor);
if (a < 1 || a < a * 0.1 || a < avg * 0.1) {
    on  = true;
    avg = (avg * 500 + a) / 501;
    digitalWrite(motor, HIGH);
    delay(1000);
  } else { 
    on = false;
    avg = (avg * 100 + a) / 101;
    digitalWrite(motor, LOW);
  }

  Serial.println("Val: " + (String) a + " Avg: " + (String) avg + " ON: " + (String) on);
  
}
