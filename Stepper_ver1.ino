#define yonPin   2   //yön değişkeni için low olursa ileri hıgh olursa geri
#define adimPin  3   //adım pini low ve hıgh olmalı 


/********************************************************/
/********************************************************/
//emir verleri

// Ileri_Don   202
// Geri_Don    203

/********************************************************/
/********************************************************/
     
String emir,turSayisi,turSuresi;

void adim() 
{
  digitalWrite(adimPin, LOW);
  delay(turSuresi.toInt());
  digitalWrite(adimPin, HIGH);
  delay(turSuresi.toInt());
 
}
void adim (int toplamAdim)
{
    for(int i=0;i<toplamAdim;i++)
    {
     adim();
    }  
}

void setup() {
  // sabit değişkenler
  
    
    pinMode(adimPin, OUTPUT);
    pinMode(yonPin, OUTPUT);
    Serial.begin(9600); 
   
}
void loop() {
 
   if(Serial.available())
   {
    emir=Serial.readStringUntil(',');
    Serial.println(emir);
    turSayisi=Serial.readStringUntil(',');
    Serial.println("Tur Sayisi:"+turSayisi);
    turSuresi=Serial.readStringUntil(',');
    Serial.println("Tur Sayisi:"+turSuresi);
      
  switch(emir.toInt())
     {
          
          case  202:
            digitalWrite (yonPin, LOW);
            adim(turSayisi.toInt());
            break;
          case 203:
           digitalWrite (yonPin, HIGH);
          adim(turSayisi.toInt());
           break;
 
      }
               
     }
}
