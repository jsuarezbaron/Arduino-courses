const int button = 8;

void setup() {
  for (int pin = 2; pin <= 7; pin++) {
    pinMode(pin, OUTPUT);
  }
  pinMode(button, INPUT);
  Serial.begin(9600);

}

void semaphoreOne() {
  digitalWrite(2, HIGH);
  int count = 0;
  while (count < 50) {
    int valor=digitalRead(button); 
    Serial.println(valor);
    if (valor==false) {
      break;
    }
    count++;
    delay(200);
  }
  digitalWrite(2, LOW);
  digitalWrite(3, HIGH);
  delay(2500);
  digitalWrite(3, LOW);
  digitalWrite(4, HIGH);
  digitalWrite(7, LOW);
  digitalWrite(6, HIGH);
  delay(2500);
  digitalWrite(6, LOW);
  semaphoreTwo();
}

void semaphoreTwo() {
  digitalWrite(5, HIGH);
  int count = 0;
  while (count < 50) {
     int valor=digitalRead(button); 
    Serial.println(valor);
    if (valor==false) {
      break;
    }
    count++;
    delay(200);
  }
  digitalWrite(5, LOW);
  digitalWrite(6, HIGH);
  delay(2500);
  digitalWrite(6, LOW);
  digitalWrite(7, HIGH);
  digitalWrite(4, LOW);
  digitalWrite(3, HIGH);
  delay(2500);
  digitalWrite(3, LOW);
  semaphoreOne();
}

void loop() {
  for (int pin = 2; pin <= 7; pin++) {
    digitalWrite(pin, LOW);
  }
  digitalWrite(2, HIGH);
  digitalWrite(7, HIGH);
  semaphoreOne();
}
