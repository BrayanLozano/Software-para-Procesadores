/* Here yo MUST declare BOUNCE_T, HEART_T y DISPLAY_T */

/* Definition of structures to preserve every context (= state + private vbles) */
int pin_Selector_1=12,
     pin_Selector_2=13;

 int a= 2; 
 int b= 3; 
 int c= 4;
 int d= 5;
 int e= 6;
 int f= 7;
 int g= 8; 
 int punto= 9;
 
typedef struct {
int debouncing_ctx_0;
int debouncing_ctx_1;
int debouncing_ctx_2;
int debouncing_ctx_3;
} BOUNCE_T;
BOUNCE_T bounce_t;
typedef struct {
int heart_monitor_ctx_0;
int heart_monitor_ctx_1;
int heart_monitor_ctx_2;
int heart_monitor_ctx_3;

 } HEART_T;
HEART_T heart;
typedef struct {
  int display_ctx;
  }DISPLAY_T; 

DISPLAY_T display_T;

/* Global vbles of system */

/* Next variable store a 0 or 1, a LOW or HIGH */
int bounced_signal_0, 
    bounced_signal_1, 
    bounced_signal_2, 
    bounced_signal_3;
    
int clean_signal_0, 
    clean_signal_1, 
    clean_signal_2, 
    clean_signal_3;

/* Next variables could store a number between 0000 and 9999 to display */
int heart_rate_0, 
    heart_rate_1, 
    heart_rate_2, 
    heart_rate_3,
    heart_rate_out;

int pin_0=30,
    pin_1=31,
    pin_2=32,
    pin_3=33;


void setup()
{

pinMode(13,INPUT);
pinMode(12,INPUT);


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
 pinMode ( pin_0, INPUT); 
 pinMode ( pin_1, INPUT);
 pinMode ( pin_2, INPUT);
 pinMode ( pin_3, INPUT);
pinMode(pin_Selector_1,INPUT);
pinMode(pin_Selector_2,INPUT);
}
//Initiate_Debouncing( /* vbles initiating state, context & transition */,
      //              &debouncing_ctx_0 );
//Initiate_Debouncing( /* vbles initiating state, context & transition */,
    //                &debouncing_ctx_1 );
//Initiate_Debouncing( /* vbles initiating state, context & transition */,
  //                  &debouncing_ctx_2 );
//Initiate_Debouncing( /* vbles initiating state, context & transition */,
  //                  &debouncing_ctx_3 );

//Initiate_Heart_Monitor( /* vbles initiating state, context & transition */,
//                       &heart_monitor_ctx_0 );
//Initiate_Heart_Monitor( /* vbles initiating state, context & transition */,
  //                     &heart_monitor_ctx_1 );
//Initiate_Heart_Monitor( /* vbles initiating state, context & transition */,
  //                     &heart_monitor_ctx_2 );
//Initiate_Heart_Monitor( /* vbles initiating state, context & transition */,
  //                     &heart_monitor_ctx_3 );
//;Initiate_Display( /* vbles initiating state, context & transition */,
  //               &display_ctx );



void Debouncing(int bounced_signal, int  *clean_signaL,BOUNCE_T *debouncing_ctx,int pin ) ;
void Heart_Monitor (int clean_signal, int *Heart_rate,HEART_T*heart_monitor_ctx);
void Multiplexer( int heart_rate_0, int heart_rate_1, int heart_rate_2, int heart_rate_3, int heart_rate_out );
void Display( int Heart_rate_Out,DISPLAY_T *display_ct );

