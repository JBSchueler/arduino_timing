# arduino_timing
Arduino Timing

Usage:

```c
#include "timing.h"

#define ledPin       13

#define SOMETIME 333UL
uint32_t prevtime;

void setup()
{
  pinMode( ledPin, OUTPUT ); digitalWrite( ledPin, LOW );
  Serial.begin(115200);

  Serial.print("Start!\r\n");

}

void loop()
{
  if ( timePastFixed( prevtime, SOMETIME ) ) {
    digitalWrite( ledPin, !digitalRead( ledPin ) );
    Serial.print( millis() );
    Serial.print("\tTick!\r\n");
  }
}

```

