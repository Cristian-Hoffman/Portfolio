---
layout: project
title: "Drone Pilot Commands Dataset"
subtitle: "Understanding flight dynamics through human expert control"
description: "A comprehensive dataset collected from a Nazgul drone to capture and analyze human pilot commands and rotation tendencies using Betaflight Blackbox."
date: 2026-04-07
categories: [Drones, Machine Learning, Robotics, FPV]
authors: ["Alejandro Ojeda Olarte"]
institution: "Universidad Nacional de Colombia"
organization: ["IEEE UN", "CEIMTUN-RAS", "AESS UN"]
featured: true
featured_image: "/assets/images/projects/drone-dataset/viz.png"

demo_url: "https://huggingface.co/spaces/lerobot/visualize_dataset?path=%2Fxwingspruebas%2Fprueba%2Fepisode_0%3Ft%3D63"
website_url: "https://huggingface.co/datasets/xwingspruebas/prueba"

gallery:
  - file: "/assets/images/projects/drone-dataset/viz.png"
    description: "Visualization of the drone dataset on LeRobot (Hugging Face) showing motor outputs and rotation rates."
  - file: "/assets/images/projects/drone-dataset/XWings.mp4"
    description: "Initial test flights — slalom maneuvers between obstacles for dataset collection."

---

## Project Overview

This project focuses on the collection and analysis of flight data from FPV (First Person View) drones to bridge the gap between human piloting expertise and autonomous control systems. The dataset was collected using a **Nazgul drone** equipped with Betaflight Blackbox logging.

The main objective was to capture high-fidelity information from **human pilot commands** to understand **rotation tendencies** (Yaw and Roll) during high-speed flight. While high-speed control systems typically handle pitch stabilization effectively to maintain forward velocity, understanding how expert pilots manage rotation is crucial for developing more natural and agile autonomous flight controllers.

### Data Collection Method

The data was recorded using the **Betaflight Blackbox** functionality, which logs every motor command, gyro reading, and RC input at high frequencies (up to 8kHz). This raw data was then processed and uploaded to the Hugging Face platform for broader accessibility and research.

- **Platform**: Nazgul 5" FPV Drone
- **Logging**: Betaflight Blackbox (SD Card/Internal Flash)
- **Host**: [Hugging Face Datasets](https://huggingface.co/datasets/xwingspruebas/prueba)
- **Visualization Tool**: [LeRobot Dataset Visualizer](https://huggingface.co/spaces/lerobot/visualize_dataset?path=%2Fxwingspruebas%2Fprueba%2Fepisode_0%3Ft%3D63)

## Key Insights

*   **Rotation Dynamics**: Analysis of how pilots initiate and exit high-speed turns.
*   **Pitch vs. Rotation**: Evidence showing that during fast forward flight, pitch remains relatively stable while roll and yaw exhibit high variance based on pilot corrective actions.
*   **Expert Behavior**: The dataset captures the "muscle memory" of human pilots, providing a baseline for imitation learning algorithms.

---

## Access the Data

You can explore the dataset interactively or download it for your own research using the links below:

*   **[Dataset on Hugging Face](https://huggingface.co/datasets/xwingspruebas/prueba)**
*   **[Interactive Visualization](https://huggingface.co/spaces/lerobot/visualize_dataset?path=%2Fxwingspruebas%2Fprueba%2Fepisode_0%3Ft%3D63)**
