from __future__ import print_function
import time, sys, signal, atexit
from upm import pyupm_uln200xa as upmULN200XA

def main():
    # Instantiate a Stepper motor on a ULN200XA Darlington Motor Driver
    # This was tested with the Grove Geared Step Motor with Driver

    # Instantiate a ULN2003XA stepper object
    myUln200xa = upmULN200XA.ULN200XA(4096, 0, 1, 2, 3)

    ## Exit handlers ##
    # This stops python from printing a stacktrace when you hit control-C
    def SIGINTHandler(signum, frame):
        raise SystemExit

    # This lets you run code on exit,
    # including functions from myUln200xa
    def exitHandler():
        print("Exiting")
        sys.exit(0)

    # Register exit handlers
    atexit.register(exitHandler)
    signal.signal(signal.SIGINT, SIGINTHandler)

    myUln200xa.setSpeed(5) # 5 RPMs
    myUln200xa.setDirection(upmULN200XA.ULN200XA.DIR_CW)

    print("Rotating 1 revolution clockwise.")
    myUln200xa.stepperSteps(4096)

    print("Sleeping for 2 seconds...")
    time.sleep(2)

    print("Rotating 1/2 revolution counter clockwise.")
    myUln200xa.setDirection(upmULN200XA.ULN200XA.DIR_CCW)
    myUln200xa.stepperSteps(2048)

    # release
    myUln200xa.release()

    # exitHandler is called automatically

if __name__ == '__main__':
    main()
