/* 
* Programa para controlar dous motores eléctricos con dous relés por medio dun 
* pulsador, e con dous pulsadores (como fin de carreira).
* Ao premer unha vez, actívase o motor (relé) que corresponde co estado actual do sistema, 
* (b) o motor permanece activo até que o fin de carreira correspondente detecta a chegada do vidro, 
* momento no queo motor para, (c) en calquera momento intermedio, 
* o pulsador da xanela pode parar o vidro (unha pulsación) ou invertir o movemento (seguinte pulsación).
*
* Autor: Juan Manuel Martínez Lojo
* Data: Marzo de 2024
*/

// Definir os pins de entrada e saída
const int pinEntrada1 = 12; //Pulsador marcha/paro
const int pinEntrada2 =11; //Final carreira subida
const int pinEntrada3 =10;  //Final carreira baixada
const int pinSalida1 = 13;  //Motor Subida
const int pinSalida2 = 9;  //Motor Baixada

int debeActivarse = 0;
int estaActivado = 0;
int direccion = 0;		 //0 = Subir ; 1 = Baixar
int valorPinEntrada2 =0; //Valor final carreira subida
int valorPinEntrada3 =0; //Valor final carreira baixada

void setup (){
//Activar pins
	pinMode(pinEntrada1,INPUT);		
	pinMode(pinEntrada2,INPUT);
	pinMode(pinEntrada3,INPUT);
	pinMode(pinSalida1,OUTPUT);
	pinMode(pinSalida2,OUTPUT);  
}
void loop () {
  valorPinEntrada2 = digitalRead(pinEntrada2);
  valorPinEntrada3 = digitalRead(pinEntrada3);
  while (digitalRead(pinEntrada1)) {	//Lectura do pulsador 
  	debeActivarse = 1;
  }  
  if (debeActivarse){
	debeActivarse = 0;
  if (estaActivado){
    digitalWrite (pinSalida1,LOW);
    digitalWrite (pinSalida2,LOW); 
    estaActivado = 0;
    direccion = !direccion;    //Invertir Xiro
  }else{
    if(direccion){
      estaActivado = 1;
      digitalWrite (pinSalida2,HIGH);  
    }else{
      estaActivado = 1;
      digitalWrite (pinSalida1,HIGH);  
   }
  }
 }
  if (estaActivado){
    if (direccion && valorPinEntrada3){
     digitalWrite(pinSalida2,LOW);
     estaActivado = 0;
     direccion = !direccion;   //Invertir Xiro
    }
    if (!direccion && valorPinEntrada2){
      digitalWrite(pinSalida1,LOW);
     estaActivado = 0;
     direccion = !direccion;
    }
    
  }
}
