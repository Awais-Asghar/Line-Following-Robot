# Line-Following-Robot

### Description:
This code is for a line-following robot, designed to navigate a path marked by a contrasting line on a surface. The robot utilizes infrared sensors to detect the line and adjust its movement accordingly. It includes functions for moving forward, turning left, turning right, and stopping based on sensor readings.

### Hardware Configuration:
- **Infrared (IR) Sensors:**
  - Left Sensor Pin: A1
  - Right Sensor Pin: A0

- **Motor Control Pins:**
  - Enable A Pin (ENA_PIN): 5
  - Enable B Pin (ENB_PIN): 3
  - Motor Left Pin 1 (MOTOR_LEFT_PIN1): 11
  - Motor Left Pin 2 (MOTOR_LEFT_PIN2): 10
  - Motor Right Pin 1 (MOTOR_RIGHT_PIN1): 9
  - Motor Right Pin 2 (MOTOR_RIGHT_PIN2): 8

### Code Explanation:

#### Setup:
- **Motor Control Pins Setup:**
  - Configures the motor control pins as OUTPUT to control the motor direction.

- **IR Sensor Pins Setup:**
  - Configures the IR sensor pins as INPUT to read the sensor values.

- **Serial Communication Initialization:**
  - Initializes serial communication with a baud rate of 9600 for debugging purposes.

#### Loop:
- **Read Sensor Values:**
  - Reads the values of the left and right IR sensors.

- **Debugging Output:**
  - Prints the sensor values to the serial monitor for debugging.

- **Decision Making:**
  - Determines motor actions based on the sensor readings:
    - If both sensors detect the line (LOW), the robot moves forward.
    - If only the left sensor detects the line, the robot turns left.
    - If only the right sensor detects the line, the robot turns right.
    - If both sensors lose track of the line (HIGH), the robot stops.

#### Functions:
- **moveForward():**
  - Sets motor directions for forward motion and adjusts motor speeds accordingly.

- **turnLeft():**
  - Sets motor directions for left turn and adjusts motor speeds accordingly.

- **turnRight():**
  - Sets motor directions for right turn and adjusts motor speeds accordingly.

- **stopMotors():**
  - Stops the motors by setting the motor speed to 0.

### Usage:
1. Connect the hardware components according to the specified pin configuration.
2. Upload the code to the microcontroller.
3. Place the robot on a surface with a contrasting line to follow.
4. Observe the robot's movement as it follows the line based on the sensor readings.

### Note:
- Adjust the `Forward_Speed` and `Turn_Speed` variables to fine-tune the robot's movement speed and turning capability.

### Author:
This code was written by [Your Name/Organization] for educational purposes.

### License:
This project is licensed under [License Name/Information].
