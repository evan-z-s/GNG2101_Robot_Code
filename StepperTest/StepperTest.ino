const int direction = 5;
const int pulse = 7;
const int topSpeed = 70; //Adjust this number to cap top speed

long interval = 250;
long interval2 = 40;
long previousMillis = 0;
long askel = 1; //This sets acceleration. Faster constant acceleration reduces top speed.
//Decreasing acceleration would be effective to get to high rpm as fast as possible.

//Set outputs and write direction to LOW
void setup(){
  pinMode (pulse, OUTPUT);
  pinMode (direction, OUTPUT);
  digitalWrite(direction, LOW);
}

void loop(){
  unsigned long currentMillis = millis(); 
  digitalWrite(pulse, HIGH);
  delayMicroseconds(interval);
  digitalWrite(pulse, LOW);
  delayMicroseconds(interval);

  if(currentMillis - previousMillis > interval2) {
    previousMillis = currentMillis;
    if (interval > topSpeed) {
      interval = interval - askel;
    }
  }
}