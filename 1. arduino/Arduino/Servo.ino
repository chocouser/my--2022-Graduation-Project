#include<Servo.h>
#include <SoftwareSerial.h>
 
int blueTx=2;   //Tx (보내는핀 설정)at
int blueRx=3;   //Rx (받는핀 설정)
SoftwareSerial mySerial(blueTx, blueRx);  //시리얼 통신을 위한 객체선언

Servo myservo1;
Servo myservo2;

//////////////////////////////////////////////////////////// 
void setup()
{
  myservo1.attach(9);
  myservo2.attach(10);
  Serial.begin(9600);   //시리얼모니터
  mySerial.begin(9600); //블루투스 시리얼
  myservo1.write(0);
  myservo2.write(0);
}
void loop()
{
  char cc;
  if (mySerial.available()) {
    cc = (char)mySerial.read();  
    Serial.write(mySerial.read());  //블루투스측 내용을 시리얼모니터에 출력
  }  
  
  if (cc == '1'){
    myservo2.write(90);
    myservo1.write(90);  
  }
  
  if (cc == '2'){
    myservo1.write(0);
    myservo2.write(0);
  }
  
}  
