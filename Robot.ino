
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

int trig2=34;
int echo2=36;
int duree2;
float distance2;
float meter2;

int trig3=38;
int echo3=40;
int duree3;
float distance3;
float meter3;

int trig4=42;
int echo4=44;
int duree4;
float distance4;
float meter4;

int equipe = 10;

int servos1 = 8;
int servos2 = 9;

int depart = 13;

int jaunedroite = 22;
int blancdroite = 24;
int jaunegauche = 26;
int blancgauche = 28;




void arriere(){
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
void avant(){
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

float lireDistance(int trigPin, int echoPin) {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  int duree = pulseIn(echoPin, HIGH); // timeout 20ms
  return duree * 0.034 / 2;
}

void jaune(){
  avant();
  delay(10000);
  stop();
  delay(50);
  gauche()
  delay(1000);
  stop();
  delay(50);
  avant();
  delay(1000);
  stop()
  delay(10);

}


void bleu(){
  avant();
  delay(10000);
  stop();
  delay(50);
  droite()
  delay(1000);
  stop();
  delay(50);
  avant();
  delay(1000);
  stop()
  delay(10);

}


void arret(){
  distance1 = lireDistance(trig1, echo1);
  distance2 = lireDistance(trig2, echo2);
  distance3 = lireDistance(trig3, echo3);
  distance4 = lireDistance(trig4, echo4);


  if ((distance1 >10) && (distance2 > 10))
  {
    avant();
    delay(1000);
    stop();
  }
  else if ((distance1 >10) && (distance2 < 10))
  {
    gauche();
    delay(1000);
    stop();
  }
  else if ((distance1 <10) && distance2 > 10)
  {
    droite();
    delay(1000);
    stop();
  }
  else{
    stop();
  }

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
   pinMode(trig2, OUTPUT);  
   pinMode(echo2, INPUT); 
   pinMode(trig3, OUTPUT);  
   pinMode(echo3, INPUT);
   pinMode(trig4, OUTPUT);  
   pinMode(echo4, INPUT); 

   pinMode(equipe, INPUT);  
   pinMode(depart, INPUT);
   pinMode(servos1, OUTPUT);  
   pinMode(servos, OUTPUT);
   
   Serial.begin(9600);

}


void loop()
{
  distance1 = lireDistance(trig1, echo1);
  distance2 = lireDistance(trig2, echo2);
  distance3 = lireDistance(trig3, echo3);
  distance4 = lireDistance(trig4, echo4);

  Serial.print("Dist1: "); Serial.print(distance1);
  Serial.print(" | Dist2: "); Serial.print(distance2);
  Serial.print(" | Dist3: "); Serial.print(distance3);
  Serial.print(" | Dist4: "); Serial.println(distance4);

  if ((distance1 >10) && (distance2 > 10))
  {
    avant();
    delay(1000);
    stop();
  }
  else if ((distance1 >10) && (distance2 < 10))
  {
    gauche();
    delay(1000);
    stop();
  }
  else if ((distance1 <10) && distance2 > 10)
  {
    droite();
    delay(1000);
    stop();
  }
  else{
    stop();
  }

}



