#include <PID_v1.h>
#include <LiquidCrystal.h>
#include <max6675.h>

/*
Written by github.com/petl, peter@traunmueller.net, 21.08.2016

 *PINOUT:
 * A0--analog IN
 * 9 --SSR OUT
 * 
 * Thermo:
 * 13--SCK
 * 12--MISO (from thermocouple MAX6675K)
 * 10--SS
 * 
 * LCD:
 * A5--RS 
 * A4--E
 * 5 --4
 * 6 --5
 * 7 --6
 * 8 --7
 */

 #define tempIn A0
 #define ssrOut 9
 #define thermoSck 13
 #define thermoMiso 12
 #define thermoSs 10


double tempSoll = 0;
double tempIst = 0;
unsigned long lastTime = 0;
int output = 0;
double outVar = 0;

int WindowSize = 200;
unsigned long windowStartTime;


MAX6675 thermocouple(thermoSck, thermoSs, thermoMiso);
LiquidCrystal lcd(A5, A4, 5, 6, 7, 8);
PID myPID(&tempIst, &outVar, &tempSoll,1.15,1,1, DIRECT);


void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("Booting .!.");
  lcd.setCursor(0,1);
  lcd.print("21.8.16, Peter T");
  pinMode(ssrOut, OUTPUT);
  delay(500);
  lcd.clear();

  windowStartTime = millis();
  tempSoll = analogRead(tempIn);
  tempSoll = map(tempSoll, 0, 1023, 400, 0);  //map to 400-0°C
  myPID.SetOutputLimits(0, WindowSize);
  myPID.SetMode(AUTOMATIC);

}

void loop() {
  tempSoll = analogRead(tempIn);
  tempSoll = map(tempSoll, 0, 1023, 400, 0);  //map to 400-0°C

  myPID.Compute();
  Serial.println("outVar");
  Serial.println(outVar);

  lcd.setCursor(0,0);
  lcd.print("SOLL|IST |STATUS");
  lcd.setCursor(0,1);
  lcd.print("                ");
  lcd.setCursor(0,1);
  lcd.print((int)tempSoll);
  lcd.setCursor(4,1);
  lcd.print("|");
  lcd.print((int)tempIst);
  lcd.setCursor(9,1);
  lcd.print("|");
  if(digitalRead(ssrOut)){ lcd.print("    ON");}
  if(!digitalRead(ssrOut)){lcd.print("   OFF");}

 unsigned long now = millis();
  if(now - windowStartTime>WindowSize)
  { //time to shift the Relay Window
    windowStartTime += WindowSize;
  }
  if(outVar > now - windowStartTime) digitalWrite(ssrOut,HIGH);
  else digitalWrite(ssrOut,LOW);

  if(millis()>(lastTime+200)){   //update every 5sec, the max6675 cant do more. 
    lastTime=millis();
    tempIst = thermocouple.readCelsius();  
  }
  delay(100);
  
}
