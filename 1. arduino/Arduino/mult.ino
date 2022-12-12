#include <SoftwareSerial.h>

#define LED1  9 //LED핀 번호
#define LED2 10 
#define BTtx 8   // 블루투스 tx핀이 연결된 아두이노 핀 번호
#define BTrx 7 // 블루투스 rx핀이 연결된 아두이노 핀 번호

#include "DHT.h"
#define DHTPIN 2
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);
int FAN = 5;
int FAN2 = 6;


SoftwareSerial BT(BTtx, BTrx);  //소프트웨어 시리얼 객체

char data = 0;  //모바일 앱으로부터 입력받은 값 저장할 변수

void setup(){
  BT.begin(9600);  //소프트웨어 시리얼 통신 준비
  Serial.begin(9600);  //하드웨어 시리얼 통신 준비
  pinMode(LED2, OUTPUT);
  pinMode(LED1, OUTPUT);  //4번핀 출력 모드
  
  Serial.begin(9600);
  pinMode(FAN,OUTPUT);
  pinMode(FAN2,OUTPUT);

}

void loop(){
  if(BT.available() > 0){  //블루투스 통신으로 입력된 데이터가 있으면
      data = BT.read();    //입력된 데이터를 읽어서 변수에 저장하기
  }

  
  if(data == 'a'){  
      digitalWrite(LED2, HIGH);  //LED 켜기
      digitalWrite(LED1, HIGH);  //LED 켜기
  }
  
  else if(data == 'b'){  
      digitalWrite(LED2, LOW);  //LED 끄기
      digitalWrite(LED1, LOW);  //LED 끄기
      
  }
  
  data = 0;  //data 초기화

 delay(2000);
  int h = dht.readHumidity();
  int t = dht.readTemperature();
  Serial.print("Humidity: ");
  Serial.print(h);
  Serial.print("%\t");
  Serial.print("Temperature: ");
  Serial.print(t);
  Serial.println("C");

  if(isnan(h) || isnan(t)){
    Serial.println("fail dht");
    return;
  }
  if(((float)h)>=60){
    digitalWrite(FAN,HIGH);
    digitalWrite(FAN2,HIGH);
  }
  else if(((float)h)<=35){
     digitalWrite(FAN,LOW);
     digitalWrite(FAN2,LOW);
  }

}
