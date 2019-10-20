#include <Arduino_FreeRTOS.h>

void TaskBlink1( void *pvParameters );
void TaskBlink2( void *pvParameters );

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  xTaskCreate(
    TaskBlink1, 
    (const portCHAR *)"Blink_One",
    128,
    NULL,
    1,
    NULL
  );

  xTaskCreate(
    TaskBlink2, 
    (const portCHAR *)"Blink_Two",
    128,
    NULL,
    2,
    NULL
  );

}

void loop() {
  // put your main code here, to run repeatedly:

}

void TaskBlink1(void *pvParameters) {
  (void) pvParameters;

  // initialize digital LED_BUILTIN on pin 13 as an output.
  pinMode(9, OUTPUT);

  for (;;) {
    for (int b=0; b<=255; b+=5) {
      analogWrite(9, b);
      vTaskDelay(30/portTICK_PERIOD_MS);
    }
    for (int b=255; b>=0; b-=5) {
      analogWrite(9, b);
      vTaskDelay(30/portTICK_PERIOD_MS);
    }
//    digitalWrite(13, HIGH);   // turn the LED on (HIGH is the voltage level)
//    vTaskDelay( 1000 / portTICK_PERIOD_MS ); // wait for one second
//    digitalWrite(13, LOW);    // turn the LED off by making the voltage LOW
//    vTaskDelay( 1000 / portTICK_PERIOD_MS ); // wait for one second
  }

}

void TaskBlink2(void *pvParameters) {
  (void) pvParameters;

  // initialize digital LED_BUILTIN on pin 11 as an output.
  pinMode(11, OUTPUT);

  for (;;) {
    for (int b=0; b<=255; b+=5) {
      analogWrite(11, b);
      vTaskDelay(30/portTICK_PERIOD_MS);
    }
    for (int b=255; b>=0; b-=5) {
      analogWrite(11, b);
      vTaskDelay(30/portTICK_PERIOD_MS);
    }
    vTaskDelay( 500 / portTICK_PERIOD_MS );
//    digitalWrite(11, HIGH);   // turn the LED on (HIGH is the voltage level)
//    vTaskDelay( 500 / portTICK_PERIOD_MS ); // wait for one second
//    digitalWrite(11, LOW);    // turn the LED off by making the voltage LOW
//    vTaskDelay( 500 / portTICK_PERIOD_MS ); // wait for one second
  }
}
