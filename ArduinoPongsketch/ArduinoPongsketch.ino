int buttonInput = 2;
int LED = 8;
int buttonState = 0;
int x_pin = A0;
int y_pin = A1;

int x_pos = 0;
int y_pos = 0;

void setup(){

  pinMode(buttonInput,INPUT);
  pinMode(LED,OUTPUT);
  
  pinMode(x_pin,INPUT);
  pinMode(y_pin,INPUT);
  
  digitalWrite(buttonInput,HIGH);
  
  Serial.begin(9600);
  
}

void loop(){

buttonState = digitalRead(buttonInput);
  
int value = buttonState;

x_pos = analogRead(x_pin);
y_pos = analogRead(y_pin);

//DOWN joystick
while ((y_pos >=520) && ((x_pos <=600) && (x_pos >=400)))
{
  Serial.println("2");
  x_pos = analogRead(x_pin);
  y_pos = analogRead(y_pin);

//Serial.print(x_pos);
//Serial.print(" : ");
//Serial.print(y_pos);
//Serial.println();

  delay(10);
}
//UP joystick
while ((y_pos <= 500) && ((x_pos <=600) && (x_pos >=400)))
{
  Serial.println("3");
  x_pos = analogRead(x_pin);
  y_pos = analogRead(y_pin);

//Serial.print(x_pos);
//Serial.print(" : ");
//Serial.print(y_pos);
//Serial.println();

  delay(10);
}
//PRESSED button
while (value == 1)
{
 Serial.println("0");
  digitalWrite(LED,LOW);
  buttonState = digitalRead(buttonInput);
  value = buttonState;
  delay(10);
}
//NOTPRESSED button
  digitalWrite(LED,HIGH);
  Serial.println("1");
  delay(10);
}

