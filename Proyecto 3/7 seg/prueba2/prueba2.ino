int boton=0;
int pin=30,aux=0;
int tiempoAntirebote=10;
void setup() {
 Serial.begin(9600);
//BOTONES
pinMode(pin,INPUT);
pinMode(31,INPUT);
pinMode(32,INPUT);
pinMode(33,INPUT);

pinMode(13,OUTPUT);

}

int cont=0;
void loop() {
 // boton = antirebote(pin);
 
  //if (boton == 1){
     // digitalWrite(13, HIGH);}
   //else{digitalWrite(13, LOW);}
 //  Serial.println (boton);

Serial.println (digitalRead(30));

if (digitalRead(30)==1)
aux=1;
if(aux==1 && digitalRead(30)==0)
{
aux=0;
cont++;

 }  

 if(cont%2==0 && cont !=0)
 digitalWrite(13,LOW);
 else if(cont%2==1) digitalWrite(13,HIGH);
}
boolean antirebote  (int pin ) {
  int  contador =0;
  boolean estado;            // guarda el estado del boton 
  boolean estadoAnterior;    // guarda el ultimo estado del boton 

  do {
    estado = digitalRead (pin);
    if (estado != estadoAnterior ){  // comparamos el estado actual 
      contador = 0;                   // reiniciamos el contador 
      estadoAnterior = estado;
    }
    else{
      contador = contador +1;       // aumentamos el contador en 1
    }
    delay (1);
  }
  while (contador < tiempoAntirebote);
  return estado;
}
