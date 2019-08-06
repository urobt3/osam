/**
 ** Raspberry Pi 2 : GPIO 18 Example -> by wiringPi
 **
 **/

#include <stdio.h>
#include <wiringPi.h>

#define LED1	1  // BCM_GPIO 18

int main()
{
    if (wiringPiSetup() == -1)
        return 1;

    pinMode (LED1, OUTPUT);

    for ( ;; )
    {
        digitalWrite(LED1, 1); // LED ON
	delay(1000);

	digitalWrite(LED1, 0); // LED OFF
	delay(1000);
    }

    return 0;
}
