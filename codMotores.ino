#define pino_S1 A0 //sensor esquerda
#define pino_S2 A1 //sensor meio
#define pino_S3 A3 //sensor direita

void testeMotor(int);
void testeSensor(int, int);

//Definicoes pinos Arduino ligados a entrada da Ponte H
int IN1 = 4; //Direito horario
int IN2 = 3; //Direito ante-horario
int IN3 = 7; //Esquerdo horario
int IN4 = 8; //Esquerdo ante-horario

int ENA = 6; //Enable de motor direito
int ENB = 5; //Enable de motor esquerdo

int S1Val = 0;
int S2Val = 0;
int S3Val = 0;

int pisoPreto = 300;

const int vel = 250;

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

S1Val = analogRead(pino_S1); //sendor direito (azul)
S2Val = analogRead(pino_S2); //sensor meio (roxo)
S3Val = analogRead(pino_S3); //sensor esquerdo (verde)

// testeMotor(250);
//testeSensor(S1Val, S2Val);

if ( S1Val >= pisoPreto && S3Val >= pisoPreto) {
  moveFrente(vel);
   }else if(S1Val < pisoPreto && S2Val >= pisoPreto){
      moveDireitaPouco(vel);
      }else{
          moveEsquerdaPouco(vel);
}

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

void testeSensor(int S1Val, int S2Val){
  
  Serial.print("\nS1: ");
  Serial.print(S1Val);
  Serial.print("\n S2: ");
  Serial.print(S2Val);

  delay(3000);
}

void testeMotor(int velocidade){
//Teste para ver se o motor está funcionando
  digitalWrite(IN1, HIGH);
  digitalWrite(IN3, HIGH);
  analogWrite(ENA, vel);
  analogWrite(ENB, vel);
}