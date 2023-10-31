//Incluyo librerias
#include <DHT.h>
#include <DHT_U.h> // librerias del sensor de humedad y temp
#include "RTClib.h"
#include <SD.h>
#include "PMS.h"
#include <SoftwareSerial.h>
#include <Wire.h>
 
File myFile;
RTC_DS3231 rtc;

//Definiciones para el sensor PMS1003
SoftwareSerial pmsSerial(2, 3);
PMS pms(pmsSerial);
PMS::DATA data;

//Defino las variables que se van a usar en el proceso y los pines de arduino
float p10, p25, p01;
int error;
int x,y,z,t,a,b;
int SENSOR = 8;     // pin DATA de DHT22 a pin digital 8
int TEMPERATURA;
int HUMEDAD;
int LROJO = 5;
int LVERDE = 6;

//Sensor de temperatura y humedad
DHT dht(SENSOR, DHT22);   // creacion del objeto, cambiar segundo parametro
        // por DHT11 si se utiliza en lugar del DHT22
        
void setup () {
  Serial.begin(9600); 
  pmsSerial.begin(9600);  
  dht.begin();      // inicializacion de sensor
  pinMode(LROJO, OUTPUT);
  pinMode(LVERDE, OUTPUT);
  digitalWrite(LROJO,LOW);
  digitalWrite(LVERDE,HIGH);
  
  Serial.print("Initializing SD card...");
  // SD card pin output
  pinMode(10, OUTPUT);
 
  if (!SD.begin(10)) {
    Serial.println("SD initialization failed!");
    digitalWrite(LROJO,HIGH);
    digitalWrite(LVERDE,LOW);
    return;
  }
  Serial.println("SD initialization done.");

  delay(3000); // wait for console opening

  if (!rtc.begin()) {
    Serial.println("rtc initialization failed!");
    digitalWrite(LROJO,HIGH);
    digitalWrite(LVERDE,LOW);
    while (1);
  }

//La linea que tengo que comentar es rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));

  if (rtc.lostPower()) {
    Serial.println("RTC lost power, lets set the time!");
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
    // following line sets the RTC to the date & time this sketch was compiled
 
    // This line can be used to set the RTC with an explicit date & time, for example to set
    // January 21, 2014 at 3am you would call:
    // rtc.adjust(DateTime(2014, 1, 21, 3, 0, 0));
  }
  
  myFile = SD.open("PMlog.txt", FILE_WRITE);
  // if the file opened okay, write to it:
  if (myFile) {
    myFile.print("FECHA");
    myFile.print(";");
    myFile.print("HORA");
    myFile.print(";");
    myFile.print("TEMP1");
    myFile.print(";");
    myFile.print("PM01" );   
    myFile.print(";");
    myFile.print("PM25" );
    myFile.print(";");
    myFile.print("PM10" );
    myFile.print(";");  
    myFile.print("TEMP2 " );
    myFile.print(";");
    myFile.println("HUM");
    // close the file:
    myFile.close();
    Serial.println("done.");
  } 
  else {
    // if the file didn't open, print an error:
    Serial.println("error opening text file");
    digitalWrite(LROJO,HIGH);
    digitalWrite(LVERDE,LOW);
  }    
}

void loop () {
  DateTime now = rtc.now();
  TEMPERATURA = dht.readTemperature();  // obtencion de valor de temperatura
  HUMEDAD = dht.readHumidity();   // obtencion de valor de humedad
  pms.requestRead();
  t = rtc.getTemperature();
  
  if (pms.readUntil(data))
  {
    Serial.print("PM 1.0 (ug/m3): ");
    Serial.println(data.PM_AE_UG_1_0);

    Serial.print("PM 2.5 (ug/m3): ");
    Serial.println(data.PM_AE_UG_2_5);

    Serial.print("PM 10.0 (ug/m3): ");
    Serial.println(data.PM_AE_UG_10_0);

    Serial.println("Temperatura: " + String(TEMPERATURA));
    Serial.println(" Humedad: " + String(HUMEDAD));
    
    Serial.print(" Fecha: ");
    Serial.print(now.year(), DEC);
    Serial.print('/');
    Serial.print(now.month(), DEC);
    Serial.print('/');
    Serial.println(now.day(), DEC);
    Serial.print(" Hora: ");
    Serial.print(now.hour(), DEC);
    Serial.print(':');
    Serial.print(now.minute(), DEC);
    Serial.print(':');
    Serial.println(now.second(), DEC);

  }
  else
  {
    Serial.println("No data.");
    digitalWrite(LROJO,HIGH);
    digitalWrite(LVERDE,LOW);
  }
  
  x = (int) data.PM_AE_UG_1_0;
  y = (int) data.PM_AE_UG_2_5;
  z = (int) data.PM_AE_UG_10_0;
  a = (int) TEMPERATURA;
  b = (int) HUMEDAD;
  
  // open the file. note that only one file can be open at a time,
  // so you have to close this one before opening another.
  myFile = SD.open("PMlog.txt", FILE_WRITE);
 
  // if the file opened okay, write to it:
  if (myFile) {
    Serial.print("Writing to PMlog.txt...");
    myFile.print(now.year(), DEC);
    myFile.print('/');
    myFile.print(now.month(), DEC);
    myFile.print('/');
    myFile.print(now.day(), DEC);
    myFile.print(";");
    myFile.print(now.hour(), DEC);
    myFile.print(':');
    myFile.print(now.minute(), DEC);
    myFile.print(':');
    myFile.print(now.second(), DEC);
    myFile.print(";");
    myFile.print(t);
    myFile.print(";");
    myFile.print(String(x));
    myFile.print(";");
    myFile.print(String(y));
    myFile.print(";");
    myFile.print(String(z));  
    myFile.print(";");
    myFile.print(String(a));
    myFile.print(";");
    myFile.println(String(b));
    // close the file:
    myFile.close();
    Serial.println("done.");
  } 
  else {
    // if the file didn't open, print an error:
    Serial.println("error opening text file");
    digitalWrite(LROJO,HIGH);
    digitalWrite(LVERDE,LOW);
  }    
    delay(10000);
}
