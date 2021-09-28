
String us;
int pin1 = 2;
int pin2 = 4;
int pin3 = 5;
int pin4 =7;
int pin5 = 8;
void setup() {
  Serial.begin(9600);
  pinMode(pin1, OUTPUT);
  pinMode(pin2, OUTPUT); 
  pinMode(pin3, OUTPUT);
}
void loop() {
  
  if(Serial.available()>0){
    us = Serial.readString();
    
    Serial.println(us);
    Serial.println(us[1]);
    Serial.println(int(us[1]));
    
    if(int(us[0]) == 49){
      Serial.println("fig 1");
      digitalWrite(pin1, HIGH);
    }
    else{
      digitalWrite(pin1, LOW);
      Serial.println("one low");
      }
    if(int(us[1]) == 49){
      Serial.println("fig 2");
      digitalWrite(pin2, HIGH);
    }
    else{
      digitalWrite(pin2, LOW);
      Serial.println("two low");
      
      }
    if(int(us[2]) == 49){
      Serial.println("fig 3");
      digitalWrite(pin3, HIGH);
    }
    else{
      digitalWrite(pin3, LOW);
      Serial.println("three low");
      }
    if(int(us[3]) == 49){
      Serial.println("fig 4");
      digitalWrite(pin4, HIGH);
    }
    else{
      digitalWrite(pin4, LOW);
      Serial.println("four low");
      }
    if(int(us[4]) == 49){
      Serial.println("fig 5");
      digitalWrite(pin5, HIGH);
    }
    else{
      digitalWrite(pin5, LOW);
      Serial.println("five low");
      }
  }
}
