  //Definicion de pines 
#define EP 1
#define LM 2
#define CE 3
#define EI 4
#define LA 5
#define EA 6
#define SU 7
#define EU 8
#define LB 9
#define LO 10
#define LI 11 
#define CP 12
#define I4 37
#define I5 36
#define I6 35
#define I7 34
#define CLK 33
#define CLR 32

void setup(){
  pinMode(EP, OUTPUT);
  pinMode(LM, OUTPUT);
  pinMode(CE, OUTPUT);
  pinMode(EI, OUTPUT);
  pinMode(LA, OUTPUT);
  pinMode(EA, OUTPUT);
  pinMode(SU, OUTPUT);    
  pinMode(EU, OUTPUT);
  pinMode(LB, OUTPUT);
  pinMode(LO, OUTPUT);
  pinMode(LI, OUTPUT);
  pinMode(CP, OUTPUT);
  pinMode(CLK,OUTPUT);
  pinMode(CLR,OUTPUT);
  pinMode(I4, INPUT);
  pinMode(I5, INPUT);
  pinMode(I6, INPUT);
  pinMode(I7, INPUT);



  
}

void fetchMemory(){
  
  digitalWrite(EP,HIGH);
  digitalWrite(LM,HIGH);
  digitalWrite(CLK,HIGH);
  digitalWrite(EP,LOW);
  digitalWrite(LM,LOW);
  
  digitalWrite(CLK, LOW);
  
  digitalWrite(CE,HIGH);
  digitalWrite(LI,HIGH);
  digitalWrite(CLK,HIGH);
  digitalWrite(CE,LOW);
  digitalWrite(LI,LOW);
  
  digitalWrite(CLK, LOW);

  digitalWrite(CP,HIGH); 
  digitalWrite(CP,LOW);
 

}

void LDA(){
  
  digitalWrite(EI,HIGH);
  digitalWrite(LM,HIGH);
  digitalWrite(CLK,HIGH);
  digitalWrite(EI,LOW);
  digitalWrite(LM,LOW);
  
  digitalWrite(CLK, LOW);
  
  digitalWrite(CE,HIGH);
  digitalWrite(LA,HIGH);
  digitalWrite(CLK,HIGH); 
  digitalWrite(CE,LOW);
  digitalWrite(LA,LOW);
      
  digitalWrite(CLK, LOW); 

}

void ADD(){
  
  digitalWrite(EI,HIGH);
  digitalWrite(LM,HIGH);
  digitalWrite(CLK,HIGH);
  digitalWrite(EI,LOW);
  digitalWrite(LM,LOW);
  
  digitalWrite(CLK, LOW);
  
  digitalWrite(CE,HIGH);
  digitalWrite(LB,HIGH);
  digitalWrite(CLK,HIGH); 
  digitalWrite(CE,LOW);
  digitalWrite(LB,LOW);
      
  digitalWrite(CLK, LOW); 

  digitalWrite(EU,HIGH);
  digitalWrite(LA,HIGH);
  digitalWrite(CLK,HIGH);
  digitalWrite(EU,LOW);
  digitalWrite(LA,LOW);
  
  digitalWrite(CLK, LOW);

}

void SUB(){
  
  digitalWrite(EI,HIGH);
  digitalWrite(LM,HIGH);
  digitalWrite(CLK,HIGH);
  digitalWrite(EI,LOW);
  digitalWrite(LM,LOW);
  
  digitalWrite(CLK, LOW);
  
  digitalWrite(CE,HIGH);
  digitalWrite(LB,HIGH);
  digitalWrite(CLK,HIGH); 
  digitalWrite(CE,LOW);
  digitalWrite(LB,LOW);
      
  digitalWrite(CLK, LOW); 

  digitalWrite(SU,HIGH);
  digitalWrite(EU,HIGH);
  digitalWrite(LA,HIGH);
  digitalWrite(CLK,HIGH);
  digitalWrite(SU,HIGH);
  digitalWrite(EU,LOW);
  digitalWrite(LA,LOW);
  
  digitalWrite(CLK, LOW);

}

void OUT(){
  
  digitalWrite(EA,HIGH);
  digitalWrite(LO,HIGH);
  digitalWrite(CLK,HIGH);
  digitalWrite(EA,LOW);
  digitalWrite(LO,LOW);
  
  digitalWrite(CLK,LOW);
  
}


void loop() {
  
  fetchMemory();
  
  // Leer los 4 bits y combinarlos en un solo byte
  uint8_t input = (digitalRead(I7) << 3) | 
                  (digitalRead(I6) << 2) | 
                  (digitalRead(I5) << 1) | 
                  digitalRead(I4);
  
  // Evaluar el valor combinado de los 4 bits


  if (input == 0b0000) { // LDA Routine
    LDA();
  } 
  else if (input == 0b0001) { // ADD Routine
    ADD();
  } 
  else if (input == 0b0010) { // SUB Routine
    SUB();
  } 
  else if (input == 0b1110) { // OUT Routine
    OUT();
  } 
  else if (input == 0b1111) { // HLT Routine
    digitalWrite(CP, LOW);
    digitalWrite(CLK, LOW);
    digitalWrite(EP, LOW);
    digitalWrite(LM, LOW);
    digitalWrite(CE, LOW);
    digitalWrite(EI, LOW);
    digitalWrite(LA, LOW);
    digitalWrite(EA, LOW);
    digitalWrite(SU, LOW);
    digitalWrite(EU, LOW);
    digitalWrite(LB, LOW);
    digitalWrite(LO, LOW);
    digitalWrite(LI, LOW);
    while (true);
  }

  
}
