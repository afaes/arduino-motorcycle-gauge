void setup() {
  
  //analogWrite(A2,LOW);
  //Wire.setClock(700000);
  Serial.begin(9600);

  // Initiate u8g2 
  u8g2.begin();
  
  // Initate components
  
  
  Tachometer::init(PB12); // iniate tachometer on pin #2
  Odometer::init(PB13); // initate odometer on pin #3
  Fuelmeter::init(PA3,PB14);
  //SceneManager::init(2); // iniate Navigation Manager on pin #3

  
}
