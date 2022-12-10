/*
   PIR sensor tester
*/

int ledPin = 12;                // choose the pin for the LED
int inputPin = 14;               // choose the input pin (for PIR sensor)
int val = 0;                     // variable for reading the pin status
int pirState = LOW;
int paciente = 1;
bool pacienteDentro = false;                   

void setup() {
  pinMode(ledPin, OUTPUT);      // declare LED as output
  pinMode(inputPin, INPUT);     // declare sensor as input

  Serial.begin(9600);
}

void loop() {
  val = digitalRead(inputPin);  // read input value
  if (val == HIGH) {            // check if the input is HIGH
    digitalWrite(ledPin, HIGH);  // turn LED ON
    if(pirState == LOW){
      if (pacienteDentro == false) {
        // paciente entra
        Serial.print("Paciente ");
        Serial.print(paciente);
        Serial.print(" detectado en la unidad renal.\nHistorial del paciente descargado.\n");

        pacienteDentro = true;
      }else {
        // paciente sale
        Serial.print("Paciente ");
        Serial.print(paciente);
        Serial.print(" abandona la unidad renal.\nVisita almacenada en el historial.\n");

        pacienteDentro = false;
        paciente++;
      }
    }
    pirState = HIGH;
  }else{
    digitalWrite(ledPin, LOW); // turn LED OFF
    pirState = LOW;
  }
}
