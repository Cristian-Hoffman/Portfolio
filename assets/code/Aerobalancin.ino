// Definir variables
#define SensorInput_GPIO A0 
#define OutputPWM_GPIO 9  
#define pwmRes 12   
#define pwmMax 4095 

// Variables de escala
#define Uunits 100  // Ahora representa el 100% de PWM

// Control de tiempo
unsigned long previousMillis = 0;  
float Ts = 10; // Tiempo de muestreo [ms]

// Variables de medición
float angle = 0.0;
int rawValue = 0;


// Control PID
float Ref = 0;          // Valor inicial de la rampa
float Ref_final = 120;   // Valor final deseado
float ramp_rate = 0.01; // Velocidad de cambio por ciclo (~0.05° cada 10ms)
const float U_op = 0.0;
float U_t = 0.0;      // Salida total del control
unsigned int pwmPercent = 0;

// Comunicación serial
const byte numChars = 32;
char receivedChars[numChars];
boolean newData = false;

float kp = 0.8; 
float ki = 0.5;
float kd = 0.04;
float N = 100;
float T = Ts/1000;
float a = 0.1046;
float b = 0.03513;


float error = 0.0; //Error actual
float ep = 0.0; //Error pasado e(k-1)
float Uc = 0.0; //Control actual
float U = 0.0;
float Up = 0.0;
float Uip = 0.0;
float Udp = 0.0;
float Redp = 0.0;


void calibracion(void) {
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= Ts) {
    previousMillis = currentMillis;

    // --- Rampa en la referencia ---
    if (Ref < Ref_final) {
      Ref += ramp_rate;
      if (Ref > Ref_final) Ref = Ref_final;
    } else if (Ref > Ref_final) {
      Ref -= ramp_rate;
      if (Ref < Ref_final) Ref = Ref_final;
    }

    // Leer sensor y convertir a ángulo
    rawValue = analogRead(SensorInput_GPIO);
    angle = ((rawValue - 238) * 360.0) / 1023.0;

    // Control PID
    error = Ref - angle;

    float P = kp * error;
    float I = ki * T * ep + Uip;
    float D = kd * N * (error - ep) + (1 - N * T) * Udp;

    U = P + I + D;

    float Red = ((T + a) / (T + b)) * U - (a / (T + b)) * Up + (b / (T + b)) * Redp;

    U_t = U_op + Red;

    // Saturación
    float U_tl = min(max(U_t, 0), Uunits);

    // Conversión a PWM 12 bits
    pwmPercent = int((U_tl / Uunits) * pwmMax);
    analogWriteADJ(OutputPWM_GPIO, pwmPercent);

    // Impresión serial
    float pct = (float)pwmPercent / pwmMax * 100.0;
    Serial.print("PWM(%): ");
    Serial.print(pct);
    Serial.print(" | Ángulo: ");
    Serial.print(angle, 2);
    Serial.print(" | Ref: ");
    Serial.print(Ref, 2);
    Serial.print(" | Error: ");
    Serial.println(error, 2);

    // Actualizar variables
    ep = error;
    Uip = I;
    Udp = D;
    Redp = Red;
    Up = U;
  }

  // Leer entrada por serial (para nueva referencia)
  recvWithStartEndMarkers();  
  if (newData == true) {
    parseData();
    newData = false;
  }
}

void setup() {
  Serial.begin(115200);
  pinMode(OutputPWM_GPIO, OUTPUT);
  pinMode(SensorInput_GPIO, INPUT);
  setupPWMadj();
  delay(3000);
}

void loop() {
  calibracion();
}

/* Configura Timer1 para PWM de 12 bits */
void setupPWMadj() {
  DDRB |= _BV(PB1) | _BV(PB2);
  TCCR1A = _BV(COM1A1) | _BV(COM1B1) | _BV(WGM11);
  TCCR1B = _BV(WGM13) | _BV(WGM12) | _BV(CS10);
  ICR1 = 0x0fff;
}

/* Versión extendida de analogWrite() */
void analogWriteADJ(uint8_t pin, uint16_t val){
  switch (pin) {
    case  9: OCR1A = val; break;  // Si el pin es 9, se escribe en OCR1A
    case 10: OCR1B = val; break;  // Si el pin es 10, se escribe en OCR1B
    }
}

void recvWithStartEndMarkers() {
  static boolean recvInProgress = false;
  static byte ndx = 0;
  char startMarker = '<';
  char endMarker = '>';
  char rc;

  while (Serial.available() > 0 && newData == false) {
    rc = Serial.read();

    if (recvInProgress == true) {
      if (rc != endMarker) {
        receivedChars[ndx] = rc;
        ndx++;
        if (ndx >= numChars) {
            ndx = numChars - 1;
        } 
      } else {
        receivedChars[ndx] = '\0';
        recvInProgress = false;
        ndx = 0;
        newData = true;
      }
    } else if (rc == startMarker) {
      recvInProgress = true;
    }
  }
}

void parseData() {
  Ref_final = atof(receivedChars); // Ahora se actualiza la meta de la rampa
}