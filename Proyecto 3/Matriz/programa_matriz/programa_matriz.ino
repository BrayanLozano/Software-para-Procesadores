int f1 = 32;    int c1 = 22;
int f2 = 33;    int c2 = 23;
int f3 = 34;    int c3 = 24;
int f4 = 35;    int c4 = 25;
int f5 = 36;    int c5 = 26;
int f6 = 37;    int c6 = 27;
int f7 = 38;    int c7 = 28;
int f8 = 39;    int c8 = 29;

char m[8][8] =
{ {1, 0, 0, 0, 0, 0, 0, 0}, // digito 1
  {0, 1, 0, 0, 0, 0, 0, 0}, // digito 2
  {0, 0, 1, 0, 0, 0, 0, 0}, // digito 3
  {0, 0, 0, 1, 0, 0, 0, 0}, // digito 4
  {0, 0, 0, 0, 1, 0, 0, 0}, // digito 5
  {0, 0, 0, 0, 0, 1, 0, 0}, // digito 6
  {0, 0, 0, 0, 0, 0, 1, 0}, // digito 7
  {0, 0, 0, 0, 0, 0, 0, 1}
};// digito 8

char e[8][8] = // matriz ejemplo de entrada 
{ {0, 0, 0, 0, 0, 0, 0, 0}, 
  {0, 0, 1, 1, 0, 1, 1, 0}, 
  {0, 1, 1, 1, 1, 1, 1, 1}, 
  {0, 1, 1, 1, 1, 1, 1, 1}, 
  {0, 1, 1, 1, 1, 1, 1, 1}, 
  {0, 0, 1, 1, 1, 1, 1, 0}, 
  {0, 0, 0, 1, 1, 1, 0, 0}, 
  {0, 0, 0, 0, 1, 0, 0, 0}
};// digito 8

void setup() {
  // put your setup code here, to run once:
  pinMode(f1, OUTPUT); pinMode(c1, OUTPUT);
  pinMode(f2, OUTPUT); pinMode(c2, OUTPUT);
  pinMode(f3, OUTPUT); pinMode(c3, OUTPUT);
  pinMode(f4, OUTPUT); pinMode(c4, OUTPUT);
  pinMode(f5, OUTPUT); pinMode(c5, OUTPUT);
  pinMode(f6, OUTPUT); pinMode(c6, OUTPUT);
  pinMode(f7, OUTPUT); pinMode(c7, OUTPUT);
  pinMode(f8, OUTPUT); pinMode(c8, OUTPUT);
}
char mostrarMatriz( char m[][8], char  e[][8]) {
  for (int k = 0; k < 8 ; k++) {
    //-----------------------
    for (int i = 0; i < 8 ; i++) {
      if (m[k][i] == 1) { digitalWrite(i + 2, 1); }
      else { digitalWrite(i + 2, 0); }
    }
    for (int j = 0; j < 8 ; j++) {
      if (e[k][j] == 1) { digitalWrite(j + 22, 0); }
      else { digitalWrite(j + 22, 1); } 
    }
    for (int i = 0; i < 8 ; i++) {
      digitalWrite(i + 22, 1);
    }
    //-----------------------
  }
}


void loop() {
  // put your main code here, to run repeatedly:
  mostrarMatriz( m, e);
}






