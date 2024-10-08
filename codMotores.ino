#define pino_S1 A2
#define pino_S2 A1

/*
Tem que mudar o nome dos motores na parte onde movimenta os senssores. 
*/
//Definicoes pinos Arduino ligados a entrada da Ponte H
int IN1 = 4; //Direito horario
int IN2 = 3; //Direito ante-horario
int IN3 = 8; //Esquerdo horario
int IN4 = 7; //Esquerdo ante-horario

int ENA = 6; //Enable de motor direito
int ENB = 5; //Enable de motor esquerdo

int S1Val = 0;
int S2Val = 0;

int pisoPreto = 300;

const int vel = 220;

void setup(){
 // Define os pinos como saida
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);

  Serial.begin(9600);
}
  
  void moveFrente (int vel) {
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENB, vel);

  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, vel);
  }

  void moveDireitaPouco (int vel) {
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
    analogWrite(ENB, vel);

    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    analogWrite(ENA, vel / 2);
  }

  void moveEsquerdaPouco (int vel) {
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
    analogWrite(ENB, vel / 2);

    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    analogWrite(ENA, vel);
  }

  void loop(){
      // S1Val = analogRead(pino_S1); //sendor direito (azul)
      // S2Val = analogRead(pino_S2); //sensor esquerdo (verde)

      // Serial.print("\nS1: ");
      // Serial.print(S1Val);
      // Serial.print("\n S2: ");
      // Serial.print(S2Val);

        if ( S1Val >= pisoPreto && S2Val >= pisoPreto) {
          moveFrente(vel);
      }else if(S1Val < pisoPreto && S2Val >= pisoPreto){
          moveDireitaPouco(vel);
      }else{
          moveEsquerdaPouco(vel);
  }





























    // Serial.print("\nS1: ");
    // Serial.print(S1Val);
    // Serial.print("\nS2: ");
    // Serial.print(S2Val);

    // //Gira o Motor A no sentido horario
    // analogWrite(ENA, 120);
    // analogWrite(ENB, 120);
    // digitalWrite(IN1, HIGH);
    // digitalWrite(IN2, LOW);
    // delay(2000);

    //   //Gira o Motor B no sentido horario
    //   analogWrite(ENA, 120);
    // analogWrite(ENB, 120);
    // digitalWrite(IN3, HIGH);
    // digitalWrite(IN4, LOW);
    delay(3000);
}