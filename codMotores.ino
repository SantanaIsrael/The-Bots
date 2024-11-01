#define pino_S1 A1  // sensor extrema esquerda (verde)
#define pino_S2 A2  // sensor esquerda (roxo)
#define pino_S3 A3  // sensor meio (azul)
#define pino_S4 A4  // sensor direita (branco)
#define pino_S5 A5  // sensor extrema direita (amarelo)

void paraCarro();
void testeMotor();
void moveFrente(int, int);
void controleMotorPID(int erro);
void leituraSensores();

int IN1 = 4;  // Direito horário
int IN2 = 3;  // Direito anti-horário
int IN3 = 7;  // Esquerdo horário
int IN4 = 8;  // Esquerdo anti-horário
int ENA = 6;  // Enable de motor direito
int ENB = 5;  // Enable de motor esquerdo

int S1Val = 0;
int S2Val = 0;
int S3Val = 0;
int S4Val = 0;
int S5Val = 0;
int pisoPreto = 502;  // valor de piso preto (ajustável)

float Kp = 6.0;  // Constante Proporcional
float Ki = 0.2;  // Constante Integral
float Kd = 4.5;  // Constante Derivativa

int erro = 0, erroAnterior = 0;
int integral = 0;
int derivativo = 0;

void setup() {
  // Define os pinos como saída
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // Leitura dos sensores e exibição no monitor serial
  leituraSensores();

  // Calcula o erro baseado nos valores dos sensores
  erro = (S1Val - pisoPreto) + 2 * (S2Val - pisoPreto) + 3 * (S3Val - pisoPreto) + 4 * (S4Val - (pisoPreto - 150)) + 5 * (S5Val - pisoPreto);

  // // Imprime o valor do erro no monitor serial para verificação
  // Serial.print("Erro: ");
  // Serial.println(erro);

  // Controla o motor baseado no erro calculado pelo controlador PID
  controleMotorPID(erro);
}

void leituraSensores() {
  S1Val = analogRead(pino_S1);
  S2Val = analogRead(pino_S2);
  S3Val = analogRead(pino_S3);
  S4Val = analogRead(pino_S4);
  S5Val = analogRead(pino_S5);

  // Serial.print("S1: ");
  // Serial.print(S1Val);
  // Serial.print(" S2: ");
  // Serial.print(S2Val);
  // Serial.print(" S3: ");
  // Serial.print(S3Val);
  // Serial.print(" S4: ");
  // Serial.print(S4Val);
  // Serial.print(" S5: ");
  // Serial.println(S5Val);
  // delay(1000);
}

void controleMotorPID(int erro) {
  integral += erro;
  derivativo = erro - erroAnterior;
  int ajuste = Kp * erro + Ki * integral + Kd * derivativo;
  erroAnterior = erro;

  // Ajusta a velocidade dos motores com base no ajuste do PID
  int velocidadeDireita = 255 - ajuste;
  int velocidadeEsquerda = 255 + ajuste;

  // Limita os valores entre 0 e 255
  velocidadeDireita = constrain(velocidadeDireita, 0, 255);
  velocidadeEsquerda = constrain(velocidadeEsquerda, 0, 255);

  // Move o robô com as velocidades ajustadas
  moveFrente(velocidadeDireita, velocidadeEsquerda);
}

void moveFrente(int velocidadeDireita, int velocidadeEsquerda) {
  // Motor direito
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENB, velocidadeDireita);

  // Motor esquerdo
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, velocidadeEsquerda);
}

void paraCarro() {
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  analogWrite(ENB, 0);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, 0);
}
void testeMotor() {
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENB, 255);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, 255);
}
