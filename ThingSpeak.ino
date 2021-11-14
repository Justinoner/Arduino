#include <M5StickCPlus.h>
#include <WiFi.h>
#include "secrets.h"
#include "ThingSpeak.h"
char ssid[] = SECRET_SSID;
char pass[] = SECRET_PASS;
int keyIndex = 0;
WiFiClient client;

unsigned long myChannelNumber = SECRET_CH-ID;
const char * myWriteAPIKey = SECRET_WRITE_APIKEY;

float accX = 0.0F;
float accY = 0.0F;
float accZ = 0.0F;

float accXSq = 0.0F;
float accYSq = 0.0F;
float accZSq = 0.0F;
float magSq = 0.0F;
float currMag = 0.0F;
float maxMag = 0.0F;
int timerSt = millis();


void setup() {

  
  // put your setup code here, to run once:
  M5.begin();
  M5.IMU.Init();
  M5.Lcd.setRotation(3);
  M5.Lcd.fillScreen(BLACK);
  M5.Lcd.setTextSize(1);
  M5.Lcd.setCursor(50, 15);
  M5.Lcd.println("Max Accel Speak");

  Serial.begin(115200); //Initialize serial
  while (!Serial) {
 
 
}
WiFi.mode(WIFI_STA);
ThingSpeak.begin(client);
}

/***float temp = 0;
/*****************************************
M5.IMU.getGyroData(&gyroX,&gyroY,&gyroZ);
M5.IMU.getAccelData(&accX,&accY,&accZ);
M5.IMU.getAhrsData(&pitch,&roll,&yaw);
M5.IMU.getTempData(&temp);
*****************************************/
void loop() {
  // put your main code here, to run repeatedly:
  M5.IMU.getAccelData(&accX,&accY,&accZ);
  magSq = ((pow(accX,2)) + (pow (accY, 2)) + (pow (accZ,2))) ;
  currMag = pow (magSq, 0.5);
  M5.Lcd.setTextSize (2);
  if (currMag > maxMag){
    maxMag = currMag;
  }

  M5.Lcd.setCursor(80,50);
  M5.Lcd.println(maxMag);

 int timerCur = millis();
 int timerDiff = timerCur - timerSt;

 if(timerDiff > 10000{

  if(WiFi status()[] != WI.CONNECTED){
    Serial.print("Attemtping to connect to ssid: ");
    Serial.printin
    
  }
  }
}
