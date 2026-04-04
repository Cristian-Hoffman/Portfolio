---
layout: project
title: "Aeropendulum — Inverted Pendulum Control"
description: "Implementation of a PID controller with lead compensator to stabilize an aeropendulum at 180°, combining Root Locus and frequency domain design methods."
date: 2024-01-01
categories: [Control Systems, Arduino, Embedded]
featured: true
featured_image: "/assets/images/projects/aerobalancin/aerobalancin2.jpg"

gallery:
  - type: "video"
    file: "/assets/images/projects/aerobalancin/aerobalancin1.mp4"
    description: "System response — stabilization at 165°"
  - type: "image"
    file: "/assets/images/projects/aerobalancin/aerobalancin3.jpg"
    description: "PID step response"
  - type: "image"
    file: "/assets/images/projects/aerobalancin/aerobalancin4.jpg"
    description: "PID + lead compensator response"

code_files:
  - name: "Aeropendulum PID Controller"
    file: "Aerobalancin.ino"
    language: "cpp"
    download_url: "/assets/code/Aerobalancin.ino"
    content: ""
---

## Overview

The aeropendulum is an inverted pendulum system where a motor-driven propeller mounted at the end of a rigid arm provides the actuation force. Unlike a classic pendulum at rest (0°), the control objective was to drive and stabilize the system as close to 180° as possible — the upright unstable equilibrium point.

This project covered the full control engineering cycle: mathematical modeling, controller design, simulation in Simulink, and physical implementation on an Arduino Uno.

## Plant Description

The system consists of a rigid arm free to rotate, with a brushed DC motor and propeller at one end providing aerodynamic thrust. The arm angle is measured by an **AS5600** magnetic encoder, which provides smooth and precise angular feedback. A **MX1919 H-bridge** drives the motor bidirectionally, allowing thrust control in both directions.

| Component | Details |
|-----------|---------|
| Actuator | DC motor + propeller |
| Driver | MX1919 H-bridge |
| Sensor | AS5600 magnetic encoder |
| Controller | Arduino Uno |
| Control objective | Stabilize at 180° (upright position) |

## Controller Design

A **PID controller with lead compensator** was implemented. The proportional and integral gains were designed using **Root Locus** and **frequency domain** techniques, ensuring adequate phase margin and steady-state performance. The derivative gain was tuned empirically to reduce overshoot without amplifying noise.

| Parameter | Value | Design Method |
|-----------|-------|---------------|
| Kp | 0.8 | Root Locus |
| Ki | 0.5 | Frequency Domain |
| Kd | 0.04 | Empirical tuning |
| Lead Compensator | Yes | Phase margin improvement |

## Simulation

Prior to physical implementation, the closed-loop system was simulated in **MATLAB/Simulink** to validate the controller design, tune parameters, and analyze step response characteristics including rise time, overshoot, and settling time.

## Results

The implemented controller successfully stabilized the aeropendulum near the 180° upright position. The AS5600 encoder provided reliable angle feedback, and the lead compensator improved the transient response compared to a pure PID design.