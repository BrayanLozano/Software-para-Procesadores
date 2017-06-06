 
/* int pin_Selector_1=12,
     pin_Selector_2=13;*/
int  pin_Selector_1=2,
     pin_Selector_2=3;
/* int a= 2; 
 int b= 3; 
 int c= 4;
 int d= 5;
 int e= 6;
 int f= 7;
 int g= 8; 
 int punto= 9;*/
 
 int a= 26; 
 int b= 28; 
 int c= 30;
 int d= 32;
 int e= 34;
 int f= 36;
 int g= 38; 
 int punto= 40;

 int boton1;
 int boton2;
 int boton3;
 int boton4;
 int selector_1;
 int selector_2;
void setup() {
Serial.begin(9600);

pinMode(a,OUTPUT);
pinMode(b,OUTPUT);
pinMode(c,OUTPUT);
pinMode(d,OUTPUT);
pinMode(e,OUTPUT);
pinMode(f,OUTPUT);
pinMode(g,OUTPUT);
pinMode(punto,OUTPUT);
// DIGITOS 
pinMode(22,OUTPUT);
pinMode(23,OUTPUT);
pinMode(24,OUTPUT);
pinMode(25,OUTPUT);
//BOTONES
/*pinMode(30,INPUT);
pinMode(31,INPUT);
pinMode(32,INPUT);
pinMode(33,INPUT);*/

pinMode(12,INPUT);
pinMode(11,INPUT);
pinMode(10,INPUT);
pinMode(9,INPUT);

pinMode(pin_Selector_1,INPUT);
pinMode(pin_Selector_2,INPUT);

digitalWrite(22,0);
digitalWrite(23,0);
digitalWrite(24,0);
digitalWrite(25,0);
  
 digitalWrite(a,0);
 digitalWrite(b,0);
 digitalWrite(c,0);
 digitalWrite(d,0);
 digitalWrite(f,0);
 digitalWrite(g,0);
 digitalWrite(punto,0);

}

void loop() {


boton1=digitalRead(12);Serial.println (boton1); //boton1=digitalRead(30);Serial.println (boton1);
boton2=digitalRead(11);Serial.println (boton2);  //boton2=digitalRead(31);Serial.println (boton2);
boton3=digitalRead(10);Serial.println (boton3); //boton3=digitalRead(32);Serial.println (boton3);
boton4=digitalRead(9);Serial.println  (boton4); //boton4=digitalRead(33);Serial.println (boton4);

selector_1= digitalRead(pin_Selector_1);Serial.println (selector_1);
selector_2= digitalRead(pin_Selector_2);Serial.println (selector_2);
if (boton1 == 1)
{  
digitalWrite(22,0);
digitalWrite(23,1);
digitalWrite(24,1);
digitalWrite(25,1);
}else if(boton2 == 1)
{digitalWrite(22,1);
digitalWrite(23,0);
digitalWrite(24,1);
digitalWrite(25,1);}

else if(boton3 == 1)
{digitalWrite(22,1);
digitalWrite(23,1);
digitalWrite(24,0);
digitalWrite(25,1);}

 else if(boton4 == 1)
{digitalWrite(22,1);
digitalWrite(23,1);
digitalWrite(24,1);
digitalWrite(25,0);}
  }
