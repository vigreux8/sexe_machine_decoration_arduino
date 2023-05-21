#include <Arduino.h>
//2 vert
//0 blanc
//4 vert
//5 blanc

//vert --> 2,4
//blanc --> 0,5

//2,0,4,5 nop

//2,5,4,0 nop

//4,5,2,0 nop

//4,0,2,5

int irotate = 0;
const int ln_1 = 2;  //5;
const int ln_2 = 0;  //4;
const int ln_3 = 4;  //0;
const int ln_4 = 5;  //2
int t = 10;
int valeur_original = 20;
int degrer = map(valeur_original, 0, 100, 0, 191);
const int Etape_limite = 191 / 2;
int compteur_etape = 191 / 2;

void sens_anti_horaire() {
  int irotate = 0;
  int Etape_limite = random(5, 191);
  do {
    if (irotate == Etape_limite / 2) {
      vitesse_alea();
    }
    Serial.println(t);
    digitalWrite(ln_1, LOW);
    digitalWrite(ln_2, LOW);
    digitalWrite(ln_3, LOW);
    digitalWrite(ln_4, HIGH);
    delay(t);

    digitalWrite(ln_1, LOW);
    digitalWrite(ln_2, LOW);
    digitalWrite(ln_3, HIGH);
    digitalWrite(ln_4, LOW);
    delay(t);

    digitalWrite(ln_1, LOW);
    digitalWrite(ln_2, HIGH);
    digitalWrite(ln_3, LOW);
    digitalWrite(ln_4, LOW);
    delay(t);

    digitalWrite(ln_1, HIGH);
    digitalWrite(ln_2, LOW);
    digitalWrite(ln_3, LOW);
    digitalWrite(ln_4, LOW);
    delay(t);
    irotate ++;
    compteur_etape --;
    limit_tchek();
  } while (irotate <= Etape_limite);
}

void sens_horaire() {
  int irotate = 0;
  int Etape_limite = random(0, 191);

  do {
    if (irotate == Etape_limite /2) {
      vitesse_alea();
    }
    Serial.println(t);
    digitalWrite(ln_1, HIGH);
    digitalWrite(ln_2, LOW);
    digitalWrite(ln_3, LOW);
    digitalWrite(ln_4, LOW);
    delay(t);

    digitalWrite(ln_1, LOW);
    digitalWrite(ln_2, HIGH);
    digitalWrite(ln_3, LOW);
    digitalWrite(ln_4, LOW);
    delay(t);

    digitalWrite(ln_1, LOW);
    digitalWrite(ln_2, LOW);
    digitalWrite(ln_3, HIGH);
    digitalWrite(ln_4, LOW);
    delay(t);

    digitalWrite(ln_1, LOW);
    digitalWrite(ln_2, LOW);
    digitalWrite(ln_3, LOW);
    digitalWrite(ln_4, HIGH);
    delay(t);
    irotate ++;
    compteur_etape ++;
    limit_tchek();
  } while (irotate <= Etape_limite);
  //le moteur doit bouger de 2048 pas pour faire 360c°
}


void vitesse_alea() {
  int condition_aléatoire = random(1, 3);
  if (condition_aléatoire == 2) {
    t = random(2, 6);
  }
}

void limit_tchek() {
  if (compteur_etape >= 189) {
    sens_anti_horaire();

  } else if (compteur_etape <= 10) {
    sens_horaire();
  }
}
void setup() {

  Serial.begin(9600);
  pinMode(ln_1, OUTPUT);
  pinMode(ln_2, OUTPUT);
  pinMode(ln_3, OUTPUT);
  pinMode(ln_4, OUTPUT);

}

void loop() {

  sens_horaire();
}