void loop(){

/* In case of reading pins outside the function Debouncing() */
bounced_signal_0 = digitalRead( pin_0);
bounced_signal_1 = digitalRead( pin_1);
bounced_signal_2 = digitalRead( pin_2);
bounced_signal_3 = digitalRead( pin_3);

Debouncing( bounced_signal_0, &clean_signal_0, bounce_t.debouncing_ctx_0 ,pin_0);
Debouncing( bounced_signal_1, &clean_signal_1, bounce_t.debouncing_ctx_1 ,pin_1);
Debouncing( bounced_signal_2, &clean_signal_2, bounce_t.debouncing_ctx_2 ,pin_2);
Debouncing( bounced_signal_3, &clean_signal_3, bounce_t.debouncing_ctx_3 ,pin_3);

Heart_Monitor( clean_signal_0, &heart_rate_0, heart.heart_monitor_ctx_0 );
Heart_Monitor( clean_signal_1, &heart_rate_1, heart.heart_monitor_ctx_1 );
Heart_Monitor( clean_signal_2, &heart_rate_2, heart.heart_monitor_ctx_2 );
Heart_Monitor( clean_signal_3, &heart_rate_3, heart.heart_monitor_ctx_3 );

Multiplexer( heart_rate_0, heart_rate_1, heart_rate_2, heart_rate_3,  heart_rate_out );


Display( heart_rate_out, display_T.display_ctx );


} /* loop */
void Debouncing(int bounced_signal, int  *clean_signaL,BOUNCE_T *debouncing_ctx,int pin ) /* boton = estructura de variables*/
{  
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
    bounce_t->debouncing_ctx_0=estado;
    My_Delay (1);
  }
  while (contador < 10);
  return estado; 
}
void My_Delay(int num ){
  int previous, current;
  previous=current=millis();
  while(previous-current<num){
        current=millis();
        }
  
  }
  
  void Heart_Monitor (int clean_signal, int *Heart_rate,HEART_T*heart_monitor_ctx){
    typedef enum {
   
}STATE_T;
static STATE_T state=0;
static int estado= clean_signal;
static int previus=0;
static int long k=0,l=0,cont= 0;
int frec=0;

if( true ) {
 
    switch( state ) {
        case 0:
            if (clean_signal != previus){
               state = 1;
            } else {
               state =0;        
            } break;
        case 1:
            if (clean_signal ==1){
              k=l;
              l= millis();
              cont++;
              state =0;  
            } else {
                state =2;          
            } break;
        case 2:
            if (cont!= 1){
               frec= 600000/(l-k); Serial.println(frec);
               heart_monitor_ctx= frec;
               state = 0;
            } else {
                previus = clean_signal;
                state =0;         
            } break;           
        
    } /* switch */
  }
}
void Multiplexer( int heart_rate_0, int heart_rate_1, int heart_rate_2, int heart_rate_3, int heart_rate_out )
{
/* Assuming that the design fsm pattern is a flower with 4 petals... */
/* ... to simplify, I deleted if( TRUE ), switch-case with ONE state */

int selector_0 = digitalRead( 12);
int selector_1 = digitalRead( 13);

if( selector_0 == LOW && selector_1 == LOW )
    heart_rate_out = heart_rate_0;
if( selector_0 == HIGH && selector_1 == LOW )
    heart_rate_out = heart_rate_1;
if( selector_0 == LOW  && selector_1 == HIGH )
    heart_rate_out = heart_rate_2;
if( selector_0 == HIGH && selector_1 == HIGH )
    heart_rate_out = heart_rate_3;

} /* Multiplexer */
void Display( int Heart_rate_Out,DISPLAY_T *display_ctx )
{
typedef enum {
    AVANZAR_DIGITO,
  DIGITO,
  NUMERO,
  DELAY   
    } STATE_T;

static STATE_T state = AVANZAR_DIGITO;
static long int A=0;
static int Frec = Heart_rate_Out; /*Frec entrada*/ 
char Dig [4][4]=
{ {1, 0, 0, 0}, // digito 1
  {0, 1, 0, 0}, // digito 2
  {0, 0, 1, 0}, // digito 3
  {0, 0, 0, 1}  // digito 4
};

char NUM [10][7]=
/*a  b  c  d  e   f  g*/
{ {1, 1, 1, 1, 1, 1, 0}, // Numero 0
  {0, 1, 1, 0, 0, 0, 0}, // Numero 1
  {1, 1, 0, 1, 1, 0, 1}, // Numero 2
  {1, 1, 1, 1, 0, 0, 1}, // Numero 3 
  {0, 1, 1, 0, 0, 1, 1}, // Numero 4
  {1, 0, 1, 1, 0, 1, 1}, // Numero 5
  {1, 0, 1, 1, 1, 1, 1}, // Numero 6
  {1, 1, 1, 0, 0, 0, 0}, // Numero 7
  {1, 1, 1, 1, 1, 1, 1}, // Numero 8
  {1, 1, 1, 1, 0, 1, 1}  // Numero 9
};

static int cont=0, i=0, j=0;
int num1 = Frec /1000;  /* centena */
int num2 = (Frec % 1000)/100;  /* decena */
int num3 =(Frec % 100) /10;  /* unidad */
int num4 = Frec %10;  /* punto flotante*/
char Numeros [4] = { num1, num2, num3, num4 };

if( 1 == 1 ) {

    switch( state ) {

        case AVANZAR_DIGITO :
            if( cont <4 ) { 
           i=0; 
           state = DIGITO;
      } else { 
           cont= 0;  
             state= AVANZAR_DIGITO; }  break;

        case DIGITO :
            if( i<4 ) {
                 digitalWrite( i+22, Dig [cont ][i ] );
                 i=i+1;
                state= DIGITO;
            } else { j=0;
                 state= NUMERO; } break;

        case NUMERO :
            if( j<7 ) {
                 digitalWrite( j, NUM[ Numeros [cont]] [j] );
                 j=j+1;   
         state= NUMERO;   
            } else {
                 A= millis();
                 state= DELAY; } break;
                 
        case DELAY :
            if( millis() < A+6  ) {
              state= DELAY;
            } else {
                cont=cont+1;
                state= AVANZAR_DIGITO; } break;

    } /* switch */

} /* if */

} /* Display */
