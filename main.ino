// Pomenovavanie a nastavovanie pinov
int led = 3;
int sensor = A1;
int motor = 4;
int last = 0;
int tolerancia = 1.4;
int current, i;

// Nastavovanie
void setup() {
  // Nastavovanie typu pinov
  pinMode(led, OUTPUT);
  pinMode(motor, OUTPUT);
  pinMode(sensor, INPUT);
  // Zapinanie LED
  digitalWrite(led, HIGH);
  // Zapinanie konzoly (v pravo hore lupa)
  Serial.begin(9600);
  // Vypinanie motoru
  digitalWrite(motor, LOW);
}

// Základný loop
void loop() {
  current = analogRead(sensor); // Získavania terajšej hodnoty na pine senzora
  
  // Výpis hodnôt na konzolu
  Serial.print("   Last: ");
  Serial.println(last);
  Serial.print("Current: ");
  Serial.println(current);
  
  
  // Udržovanie behu motora, zistovaním, či už prešlo *25 loopov 
  if (i < 25) {
    digitalWrite(motor, HIGH); // Zapinanie motora
    i++; // Zvišovanie loop countu
  } else { // Ak prešlo *25 loopov, tak sa motor vypne
    digitalWrite(motor, LOW); // Vypínanie motoru
  }
  if (current * 1.1 < last) i = 0; // Spúšťanie počítania cykov (mohlo by byť aj pred if podmienkou
  
  last = current; // Nastavovanie terajšej hodnoty na predošlú
  delay(50); // Oneskorenie 50 ms
}
