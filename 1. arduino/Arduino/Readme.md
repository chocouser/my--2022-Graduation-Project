### Arduino

## 아두이노 관련해서 개발한 사항들을 적는곳 입니다 

11월/ 01일 아두이노 개발시작.

향후 개발 사항
<br>

| 회차 | 졸업작품 | 과제 | 내용 |
| ------ | -- | -- |----------- |
| 1회차 | ☑️ | ☑️ | 기본적인 사항 개발  |
| 2회차 | ☑️ | ☑️ | 하드웨어 설계 |
| 3회차 | ☑️ | ☑️ | 하드웨어 조립 및 테스트 |
| 4회차 | ☑️ | ☑️ | 코드 수정 및 유지보수 |
| 4회차 |  |  | 졸업작품 최종발표 |
<br>

## 1회차
<br>
아두이노 LED 회로도 및 하드웨어 제작
<img whith="30%" height="30%" src="https://user-images.githubusercontent.com/73435598/201585003-3809f414-b1eb-4be5-acfb-26a6d8a2b020.PNG"/><br>
아두이노 코드 작성<br>

```c
#define LED1  9 //LED핀 번호
#define LED2 10 

void setup(){
 pinMode(LED2, OUTPUT);
 pinMode(LED1, OUTPUT);
}
void loop(){
if(data == 'a'){  
      digitalWrite(LED2, HIGH);  //LED 켜기
      digitalWrite(LED1, HIGH);  //LED 켜기
  }
  
  else if(data == 'b'){  
      digitalWrite(LED2, LOW);  //LED 끄기
      digitalWrite(LED1, LOW);  //LED 끄기
      
  }
}
```
## 2회차
<br>
아두이노 LCD 코드 및 하드웨어 
<img whith="30%" height="30%" src="https://user-images.githubusercontent.com/73435598/201587779-a33ac171-b384-4067-939c-c5c22049e490.PNG"/><br>
아두이노 코드 작성<br>

```c
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
void setup()
{
Serial.begin(9600);  //하드웨어 시리얼 통신 준비
 lcd.init(); 		// initialize the lcd 
  lcd.backlight();
  lcd.setCursor(2,0);
  delay(5000);
  lcd.clear();
}
void loop()
{
float h = dht.readHumidity();
  float t = dht.readTemperature();

  if(isnan(h) || isnan(t)){
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }

  Serial.print((int)t); Serial.print("*C ");
  Serial.print((int)h); Serial.println("%");

  //delay(1000);

  lcd.setCursor(0,0); // LCD Cursor 원점
  lcd.print("TEMP: "); // LCD에 "temp" 표시
  
  lcd.print(t,1); // 온도값 LCD로 출력
  lcd.print(" C"); // 온도 단위 표시
  lcd.setCursor(0,1); //LCD 커서 줄바꿈
  lcd.print("HUMI: "); //LCD 2번째 줄에 "humidity:" 출력

  lcd.print(h); //습도값 LCD에 출력
  lcd.print(" %"); //습도 단위 출력
}
```
## 3회차
<br>
아두이노 DHT,FAN,HC-06 코드 및 하드웨어 
<img whith="30%" height="30%" src="https://user-images.githubusercontent.com/73435598/201589008-98085a64-c654-4530-8b51-89d28231c13b.PNG"/><br>
아두이노 코드 작성<br>

```c
#include <SoftwareSerial.h>
#include<Servo.h>
#include<LiquidCrystal_I2C.h>
#include <Wire.h>
#include "DHT.h"
 
#define LED1  9 //LED핀 번호
#define LED2 10 
#define BTtx 8   // 블루투스 tx핀이 연결된 아두이노 핀 번호
#define BTrx 7 // 블루투스 rx핀이 연결된 아두이노 핀 번호




#define DHTPIN 2
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);
int FAN = 5;
int FAN2 = 6;


SoftwareSerial BT(BTtx, BTrx);  //소프트웨어 시리얼 객체

Servo myservo1;
Servo myservo2;

char data = 0;  //모바일 앱으로부터 입력받은 값 저장할 변수

void setup(){
  dht.begin();
  BT.begin(9600);  //소프트웨어 시리얼 통신 준비
  Serial.begin(9600);  //하드웨어 시리얼 통신 준비
  myservo1.attach(3);
  myservo2.attach(4);
  

  pinMode(LED2, OUTPUT);
  pinMode(LED1, OUTPUT);  //4번핀 출력 모드
  
  
  pinMode(FAN,OUTPUT);
  pinMode(FAN2,OUTPUT);

 
  
}


void loop(){
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  if(isnan(h) || isnan(t)){
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }
  Serial.print((int)t); Serial.print("*C ");
  Serial.print((int)h); Serial.println("%");

  delay(5000);

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

  else if (data == 'c'){
    myservo2.writeMicroseconds(1700);
    myservo1.writeMicroseconds(1300);
    delay(1000);  
    myservo2.writeMicroseconds(1500);
    myservo1.writeMicroseconds(1500); 
  }

  
  data = 0;  //data 초기화

  if(((float)h)>=60){
    digitalWrite(FAN,HIGH);
    digitalWrite(FAN2,HIGH);
  }
  else if(((float)h)<=35){
     digitalWrite(FAN,LOW);
     digitalWrite(FAN2,LOW);
  }

}
```

