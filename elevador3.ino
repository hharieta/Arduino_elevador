const byte entrada1 = 3;
const byte entrada2 = 5;
int piso = 1;

String input = "";
bool inputComplete = false;

// instanciar clase Print con el operador <<
template <typename T>
Print& operator<<(Print& printer, T value)
{
    printer.print(value);
    return printer;
}


void setup() {
  pinMode(entrada1, OUTPUT);
  pinMode(entrada2, OUTPUT);
  input.reserve(50);
  Serial.begin(9600);
}

void loop() {
  if(inputComplete) {
    Serial << "COMANDO RECIBIDO: " << input << '\n';
    input.trim();
    processCMD(input);
    input = "";
    inputComplete = false;
  }
}

void serialEvent() {
  while(Serial.available()) {
    char inChar = (char)Serial.read();
    if(inChar == '\n') {
      inputComplete = true;
    } else {
      input += inChar;
    }
  }
}

void processCMD(String cmd) {
  if(cmd.equals("subir")) {
    if(piso >=1 and piso <4) {
      analogWrite(entrada1, 130);
      digitalWrite(entrada2, LOW);
      delay(600);
      digitalWrite(entrada1, LOW);
      digitalWrite(entrada2, LOW);
      piso += 1;
      Serial << "Piso actual: " << piso << '\n';
      
    }else {
      Serial << "Imposible bajar. Piso actual: " << piso << '\n';
    }
  }
  else if(cmd.equals("bajar")) {
    if(piso > 1) {
      digitalWrite(entrada1, LOW);
      analogWrite(entrada2, 120);
      delay(600);
      digitalWrite(entrada1, LOW);
      digitalWrite(entrada2, LOW);
      piso -= 1;
      Serial << "Piso actual: " << piso << '\n';
      
    } else {
      Serial << "Imposible bajar. Piso actual: " << piso << '\n';
    }
  }
}
