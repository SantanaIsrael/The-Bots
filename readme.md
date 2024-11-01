# Projeto Robô Seguidor de Linha

## Descrição
Este projeto consiste no desenvolvimento de um robô seguidor de linha utilizando sensores infravermelhos para detectar e seguir uma linha branca em um plano preto. O objetivo do robô é ajustar sua trajetória de acordo com a linha, utilizando um controlador PID (Proporcional, Integral, Derivativo) para aprimorar a precisão dos movimentos.

## Código
O código está estruturado para leitura dos sensores, cálculo do erro em relação à linha e ajuste da velocidade dos motores baseado no controlador PID. As principais funções incluem:
- **leituraSensores()**: Realiza a leitura dos valores dos sensores infravermelhos e imprime no monitor serial.
- **controleMotorPID(erro)**: Calcula a correção necessária baseada nos valores de Kp, Ki e Kd, ajustando a velocidade dos motores.
- **moveFrente(velocidadeDireita, velocidadeEsquerda)**: Movimenta o robô para frente com as velocidades ajustadas.
- **paraCarro()**: Para o robô.

## Desenvolvedores
- Israel Santana
- Brenda Castro
- Flavia Alessandra
- Adriele Queiroz

## Instituição
O projeto está sendo desenvolvido na Universidade Estadual de Santa Cruz (UESC) e é um projeto independente, sem a orientação direta de professores titulares.

## Histórico do Projeto
O projeto de robótica vem sendo desenvolvido ao longo de aproximadamente dois anos. Durante esse período, a equipe participou de diversas competições e eventos, incluindo:
- Competições na UFRB
- Apresentações na Itabuna Geek
- Presença no Circuito das Profissões da UESC nos anos de 2023 e 2024.

## Instruções
Para rodar o código, certifique-se de ajustar o valor da variável `pisoPreto` de acordo com a leitura dos sensores no plano preto. Ajuste os valores das constantes `Kp`, `Ki` e `Kd` conforme necessário para otimizar o desempenho do controlador PID.

---

Esperamos que este projeto sirva de inspiração e guia para outros entusiastas de robótica. Continuem inovando e explorando! 🚀