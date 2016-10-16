import mraa
import time

x = mraa.Gpio(8)
x.dir(mraa.DIR_OUT)

while True:
    x.write(1) 
    print 'LIGOU'
    time.sleep(0.2)
    x.write(0)
    print 'DESLIGOU'
    time.sleep(0.2)
