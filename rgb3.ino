// pin a cui collegare i piedini del LED RGB  
const int VERDE = 9;  
const int BLU = 11;  
const int ROSSO = 3;  
  
// tempo di transizione colore  
const int delayTime = 500;  
  
void setup() {  
  
  // imposta il pin digitale come output  
  pinMode(VERDE, OUTPUT);  
  pinMode(BLU, OUTPUT);  
  pinMode(ROSSO, OUTPUT);  
  Serial.begin(9600);
  // si impostano ad HIGH i pin VERDE, BLU, ROSSO  
  // inizialmente il led RGB sarà spento  
  digitalWrite(VERDE, HIGH);  
  digitalWrite(BLU, HIGH);  
  digitalWrite(ROSSO, HIGH);  
  Serial.println("Inizializzazione completata.");
  
}  
  
// definizione di variabili globali  
int ValRosso;  
int ValBlu;  
int ValVerde;  
  
  
void loop() {  
  
  // variazione da verde a rosso  
  
  int ValRosso = 255;  
  int ValBlu = 0;  
  int ValVerde = 0;  
  
  for( int i = 0 ; i < 255 ; i += 1 ){  
  
    ValVerde += 1;  
    ValRosso -= 1;  
    
    /* ad ogni ciclio la differenza 
     255 - ValVerde DIMINUISCE 
     255 - ValRosso AUMENTA 
     provocando un graduale passaggio 
     dal verde al rosso 
     */  
  
    analogWrite( VERDE, 255 - ValVerde );  
    analogWrite( ROSSO, 255 - ValRosso );  
  
  
    // attesa di 20 ms per percepire il colore  
    delay( delayTime );  
  }  
  
  // variazione da blu al verde  
  
  ValRosso = 0;  
  ValBlu = 0;  
  ValVerde = 255;  
  
  ValRosso = 0;  
  ValBlu = 0;  
  ValVerde = 255;  
  
  for( int i = 0 ; i < 255 ; i += 1 ){  
  
    ValBlu += 1;  
    ValVerde -= 1;  
  
    /* ad ogni ciclio la differenza 
     255 - ValBlu DIMINUISCE 
     255 - ValVerde AUMENTA 
     provocando un graduale passaggio 
     dal blu al verde 
     */  
  
    analogWrite( BLU, 255 - ValBlu );  
    analogWrite( VERDE, 255 - ValVerde );  
  
    // attesa di 20 ms per percepire il colore  
    delay( delayTime );  
  }  
  
  // variazione da rosso al blu  
  
  ValRosso = 0;  
  ValBlu = 255;  
  ValVerde = 0;  
  
  for( int i = 0 ; i < 255 ; i += 1 ){  
  
    ValRosso += 1;  
    ValBlu -= 1;  
  
    /* ad ogni ciclio la differenza 
     255 - ValRosso DIMINUISCE 
     255 - ValBlu AUMENTA 
     provocando un graduale passaggio 
     dal rosso al blu 
     */  
  
    analogWrite( ROSSO, 255 - ValRosso );  
    analogWrite( BLU, 255 - ValBlu );  
  
    // attesa di 20 ms per percepire il colore  
    delay( delayTime );  
  }  
} 
