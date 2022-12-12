int buttonPin[] = {11,12,13};
int buttonState = 0;

void setup() {
  Serial.begin(9600);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  for(int x=0; x<4; x++)
  {
    pinMode(buttonPin[x], INPUT_PULLUP);
  }
}

void loop() {
  for(int x=0;x<4;x++){
    buttonState = digitalRead(buttonPin[x]);
    if(buttonState == LOW){
      switch(buttonPin[x]){

        case 11:
        digitalWrite(8, HIGH);
        break;
        case 12:
        digitalWrite(9, HIGH);
        break;
        case 13:
        digitalWrite(8, LOW);
        digitalWrite(9, LOW);
        break;
      }
    }
  }
}
