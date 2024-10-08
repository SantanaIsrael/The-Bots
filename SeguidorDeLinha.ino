// /*// Mapeamento de Pinos

// // Motor Direita
// #define pino_enableDIR   5
// #define pino_motorDIR_A  6
// #define pino_motorDIR_B  7

// // Motor Esquerda
// #define pino_enableESQ   10
// #define pino_motorESQ_A  9
// #define pino_motorESQ_B  8

// // Sensores Infravermelho
// #define pino_S1 A4
// #define pino_S2 A3
// #define pino_S3 A2
// #define pino_S4 A1
// #define pino_S5 A0

// // Variáveis

// // Variáveis de leitura dos sensores infravermelho
// int S1Val = 0;
// int S2Val = 0;
// int S3Val = 0;
// int S4Val = 0;
// int S5Val = 0;

// // Variáveis de velocidade do motor
// // Estas variáveis podem ser configuradas para um valor mais adequado conforme o seu robô for sendo testado
// const int velMAX = 220;
// const int velMED = 170;
// const int velBAIXA = 120;

// // Variáveis de base de leitura do sensor infravermelho
// /* Ajustar estes valores conforme a leitura feita com os seus sensores. 
//   IMPORTANTE: 
//   - O valor de preto tem que ser um pouco menor do que a menor medida dos sensores no piso preto
//   - O valor de branco tem que ser um pouco maior do que a maior medida dos sensores no piso branco
// */
// int pisoBranco = 70;
// int pisoPreto = 400;

// // Variáveis de apoio do Loop
// int contPisoPreto = 0;
// int ultimoMov = 0;

// void setup()
// {
//   // Configura Pinos dos Motores como saída
//   pinMode(pino_enableDIR, OUTPUT);
//   pinMode(pino_enableESQ, OUTPUT);
//   pinMode(pino_motorDIR_A, OUTPUT);
//   pinMode(pino_motorDIR_B, OUTPUT);
//   pinMode(pino_motorESQ_A, OUTPUT);
//   pinMode(pino_motorESQ_B, OUTPUT);

//   // Debug
//   Serial.begin(9600);
// }


// void loop()
// {

//   // leitura dos sensores
//   S1Val = analogRead(pino_S1);
//   S2Val = analogRead(pino_S2);
//   S3Val = analogRead(pino_S3);
//   S4Val = analogRead(pino_S4);
//   S5Val = analogRead(pino_S5);
//   /*
//    // PARA FAZER CALIBRAÇÃO DOS SENSORES REMOVA O TAG DE COMENTÁRIO ACIMA E ABAIXO 
//    // DESSE BLOCO E COLOQUE COMO COMO COMENTÁRIO O RESTO DO PROGRAMA ABAIXO 
//    // (MANTENHA A LEITURA DOS SENSORES SOMENTE)
//     Serial.print("S1: ");
//     Serial.print(S1Val);
//     Serial.print(" S2: ");
//     Serial.print(S2Val);
//     Serial.print(" S3: ");
//     Serial.print(S3Val);
//     Serial.print(" S4: ");
//     Serial.print(S4Val);
//     Serial.print(" S5: ");
//     Serial.println(S5Val);

//   */

//   // Lógicas de verificação de qual sensor está "vendo" a faixa preta
//   // Aplica o movimento correto e registra qual foi esse movimento realizado
//   if ( S1Val <= pisoPreto && S2Val <= pisoPreto && S3Val >= pisoBranco && S4Val <= pisoPreto && S5Val <= pisoPreto) {
//     moveFrente(velMAX);
//     ultimoMov = 0;
//   } else {
//     if ( S2Val >= pisoBranco) {
//       moveEsquerdaPouco(velMED);
//       ultimoMov = 1;
//     } else {
//       if ( S4Val >= pisoBranco) {
//         moveDireitaPouco(velMED);
//         ultimoMov = 2;
//       } else {
//         if ( S1Val >= pisoBranco) {
//           moveEsquerdaMuito(velBAIXA);
//           ultimoMov = 3;
//         } else {
//           if ( S5Val >= pisoBranco) {
//             moveDireitaMuito(velBAIXA);
//             ultimoMov = 4;
//           }
//         }
//       }
//     }
//   }

