#include <Wire.h>
void setup() 
{
  Wire.begin();        // join i2c bus (address optional for master)
  Serial.begin(9600);  // start serial for output
}
void loop() 
{
    Wire.requestFrom(8, 6);    // request 6 bytes from slave device #8
    Serial.print("Received Name of address 8 : ");
    while (Wire.available()) 
    { // slave may send less than requested
        char c = Wire.read(); // receive a byte as character
        Serial.print(c);         // print the character
    }
    Serial.println("\n");

    int charsReceived;
    char inputBuffer[20];            // Make whatever size you need plus one

    if (Serial.available()) {
        charsReceived = Serial.readBytesUntil('\n', inputBuffer, sizeof(inputBuffer) - 1);  // Save room for NULL
        inputBuffer[charsReceived] = NULL;      // Make it a string
        Serial.print("there were ");
        Serial.print(charsReceived);
        Serial.print(" chars received, which are: ");
        Serial.println(inputBuffer);
    }
  
    delay(500);

}
