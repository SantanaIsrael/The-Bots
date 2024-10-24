#define pino_S1 A1  //sensor extrema esquerda (verde)
#define pino_S2 A2  //sensor esquerda (roxo)
#define pino_S3 A3  //sensor meio (azul)
#define pino_S4 A4  //sensor direita (branco)
#define pino_S5 A5  //sensor extema direita (amarelo)

void testeMotor(int);
void testeSensor(int, int, int);

//Definicoes pinos Arduino ligados a entrada da Ponte H
int IN1 = 4;  //Direito horario
int IN2 = 3;  //Direito ante-horario
int IN3 = 7;  //Esquerdo horario
int IN4 = 8;  //Esquerdo ante-horario

int ENA = 6;  //Enable de motor direito
int ENB = 5;  //Enable de motor esquerdo

int S1Val = 0;
int S2Val = 0;
int S3Val = 0;
int S4Val = 0;
int S5Val = 0;

int pisoPreto = 0;

// Variáveis de apoio do Loop
int contPisoPreto = 0;
int ultimoMov = 0;

const int velMAX = 250;    //tava 250
const int velMED = 180;    // 180
const int velBAIXA = 100;  //120

void setup() {
  // Define os pinos como saida
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);

  Serial.begin(9600);
}

void paraCarro() {
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  analogWrite(ENB, 0);

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, 0);
}

void moveFrente(int velocidade) {
  //motor direito movimenta para frente
  digitalWrite(IN3, HIGH);
  //motor esquerdo se moviemnta para frente
  digitalWrite(IN1, HIGH);

  analogWrite(ENA, velocidade);
  analogWrite(ENB, velocidade);
}

void moveDireitaPouco(int velocidade) {
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENB, velocidade);

  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, velocidade / 2);
}

void moveEsquerdaPouco(int velocidade) {
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENB, velocidade / 2);

  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, velocidade);
}

void moveDireitaMuito(int velBAIXA) {
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENB, velBAIXA);

  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, velBAIXA);
}

void moveEsquerdaMuito(int velBAIXA) {
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENB, velBAIXA);

  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, velBAIXA);
}

void loop() {

  pisoPreto = 200;

  S1Val = analogRead(pino_S1);  //sensor extrema esquerdo (verde)
  S2Val = analogRead(pino_S2);  //sensor esquerda (roxo)
  S3Val = analogRead(pino_S3);  //sensor meio (azul)
  S4Val = analogRead(pino_S4);  //sensor direita (branco)
  S5Val = analogRead(pino_S5);  //sensor extrema direita (amarelo)

  //testeMotor(100);
  // testeSensor(S1Val, S2Val, S3Val, S4Val, S5Val);

  //if (S1Val >= pisoPreto && S5Val >= pisoPreto && S3Val < pisoPreto || S2Val < pisoPreto || S4Val < pisoPreto) { //pra frente
  if(S3Val < pisoPreto && S2Val >= pisoPreto && S4Val >= pisoPreto){

    Serial.print("\nS3: ");
    Serial.print(S3Val);

    Serial.print("\nS2: ");
    Serial.print(S2Val);

    Serial.print("\nS4: ");
    Serial.print(S4Val);
    moveFrente(100);
    ultimoMov = 0;

  } else if (S4Val < pisoPreto) { //direita

    Serial.print("\n Virando direita pouco S4: ");
    moveDireitaPouco(100);
    delay(2000);

  } else if (S2Val < pisoPreto) { //esquerda
    
    Serial.print("\n Virando esquerda pouco S2: ");
    moveEsquerdaPouco(100);

  } else {

    paraCarro();

  }




  // } else {
  //   if (S1Val < pisoPreto) {
  //     moveDireitaPouco(velMED);
  //     //delay(120);
  //     ultimoMov = 4;
  //   } else if (S3Val < pisoPreto) {
  //     moveEsquerdaPouco(velMED);
  //     //delay(120);
  //     ultimoMov = 3;
  //   } else {
  //     if (ultimoMov == 4 || ultimoMov == 3) {
  //       delay(100);
  //       moveFrente(velMED);
  //       ultimoMov = 0;
  //     }
  //   }
  //}



  // // Caso esteja todos no piso preto:
  // if (S2Val >= pisoPreto && S1Val >= pisoPreto && S3Val >= pisoPreto) {
  //   if (contPisoPreto > 30) {
  //     paraCarro();  // para o carro caso estourou o contador
  //   } //else {
  //     contPisoPreto++;  // incrementa contador e aplica último movimento feito antes do piso todo preto
  //     switch (ultimoMov) {
  //       case 0:
  //         moveFrente(velMAX);
  //         break;
  //       case 1:
  //         moveEsquerdaPouco(velMED);
  //         break;
  //       case 2:
  //         moveDireitaPouco(velMED);
  //         break;
  //       case 3:
  //         moveEsquerdaMuito(velBAIXA);
  //         break;
  //       case 4:
  //         moveDireitaMuito(velBAIXA);
  //         break;
  //     }
  //   }
  // } else {
  //   contPisoPreto = 0;  // Zera contador
  //}
  //delay(1000);
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

//delay(100);

void testeSensor(int S1Val, int S2Val, int S3Val, int S4Val, int S5Val) {

  Serial.print("\nS1: ");
  Serial.print(S1Val);

  Serial.print(" S2: ");
  Serial.print(S2Val);

  Serial.print(" S3: ");
  Serial.print(S3Val);

  Serial.print(" S4: ");
  Serial.print(S4Val);

  Serial.print(" S5: ");
  Serial.print(S5Val);

  delay(3000);
}

void testeMotor(int velocidade) {
  //Teste para ver se o motor está funcionando
  digitalWrite(IN1, HIGH);  //Motor Esquerdo
  digitalWrite(IN3, HIGH);  //Motor direito
  analogWrite(ENA, velocidade);
  analogWrite(ENB, velocidade);
}