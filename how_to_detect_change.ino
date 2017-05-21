int initial;
int second;
int infopin = 7;
int digital; 
const int buzzer = 9;
int fanstatus;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
    pinMode(buzzer, OUTPUT); // Set buzzer - pin 9 as an output

}

void loop() 
{
  // put your main code here, to run repeatedly:
  
  fanstatus = checkfan();
if (fanstatus == 1)
{
  delay(5000);
}
if (fanstatus == 0)
{
  fanstatus = checkfan();
}
if (fanstatus == 1)
{
 Serial.println(digital); 
  tone(buzzer, 1000); // Send 1KHz sound signal...
  delay(1000);        // ...for 1 sec
  noTone(buzzer);     // Stop sound...
  delay(1000);        // ...for 1sec
}
}

int checkfan()
{
  //this fuction will check and return the info about the fan if it is on or off.
  initial = digitalRead(infopin);
  second = digitalRead(infopin);
  if (initial != second)
  {
    return 1;
  }
  if (initial == second)
  {
    return 0;
  }
    
  }

  


