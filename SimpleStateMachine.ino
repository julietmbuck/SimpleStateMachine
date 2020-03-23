int buttonState = 0; 
int lastButtonState = 0; 
int buttonCounter = 0; 



int ledPin = 13; 
int buttonPin = 7; 

void setup()
{
  pinMode(ledPin, OUTPUT);
   pinMode(buttonPin, OUTPUT);
  Serial.begin(9600); 
}

void loop()
{
  int btnVal = analogRead(buttonPin); 
  Serial.println(btnVal); 
  
if (buttonState != lastButtonState) {

    if (buttonState == HIGH) {

      buttonCounter += 1;
      Serial.println("on");
      Serial.print("number of button pushes: ");
      Serial.println(buttonCounter);
    } else {
  
      Serial.println("off");
    }

    delay(5); 
  }

  lastButtonState = buttonState;
  
  buttonCounter = buttonCounter % 5;
  
  if (buttonCounter == 4) {
    digitalWrite(ledPin, HIGH); 
   
  } else {
    
    digitalWrite(ledPin, LOW); }
  
  if (buttonCounter == 5) {
    buttonCounter = 0; 
  }

}