int on = 3;
int motorplus = 6;
int waterplus = 8;
int soilplus = 9;
int watergreen = 5;
int wateryellow = 4;
int soilgreen = 10;
int soilyellow = 11;
int waterLevel = 0;  //القيمه البدائيه للحساس
int soil = 0; //القيمه البدائيه للحساس
int mp1= 12;
int mp2=13;

void setup() { // قيم ثابته
  Serial.begin (9600);
  pinMode (motorplus, OUTPUT);
  pinMode (waterplus, OUTPUT);
  pinMode (soilplus, OUTPUT);
  pinMode (watergreen, OUTPUT);
  pinMode (wateryellow, OUTPUT);
  pinMode (on, OUTPUT);
  pinMode (mp1, OUTPUT);
  pinMode (mp2, OUTPUT);
  pinMode (soilgreen, OUTPUT);
  pinMode (soilyellow, OUTPUT);
  digitalWrite (on ,HIGH);
  digitalWrite (mp1 ,HIGH);
  digitalWrite (mp2 ,HIGH);
  digitalWrite (waterplus, HIGH);
  digitalWrite (soilplus, HIGH);
}

void loop() {
  
  waterLevel = analogRead (A1) ;
  Serial.print("water level=");
  Serial.println(waterLevel);
  
  soil = analogRead (A0) ;
  Serial.print("soil=");
  Serial.println(soil);

  
  if (soil > 300 && waterLevel > 400) 
  {
    digitalWrite(motorplus, HIGH);
  }
    else
    {
    digitalWrite(motorplus, LOW);
    }


 if ( waterLevel > 400)
 {
 digitalWrite( watergreen, HIGH); 
 digitalWrite( wateryellow, LOW);
 }
  else
  {
    digitalWrite( watergreen, LOW); 
    digitalWrite( wateryellow, HIGH);
  }


  if (soil < 300) 
  {
 digitalWrite( soilgreen, HIGH); 
 digitalWrite( soilyellow, LOW);
  }
    else
    {
     digitalWrite( soilgreen, LOW); 
     digitalWrite( soilyellow, HIGH);
   }
  
}
