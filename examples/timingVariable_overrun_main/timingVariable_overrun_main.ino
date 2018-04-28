/* ****************************************************
 * File     : timingVariable_overrun_main.ino
 * Data     : 28-04-2018
 * Version  : 1.0
 * Author   : Ben Schueler
 * ****************************************************/

#include "timing.h"

#define ledPin       13

unsigned long currentTime;
unsigned long previousTimeTick;
#define intervalTick 1000UL
boolean overrun;

unsigned long delayTime;

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
  currentTime = millis();

  Serial.print( currentTime );
  Serial.print( "ms, next tick at " );
  Serial.print( previousTimeTick + intervalTick );
  Serial.print( " ms\r\n" );

  /* add some delay */
  delayTime = random( 100, 1500 );
  Serial.print( currentTime );
  Serial.print( " ms, delay " );
  Serial.print( delayTime );
  Serial.print( " ms" );
  delay( delayTime );


  /* wait until time has past */
  while ( !timePastOverrunVariable(  millis(), previousTimeTick, intervalTick, overrun ) ) {;}
  digitalWrite( ledPin, overrun );
  if ( !overrun ) {
      Serial.print( "\t\t-> Tick!\r\n" );
  } else {
      Serial.print("\t\t-> OVERRUN!!!\r\n");
  }
}

/*********************************************************************************************************
  END FILE
*********************************************************************************************************/