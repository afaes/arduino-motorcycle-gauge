namespace SceneManager{

  int pin = 0;
  double timer = 0;
  bool currentState = true;
  int currentScene = 0;
  
  unsigned long lastTime = millis();
  unsigned long lastTimeFuel = millis();
  
  void next(){
    //Serial.println("next()");
    currentScene++;
    if(currentScene == 2)
      currentScene = 0;
  }

  void action(){
    //Serial.println(F("action()");
  }
  
  void draw(){

    
    if(millis() - lastTime > 16){

      // update tachometer 
      // just for graphics 
      Tachometer::update();

       
      lastTime = millis();
      //Serial.println("draw");
      switch(currentScene){
        case 0: 
          SceneMain::draw();  
      }

      // read fuel level every 
      
      if(millis() - lastTimeFuel   > 1000){

        Fuelmeter::update();
        lastTimeFuel = millis();
      }
    }

    
    
  }

  void onButton(){
    //Serial.print("button ");
    double _time = millis()-timer;
    int state = digitalRead(SceneManager::pin);
    if(state == 0 && SceneManager::currentState == true){
      timer = millis();
      SceneManager::currentState=false;
    }
    if(state == 1 && SceneManager::currentState == false){
      
      //Serial.print("time");
      //Serial.println(_time);
      timer = millis();
      if(_time < 500){
        SceneManager::next();
      }
      if(_time>500){
        SceneManager::action();
      }
      
      SceneManager::currentState = true;
    }
  }
  
  void init ( int pin ){
    SceneManager::pin = pin;
    attachInterrupt(digitalPinToInterrupt(pin), onButton, CHANGE);
  }

  
  
}
