# mxChipTextAdventure

A text based adventure game which runs on the mx chip. This project aims to hone in C#/C++ skills by:

* Understanding the relationship of the Arduino IDE and MX DevKit
* Learn about the varying sensors onboard; using these sensors to solve problems.


## About IoT DevKit

The [MXChip IoT DevKit](https://aka.ms/iot-devkit) (a.k.a. IoT DevKit) is an all-in-one Arduino compatible board with rich peripherals and sensors. You can develop for it using [Azure IoT Device Workbench ](https://aka.ms/azure-iot-workbench). And it comes with a growing [projects catalog](https://aka.ms/devkit/project-catalog) to guide you prototype Internet of Things (IoT) solutions that take advantage of Microsoft Azure services.

## Before you begin

To complete the steps in this tutorial, you need to do the following:

* Prepare your DevKit with [Getting Started Guide](https://microsoft.github.io/azure-iot-developer-kit/docs/get-started/).
* Upgrade to latest firmware (>= 1.6.2) with [Firmware Upgrading](https://microsoft.github.io/azure-iot-developer-kit/docs/firmware-upgrading/) tutorial.

## Set up the Environment

### Setting up the Environment.

1. Download or Git Clone GitHub Repo to your local drive. You can find more information on git clone and downloading a repo [here](https://help.github.com/en/articles/cloning-a-repository). 

2. **Click** Open file directory within Visual Studio Code (Rightclick > Open with Visual Studio Code), Azure IoT Extension should automatically detect the IoTProject Workspace. After dependancies are loaded, connect MXChip Devkit(AZ3166) to your computer's USB.

3. Upload code by clicking on the **Upload** button, underneath the Windows' Min, Max and Close buttons OR, Open the command palette and select **Azure IoT Device Workbench: Upload Device Code**.

4. VS Code then starts verifying and uploading the code to your DevKit.