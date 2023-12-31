 char val; // Data received from the serial port
 int led1 = 9; // Set the pin to digital I/O 9
 int led2 = 10;
 int led3 = 11;
 
void setup() {
  pinMode(led1, OUTPUT); // set pin as output
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  Serial.begin(9600); // initialize serial communications at a 9600 baud rate
}

void loop() {
  if (Serial.available()) { // if data is available to read
    val = Serial.read(); // read it and store it in val
  }
 if (val == '1') { // if 1 was received
  digitalWrite(led1, HIGH); // turn LED on  
  digitalWrite(led2, HIGH);
  digitalWrite(led3, HIGH);
}
 else  {
   digitalWrite(led1, LOW); //otherwise turn it off
   digitalWrite(led2, LOW);
   digitalWrite(led3, LOW);
  }
}
