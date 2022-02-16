int a;                                        // hodnota z fototranzistora
int dsm = 50;                                 // dlzka spustenia motora
int cakanie = 75;                             // cakanie, kym sa znova moze zaktivovat senzor
int i = dsm + cakanie + 1;                    // Casovanie motora
int motor = 13;                               // |
int FTN = A1;                                 // Nastavovanie pinov
int UV = A2;                                  // |
int resetPin = 12;                            //  Nastavenie resetovacieho pinu
int refreshArduinoTime = 30;                  // Cas resetovania arduina v min

void setup() {
  digitalWrite(resetPin, HIGH);
  pinMode(resetPin, OUTPUT);                  // nastavovanie resetovacieho pinu
  pinMode(motor, OUTPUT);                     // motor
  pinMode(UV, OUTPUT);                        // UV LED
  pinMode(FTN, INPUT);                        // fototranzistor

  Serial.begin(9600);                         // spustenie serial konzole
  digitalWrite(UV, 0.05);                     // spusti UV diodu
}

void loop() {
  a = analogRead(FTN);                        // nacita hodnotu z fototranzistora
  
  Serial.print("  a =  ");                    // vypise hodnotu aby som vedel cca kolko mam dat do if
  Serial.println(a);                          // fototranz. znizi odpor na 0 ked je zopnutý / svieti nan UV svetlo
  
  if (i < dsm)                                // Udržovanie behu motora, zistovaním, či už prešlo *dsm loopov 
    digitalWrite(motor, HIGH);                // Zapinanie motora 
  
   else                                       // Ak prešlo *dsm loopov, tak sa motor vypne
    digitalWrite(motor, LOW);                 // Vypínanie motor
  
  if (a > 10 &&                               // ak bude rozdiel napati Uce = 0 tak moze byt aj a<1(rusenie)(cca 7-20)
      i > (dsm + cakanie))                    // Spustenie pocitania, podla podmienky (a < 10), ked uz presla doba cakania
    i = 0;                                    // Spúšťanie počítania cykov (mohlo by byť aj pred if podmienkou
  
  i++;                                        // Zvišovanie loop countu

  if (millis() > refreshArduinoTime * 60000)  // Kazdych n minut to resetuje arduino, aby sa predislo zaseknutiu
    digitalWrite(resetPin, LOW);
    
  delay(50);                                  // cas medzi meraniami(naj medzi 50-200)
}
