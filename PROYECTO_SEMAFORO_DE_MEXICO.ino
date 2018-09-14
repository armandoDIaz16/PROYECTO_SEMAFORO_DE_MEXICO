//diseño de un semáforo
//José Armando Díaz Anguiano
//Ingeniería en Sistemas Computacionales 

//DATOS *************************************
  //LEDS del semáforo de autos 
#define led_Verde 13      //jumper verde
#define led_Ambar 12      //jumper ambar
#define led_Rojo  11      //jumper rojo
//Leds del semáforo de peatones 
#define boton_Peatonal 10 //jumper blanco corto 
#define led_VerdePeaton 9 //jumper blanco largo
#define led_RojoPeaton 8  //jumper largo negro
  //entradas analogicas
#define pot A0            //jumper cafe
//JUMPERS BINARIOS
#define led_D 7
#define led_C 6
#define led_B 5
#define led_A 4
//bocina
#define bocina 2
//variables extras
boolean valor_led_Verde = LOW;
boolean valor_boton_Peatonal = LOW;
int valorPot = 0;
const float tiempoAmbar = 2000.0;
const float tiempoRojo  = 3000.0;
int valormap;

  void setup(){
    Serial.begin(9600);
    //Datos de los pines ************************
    pinMode(led_Verde,OUTPUT);      //LED VERDE
    digitalWrite(led_Verde,HIGH);
  
      pinMode(led_Ambar,OUTPUT);    //LED AMBAR
      digitalWrite(led_Ambar,LOW);
        pinMode(led_Rojo,OUTPUT);   //LED ROJO
        digitalWrite(led_Rojo,LOW);
        
          pinMode(boton_Peatonal,INPUT); //BOTON PEATONAL
          pinMode(led_VerdePeaton,OUTPUT);   //LED VERDE PEATON
          digitalWrite(led_VerdePeaton,LOW);
          pinMode(led_RojoPeaton,OUTPUT);   //LED VERDE PEATON
          digitalWrite(led_RojoPeaton,HIGH);
          //JUMPERS BINARIOS 
          pinMode(led_D,OUTPUT);
          digitalWrite(led_D,HIGH);
          pinMode(led_C,OUTPUT);
          digitalWrite(led_C,HIGH);
          pinMode(led_B,OUTPUT);
          digitalWrite(led_B,HIGH);
          pinMode(led_A,OUTPUT);
          digitalWrite(led_A,HIGH);
           pinMode(bocina,OUTPUT);
 
    boolean valor_led_VerdePeaton = LOW;
    boolean valor_led_RojoPeaton  = HIGH;
   
    //DATOS EXTRAS*******************************
    float tiempoVerde  = 1000.0;
    float tiempoPeatonVerde = tiempoRojo;
   
  }
  
