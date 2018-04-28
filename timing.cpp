/* ****************************************************
 * File     : timing.cpp
 * Data     : 28-04-2018
 * Version  : 1.0
 * Author   : Ben Schueler
 * ****************************************************/

#include "timing.h"

#include <inttypes.h>

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#endif

void updateTimeFixed ( unsigned long currentT, unsigned long& previousT, unsigned long interval ) {
updateTimeStamp:
    if ( (previousT + interval) <= currentT ) {
        previousT += interval;
        goto updateTimeStamp;
    }
}
void updateTimeFixed ( unsigned long& previousT, unsigned long interval ) {
    updateTimeFixed( millis(), previousT, interval );
}


bool timePastFixed( unsigned long currentT, unsigned long& previousT, unsigned long interval ) {
    if ( (currentT - previousT) >= interval ) {
        updateTimeFixed( currentT, previousT, interval );
        return true;
    }

    return false;
}

bool timePastFixed( unsigned long& previousT, unsigned long interval ) {
    return timePastFixed( millis(), previousT, interval );
}


bool timePastFixed( unsigned long currentT, unsigned long& previousT, unsigned long interval, bool force ) {
    if ( (currentT - previousT) >= interval ) {
        updateTimeFixed( currentT, previousT, interval );
        return true;
    }

    if ( force ) {
        return true;
    } else {
        return false;
    }
}

bool timePastFixed( unsigned long& previousT, unsigned long interval, bool force ) {
    return timePastFixed( millis(), previousT, interval, force );
}


bool timePastOverrunFixed( unsigned long currentT, unsigned long& previousT, unsigned long interval, bool& overrun ) {
    if ( (currentT - previousT) > interval ) {
        updateTimeFixed( currentT, previousT, interval );
        overrun = true;
        return true;
    }
    if ( timePastFixed( currentT, previousT, interval ) ) {
        overrun = false;
        return true;
    }

    overrun = false;
    return false;
}

bool timePastOverrunFixed( unsigned long& previousT, unsigned long interval, bool& overrun ) {
    return timePastOverrunFixed( millis(), previousT, interval, overrun );
}


bool timePastOverrunFixed( unsigned long currentT, unsigned long& previousT, unsigned long interval, bool& overrun, bool force ) {
    if ( (currentT - previousT) > interval ) {
        updateTimeFixed( currentT, previousT, interval );
        overrun = true;
        return true;
    }
    if ( timePastFixed( currentT, previousT, interval ) ) {
        overrun = false;
        return true;
    }

    overrun = false;
    if ( force ) {
        return true;
    } else {
        return false;
    }
}

bool timePastOverrunFixed( unsigned long& previousT, unsigned long interval, bool& overrun, bool force ) {
    return timePastOverrunFixed( millis(), previousT, interval, overrun, force );
}


bool timePastVariable( unsigned long currentT, unsigned long& previousT, unsigned long interval ) {
    if ( (currentT - previousT) >= interval ) {
        previousT = currentT;
        return true;
    }

    return false;
}

bool timePastVariable( unsigned long& previousT, unsigned long interval ) {
    return timePastVariable( millis(), previousT, interval );
}


bool timePastVariable( unsigned long currentT, unsigned long& previousT, unsigned long interval, bool force ) {
    if ( (currentT - previousT) >= interval ) {
        previousT = currentT;
        return true;
    }

    if ( force ) {
        return true;
    } else {
        return false;
    }
}

bool timePastVariable( unsigned long& previousT, unsigned long interval, bool force ) {
    return timePastVariable( millis(), previousT, interval, force );
}


bool timePastOverrunVariable( unsigned long currentT, unsigned long& previousT, unsigned long interval, bool& overrun ) {
    if ( (currentT - previousT) >= ( interval + 1 ) ) {
        previousT = currentT;
        overrun = true;
        return true;
    }
    if ( timePastVariable( currentT, previousT, interval ) ) {
        overrun = false;
        return true;
    }

    overrun = false;
    return false;
}

bool timePastOverrunVariable( unsigned long& previousT, unsigned long interval, bool& overrun ) {
    return timePastOverrunVariable( millis(), previousT, interval, overrun );
}


bool timePastOverrunVariable( unsigned long currentT, unsigned long& previousT, unsigned long interval, bool& overrun, bool force ) {
    if ( (currentT - previousT) >= ( interval + 1 ) ) {
        previousT = currentT;
        overrun = true;
        return true;
    }
    if ( timePastVariable( currentT, previousT, interval ) ) {
        overrun = false;
        return true;
    }

    overrun = false;
    if ( force ) {
        return true;
    } else {
        return false;
    }
}

bool timePastOverrunVariable( unsigned long& previousT, unsigned long interval, bool& overrun, bool force ) {
    return timePastOverrunVariable( millis(), previousT, interval, overrun, force );
}