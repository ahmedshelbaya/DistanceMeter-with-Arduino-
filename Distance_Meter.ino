/*
* This Code Written By Ahmed Shelbaya Electronic and Embedded system Designer
* To measure Distance and Display it in LCD
*/
#include<LiquidCrystal.h> // Special Library for LCD Instruction
//connect LCD Pin (RS,E,D4,D5,D6,D7)to Arduino Pin (A0, A1, A5, A4, A3, A2)
LiquidCrystal lcd(A0, A1, A5, A4, A3, A2); 
const int trigPin = 7; //Connect Trig pin to Arduino Pin 7
const int echoPin = 8; //Connect Echo Pin to Arduino pin 8
int duration; //Create a Memory location to store duration value
void setup()
{
pinMode(trigPin, OUTPUT); // Define TrigPin As OUTPUT (send data)
pinMode(echoPin, INPUT); //Define EchoPin As INPUT (Receive Data)
lcd.begin(16, 2); // Start Dealing With LCD has 2 Row and 16 column
lcd.print("ultrasonic"); //Show in LCD "Ultrasonic"
//Put the Writing Cursor in the Second ROW and Frist Column
lcd.setCursor(0, 1); 
lcd.print("Range Meter"); // Show in LCD "Range Meter"
delay(2000); // Wait 2 Seconds
}
void loop()
{
lcd.clear(); // Delete any Word in LCD
lcd.print("Distance in cm"); //Show in LCD "Distance in cm"
digitalWrite(trigPin, LOW); //Turn off Trig Pin to stop sending ultrasonic wave
delayMicroseconds(2); // Wait 2 microseconds
digitalWrite(trigPin, HIGH); //Turn on Trig Pin to send Send Ultrasonic Wave
delayMicroseconds(10); //Wait 10 Microseconds
digitalWrite(trigPin, LOW); //Turn off Trig Pin
//Start Receive data from Echo Pin and Calculate time and store in duration .
duration = pulseIn(echoPin, HIGH); 
//create memory location and calculate distance to store in .
int r = 3.4 * duration / 2; 
//create memory location and convert distance to Cm then store results in.
int distance = r / 100.00; 
lcd.setCursor (0, 1); //put writing cursor in second Row and first Column
lcd.print(distance); //Show in LCD the value stored in distance
delay (300); //wait 3 millisecond
}

