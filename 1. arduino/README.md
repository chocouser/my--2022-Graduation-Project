- 1
![1](https://user-images.githubusercontent.com/101080195/206977091-f83c91c9-12c7-45e3-a694-aaabc69ff0f4.png)

- 2
![2](https://user-images.githubusercontent.com/101080195/206978231-e476fbfb-32e8-4dfe-a44b-d9fe47b19ad8.png)

- 3
![3](https://user-images.githubusercontent.com/101080195/206978233-e763b50b-8272-4add-be91-ae40cfe0b373.png)

- 코드

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
