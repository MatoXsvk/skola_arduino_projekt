void setup() {
  pinMode(13,OUTPUT); //motor
  pinMode(A2,OUTPUT); //UV LED
  pinMode(A1,INPUT);  //fototranzistor
  int a;              //hodnota z fototranzistora
  Serial.begin(9600); //to nvm co robi
}

void loop() {
  
  int a;                    //znova lebo to nechcelo ist
  delay(50);                //cas medzi meraniami(naj medzi 50-200)
  digitalWrite(A2,0.05);    //spusti UV diodu
  a = analogRead(A1);       //nacita hodnotu z fototranzistora
  Serial.print("  a =  ");  //vypise hodnotu aby som vedel cca kolko mam dat do if
  Serial.println(a);        //fototranz. znizi odpor na 0 ked je zopnutý / svieti nan UV svetlo
  if(a>10){                 //ak bude rozdiel napati Uce = 0 tak moze byt aj a<1(rusenie)(cca 7-20)
    digitalWrite(13,HIGH);  //zapne motor
    delay(50);}             //chvilu ho necha zapnuty
  else {
    digitalWrite(13,LOW); } //vypne motor a pojde znovu
}
