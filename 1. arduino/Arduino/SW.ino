#define key1 2
#define key2 3
#define key3 4
#define key4 5




void setup() {
  Serial.begin(9600);
  pinMode(key1, INPUT_PULLUP);
  pinMode(key2, INPUT_PULLUP);
  pinMode(key3, INPUT_PULLUP);
  pinMode(key4, INPUT_PULLUP);
}

void loop() {
  int key1S = digitalRead(key1);
  int key2S = digitalRead(key2);
  int key3S = digitalRead(key3);
  int key4S = digitalRead(key4);


  if (!key1S) {
    Serial.println("key 1 is pressed");
  }
  if (!key2S) {
    Serial.println("key 2 is pressed");
  }
  if (!key3S) {
    Serial.println("key 3 is pressed");
  }
  if (!key4S) {
    Serial.println("key 4 is pressed");
  }
}
