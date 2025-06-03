int pw1 = 2;
int pw2 = 7;
int av1 = 3;
int ar1 = 4;
int av2 = 5;
int ar2 = 6;
int vitesse1 = 190;
int vitesse2 = 200;

int trig1 = 30;
int echo1 = 32;
int duree1;
float distance1;
float meter1;

int trig2 = 34;
int echo2 = 36;
int duree2;
float distance2;
float meter2;

int trig3 = 38;
int echo3 = 40;
int duree3;
float distance3;
float meter3;

int trig4 = 42;
int echo4 = 44;
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

float t_echo_AG;
float t_echo_AD;
float t_trig_AG;
float t_trig_AD;

volatile float distance_AG = 100;
volatile float distance_AD = 100;

int etat_haut_AG = 0;
int etat_haut_AD = 0;

float t_echo_DG;
float t_echo_DD;
float t_trig_DG;
float t_trig_DD;

volatile float distance_DG = 100;
volatile float distance_DD = 100;


int etat_haut_DG = 0;
int etat_haut_DD = 0;
volatile long T_affichage = 0;

int debut = 0;
void arierre() {
  digitalWrite(av1, HIGH);
  digitalWrite(ar1, LOW);

  analogWrite(pw1, vitesse1);

  digitalWrite(av2, HIGH);
  digitalWrite(ar2, LOW);

  analogWrite(pw2, vitesse2);
}

void droite() {
  digitalWrite(av1, HIGH);
  digitalWrite(ar1, LOW);

  analogWrite(pw1, vitesse1);

  digitalWrite(av2, LOW);
  digitalWrite(ar2, HIGH);

  analogWrite(pw2, vitesse2);
}

void gauche() {
  digitalWrite(av2, HIGH);
  digitalWrite(ar2, LOW);

  analogWrite(pw1, vitesse1);

  digitalWrite(av1, LOW);
  digitalWrite(ar1, HIGH);

  analogWrite(pw2, vitesse2);
}

void avant() {
  
  digitalWrite(av1, LOW);
  digitalWrite(ar1, HIGH);

  analogWrite(pw1, vitesse1);
  
  digitalWrite(av2, LOW);
  digitalWrite(ar2, HIGH);

  analogWrite(pw2, vitesse2);
}

void stop() {
  digitalWrite(av1, LOW);
  digitalWrite(ar1, LOW);


  digitalWrite(av2, LOW);
  digitalWrite(ar2, LOW);

  analogWrite(pw2, 0);
  analogWrite(pw1, 0);
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
  attachInterrupt(digitalPinToInterrupt(echo1), echo_DG, CHANGE);
  attachInterrupt(digitalPinToInterrupt(echo2), echo_DD, CHANGE);
  attachInterrupt(digitalPinToInterrupt(echo3), echo_AG, CHANGE);
  attachInterrupt(digitalPinToInterrupt(echo4), echo_AD, CHANGE);

  pinMode(equipe, INPUT_PULLUP);
  pinMode(depart, INPUT_PULLUP);
  pinMode(servos1, OUTPUT);
  pinMode(servos2, OUTPUT);
  while (digitalRead(depart) == LOW) {}
  debut = millis();
  Serial.println(debut);
  Serial.begin(9600);
}

// ------- INTERRUPTION ------

void echo_AG() {
  if (digitalRead(echo3) == HIGH) t_echo_AG = micros();
  //if (digitalRead(echo3) == LOW) distance_AG = ((micros() - t_echo_AG) * 0.0343) / 2;
  if (digitalRead(echo3) == LOW) distance_AG = (micros() - t_echo_AG);
}

void echo_AD() {
  if (digitalRead(echo4) == HIGH) t_echo_AD = micros();
  //if (digitalRead(echo4) == LOW) distance_AD = ((micros() - t_echo_AD) * 0.0343) / 2;
   if (digitalRead(echo4) == LOW) distance_AD = (micros() - t_echo_AD);
}

void echo_DG() {
  if (digitalRead(echo1) == HIGH) t_echo_DG = micros();
  //if (digitalRead(echo3) == LOW) distance_AG = ((micros() - t_echo_AG) * 0.0343) / 2;
  if (digitalRead(echo1) == LOW) distance_DG = (micros() - t_echo_DG);
}

void echo_DD() {
  if (digitalRead(echo2) == HIGH) t_echo_DD = micros();
  //if (digitalRead(echo4) == LOW) distance_AD = ((micros() - t_echo_AD) * 0.0343) / 2;
   if (digitalRead(echo2) == LOW) distance_DD = (micros() - t_echo_DD);
}

// ------- LOOP -------

void loop() {



if (((distance_AG < 1000) && (distance_AD < 1000)) ||((distance_DG < 1000) && (distance_DD < 1000))) {
  stop();
  //Serial.println("sonar voit ennemi");
  Serial.println(distance_AG);
  Serial.println(distance_AD);
} 
else {
  if ((millis() - debut)< 500) avant();
  //Serial.println("on lance avant");
  if (((millis() -debut) < 95000) && ((millis() - debut ) > 510)) stop();
  if (((millis() - debut) < 95500) && ((millis() - debut ) > 95000)) arierre();
}


   
if (millis() - debut > 96000) {
  stop();
  vitesse1 = 0;
  vitesse2 = 0;
  while(1);
}
   

  
// fin le prof
  //Serial.println("départ");
  //Serial.println(vitesse1);
  //Serial.println(vitesse2);
  //Serial.println(digitalRead(depart));
  

  // ------------- GESTION DES SONARS ---------------------
  if (etat_haut_AG == 0){
    if((millis() - t_trig_AG) > 60){
      etat_haut_AG = 1;
      digitalWrite(trig3,HIGH);
      t_trig_AG =millis();
         
    }

  }
  if (etat_haut_AG == 1){
    if((millis() - t_trig_AG) > 2){
      etat_haut_AG = 0;
      digitalWrite(trig3,LOW);
      t_trig_AG =millis();
    }
    
  }
  if (etat_haut_AD == 0){
    if((millis() - t_trig_AD) > 60){
      etat_haut_AD = 1;
      digitalWrite(trig4,HIGH);
      t_trig_AD =millis();
    }
  }
  if (etat_haut_AD == 1){
        if((millis() - t_trig_AD) > 2){
     etat_haut_AD = 0;
     digitalWrite(trig4,LOW);
     t_trig_AD =millis();
    }
  }

// ------ COM SERIE
if ((millis() - T_affichage) > 1000){
Serial.println(distance_AG); 

Serial.println(distance_AD); 
Serial.println(millis() - debut);
T_affichage = millis();


}





}
