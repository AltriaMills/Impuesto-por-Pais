#include <Servo.h>

int valorX = 0; // LECTURA DEL EJE X de J2 
int valorY = 0; // LECTURA DEL EJE Y de J2
int valorX2 = 0; // LECTURA DEL EJE X de J1
int valorY2 = 0; // LECTURA DEL EJE Y de J1
/*-----------------------------------------------------------------------------------------*/
int pinJX = A1; // PIN ANALOGICO A1 DEL EJE X de J2
int pinJY = A0; // PIN ANALOGICO A0 DEL EJE Y de J2
int pinJX2 = A2; // PIN ANALOGICO A2 DEL EJE X de J1
int pinJY2 = A3; // PIN ANALOGICO A3 DEL EJE Y de J1
/*-----------------------------------------------------------------------------------------*/
Servo motor1; // DECLARAR S1 // SERVO MOTOR 1
Servo motor2; // DECLARAR S2 // SERVO MOTOR 2
Servo motor3; // DECLARAR S3 // SERVO MOTOR 3
Servo motor4; // DECLARAR S4 // SERVO MOTOR 4
/*-----------------------------------------------------------------------------------------*/
int grados1 = 0; // GRADOS DEL S1
int grados2 = 0; // GRADOS DEL S2
int grados3 = 0; // GRADOS DEL S3
int grados4 = 0; // GRADOS DEL S4
/*-----------------------------------------------------------------------------------------*/
float tiempo;

void setup() {
  // put your setup code here, to run once: 
motor1.attach (6); // PIN DIGITAL PWM 6 DONDE ESTA CONECTADO EL S1
motor2.attach (9); // PIN DIGITAL PWM 9 DONDE ESTA CONECTADO EL S2
motor3.attach (10); // PIN DIGITAL PWM 10 DONDE ESTA CONECTADO EL S3
motor4.attach (11); // PIN DIGITAL PWM 11 DONDE ESTA CONECTADO EL S4
/*-----------------------------------------------------------------------------------------*/
// POSICION INICIAL DEL ARM ROBOT
grados1 = 20;  //S1
grados2 = 70; //S2
grados3 = 80; //S3
grados4 = 90; //S4
/*-----------------------------------------------------------------------------------------*/
}

void loop() {
  // put your main code here, to run repeatedly:
Motor1();
Motor2();
Motor3();
Motor4();

for (tiempo = 0; tiempo < 2500; tiempo++)
{
  if (tiempo >= 2500)
  {
    tiempo == 0;
  }
}
}

void Motor1 ()
{
  valorX = analogRead ( pinJX); // GUARDA LA LECTURA DEL PUERTO ANALOGICO A1 DEL EJE Y
  // INCREMENTAR GRADOS MOTOR 1 
  if ( (valorX > 520) && (valorX <= 1023) && (grados1 < 170)  ) // INCREMENTAR LOS GRADOS CUANDO LA LECTURA DEL EJE X ES MÁS GRANDE QUE EL CALIBRAJE Y MAS PEQUEÑO O IGUAL A 1023 
  {
    grados1 = grados1 + 5; // +5 GRADOS
  }
  
  // DECREMNTAR GRADOS MOTOR1
  else if ( (valorX >= 0 ) && (valorX < 480)&& (grados1 > 20) ) // DECREMENTAR LOS GRADOS CUANDO LA LECTURA DEL EJE X ES MÁS PEQUEÑA QUE EL CALIBRAJE Y MÁS GRANDE O IGUAL A 0 
  {
    grados1 = grados1 - 5;  // -5 GRADOS
  }
  motor1.write (grados1); // ENVIAR LOS GRADOS AL SERVO 1
}

void Motor2 ()
{
  valorY = analogRead ( pinJY); // GUARDA LA LECTURA DEL PUERTO ANALOGICO A0 DEL EJE X
    // INCREMENTAR GRADOS MOTOR2
  if ( (valorY > 530 ) && (valorY <= 1023) && (grados2 < 140)  )// INCREMENTAR LOS GRADOS CUANDO LA LECTURA DEL EJE X ES MÁS GRANDE QUE EL CALIBRAJE Y MAS PEQUEÑO O IGUAL A 1023
  {
    grados2 = grados2 + 5; // +5 GRADOS
  }
    
  // DECREMNTAR GRADOS MOTOR2
  else if ( (valorY >= 0 ) && (valorY < 480) && (grados2 > 70) ) // DECREMENTAR LOS GRADOS CUANDO LA LECTURA DEL EJE X ES MÁS PEQUEÑA QUE EL CALIBRAJE Y MÁS GRANDE O IGUAL A 0 
  {
    grados2 = grados2 - 5;  // -5 GRADOS
  }
  motor2.write (grados2); // ENVIAR LOS GRADOS AL SERVO 2 
}

void Motor3 ()
{
  valorX2 = analogRead ( pinJX2); // GUARDA LA LECTURA DEL PUERTO ANALOGICO A2 DEL EJE X
    // INCREMENTAR GRADOS MOTOR3
  if ( (valorX2 >= 0 ) && (valorX2 < 480) && (grados3 < 155)  ) // INCREMENTAR LOS GRADOS CUANDO LA LECTURA DEL EJE X ES MÁS GRANDE QUE EL CALIBRAJE Y MAS PEQUEÑO O IGUAL A 1023
  {
    grados3 = grados3 + 5; // +5 GRADOS
  }
  
  // DECREMNTAR GRADOS MOTOR3
  if ( (valorX2 > 530 ) && (valorX2 <= 1023) && (grados3 > 80)  ) // DECREMENTAR LOS GRADOS CUANDO LA LECTURA DEL EJE X ES MÁS PEQUEÑA QUE EL CALIBRAJE Y MÁS GRANDE O IGUAL A 0 
  {
    grados3 = grados3 - 5;  // -5 GRADOS
  }
  motor3.write (grados3); // ENVIAR LOS GRADOS AL SERVO 3 
}

void Motor4 ()
{
  valorY2 = analogRead ( pinJY2); // GUARDA LA LECTURA DEL PUERTO ANALOGICO A3 DEL EJE Y
    // INCREMENTAR GRADOS MOTOR4
  if ( (valorY2 >= 0 ) && (valorY2 < 480) && (grados4 < 125) ) // INCREMENTAR LOS GRADOS CUANDO LA LECTURA DEL EJE X ES MÁS GRANDE QUE EL CALIBRAJE Y MAS PEQUEÑO O IGUAL A 1023
  { 
    grados4 = grados4 + 5; // +5 GRADOS
  }
  
  // DECREMNTAR GRADOS MOTOR4
  else if ( (valorY2 > 530 ) && (valorY2 <= 1023) && (grados4 > 90) ) // DECREMENTAR LOS GRADOS CUANDO LA LECTURA DEL EJE X ES MÁS PEQUEÑA QUE EL CALIBRAJE Y MÁS GRANDE O IGUAL A 0 
  {
    grados4 = grados4 - 5;  // -5 GRADOS
  }
  motor4.write (grados4); // ENVIAR LOS GRADOS AL SERVO 4 
}
