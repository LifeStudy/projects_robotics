#include "mraa.h"
#define DEFAULT_IOPIN 9

static int iopin;

int main(int argc, char** argv)
{
  iopin = DEFAULT_IOPIN;
  mraa_gpio_context gpio;
  mraa_init();
  gpio = mraa_gpio_init(iopin);
  mraa_gpio_dir(gpio, MRAA_GPIO_OUT);
  while(1){
    mraa_gpio_write(gpio, 1);
    sleep(1);
    mraa_gpio_write(gpio, 0);
    sleep(1);
  }
   return 0;
}
