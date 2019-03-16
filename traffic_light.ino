/*
  Blink

  Turns an LED on for one second, then off for one second, repeatedly.

  Most Arduinos have an on-board LED you can control. On the UNO, MEGA and ZERO
  it is attached to digital pin 13, on MKR1000 on pin 6. LED_BUILTIN is set to
  the correct LED pin independent of which board is used.
  If you want to know what pin the on-board LED is connected to on your Arduino
  model, check the Technical Specs of your board at:
  https://www.arduino.cc/en/Main/Products

  modified 8 May 2014
  by Scott Fitzgerald
  modified 2 Sep 2016
  by Arturo Guadalupi
  modified 8 Sep 2016
  by Colby Newman

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/Blink
*/

// the setup function runs once when you press reset or power the board


int i=0;
//1 = B,C
//2 = A,B,G,E,D
//3 = A,B,G,C,D
//4 = F,G,B,C
//5 = A,F,G,C,D
//6 = A,F,G,C,D,E
//7 = A,B,C
//8 = A,B,C,D,E,F,G
//9 = A,F,G,B,C,D


void turn_on(int temp)
{
  switch(temp)
  {
    case 1:
      digitalWrite(13,HIGH);
      digitalWrite(1,HIGH);
      break;
    case 2:
      digitalWrite(12,HIGH);
      digitalWrite(13,HIGH);
      digitalWrite(10,HIGH);
      digitalWrite(3,HIGH);
      digitalWrite(2,HIGH);
      break;
    case 3:
      digitalWrite(12,HIGH);
      digitalWrite(13,HIGH);
      digitalWrite(10,HIGH);
      digitalWrite(3,HIGH);
      digitalWrite(1,HIGH);
      break;
    case 4:
      digitalWrite(11,HIGH);
      digitalWrite(13,HIGH);
      digitalWrite(10,HIGH);
      digitalWrite(1,HIGH);
      break;
    case 5:
      digitalWrite(12,HIGH);
      digitalWrite(11,HIGH);
      digitalWrite(10,HIGH);
      digitalWrite(3,HIGH);
      digitalWrite(1,HIGH);
      break;
    case 6:
      digitalWrite(12,HIGH);
      digitalWrite(11,HIGH);
      digitalWrite(10,HIGH);
      digitalWrite(3,HIGH);
      digitalWrite(2,HIGH);
      digitalWrite(1,HIGH);
      break;
    case 7:
      digitalWrite(12,HIGH);
      digitalWrite(13,HIGH);
      digitalWrite(1,HIGH);
      break;
    case 8:
      digitalWrite(13,HIGH);
      digitalWrite(12,HIGH);
      digitalWrite(11,HIGH);
      digitalWrite(10,HIGH);
      digitalWrite(3,HIGH);
      digitalWrite(2,HIGH);
      digitalWrite(1,HIGH);
      break;
    case 9:
      digitalWrite(13,HIGH);
      digitalWrite(12,HIGH);
      digitalWrite(11,HIGH);
      digitalWrite(10,HIGH);
      digitalWrite(3,HIGH);
      digitalWrite(1,HIGH);
      break;    
  }
}

void turn_off()
{
  for(int i=0; i<=3; i++)
  {
      digitalWrite(i,LOW);
  }
  
  for(int j=10; j<=13; j++)
  {
      digitalWrite(j,LOW);
  }
}

void green_to_red()
{
  digitalWrite(7,LOW);
  digitalWrite(6,HIGH);
  delay(1000);
  digitalWrite(6,LOW);
  digitalWrite(5,HIGH);
}

void red_to_green()
{
  digitalWrite(6,HIGH);
  delay(1000);
  digitalWrite(5,LOW);
  digitalWrite(6,LOW);
  digitalWrite(7,HIGH);
}

void setup() 
{
  for(int k=0; k<=13; k++)
  {
    pinMode(k,OUTPUT);
    digitalWrite(k,LOW);
  }
  digitalWrite(7,HIGH);

}
 
void loop() 
{

  for(int j=9; j>=1; j--)
  {
    turn_on(j);
    delay(1000);
    turn_off();
    if(j==1)
    {
      if(digitalRead(7)==HIGH)
      {
        green_to_red();
      }
      else
      {
        red_to_green();
      }
    }
  }
}
