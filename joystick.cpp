// pin initializations
int JoyStick_X(15); // ADC2_3
int JoyStick_Y(4); // ADC2_2
int button(5); // GPIO5 w/ internal pull up 

void setup() {
  pinMode(JoyStick_X, INPUT);
  pinMode(JoyStick_Y, INPUT);
  pinMode(button, INPUT_PULLUP);

  Serial.begin(9600);
}

void loop() {
  float VRx, VRy;
  bool isPressed;

  VRx = analogRead(JoyStick_X) * (3.3 / 4095.0);
  VRy = analogRead(JoyStick_Y) * (3.3 / 4095.0);
  isPressed = digitalRead(button);

  Serial.print("X: ");
  Serial.print(VRx);
  Serial.print("\t\t");

  Serial.print("Y: ");
  Serial.println(VRy);


  if(!isPressed) {
    Serial.println("Pressed");
  }

  digitalWrite(2, HIGH);
  delay(200);
}
