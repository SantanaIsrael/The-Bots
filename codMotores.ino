#define pino_S1 A0  //sensor esquerda
#define pino_S2 A1  //sensor meio
#define pino_S3 A2  //sensor direita

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

int pisoPreto = 200;

// Variáveis de apoio do Loop
int contPisoPreto = 0;
int ultimoMov = 0;

const int velMAX = 250;
const int velMED = 180;
const int velBAIXA = 120;

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

void moveFrente(int velMAX) {
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENB, velMAX);

  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, velMAX);
}

void moveDireitaPouco(int velMED) {
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENB, velMAX);

  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, velMED / 2);
}

void moveEsquerdaPouco(int velMED) {
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENB, velMED / 2);

  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, velMAX);
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

  S1Val = analogRead(pino_S1);  //sensor esquerdo (verde)
  S2Val = analogRead(pino_S2);  //sensor meio (roxo)
  S3Val = analogRead(pino_S3);  //sensor direito (azul)

  // testeMotor(250);
  //testeSensor(S1Val, S2Val, S3Val);

  // if (S2Val < pisoPreto && S1Val >= pisoPreto && S3Val >= pisoPreto) {
  //   moveFrente(vel);
  //   ultimoMov = 0;
  // } else if (S2Val >= pisoPreto && S1Val < pisoPreto && S3Val >= pisoPreto) {
  //   moveDireitaMuito(vel);
  //   ultimoMov = 2;
  //   // } else if (S2Val >= pisoPreto && S1Val >= pisoPreto && S3Val >= pisoPreto) {
  //   //   paraCarro();
  // } else if (S2Val >= pisoPreto && S1Val >= pisoPreto && S3Val < pisoPreto) {
  //   moveEsquerdaMuito(vel);
  //   ultimoMov = 1;
  // }

  if (S2Val < pisoPreto && S1Val >= pisoPreto && S3Val >= pisoPreto) {
    moveFrente(velMAX);
    ultimoMov = 0;
  } else {
  if (S1Val < pisoPreto) {
    moveDireitaPouco(velMED);
    //delay(120);
    ultimoMov = 4;
  } else if (S3Val < pisoPreto) {
    moveEsquerdaPouco(velMED);
    //delay(120);
    ultimoMov = 3;
  } else {
    if (ultimoMov == 4 || ultimoMov == 3) {
      delay(100);
      moveFrente(velMAX);
      ultimoMov = 0;
    }
  }
}

    
  

  // Caso esteja todos no piso preto:
  if (S2Val >= pisoPreto && S1Val >= pisoPreto && S3Val >= pisoPreto) {
    if (contPisoPreto > 30) {
      paraCarro();  // para o carro caso estourou o contador
    } else {
      contPisoPreto++;  // incrementa contador e aplica último movimento feito antes do piso todo preto
      switch (ultimoMov) {
        case 0:
          moveFrente(velMAX);
          break;
        case 1:
          moveEsquerdaPouco(velMED);
          break;
        case 2:
          moveDireitaPouco(velMED);
          break;
        case 3:
          moveEsquerdaMuito(velBAIXA);
          break;
        case 4:
          moveDireitaMuito(velBAIXA);
          break;
      }
    }
  } else {
    contPisoPreto = 0;  // Zera contador
  }
  delay(15);
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

void testeSensor(int S1Val, int S2Val, int S3Val) {

  Serial.print("\nS1: ");
  Serial.print(S1Val);

  Serial.print(" S2: ");
  Serial.print(S2Val);

  Serial.print(" S3: ");
  Serial.print(S3Val);

  delay(3000);
}

void testeMotor(int velocidade) {
  //Teste para ver se o motor está funcionando
  digitalWrite(IN1, HIGH);
  digitalWrite(IN3, HIGH);
  analogWrite(ENA, velMAX);
  analogWrite(ENB, velMAX);
}