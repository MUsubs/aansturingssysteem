#include <Arduino.h>

int fib(int n)
{
    if (n <= 1)
    {
        return n;
    }

    return fib(n - 1) + fib(n - 2);
}

int res;

void setup()
{
    Serial.begin(9600);

    res = fib(10);
    Serial.println(res);
}

void loop()
{
    delay(5000);
    Serial.println("Hello, world!");
    Serial.println(res);
}

// ---- TESTOPSTELLING TODO ----

// TODO Wat komt er aan de chip te hangen?

// TODO Bereken de stroom die door de chip loopt tijdens aansturen en/of zware berekeningen.
// TODO Kijk of de chip het allemaal aankan.

// Wat komt er aan de chip te hangen?:
// 1. Grond (GND)
// 2. Voeding (Batterij) (VCC)
// 4. Afstandsensor?
// 5. 3 Actuatoren (6 draden totaal)

