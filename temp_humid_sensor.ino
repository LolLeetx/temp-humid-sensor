#include <dht.h>

#define dht_apin A0 // Analog Pin sensor is connected to
String temp_status;
String humid_status; 
dht DHT;
 
void setup(){
 
  Serial.begin(9600);

}
 
void loop(){

 
    DHT.read11(dht_apin);
    
    
    Serial.print(DHT.humidity);
    Serial.print(';');
    Serial.print(DHT.temperature);
    Serial.print(';');
    Serial.print(humid_status); 
    Serial.print(';');
    Serial.println(temp_status);

    if(DHT.humidity > 85){
      humid_status = "high humidity";
    }

    else if(DHT.temperature > 35){
      temp_status = "high temperature";
    }

    else{
      humid_status = "normal humidity";
      temp_status = "normal temperature";
    }
    delay(1000);
 
  //Fastest should be once every two seconds.
 
}// end loop(
