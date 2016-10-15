#include "mraa.h"
#define pin0 0
#define pin1 1
#define pin2 2
#define pin3 3

int iopin0;
int iopin1;
int iopin2;
int iopin3;

int main(int argc, char** argv)
{
  mraa_gpio_context gpio0;
  mraa_gpio_context gpio1;
  mraa_gpio_context gpio2;
  mraa_gpio_context gpio3;
  
  iopin0 = pin0;
  iopin1 = pin1;
  iopin2 = pin2;
  iopin3 = pin3;
  
  mraa_init();
  
  gpio0 = mraa_gpio_init(iopin0);
  gpio1 = mraa_gpio_init(iopin1);
  gpio2 = mraa_gpio_init(iopin2);
  gpio3 = mraa_gpio_init(iopin3);

  mraa_gpio_dir(gpio0, MRAA_GPIO_OUT);
  mraa_gpio_dir(gpio1, MRAA_GPIO_OUT);
  mraa_gpio_dir(gpio2, MRAA_GPIO_OUT);
  mraa_gpio_dir(gpio3, MRAA_GPIO_OUT);
  while(1){
    mraa_gpio_write(gpio0, 1);
    mraa_gpio_write(gpio1, 0);
    mraa_gpio_write(gpio2, 0);
    mraa_gpio_write(gpio3, 1);
    sleep(1);
    mraa_gpio_write(gpio0, 1);
    mraa_gpio_write(gpio1, 0);
    mraa_gpio_write(gpio2, 0);
    mraa_gpio_write(gpio3, 0);
    sleep(1);
    mraa_gpio_write(gpio0, 1);
    mraa_gpio_write(gpio1, 1);
    mraa_gpio_write(gpio2, 0);
    mraa_gpio_write(gpio3, 0);
    sleep(1);
    mraa_gpio_write(gpio0, 0);
    mraa_gpio_write(gpio1, 1);
    mraa_gpio_write(gpio2, 0);
    mraa_gpio_write(gpio3, 0);
    sleep(1);
    mraa_gpio_write(gpio0, 0);
    mraa_gpio_write(gpio1, 1);
    mraa_gpio_write(gpio2, 1);
    mraa_gpio_write(gpio3, 0);
    sleep(1);
    mraa_gpio_write(gpio0, 0);
    mraa_gpio_write(gpio1, 0);
    mraa_gpio_write(gpio2, 1);
    mraa_gpio_write(gpio3, 0);
    sleep(1);
    mraa_gpio_write(gpio0, 0);
    mraa_gpio_write(gpio1, 0);
    mraa_gpio_write(gpio2, 1);
    mraa_gpio_write(gpio3, 1);
    sleep(1);
    mraa_gpio_write(gpio0, 0);
    mraa_gpio_write(gpio1, 0);
    mraa_gpio_write(gpio2, 0);
    mraa_gpio_write(gpio3, 1);
    sleep(1);
  }
  return 0;
}