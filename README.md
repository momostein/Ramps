# Ramps Library

**Welcome GitHub repository of my school project!**

This is my Library for the Ramps 1.4 shield.
The annotations are currently in Dutch, but I'm prepared to translate it all if there is enough demand.

## Functions

### Ramps.h

these are the fuctions a Ramps object can do:

* **Create a ramps object:**

   ```arduino
   Ramps ramps = Ramps();
   ```
* **Home the X, Y and Z axes:**

   ```arduino
   ramps.home();
   ```
* **Move to a position in a straight line:**

   ```arduino
   ramps.moveTo(targetX, TargetY, TargetZ, delay);
   ```
   *delay is the time between steps in microseconds*

* **Turn the the led on or off:**

   ```arduino
   ramps.led(On);
   ```
   *On is a boolean*

* **Turn the fan on or off:**

   ```arduino
   ramps.fan(On);
   ```
   *On is a boolean*

* **Control the heater:**

   ```arduino
   ramps.heater(heater, value);
   ```
   <i>heater says which heater: <b>Either 0 for heater_0 or 1 for heater_1.</b></i>

   <i>value is a byte that says how hot (PWM controlled)</i>

* **The PololuDriver objects:**

   ```arduino
   ramps.motorX
   ramps.motorY
   ramps.motorZ
   ramps.motorE
   ramps.motorQ
   ```

   *These are created by the Ramps library and can be directly controlled with the commands of the PololuDriver.h library.*
   <i><b>An example:</b></i>

   ```arduino
   ramps.motorX.stepOn();

   delayMicroseconds(500);

   ramps.motorX.stepOff();
   ```

### PololuDriver.h

The pololuDriver.h library can be used for derect control of a pololu A4988 driver or a DRV8825

* **Create a PololuDriver object:**

   ```arduino
   pololuStepper motor = pololuStepper(stepPin, dirPin, enablePin);
   ```
   *the stepPin, dirPin and enablePin are the connections to the driver.*

* **Set the direction:**

   ```arduino
   motor.setDir(direction);
   ```
   *The direction is either 1 (DIR is LOW) or -1 (DIR is HIGH)*

* **Manual stepping**

   These two functions are used together for manual stepping.
  1. **stepOn is to make the motor step**
     ```arduino
     motor.stepOn();
     ```
     *the moment you call stepOn, the motor will step and the position will be updated. if everything is handled correctly, it will return a boolean.*

  2. **stepOff is for finishing the step.**
    ```arduino
    motor.stepOff();
    ```
    *stepOff has to be called after stepOn and with a delay inbetween:*
    ```arduino
    motor.stepOn();
    delayMicroseconds(500);
    motor.stepOff();
    ```
    **_If stepOff isn't called after stepOn and you call stepOn agian, the motor won't step, position won't be updated and stepOn will return false!_**

* **Move a number of steps**

   ```arduino
   motor.autoStep(amount, delay);
   ```

   *Move the amount of steps with a delay in microseconds in between each step.*

* **Move to a position**

   ```arduino
   motor.moveTo(targetPos, delay);
   ```

   *Move to the target position with a delay in microseconds in between each step.*
