/* ****************************************************
 * File     : timingVariable_main.ino
 * Data     : 28-04-2018
 * Version  : 1.0
 * Author   : Ben Schueler
 * ****************************************************/

#include "timing.h"

#define ledPin       13

unsigned long previousTimeTick;
#define intervalTick 1000UL

unsigned long previousTimeTack;
#define intervalTack 833UL

unsigned long previousTimeTock;
#define intervalTock 666UL

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
  if ( timePastVariable( millis(), previousTimeTick, intervalTick ) ) {
    digitalWrite( ledPin, !digitalRead( ledPin ) );
    Serial.print( millis() );
    Serial.print("\tTick!\r\n");
  }

  if ( timePastVariable( millis(), previousTimeTack, intervalTack ) ) {
    Serial.print( millis() );
    Serial.print("\t\tTack!\r\n");
  }

  if ( timePastVariable( millis(), previousTimeTock, intervalTock ) ) {
    Serial.print( millis() );
    Serial.print("\t\t\tTock!\r\n");
  }
}

/*********************************************************************************************************
  END FILE
*********************************************************************************************************/