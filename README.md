# Smart_Parking_System

Course Project: Cyber Physical System

Under the Supervision: Dr.Sudhakar Modem

This project presents the implementation of a Smart Parking System at the parking spots of IIT Jammu using Raspberry Pi and ESP-32 modules. The system utilizes a Raspberry Pi with a Raspi cam installed at the entrance gate to capture images of vehicle license plates. A license plate recognition algorithm, VehPlateRecogAtGate.py, is employed to extract characters from the images and upload them to the ThingSpeak cloud.

When a vehicle enters the parking area and occupies a parking slot, an ESP-32 module equipped with an ultrasonic sensor detects the presence of the vehicle and transmits the data to the cloud using the esp32_ultrasonic.ino code. The data from both the license plate recognition and ultrasonic sensor is combined to provide real-time information on the availability and occupancy status of parking slots.

The system offers a user-friendly interface through a webpage, Webpage.html, where users can access the information on available and occupied parking slots. By utilizing this Smart Parking System, IIT Jammu aims to optimize parking management and enhance the overall parking experience for its staff, students, and visitors.  

Components Required:
Raspberry pi,
ESP32,
Rpi Camera Module,
Ultrasonic Sensors.




To check camera module in Raspberry pi, simpily connect the camera module to the raspberry pi and open terminal. Type "raspistill -o name_of_the_image.jpg" and run.

# Pre-requisites for Number Plate Recognition OpenCV Python
Here we use the OpenCV library to detect and recognize number plates, and the Tesseract library is used to read the characters. So before proceeding further, first install the OpenCV, Tesseract, and other required libraries. We previously used OpenCV in Face Recognition using the Raspberry Pi project.

 
 
### Step 1: Installing OpenCV in Raspberry Pi 3
Here OpenCV library is used to detect and recognize faces. To install the OpenCV, first, update the Raspberry Pi.

#### sudo apt-get update
 
Then use the following commands to install the required dependencies for installing OpenCV on your Raspberry Pi.
#### sudo apt-get install libhdf5-dev -y 
#### sudo apt-get install libhdf5-serial-dev –y 
#### sudo apt-get install libatlas-base-dev –y 
#### sudo apt-get install libjasper-dev -y
#### sudo apt-get install libqtgui4 –y
#### sudo apt-get install libqt4-test –y
 

After that, use the below command to install the OpenCV on your Raspberry Pi.

#### pip3 install opencv-contrib-python==4.1.0.25
 

### Step 2: Installing Tesseract 

To install the Tesseract, first, configure the Debian Package (dpkg) using the below command:

#### sudo dpkg --configure –a
 

After that, install the Tesseract OCR (Optical Character Recognition) using the apt-get option.

#### sudo apt-get install tesseract-ocr
 

After that, install the pytesseract using the pip.

#### pip install pytesseract
 

After this, install the PYTTSX3 library for text to speech conversion using the below command:

#### pip install pyttsx3
 

### Step 3: Installing imutils 

imutils is used to make essential image processing functions such as translation, rotation, resizing, skeletonization, and displaying Matplotlib images easier with OpenCV. Use the below command to install the imutils:

#### pip3 install imutils
 

 

