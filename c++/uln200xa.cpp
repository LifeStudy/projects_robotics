#include <unistd.h>
#include <iostream>
#include "uln200xa.hpp"

using namespace std;
int main ()
{
  upm::ULN200XA* uln200xa = new upm::ULN200XA(4096, 8, 9, 10, 11);

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
