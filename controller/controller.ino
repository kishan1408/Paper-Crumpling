  /*



To start the trigger send 'a' using serial communication . A blue LED1  indicates  the  state
of trigger.The blinking of  green LED shows the  change in the  session.  The  trigger signal
has following component : 2 types of start bit [ a digital HIGH for 4  frames  (00111100) and 
a digital HIGH for 8 frames (001111111100) ] and a four bit trigger  values.  The  4  trigger
bits can be sent by sending a letter from 'b' to 'p' using  serial  communication. Similarly,
response could be sent  by sendinga  letter  from 'B'  to  'P'  using  serial  communication.
The trigger associated with the image screen is either 'q'(for face) [0011001100110011 
or 'Q' (for car).

setup :

Rx & Tx are connected to serial port pin 2 and pin 3 respectively 
Digital pin 7 is connected to trigger of nexus 
LED1,LED2,LED3 are connected to pin 13,12 and 2 respectively  */                                                                                                                                                           /* created for eeglab iiserk by kishan (kishan1408@gmail.com),bapun (bapunk@iiserkol.ac.in) and johanan(johanan1033@iiserkol.ac.in) */                                                                                                                             

int pos = 0;
int flag1 = 0;
int flagm =0;      // flag for mouse
int trig1 = 12 ;    // trigger pin
int val = 1;       // state of trigger
int sw1 =1;        // switch for preventing double clicks
int j=0;
String s= "00000000100100011010001010110011110001001101010111100110111101111";

void setup()                    
{

  
  Serial.begin(9600);           // baud rate 
  Serial.flush();
  pinMode(13,OUTPUT);           // LED 1
  pinMode(12,OUTPUT);           // LED 2
  pinMode(trig1,OUTPUT);        
  pinMode(2,OUTPUT);pinMode(6,OUTPUT);pinMode(7,OUTPUT);pinMode(8,OUTPUT);pinMode(9,OUTPUT);pinMode(11,OUTPUT); pinMode(12,OUTPUT);  digitalWrite(trig1,LOW);           //LED 3 
}

