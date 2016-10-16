from __future__ import print_function
import time, sys, signal, atexit
import pyupm_uln200xa as upmULN200XA

def main():
    myUln200xa = upmULN200XA.ULN200XA(20000, 0, 1, 2, 3)

    def SIGINTHandler(signum, frame):
        raise SystemExit

    def exitHandler():
        print("Exiting")
        sys.exit(0)

    atexit.register(exitHandler)
    signal.signal(signal.SIGINT, SIGINTHandler)

    myUln200xa.setSpeed(3) # 5 RPMs
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
