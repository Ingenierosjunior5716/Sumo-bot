#include "Carrito.h"

Carrito Sumo; //Ingresa el nombre de tu carrito despues de Carrito y antes de el punto y coma

void setup() {
  // Ya se inicializa en el constructor
  pinMode(10, OUTPUT); // TRIGGER
  pinMode(11, INPUT);  // ECHO
  Serial.begin(9600);  //Iniciamos el monitor serial
}

//Función que mide la distancia
float ultra() {                           
int trigger = 10;                         //Pin digital para el Trigger del sensor
int echo = 11;                            //Pin digital para el Echo del sensor
float tiempo_de_espera,distancia;         //Variable decimal que usaremos más adelante

digitalWrite (trigger,LOW);               // Apagamos el pin 8 durante 2 microsegundos
delayMicroseconds(2);
digitalWrite (trigger, HIGH);             // Ahora ponemos encendemos el pin 8 durante 10 microsegundos
delayMicroseconds (10);                  
digitalWrite (trigger, LOW);              // Apagamos pin 8
tiempo_de_espera = pulseIn (echo,HIGH);   // pulseIn, recoge la señal del sonido que emite el trigger
distancia =(tiempo_de_espera/2)/29.15;    // Formula para hallar la distancia
Serial.print (distancia);                 // Imprimimos la distancia en el monitor serial
Serial.println ("cm");                    // Imprimimos "cm"
return distancia;                         // Si se llama a  la función, toma el valor de la variable distancia
}

void loop() {
  // Escribe tu codigo en el loop
  /* 
  Ejemplos:
  (nombre de tu carrito).adelante();
  (nombre de tu carrito).parar();
  Recuerda usar delay para que las instrucciones sigan una secuencia
  */
  Sumo.derecha();
  float d = ultra();
  if(d < 15){
    Sumo.adelante();
  }
}

