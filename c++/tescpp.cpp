#include <unistd.h>
#include <iostream>
#include "uln200xa.hpp"

using namespace std;
int main ()
{
  //! [Interesting]

  // Instantiate a Stepper motor on a ULN200XA Dual H-Bridge.

  // This was tested with the Grove Gear Stepper Motor with Driver

  // Wire the pins so that I1 is pin D8, I2 is pin D9, I3 is pin D10 and
  // I4 is pin D11
  upm::ULN200XA* uln200xa = new upm::ULN200XA(4096, 0, 1, 2, 3);

  uln200xa->setSpeed(5);
  uln200xa->setDirection(upm::ULN200XA::DIR_CW);
  cout << "Rotating 1 revolution clockwise." << endl;
  uln200xa->stepperSteps(4096);
  cout << "Sleeping for 2 seconds..." << endl;
  sleep(2);
  cout << "Rotating 1/2 revolution counter clockwise." << endl;
  uln200xa->setDirection(upm::ULN200XA::DIR_CCW);
  uln200xa->stepperSteps(2048);

  // turn off the power
  uln200xa->release();

  //! [Interesting]
  cout << "Exiting..." << endl;

  delete uln200xa;
  return 0;
}
