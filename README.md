<p align="center">
  <a href="" rel="noopener">
 <img width=200px height=200px src="https://encrypted-tbn0.gstatic.com/images?q=tbn:ANd9GcRaloiigezCX-5tPZNvIrh8vuYb2vPikCYxKA&usqp=CAU" alt="Project logo"></a>
</p>

<h3 align="center">Sun Seeker</h3>

<div align="center">

[![Status](https://img.shields.io/badge/status-active-success.svg)]()
[![GitHub Issues](https://img.shields.io/github/issues/kylelobo/The-Documentation-Compendium.svg)](https://github.com/kylelobo/The-Documentation-Compendium/issues)
[![GitHub Pull Requests](https://img.shields.io/github/issues-pr/kylelobo/The-Documentation-Compendium.svg)](https://github.com/kylelobo/The-Documentation-Compendium/pulls)
[![License](https://img.shields.io/badge/license-MIT-blue.svg)](/LICENSE)

</div>

---

<p align="center"> Intelligent Solar Tracker with Edge Intelligence.
    <br>
</p>

## 📝 Table of Contents

- [About](#about)
- [Getting Started](#getting_started)
- [Deployment](#deployment)
- [Usage](#usage)
- [Built Using](#built_using)
- [TODO](../TODO.md)
- [Contributing](../CONTRIBUTING.md)
- [Authors](#authors)
- [Acknowledgments](#acknowledgement)

## 🧐 About <a name = "about"></a>

"Sun Seeker - Intelligent Solar Tracker with Edge Intelligence" is a cutting-edge project that combines advanced hardware and software technologies to create an intelligent solar tracker. By utilizing an ESP32 microcontroller, MPU-6050 sensor, GPS module, and Edge Impulse machine learning platform, Sun_Seeker precisely positions solar panels to track the sun's movement and maximize energy generation.

The project integrates sensor data from the MPU-6050 and GPS module, fusing them using sophisticated algorithms to calculate the sun's position relative to the solar panel's orientation. This information is then used to control servo motors that adjust the panel's tilt and rotation angles, ensuring optimal alignment with the sun's position throughout the day.

Sun_Seeker leverages the power of Edge Impulse's machine learning capabilities to train a predictive model that enhances the solar tracking accuracy. The model learns from the collected sensor data and makes real-time predictions, fine-tuning the servo motor control for optimal tracking performance.

With its intelligent tracking system, Sun_Seeker maximizes solar panel efficiency, increasing energy output and reducing reliance on manual adjustments. The project also offers optional user interface features, including a display module for real-time information and user input functionality for manual control and configuration settings.

Sun_Seeker empowers renewable energy enthusiasts and solar power systems by providing an innovative and automated solution for harnessing the sun's energy effectively.

## 🏁 Getting Started <a name = "getting_started"></a>

Building a solar tracker using ESP32, MPU-6050, GPS, and Edge Impulse sounds like an interesting project! Here's a guide to help you get started:

1. **Hardware setup:**
   - ESP32: Use the ESP32 development board as the main microcontroller.
   - MPU-6050: Connect the MPU-6050 sensor module to the ESP32 to measure the tilt and rotation angles.
   - GPS: Connect the GPS module to the ESP32 for obtaining precise location coordinates.
   - Solar panel and servo motors: Attach the solar panel to a dual-axis mechanism controlled by servo motors. This will allow the solar panel to tilt and rotate based on the sensor data.

2. **Sensor integration:**
   - Read MPU-6050 data: Utilize the ESP32's I2C interface to communicate with the MPU-6050 sensor and obtain the tilt and rotation angles.
   - GPS data acquisition: Use the ESP32's serial communication capabilities to retrieve GPS data such as latitude and longitude.

3. **Sensor fusion:**
   - Combine sensor data: Process the data from MPU-6050 and GPS to calculate the current position of the sun relative to the solar panel's position.
   - Sensor fusion algorithm: Implement sensor fusion algorithms like complementary filter or Kalman filter to obtain accurate and stable orientation information.

4. **Controlling servo motors:**
   - Servo library: Utilize a servo library compatible with the ESP32 to control the servo motors based on the calculated angles.
   - PID control: Implement a PID control algorithm to adjust the servo positions smoothly and accurately, ensuring precise tracking of the sun's movement.

5. **Edge Impulse integration:**
   - Data collection: Use Edge Impulse's data acquisition tools to gather sensor data from the MPU-6050 and GPS for training and validation.
   - Model development: Train a machine learning model in Edge Impulse to predict the sun's position based on the sensor data.
   - Model deployment: Deploy the trained model to the ESP32, enabling it to make real-time predictions for the solar tracker's movement.

6. **Power management:**
   - Power supply: Consider a suitable power source, such as a battery or a combination of solar panels and a battery, to power the ESP32 and the servo motors.
   - Power optimization: Implement power-saving techniques, such as sleep modes or duty cycling, to conserve energy and extend the system's operation time.

7. **User interface (optional):**
   - Display: Incorporate a display module to show real-time information, such as the sun's position, tracker status, and power levels.
   - User input: Add buttons or a touchscreen interface to allow users to interact with the solar tracker, providing manual control options or configuration settings.

Remember to break down the project into smaller tasks and proceed step by step. Start with simple sensor integration and data acquisition, and gradually move towards more complex tasks like sensor fusion and machine learning integration. Consult the documentation and example code for the ESP32, MPU-6050, GPS module, and Edge Impulse to aid your development process. Good luck with your solar tracker project!

## Prerequisites

The tech stack for this project includes the following components:

1. **ESP32**: The ESP32 microcontroller serves as the main hardware platform for this project. It provides the processing power, connectivity options, and I/O capabilities necessary for sensor integration and control of the solar tracker.

2. **MPU-6050**: The MPU-6050 sensor module is used to measure the tilt and rotation angles of the solar panel. It communicates with the ESP32 via the I2C protocol.

3. **GPS Module**: A GPS module is incorporated to obtain accurate location coordinates. It communicates with the ESP32 using serial communication protocols (such as UART) to provide precise information about the system's geographical position.

4. **Edge Impulse**: Edge Impulse is a machine learning platform that forms a crucial part of this project's tech stack. It is used for data collection, model development, and model deployment. Sensor data from the MPU-6050 and GPS module is collected and processed in Edge Impulse to train a machine learning model for predicting the sun's position.

5. **Servo Library**: A servo library compatible with the ESP32 is utilized for controlling the servo motors responsible for adjusting the solar panel's tilt and rotation angles. The specific library used may depend on the chosen servo motor hardware.

6. **Power Management**: Power management techniques are employed to optimize power consumption and extend the system's operation time. The power supply may include batteries, solar panels, or a combination of both.

7. **User Interface (Optional)**: For the optional user interface features, a display module is incorporated to show real-time information, while buttons or a touchscreen interface allow users to interact with the solar tracker.

Additionally, programming languages such as C++ or MicroPython can be used to write the firmware and software code for the ESP32 microcontroller. Libraries and frameworks may be utilized to simplify development tasks related to sensor integration, communication protocols, machine learning, and user interface implementation. The specific libraries and frameworks chosen will depend on the preferences and requirements of the project.

## Milestones

Here's a breakdown of the project into milestones:

**Milestone 1: Sensor Integration**

- Connect the MPU-6050 and GPS module to the ESP32.
- Implement code to read data from the MPU-6050 and GPS module.
- Validate sensor data accuracy and reliability.

**Milestone 2: Sensor Fusion and Tracking Algorithm**

- Develop a sensor fusion algorithm (e.g., complementary filter or Kalman filter) to combine MPU-6050 and GPS data.
- Calculate the sun's position relative to the solar panel's position using the fused sensor data.
- Implement a tracking algorithm to determine the desired servo motor positions based on the sun's position.

**Milestone 3: Servo Control and Calibration**

- Integrate a servo library compatible with the ESP32.
- Write code to control the servo motors based on the desired positions calculated in Milestone 2.
- Calibrate the servo motor movements for accurate tracking.

**Milestone 4: Power Management**

- Determine the power requirements for the system.
- Select and connect a suitable power source (battery, solar panels, etc.).
- Implement power management techniques to optimize power consumption and extend battery life.

**Milestone 5: Edge Impulse Integration**

- Collect sensor data from the MPU-6050 and GPS for training and validation.
- Create a dataset in Edge Impulse and upload the collected data.
- Train a machine learning model in Edge Impulse to predict the sun's position.
- Export and deploy the trained model to the ESP32.

**Milestone 6: User Interface (Optional)**

- Integrate a display module to show real-time information.
- Implement user input functionality (buttons, touchscreen) for manual control or configuration settings.

**Milestone 7: Testing and Refinement**

- Test the complete system's functionality and performance.
- Identify and fix any bugs or issues.
- Fine-tune the tracking algorithm and servo control for improved accuracy.

Remember, the complexity and time required for each milestone may vary. Break down each milestone into smaller tasks and allocate time accordingly. Regularly test and validate each component as you progress to ensure proper functionality and integration.

### Installing

A step by step series of examples that tell you how to get a development env running.

Say what the step will be

```
Give the example
```

And repeat

```
until finished
```

End with an example of getting some data out of the system or using it for a little demo.

## 🔧 Running the tests <a name = "tests"></a>

Explain how to run the automated tests for this system.

### Break down into end to end tests

Explain what these tests test and why

```
Give an example
```

### And coding style tests

Explain what these tests test and why

```
Give an example
```

## 🎈 Usage <a name="usage"></a>

Add notes about how to use the system.

## 🚀 Deployment <a name = "deployment"></a>

Add additional notes about how to deploy this on a live system.

## ⛏️ Built Using <a name = "built_using"></a>

- [MongoDB](https://www.mongodb.com/) - Database
- [Express](https://expressjs.com/) - Server Framework
- [VueJs](https://vuejs.org/) - Web Framework
- [NodeJs](https://nodejs.org/en/) - Server Environment

## ✍️ Authors <a name = "authors"></a>

- [@FanuelConrad](https://github.com/FanuelConrad) - Idea & Initial work

See also the list of [contributors](https://github.com/kylelobo/The-Documentation-Compendium/contributors) who participated in this project.

## 🎉 Acknowledgements <a name = "acknowledgement"></a>

- Hat tip to anyone whose code was used
- Inspiration
- References