void loop(){
  
  valorPot = analogRead(pot);
  valormap = map(valorPot, 0, 1023, 5, 45)*1000; 
  
  Serial.println(valorPot);
  valor_boton_Peatonal = digitalRead(boton_Peatonal);
  
    if(valor_boton_Peatonal==LOW){
      delay(valormap);
      parpadeo3Veces();
      digitalWrite(led_Verde,LOW);
      digitalWrite(led_Ambar,HIGH);
      delay(tiempoAmbar);
      digitalWrite(led_Ambar,LOW);
      digitalWrite(led_Rojo,HIGH);
      digitalWrite(led_RojoPeaton,LOW);
      digitalWrite(led_VerdePeaton,HIGH);
      //delay(tiempoRojo);
      conteo();
      parpadeo3VecesP();    
      digitalWrite(led_VerdePeaton,LOW);
      digitalWrite(led_RojoPeaton,HIGH);
      digitalWrite(led_Rojo,LOW);
      digitalWrite(led_Verde,HIGH);
      }
    
}



  void parpadeo3Veces(){
    digitalWrite(led_Verde,LOW);
    delay(500);
    digitalWrite(led_Verde,HIGH); //1 VEZ
    delay(500);
    digitalWrite(led_Verde,LOW);
    delay(500);
    digitalWrite(led_Verde,HIGH); //2 VEZ
    delay(500);
    digitalWrite(led_Verde,LOW);
    delay(500);
    digitalWrite(led_Verde,HIGH); //3 VEZ
    delay(500);
    
  }
  
  void parpadeo3VecesP(){ 
    digitalWrite(led_VerdePeaton,LOW);
    delay(500);
    digitalWrite(led_VerdePeaton,HIGH); //1 VEZ
    digitalWrite(led_D,LOW);  //3
    digitalWrite(led_C,LOW);
    digitalWrite(led_B,HIGH);
    digitalWrite(led_A,HIGH);
    tone(bocina,100,150);
  digitalWrite(bocina,HIGH);
  digitalWrite(bocina,LOW);
    delay(500);
    digitalWrite(led_VerdePeaton,LOW);
    delay(500);
    digitalWrite(led_VerdePeaton,HIGH); //2 VEZ
    digitalWrite(led_D,LOW);  //2
    digitalWrite(led_C,LOW);
    digitalWrite(led_B,HIGH);
    digitalWrite(led_A,LOW);
    tone(bocina,100,150);
  digitalWrite(bocina,HIGH);
  digitalWrite(bocina,LOW);
    delay(500);
    digitalWrite(led_VerdePeaton,LOW);
    delay(500);
    digitalWrite(led_VerdePeaton,HIGH); //3 VEZ
    digitalWrite(led_D,LOW);  //1
    digitalWrite(led_C,LOW);
    digitalWrite(led_B,LOW);
    digitalWrite(led_A,HIGH);
  tone(bocina,100,150);
  digitalWrite(bocina,HIGH);
  digitalWrite(bocina,LOW);
    delay(1000);
    digitalWrite(led_D,LOW);  //0
    digitalWrite(led_C,LOW);
    digitalWrite(led_B,LOW);
    digitalWrite(led_A,LOW);
    tone(bocina,100,150);
  digitalWrite(bocina,HIGH);
  digitalWrite(bocina,LOW);
    delay(500);
    digitalWrite(led_D,HIGH);  //APAGADO
    digitalWrite(led_C,HIGH);
    digitalWrite(led_B,HIGH);
    digitalWrite(led_A,HIGH);
    
    
  }
  
  void conteo(){
  digitalWrite(led_D,HIGH);  //9
  digitalWrite(led_C,LOW);
  digitalWrite(led_B,LOW);
  digitalWrite(led_A,HIGH);
  tone(bocina,100,150);
  digitalWrite(bocina,HIGH);
  digitalWrite(bocina,LOW);
  delay(1000);
  digitalWrite(led_D,HIGH);  //8
  digitalWrite(led_C,LOW);
  digitalWrite(led_B,LOW);
  digitalWrite(led_A,LOW);
  tone(bocina,100,150);
  digitalWrite(bocina,HIGH);
  digitalWrite(bocina,LOW);
  delay(1000);  
  digitalWrite(led_D,LOW);  //7
  digitalWrite(led_C,HIGH);
  digitalWrite(led_B,HIGH);
  digitalWrite(led_A,HIGH);
  tone(bocina,100,150);
  digitalWrite(bocina,HIGH);
  digitalWrite(bocina,LOW);
  delay(1000);
  digitalWrite(led_D,LOW);  //6
  digitalWrite(led_C,HIGH);
  digitalWrite(led_B,HIGH);
  digitalWrite(led_A,LOW);
  tone(bocina,100,150);
  digitalWrite(bocina,HIGH);
  digitalWrite(bocina,LOW);
  delay(1000);
  digitalWrite(led_D,LOW);  //5
  digitalWrite(led_C,HIGH);
  digitalWrite(led_B,LOW);
  digitalWrite(led_A,HIGH);
  tone(bocina,100,150);
  digitalWrite(bocina,HIGH);
  digitalWrite(bocina,LOW);
  delay(1000);    
  digitalWrite(led_D,LOW);  //4
  digitalWrite(led_C,HIGH);
  digitalWrite(led_B,LOW);
  digitalWrite(led_A,LOW);
  tone(bocina,100,150);
  digitalWrite(bocina,HIGH);
  digitalWrite(bocina,LOW);
  delay(500);
  
}
