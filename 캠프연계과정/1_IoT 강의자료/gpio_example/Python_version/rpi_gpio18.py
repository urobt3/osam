# Raspberry Pi : GPIO Example -> by Python

import RPi.GPIO as GPIO
import time

GPIO.setmode(GPIO.BCM)

print "Pin 18 as GPIO Output pin"

GPIO.setup(18, GPIO.OUT)
GPIO.output(18, False)

i = 0

while i < 3:

    GPIO.output(18, True)
    time.sleep(0.5)

    GPIO.output(18, False)
    time.sleep(0.5)

    i += 1

raw_input('Press Enter key to exit')

GPIO.cleanup()
