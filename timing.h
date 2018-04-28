/* ****************************************************
 * File     : timing.h
 * Data     : 28-04-2018
 * Version  : 1.0
 * Author   : Ben Schueler
 * ****************************************************/

#ifndef __TIMING__
#define __TIMING__

#include <inttypes.h>

/* true if time has passed */
/* set previousT to new interval time, stuck to interval time */
bool timePastFixed( unsigned long currentT, unsigned long& previousT, unsigned long interval );
bool timePastFixed( unsigned long& previousT, unsigned long interval );

/* true if time has passed */
/* set previousT to new interval time, stuck to interval time */
/* When force is true, result will be true and if needed previousT will be updated */
bool timePastFixed( unsigned long currentT, unsigned long& previousT, unsigned long interval, bool force );
bool timePastFixed( unsigned long& previousT, unsigned long interval, bool force );

/* true if time has passed */
/* set previousT to new interval time, stuck to interval time */
/* overrun is set when currentT > (previuosT + interval + 1) */
bool timePastOverrunFixed( unsigned long currentT, unsigned long& previousT, unsigned long interval, bool& overrun );
bool timePastOverrunFixed( unsigned long& previousT, unsigned long interval, bool& overrun );

/* true if time has passed */
/* set previousT to new interval time, stuck to interval time */
/* overrun is set when currentT > (previuosT + interval + 1) */
/* When force is true, result will be true and if needed previousT will be updated */
bool timePastOverrunFixed( unsigned long currentT, unsigned long& previousT, unsigned long interval, bool& overrun, bool force );
bool timePastOverrunFixed( unsigned long& previousT, unsigned long interval, bool& overrun, bool force );

/* true if time has passed */
/* set previousT to (currentT + interval) */
bool timePastVariable( unsigned long currentT, unsigned long& previousT, unsigned long interval );
bool timePastVariable( unsigned long& previousT, unsigned long interval );

/* true if time has passed */
/* set previousT to (currentT + interval) */
/* When force is true, result will be true and if needed previousT will be updated */
bool timePastVariable( unsigned long currentT, unsigned long& previousT, unsigned long interval, bool force );
bool timePastVariable( unsigned long& previousT, unsigned long interval, bool force );

/* true if time has passed */
/* set previousT to (currentT + interval) */
/* overrun is set when currentT > (previuosT + interval + 1) */
bool timePastOverrunVariable( unsigned long currentT, unsigned long& previousT, unsigned long interval, bool& overrun );
bool timePastOverrunVariable( unsigned long& previousT, unsigned long interval, bool& overrun );

/* true if time has passed */
/* set previousT to (currentT + interval) */
/* overrun is set when currentT > (previuosT + interval + 1) */
/* When force is true, result will be true and if needed previousT will be updated */
bool timePastOverrunVariable( unsigned long currentT, unsigned long& previousT, unsigned long interval, bool& overrun, bool force );
bool timePastOverrunVariable( unsigned long& previousT, unsigned long interval, bool& overrun, bool force );

#endif