/* ****************************************************
 * File     : timingSimple_main.ino
 * Data     : 28-04-2018
 * Version  : 1.0
 * Author   : Ben Schueler
 * ****************************************************/

#include "timing.h"

#define ledPin       13

unsigned long previousTimeTick;
#define intervalTick 1000UL

unsigned long previousTimeTack;
#define intervalTack 925UL

unsigned long previousTimeTock;
#define intervalTock 850UL

unsigned long previousTimeTuck;
#define intervalTuck 775UL

/* ------------------------------------------
 / SETUP
 / ------------------------------------------
*/
void setup()
{
  pinMode( ledPin, OUTPUT ); digitalWrite( ledPin, LOW );
  Serial.begin(115200);

  Serial.print("Start!\r\n");

}

void loop()
{
  bool overrun;
  if ( timePastFixed( previousTimeTick, intervalTick ) ) {
    digitalWrite( ledPin, !digitalRead( ledPin ) );
    Serial.print( millis() );
    Serial.print("\tTick!\r\n");
  }

  if ( timePastVariable( previousTimeTack, intervalTack ) ) {
    Serial.print( millis() );
    Serial.print("\t\tTack!\r\n");
  }

  if ( timePastOverrunFixed( previousTimeTock, intervalTock, overrun ) ) {
    Serial.print( millis() );
    Serial.print("\t\t\tTock!\r\n");
  }

    if ( timePastOverrunVariable( previousTimeTuck, intervalTuck, overrun ) ) {
    Serial.print( millis() );
    Serial.print("\t\t\t\tTuck!\r\n");
  }
}

/*********************************************************************************************************
  END FILE
*********************************************************************************************************/