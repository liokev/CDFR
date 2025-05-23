
int pw1 = 2;
int pw2 = 7;
int av1 = 3;
int ar1 = 4;
int av2 = 5;
int ar2 = 6;
int vitesse = 200;


int trig1=30;
int echo1=32;
int duree1;
float distance1;
float meter1;


void avant(){
  digitalWrite(av1, HIGH);
  digitalWrite(ar1, LOW);

  analogWrite(pw1, vitesse);

  digitalWrite(av2, HIGH);
  digitalWrite(ar2, LOW);

  analogWrite(pw2, vitesse);
}

void gauche(){
  digitalWrite(av1, HIGH);
  digitalWrite(ar1, LOW);

  analogWrite(pw1, vitesse);

  digitalWrite(av2, LOW);
  digitalWrite(ar2, HIGH);

  analogWrite(pw2, vitesse);
}

void droite(){
  digitalWrite(av2, HIGH);
  digitalWrite(ar2, LOW);

  analogWrite(pw1, vitesse);

  digitalWrite(av1, LOW);
  digitalWrite(ar1, HIGH);

  analogWrite(pw2, vitesse);
}
void arriere(){
  digitalWrite(av1, LOW);
  digitalWrite(ar1, HIGH);

  analogWrite(pw1, vitesse);

  digitalWrite(av2, LOW);
  digitalWrite(ar2, HIGH);

  analogWrite(pw2, vitesse);
}

void stop(){
  digitalWrite(av1, LOW);
  digitalWrite(ar1, LOW);


  digitalWrite(av2, LOW);
  digitalWrite(ar2, LOW);

}



void setup()
{
   pinMode(pw1, OUTPUT);  
   pinMode(pw2, OUTPUT);
   pinMode(av1, OUTPUT);  
   pinMode(av2, OUTPUT);
   pinMode(ar1, OUTPUT);  
   pinMode(ar2, OUTPUT);

   pinMode(trig1, OUTPUT);  
   pinMode(echo1, INPUT); 

   
    
   Serial.begin(9600);




}

float lireDistance(int trigPin, int echoPin) {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  int duree = pulseIn(echoPin, HIGH, 20000); // timeout 20ms
  return duree * 0.034 / 2;
}

void loop()
{
  distance1 = lireDistance(trig1, echo1);


  Serial.print("Dist1: "); Serial.print(distance1);
  if (distance1 >10)
  {
    avant();
    delay(1000);
    stop();
  }

  else{
    stop();
  }

}