//   // Caso esteja todos no piso branco:
//   if ( S1Val <= pisoPreto && S2Val <= pisoPreto && S3Val <= pisoPreto && S4Val <= pisoPreto && S5Val <= pisoPreto) {
//     if (contPisoPreto > 30) {
//       paraCarro();    // para o carro caso estourou o contador
//     } else {
//       contPisoPreto++;   // incrementa contador e aplica último movimento feito antes do piso todo branco
//       switch (ultimoMov) {
//         case 0:
//           moveFrente(velMAX);
//           break;
//         case 1:
//           moveEsquerdaPouco(velMED);
//           break;
//         case 2:
//           moveDireitaPouco(velMED);
//           break;
//         case 3:
//           moveEsquerdaMuito(velBAIXA);
//           break;
//         case 4:
//           moveDireitaMuito(velBAIXA);
//           break;
//       }
//     }
//   } else {
//     contPisoPreto = 0;   // Zera contador
//   }

//   // Delay do Loop todo
//   // AJUSTAR ESSE VALOR CASO LOOP ESTEJA RÁPIDO DEMAIS
//   delay(30);

// }


// /*
//    FUNÇÕES DE MOVIMENTO DO CARRO
// */

// void moveFrente (int vel) {
//   digitalWrite(pino_motorESQ_A, HIGH);
//   digitalWrite(pino_motorESQ_B, LOW);
//   analogWrite(pino_enableESQ, vel);

//   digitalWrite(pino_motorDIR_A, HIGH);
//   digitalWrite(pino_motorDIR_B, LOW);
//   analogWrite(pino_enableDIR, vel);
// }

// void moveDireitaPouco (int vel) {
//   digitalWrite(pino_motorESQ_A, HIGH);
//   digitalWrite(pino_motorESQ_B, LOW);
//   analogWrite(pino_enableESQ, vel);

//   digitalWrite(pino_motorDIR_A, HIGH);
//   digitalWrite(pino_motorDIR_B, LOW);
//   analogWrite(pino_enableDIR, vel / 2);
// }

// void moveEsquerdaPouco (int vel) {
//   digitalWrite(pino_motorESQ_A, HIGH);
//   digitalWrite(pino_motorESQ_B, LOW);
//   analogWrite(pino_enableESQ, vel / 2);

//   digitalWrite(pino_motorDIR_A, HIGH);
//   digitalWrite(pino_motorDIR_B, LOW);
//   analogWrite(pino_enableDIR, vel);
// }

// void moveDireitaMuito (int vel) {
//   digitalWrite(pino_motorESQ_A, HIGH);
//   digitalWrite(pino_motorESQ_B, LOW);
//   analogWrite(pino_enableESQ, vel);

//   digitalWrite(pino_motorDIR_A, LOW);
//   digitalWrite(pino_motorDIR_B, LOW);
//   analogWrite(pino_enableDIR, vel);
// }

// void moveEsquerdaMuito (int vel) {
//   digitalWrite(pino_motorESQ_A, LOW);
//   digitalWrite(pino_motorESQ_B, LOW);
//   analogWrite(pino_enableESQ, vel);

//   digitalWrite(pino_motorDIR_A, HIGH);
//   digitalWrite(pino_motorDIR_B, LOW);
//   analogWrite(pino_enableDIR, vel);
// }

// void paraCarro() {
//   digitalWrite(pino_motorESQ_A, LOW);
//   digitalWrite(pino_motorESQ_B, LOW);
//   analogWrite(pino_enableESQ, 0);

//   digitalWrite(pino_motorDIR_A, LOW);
//   digitalWrite(pino_motorDIR_B, LOW);
//   analogWrite(pino_enableDIR, 0);
// }


