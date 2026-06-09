    // Oitava 4 (Oitava Central)
  #define NOTA_C4 262
  #define NOTA_CS4 277
  #define NOTA_D4 294
  #define NOTA_DS4 311
  #define NOTA_E4 330
  #define NOTA_F4 349
  #define NOTA_FS4 370
  #define NOTA_G4 392
  #define NOTA_GS4 415
  #define NOTA_A4 440
  #define NOTA_AS4 466
  #define NOTA_B4 494
    // Oitava 5
  #define NOTA_C5 523
  #define NOTA_CS5 554
  #define NOTA_D5 587
  #define NOTA_DS5 622
  #define NOTA_E5 659
  #define NOTA_F5 698
  #define NOTA_FS5 740
  #define NOTA_G5 784
  #define NOTA_GS5 831
  #define NOTA_A5 880
  #define NOTA_AS5 932
  #define NOTA_B5 988
    //tempos
  #define t4 2000
  #define t2 1000
  #define t1 500
  #define t05 250
  #define t025 125
  int buzzer = 3;
  int ritmo = 1.5;//serve para acelerar ou desacelerar a música
  int nota;
  int duracao;
  int notas[] = {
 	  NOTA_D5, NOTA_B4,NOTA_B4,NOTA_A4,
	  NOTA_D5, NOTA_B4,NOTA_B4,NOTA_B4,NOTA_A4,
	  NOTA_D5, NOTA_B4,NOTA_B4,NOTA_A4,
	  NOTA_D5, NOTA_B4,NOTA_B4,NOTA_B4,NOTA_A4,
	  NOTA_C5, NOTA_A4, NOTA_A4,NOTA_A4,NOTA_G4, 
	  NOTA_B4, NOTA_G4,NOTA_G4,NOTA_G4,
	  NOTA_F4, NOTA_G4
  };
  int tempos[]{
    t2,t05,t1,t05,
    t1,t05,t1,t05,t1,
    t1,t1,t1,t05,
    t1,t05,t1,t05,
    t1, t1, t1, t05, t05,
    t1,t1,t1,t05,t05,
    t1,t4
   };
   void setup()
  {
    pinMode(buzzer, OUTPUT);
  }
  void loop()
  {
      //sizeof(notas) = valor das notas dentro do vetor em bits
      //sizeof(int) = valor de um elemento inteiro em bits
      //divisão = número da nota dentro do vetor notas
    for(nota = 0;nota<(sizeof(notas)/sizeof(int)); nota++){
      duracao = tempos[nota]/ritmo;
      tone(buzzer,notas[nota],duracao);
      delay(duracao*1.5);
      noTone(buzzer);
    }  
  delay(5000);
  }
