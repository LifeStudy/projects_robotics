import mraa
import time
from stepper_config import *

step_time = 0.0035
steps = 500

for i in range(0, steps):
  step_right(1, 0, 0, 0)
  time_step(step_time)
  step_right(0, 1, 0, 0)
  time_step(step_time)
  step_right(0, 0, 1, 0)
  time_step(step_time)
  step_right(0, 0, 0, 1)
  time_step(step_time)