## 4회차

<br>
아두이노 완성본
<img whith="30%" height="30%" src="https://user-images.githubusercontent.com/73435598/201589734-9e650426-bf64-4272-8b0e-c8a2db319efd.PNG"/><br>
아두이노 코드 작성<br>

```c
#include <SoftwareSerial.h>
#include<Servo.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include "DHT.h"

#define key1 11 //초록색
#define key2 12 //노란색1
#define key3 13 //노란색2

#define LED1  9 //LED핀 번호
#define LED2 10 
#define BTtx 8   // 블루투스 tx핀이 연결된 아두이노 핀 번호
#define BTrx 7 // 블루투스 rx핀이 연결된 아두이노 핀 번호


#define DHTPIN 2
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);
int FAN = 5;
int FAN2 = 6;


SoftwareSerial BT(BTtx, BTrx);  //소프트웨어 시리얼 객체
// Set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x27, 16, 2);
Servo myservo1;
Servo myservo2;

char data = 0;  //모바일 앱으로부터 입력받은 값 저장할 변수

void setup()
{
  BT.begin(9600);  //소프트웨어 시리얼 통신 준비
  Serial.begin(9600);  //하드웨어 시리얼 통신 준비
  dht.begin();

  myservo1.attach(3);
  myservo2.attach(4);
  
 
  lcd.init(); 		// initialize the lcd 
  lcd.backlight();
  lcd.setCursor(2,0);
  delay(5000);
  lcd.clear();

  pinMode(LED2, OUTPUT);
  pinMode(LED1, OUTPUT);  //4번핀 출력 모드
  
  Serial.begin(9600);
  pinMode(FAN,OUTPUT);
  pinMode(FAN2,OUTPUT);
  
  pinMode(key1, INPUT_PULLUP);
  pinMode(key2, INPUT_PULLUP);
  pinMode(key3, INPUT_PULLUP);

 
}

void loop()
{
  int key1S = digitalRead(key1);
  int key2S = digitalRead(key2);
  int key3S = digitalRead(key3);

  if(!key1S){
     Serial.println("key 1 is pressed");
      digitalWrite(LED2, HIGH);  //LED 켜기
      digitalWrite(LED1, HIGH);  //LED 켜기
    }
     
   if (!key2S) {
    Serial.println("key 2 is pressed");
    
     digitalWrite(LED2, LOW);  //LED 끄기
      digitalWrite(LED1, LOW);  //LED 끄기
    
    }
    
    if (!key3S) {
    Serial.println("key 3 is pressed");
    myservo2.writeMicroseconds(1700);
    myservo1.writeMicroseconds(1300);
    delay(1000);  
    myservo2.writeMicroseconds(1500);
    myservo1.writeMicroseconds(1500); 
    
    
    }


     if(BT.available() > 0){  //블루투스 통신으로 입력된 데이터가 있으면
      data = BT.read();    //입력된 데이터를 읽어서 변수에 저장하기
    }

  
     
      
    

  if(data == 'a'){  
      digitalWrite(LED2, HIGH);  //LED 켜기
      digitalWrite(LED1, HIGH);  //LED 켜기
    }
  
  
  
  if(data == 'b'){  
      digitalWrite(LED2, LOW);  //LED 끄기
      digitalWrite(LED1, LOW);  //LED 끄기
    }
   

 
  if (data == 'c'){
    myservo2.writeMicroseconds(1700);
    myservo1.writeMicroseconds(1300);
    delay(1000);  
    myservo2.writeMicroseconds(1500);
    myservo1.writeMicroseconds(1500); 

    }
  

  data = 0;  //data 초기화



  float h = dht.readHumidity();
  float t = dht.readTemperature();

  if(isnan(h) || isnan(t)){
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }

  Serial.print((int)t); Serial.print("*C ");
  Serial.print((int)h); Serial.println("%");

  //delay(1000);

  lcd.setCursor(0,0); // LCD Cursor 원점
  lcd.print("TEMP: "); // LCD에 "temp" 표시
  
  lcd.print(t,1); // 온도값 LCD로 출력
  lcd.print(" C"); // 온도 단위 표시
  lcd.setCursor(0,1); //LCD 커서 줄바꿈
  lcd.print("HUMI: "); //LCD 2번째 줄에 "humidity:" 출력

  lcd.print(h); //습도값 LCD에 출력
  lcd.print(" %"); //습도 단위 출력
  //delay(500); // 샘플링 간격 2초

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
```

## 기여 방법

1. 제 졸업작품 저장소를 포크합니다.
2. 명령어로 커밋하세요.
3. 명령어로 브랜치에 푸시하세요. 
4. 풀리퀘스트를 보내주세요.
