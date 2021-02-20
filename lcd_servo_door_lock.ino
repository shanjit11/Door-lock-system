 
//Prateek
//www.prateeks.in

#include <Servo.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,20,4);
const int servoPin = 3; 
const int touchPin = 2; 
int touchState = 0;
int directionState = 0;
Servo myservo;
int pos = 0;

void setup() {
lcd.init();                      // initialize the lcd 
lcd.init();
lcd.backlight();
lcd.setCursor(4, 0);
lcd.print(" Touch Based");
lcd.setCursor(2, 1);
lcd.print("Door Lock System");
lcd.setCursor(6, 2);
lcd.print("Made By");
lcd.setCursor(6, 3);
lcd.print("Shanjit");
myservo.attach(3);
pinMode(touchPin, INPUT);

}

void loop(){
touchState = digitalRead(touchPin);
if (directionState == 0){
if (touchState == HIGH) {
directionState = 1;
for(pos = 0; pos < 180; pos += 1)

lcd.clear();
lcd.setCursor(2, 0);
lcd.print("Door Lock System");
lcd.setCursor(2, 1);
lcd.print("(made by SHANJIT)");
lcd.setCursor(0, 2);
lcd.print("Status: Locked");
lcd.setCursor(3, 3);
lcd.print("Touch to Unlock");
{
myservo.write(pos);
delay(15); // waits 15ms to reach the position
}
}

} else if (directionState == 1) {
if (touchState == HIGH) {
directionState = 0;

for (pos = 180; pos>=1; pos -=1)

lcd.clear();
lcd.setCursor(2, 0);
lcd.print("Door Lock System");
lcd.setCursor(2, 1);
lcd.print("(made by SHANJIT)");
lcd.setCursor(0, 2);
lcd.print("Status: Unlocked");
lcd.setCursor(3, 3);
lcd.print("Touch to Lock");
{
myservo.write(pos);
delay(15);
}
}
}
}
