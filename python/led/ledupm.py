import time
import pyupm_grove as grove
# Create the Grove LED object using GPIO pin 2
led = grove.GroveLed(8)
# Print the name
print led.name()
# Turn the LED on and off 10 times, pausing one second
# between transitions
for i in range (0,10):
  led.on()
  time.sleep(1)
  led.off()
  time.sleep(1)
# Delete the Grove LED object
del led
