void setup() {
  pinMode(13,OUTPUT); //motor
  pinMode(A2,OUTPUT); //UV LED
  pinMode(A1,INPUT);  //fototranzistor
  int a;              //hodnota z fototranzistora
}

void loop() {
  int a;                    //znova lebo to nechcelo ist
  digitalWrite(A2,0.05);    //spusti UV diodu
  a = analogRead(A1);       //nacita hodnotu z fototranzistora
  Serial.print("  i =  ");  //vypise hodnotu aby som vedel cca kolko mam dat do if
  Serial.println(A1);       //fototranz. znizi odpor na 0 ked je zopnutý / svieti nan UV svetlo
  if(a<5){                  //ak bude rozdiel napati Uce = 0 tak moze byt aj a<1(rusenie)
    digitalWrite(13,HIGH);  //zapne motor
    delay(50);}            //chvilu ho necha zapnuty
  else {
    digitalWrite(13,LOW); } //vypne motor a pojde znovu
}
