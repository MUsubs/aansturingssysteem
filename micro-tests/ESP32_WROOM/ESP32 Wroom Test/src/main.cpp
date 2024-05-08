#include <Arduino.h>

int fib(int n)
{
    if (n <= 1)
    {
        return n;
    }

    return fib(n - 1) + fib(n - 2);
}

void setup()
{
    Serial.begin(115200);

    int res = fib(10);
    // printf("fib(10) = %d\n", res);
    Serial.println(res);
}

void loop()
{
    delay(5000);
    // printf("Hello, world!\n");
    Serial.println("Hello, world!");
}

int main(int argc, char **argv)
{
    setup();
    while (true) 
    {
        loop();
    }
    return 0;
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
