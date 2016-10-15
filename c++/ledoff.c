#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include "mraa.h"

#define DEFAULT_IOPIN 9

static int iopin;

int main(int argc, char** argv)
{
  mraa_result_t r = MRAA_SUCCESS;
  iopin = DEFAULT_IOPIN;
  mraa_init();
  mraa_gpio_context gpio;
  gpio = mraa_gpio_init(iopin);
  r = mraa_gpio_dir(gpio, MRAA_GPIO_OUT);
  r = mraa_gpio_write(gpio, 0);
  return r;
}