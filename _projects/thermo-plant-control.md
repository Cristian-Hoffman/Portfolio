---
layout: project
title: "Greenhouse Thermal Plant Control"
subtitle: "Electronic Temperature Control System for Crop Simulation"
description: "A precision temperature control system using a 2N2222 transistor as a heat source and a DS18B20 sensor to simulate greenhouse climate conditions for agriculture."
date: 2026-04-08
categories: [Control Systems, Arduino, Electronics, Thermal Analysis]
authors: ["Cristian Hoffman Martin Mondragon", "Ana Orozco Reyes", "Sebastian Grillo Gonzalez", "Juan Jose Cifuentes Rojas"]
institution: "Universidad Nacional de Colombia"
organization: ["Control Systems Lab"]
featured: true
featured_image: "/assets/images/projects/thermo-plant/featured.jpg"

schematics:
  - file: "/assets/schematics/thermo-plant/LabControl-G2-E1.pdf"
    description: "Complete technical report and circuit schematics for the Greenhouse Thermal Plant Control project."

gallery:
  - file: "/assets/images/projects/thermo-plant/featured.jpg"
    description: "Project Cover: Greenhouse Temperature Control Study."
  - file: "/assets/images/projects/thermo-plant/assembly.jpg"
    description: "Hardware Assembly: Arduino and sensor integration for thermal characterization."

---

## Project Overview

The **Greenhouse Thermal Plant Control** project focuses on designing and implementing a robust temperature regulation system. The core of the plant is a **2N2222 transistor** which serves as the heating element, effectively simulating the thermal dynamics of a greenhouse environment across different Colombian climates (warm floor).

The primary goal is to maintain a stable temperature of **28°C ± 3°C**, ensuring optimal conditions for crops like melon, soy, and tomato. 

### Key Objectives

- **Precise Regulation**: Implement a controller that maintains temperature within a critical range for agricultural precision.
- **Robust Performance**: Ensure the system handles external disturbances (e.g., ambient temperature changes) with a settlement time of less than 10 minutes.
- **Academic Rigor**: Perform mathematical modeling (Transfer Function) and characterization of the thermal plant.

## Technical Implementation

### Hardware & Software
*   **Microcontroller**: Arduino UNO.
*   **Sensing**: DS18B20 Digital Temperature Sensor.
*   **Actuation**: NPN 2N2222 Transistor controlled via PWM.
*   **Tools**: MATLAB & Simulink for control design; Arduino IDE for implementation.

### Control Strategy
The system utilizes a **PI Controller** (Proportional-Integral) designed via the Root Locus method. 
- **Gain Factors**: $K_p = 10$, $K_i = 0.25$.
- **Discretization**: The controller was implemented in the Arduino using the **Tustin method** for digital execution.
- **Performance**: Achieved zero steady-state error and controlled overshoots ($M_p < 35.7\%$).

## Resilience & Testing
The project included "robustness experiments" where the thermal capacity and resistance were altered using physical barriers (paper layers and small enclosures). The PI controller demonstrated significant stability, adapting to these changes and maintaining the target temperature despite increased thermal resistance.

---

## Detailed Report
For a deep dive into the mathematical models, root locus diagrams, and experimental data, please refer to the full technical report:

*   **[Download Full Project Report (PDF)](/assets/schematics/thermo-plant/LabControl-G2-E1.pdf)**
