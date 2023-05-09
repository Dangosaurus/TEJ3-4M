int pumpTwoPin = 6; // pin # for pump two
int wateringTime = 3000; // seconds the pump will water the plants
int pumpHesitation = 1000; // time between turning on pump one and two
void setup() {
  // declare the ledPin as an OUTPUT:
   Serial.begin(9600);  
   pinMode(pumpOnePin, OUTPUT);
   pinMode(pumpTwoPin, OUTPUT);
}
void water (){ //watering function

    digitalWrite(pumpOnePin, HIGH); //turn om pump 1 
    delay(pumpHesitation); //delay for x seconds
    digitalWrite(pumpTwoPin, HIGH); //turn on pump 2 
    delay(wateringTime); //delay for x seconds
    digitalWrite(pumpOnePin, LOW); //turn off both
    digitalWrite(pumpTwoPin, LOW); //clear system
}
void loop() {
  sensorValue = analogRead(sensorPin);      // read the value from the sensor:
  delay(1000);          //delay to make sure value is read
  Serial.print("sensor = " );        //print the value of the sensor               
  Serial.println(sensorValue);  
  Serial.print("timer ="); //print timer value
  Serial.println(timer);   
  
  if (sensorValue > 1000 || timer > maxtime){ //checks if the plant hasn't been watered recently or if the plant is dry
      water(); //waters plant
      timer = 0; //reset timer
  }
  else{
      digitalWrite(pumpOnePin, LOW); //makes sure pumps are off
      digitalWrite(pumpTwoPin, LOW);
      timer = timer + 1; // constantly updates timer value so it increases
  }    
          
}