void loop()
{
 if (Serial.available() > 0 &&   flag1 == 0 ) 
   {    int inByte = Serial.read();
        digitalWrite(12, LOW);
        digitalWrite(13, LOW);
        digitalWrite(2, LOW);
        digitalWrite(7, LOW);
        digitalWrite(8, LOW);
        analogWrite(6,0);analogWrite(11,0);analogWrite(9,0);
        switch (inByte)
        { case 'a':   
          digitalWrite(13, HIGH);delay(1000);digitalWrite(13,LOW); flag1 = 1;
          break;}}
       
//////////////////////////flag 1  (a)  /////////////////////
    if (Serial.available() > 0 && flag1 == 1 && flagm == 0)
    { int  trigs  = Serial.read();
      switch (trigs){
        case 'b':
        j=1;
        digitalWrite(trig1,HIGH);digitalWrite(13,HIGH);delayMicroseconds(7812);digitalWrite(trig1,LOW);digitalWrite(13,LOW);delayMicroseconds(3906);
        break;
        
        case 'c':
        j=5;
               while(1){ digitalWrite(trig1,HIGH);digitalWrite(13,HIGH);delayMicroseconds(100000);digitalWrite(trig1,LOW);digitalWrite(13,LOW);delayMicroseconds(10000);}
        break;
        
        case 'd':
        j=9;
        analogWrite(6,255);
        break;
        
        case 'e':
        j=13;
        analogWrite(6,0);
        break;
        
        
        case 'f':
        j=17;
        digitalWrite(7,HIGH);
        break;
        
        case 'g':
        j=21;
        digitalWrite(7,LOW);
        break;
        
        case 'h':
        j=25;
        digitalWrite(8,HIGH);
        break;
        
        case 'i':
        j=29;
        digitalWrite(8,LOW);
        break;
        
        case 'j':
        j=33;
        analogWrite(9,255);
        break;
        
        case 'k':
        j=37;
        analogWrite(9,0);
        break;
        
        case 'l':
        j=41;
         for (int jj = 0;jj<50;jj++){
        digitalWrite(13,HIGH);analogWrite(11,255);delayMicroseconds(1000);analogWrite(11,0);digitalWrite(13,LOW);delay(10);}
        break;
        
        case 'm':
        j=45;
        break;
        
            
       
        case 'n':
        j=41;
        digitalWrite(2,HIGH);
        break;
        
        case 'o':
        j=45;
       digitalWrite(2,LOW);
       break;
        
        
         case 'p':
        j=57;
        digitalWrite(trig1,HIGH);digitalWrite(12,HIGH);delayMicroseconds(7812);digitalWrite(trig1,LOW);digitalWrite(12,LOW);delayMicroseconds(3906);for (int i =j;i<=j+3;i++){
          digitalWrite(trig1,int(s.charAt(i))-48);digitalWrite(2,int(s.charAt(i))-48);delayMicroseconds(3906);digitalWrite(trig1,LOW);digitalWrite(2,LOW);delayMicroseconds(3906);}
        break;
        
        
        case 'q': // for face 
        j=61;
        digitalWrite(trig1,HIGH);digitalWrite(12,HIGH);delayMicroseconds(7812);digitalWrite(trig1,LOW);digitalWrite(12,LOW);delayMicroseconds(3906);for (int i =j;i<=j+3;i++){
          digitalWrite(trig1,int(s.charAt(i))-48);digitalWrite(2,int(s.charAt(i))-48);delayMicroseconds(3906);digitalWrite(trig1,LOW);digitalWrite(2,LOW);delayMicroseconds(3906);}
          
        break; 
        
         case 'B':
        j=1;
        digitalWrite(trig1,HIGH);digitalWrite(2,HIGH);delayMicroseconds(15624);digitalWrite(trig1,LOW);digitalWrite(12,LOW);delayMicroseconds(3906);for (int i =j;i<=j+3;i++){
          digitalWrite(trig1,int(s.charAt(i))-48);digitalWrite(2,int(s.charAt(i))-48);delayMicroseconds(3906);digitalWrite(trig1,LOW);digitalWrite(2,LOW);delayMicroseconds(3906);}
        break;
        
        case 'C':
        j=5;
        digitalWrite(trig1,HIGH);digitalWrite(12,HIGH);delayMicroseconds(15624);digitalWrite(trig1,LOW);digitalWrite(12,LOW);delayMicroseconds(3906);for (int i =j;i<=j+3;i++){
          digitalWrite(trig1,int(s.charAt(i))-48);digitalWrite(2,int(s.charAt(i))-48);delayMicroseconds(3906);digitalWrite(trig1,LOW);digitalWrite(2,LOW);delayMicroseconds(3906);}
        break;
        
        case 'D':
        j=9;        
        
        break;
               
        case 'E':
        j=13;
       
        break;
        
        
        case 'F':
        j=17;
        digitalWrite(trig1,HIGH);digitalWrite(12,HIGH);delayMicroseconds(15624);digitalWrite(trig1,LOW);digitalWrite(12,LOW);delayMicroseconds(3906);for (int i =j;i<=j+3;i++){
          digitalWrite(trig1,int(s.charAt(i))-48);digitalWrite(2,int(s.charAt(i))-48);delayMicroseconds(3906);digitalWrite(trig1,LOW);digitalWrite(2,LOW);delayMicroseconds(3906);}
        break;
        
        case 'G':
        j=21;
        digitalWrite(trig1,HIGH);digitalWrite(12,HIGH);delayMicroseconds(15624);digitalWrite(trig1,LOW);digitalWrite(12,LOW);delayMicroseconds(3906);for (int i =j;i<=j+3;i++){
          digitalWrite(trig1,int(s.charAt(i))-48);digitalWrite(2,int(s.charAt(i))-48);delayMicroseconds(3906);digitalWrite(trig1,LOW);digitalWrite(2,LOW);delayMicroseconds(3906);}
        break;
        
        case 'H':
        j=25;
        digitalWrite(trig1,HIGH);digitalWrite(12,HIGH);delayMicroseconds(15624);digitalWrite(trig1,LOW);digitalWrite(12,LOW);delayMicroseconds(3906);for (int i =j;i<=j+3;i++){
          digitalWrite(trig1,int(s.charAt(i))-48);digitalWrite(2,int(s.charAt(i))-48);delayMicroseconds(3906);digitalWrite(trig1,LOW);digitalWrite(2,LOW);delayMicroseconds(3906);}
        break;
        
        case 'I':
        j=29;
        digitalWrite(trig1,HIGH);digitalWrite(12,HIGH);delayMicroseconds(15624);digitalWrite(trig1,LOW);digitalWrite(12,LOW);delayMicroseconds(3906);for (int i =j;i<=j+3;i++){
          digitalWrite(trig1,int(s.charAt(i))-48);digitalWrite(2,int(s.charAt(i))-48);delayMicroseconds(3906);digitalWrite(trig1,LOW);digitalWrite(2,LOW);delayMicroseconds(3906);}
        break;
        
         case 'J':
        j=33;
        digitalWrite(trig1,HIGH);digitalWrite(12,HIGH);delayMicroseconds(15624);digitalWrite(trig1,LOW);digitalWrite(12,LOW);delayMicroseconds(3906);for (int i =j;i<=j+3;i++){
          digitalWrite(trig1,int(s.charAt(i))-48);digitalWrite(2,int(s.charAt(i))-48);delayMicroseconds(3906);digitalWrite(trig1,LOW);digitalWrite(2,LOW);delayMicroseconds(3906);}
        break;
        
        case 'K':
        j=37;
        digitalWrite(trig1,HIGH);digitalWrite(12,HIGH);delayMicroseconds(15624);digitalWrite(trig1,LOW);digitalWrite(12,LOW);delayMicroseconds(3906);for (int i =j;i<=j+3;i++){
          digitalWrite(trig1,int(s.charAt(i))-48);digitalWrite(2,int(s.charAt(i))-48);delayMicroseconds(3906);digitalWrite(trig1,LOW);digitalWrite(2,LOW);delayMicroseconds(3906);}
        break;
        
        case 'L':
        j=41;
        digitalWrite(trig1,HIGH);digitalWrite(12,HIGH);delayMicroseconds(15624);digitalWrite(trig1,LOW);digitalWrite(12,LOW);delayMicroseconds(3906);for (int i =j;i<=j+3;i++){
          digitalWrite(trig1,int(s.charAt(i))-48);digitalWrite(2,int(s.charAt(i))-48);delayMicroseconds(3906);digitalWrite(trig1,LOW);digitalWrite(2,LOW);delayMicroseconds(3906);}
        break;
        
        case 'M':
        j=45;
        digitalWrite(trig1,HIGH);digitalWrite(12,HIGH);delayMicroseconds(15624);digitalWrite(trig1,LOW);digitalWrite(12,LOW);delayMicroseconds(3906);for (int i =j;i<=j+3;i++){
          digitalWrite(trig1,int(s.charAt(i))-48);digitalWrite(2,int(s.charAt(i))-48);delayMicroseconds(3906);digitalWrite(trig1,LOW);digitalWrite(2,LOW);delayMicroseconds(3906);}
        break;
        
        
        case 'N':
        j=49;
        digitalWrite(trig1,HIGH);digitalWrite(12,HIGH);delayMicroseconds(15624);digitalWrite(trig1,LOW);digitalWrite(12,LOW);delayMicroseconds(3906);for (int i =j;i<=j+3;i++){
          digitalWrite(trig1,int(s.charAt(i))-48);digitalWrite(2,int(s.charAt(i))-48);delayMicroseconds(3906);digitalWrite(trig1,LOW);digitalWrite(2,LOW);delayMicroseconds(3906);}
        break;
        
        case 'O':
        j=53;
        digitalWrite(trig1,HIGH);digitalWrite(12,HIGH);delayMicroseconds(15624);digitalWrite(trig1,LOW);digitalWrite(12,LOW);delayMicroseconds(3906);for (int i =j;i<=j+3;i++){
          digitalWrite(trig1,int(s.charAt(i))-48);digitalWrite(2,int(s.charAt(i))-48);delayMicroseconds(3906);digitalWrite(trig1,LOW);digitalWrite(2,LOW);delayMicroseconds(3906);}
        break;
        
         case 'P':
        j=57;
        digitalWrite(trig1,HIGH);digitalWrite(12,HIGH);delayMicroseconds(15624);digitalWrite(trig1,LOW);digitalWrite(12,LOW);delayMicroseconds(3906);for (int i =j;i<=j+3;i++){
          digitalWrite(trig1,int(s.charAt(i))-48);digitalWrite(2,int(s.charAt(i))-48);delayMicroseconds(3906);digitalWrite(trig1,LOW);digitalWrite(2,LOW);delayMicroseconds(3906);}
        break;
        
        
        case 'Q': // for car
        j=61;
        digitalWrite(trig1,HIGH);digitalWrite(12,HIGH);delayMicroseconds(15624);digitalWrite(trig1,LOW);digitalWrite(12,LOW);delayMicroseconds(3906);for (int i =j;i<=j+3;i++){
          digitalWrite(trig1,int(s.charAt(i))-48);digitalWrite(2,int(s.charAt(i))-48);delayMicroseconds(3906);digitalWrite(trig1,LOW);digitalWrite(2,LOW);delayMicroseconds(3906);}
          
        break;
      
    case 't':
    for (int j = 0;j<48;j++){
        Serial.println(s.charAt(j));}
        break;
      }
      }
      }  
     



 
            

