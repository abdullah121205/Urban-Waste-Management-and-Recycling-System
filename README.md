# Urban Waste Management and Recycling System

Project Overview

The Urban Waste Management and Recycling System is a smart waste management solution designed to improve waste segregation, monitoring, and collection.

The system uses an ESP32 microcontroller along with sensors to detect waste, monitor bin status, and identify whether the waste is wet or dry. The project can be further extended with Artificial Intelligence, IoT connectivity, GPS-based collection routing, and automated waste classification.

Objectives

- Detect the presence of waste using an IR sensor.
- Monitor the filling level of the waste bin using an ultrasonic sensor.
- Identify wet and dry waste using a moisture sensor.
- Provide real-time sensor readings through the Serial Monitor.
- Support future IoT-based waste monitoring.
- Improve waste segregation and recycling efficiency.

Technologies Used

Hardware
- ESP32
- HC-SR04 Ultrasonic Sensor
- IR Sensor
- Soil/Moisture Sensor
- Breadboard
- Jumper Wires

Software
- Arduino IDE
- Embedded C/C++
- ESP32

System Workflow

1. The IR sensor detects whether waste is present.
2. When waste is detected, the ultrasonic sensor measures the distance inside the bin.
3. The system determines whether the bin is FULL or AVAILABLE.
4. The moisture sensor measures the moisture level of the waste.
5. Based on the moisture reading, the system classifies the waste as WET or DRY.
6. The results are displayed through the Serial Monitor.

Current Classification

| Parameter | Condition | Result |

| IR Sensor | Object detected | Waste detected |
| Ultrasonic | Distance < 10 cm | Bin FULL |
| Ultrasonic | Distance ≥ 10 cm | Bin AVAILABLE |
| Moisture | Value < 2000 | Wet Waste |
| Moisture | Value ≥ 2000 | Dry Waste |

> Note: The moisture threshold is a provisional value and should be calibrated according to the sensor and waste conditions.

Future Enhancements
  *AI-based waste classification
  *IoT cloud monitoring
  *Real-time bin fill-level monitoring
  *GPS-based waste collection route optimization
  *Mobile/web dashboard
  *Automated waste segregation
  *Smart collection alerts
  *Recycling and waste-processing analytic
