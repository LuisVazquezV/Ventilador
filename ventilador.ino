    const int analogPin = A0; // Entrada señal analogica
    const int analogOutPin = 11; // Analog output pin
    byte outputValue = 0;        // valor del PWM
    int pot=512; // almacena la lectura analógica raw del potenciometro
    int percent; // posicion del potenciometro en tanto por ciento
    int last_Value;
    
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  Serial.begin(9600);
  pinMode(12, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(12, HIGH);   //Iniciar motor
  pot = analogRead(analogPin); // lectura analógica raw (0-1023)
  percent = map(pot, 0, 1023, 0, 100); // convertir a porcentaje (0-100)
  outputValue= map(pot, 0, 1023, 0, 255); //convierte a 0-255
  analogWrite(analogOutPin, outputValue);
  if (outputValue!=last_Value) {  // Si se ha modificado el potenciometro
       last_Value = outputValue;
       serial();               // imprime cambios
   }
  delay(100);
}

void serial() { 
   Serial.print ("Potenciometro = ");
   Serial.print (percent, DEC);
   Serial.print ("% \n");
   Serial.print ("Valor PWM = ");
   Serial.print (outputValue);
   Serial.print (" \n");
}
