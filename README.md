# Smart_Parking_System

Using Raspberry pi

Components Required:
Raspberry pi,
ESP32
Rpi Camera Module,
Ultrasonic Sensors,
Servo Motors,




To check camera module in Raspberry pi, simpily connect the camera module to the raspberry pi and open terminal. Type "raspistill -o name_of_the_image.jpg" and run.

# Pre-requisites for Number Plate Recognition OpenCV Python
Here we use the OpenCV library to detect and recognize number plates, and the Tesseract library is used to read the characters. So before proceeding further, first install the OpenCV, Tesseract, and other required libraries. We previously used OpenCV in Face Recognition using the Raspberry Pi project.

 
 
#### Step 1: Installing OpenCV in Raspberry Pi 3
Here OpenCV library is used to detect and recognize faces. To install the OpenCV, first, update the Raspberry Pi.

### sudo apt-get update
 

Then use the following commands to install the required dependencies for installing OpenCV on your Raspberry Pi.
### sudo apt-get install libhdf5-dev -y 
### sudo apt-get install libhdf5-serial-dev –y 
### sudo apt-get install libatlas-base-dev –y 
### sudo apt-get install libjasper-dev -y
### sudo apt-get install libqtgui4 –y
### sudo apt-get install libqt4-test –y
 

After that, use the below command to install the OpenCV on your Raspberry Pi.

### pip3 install opencv-contrib-python==4.1.0.25
 

#### Step 2: Installing Tesseract 

To install the Tesseract, first, configure the Debian Package (dpkg) using the below command:

### sudo dpkg - -configure –a
 

After that, install the Tesseract OCR (Optical Character Recognition) using the apt-get option.

### sudo apt-get install tesseract-ocr
 

After that, install the pytesseract using the pip.

### pip install pytesseract
 

After this, install the PYTTSX3 library for text to speech conversion using the below command:

### pip install pyttsx3
 

#### Step 3: Installing imutils 

imutils is used to make essential image processing functions such as translation, rotation, resizing, skeletonization, and displaying Matplotlib images easier with OpenCV. Use the below command to install the imutils:

### pip3 install imutils
 

#### Step 4: SMTP Mail Setup for Raspberry Pi Car Plate Recognition
SMTP (Simple Mail Transfer Protocol) is the standard protocol for providing email services on a TCP/IP network. This server provides the ability to receive and send email messages. We are using SMTP to send a mail when the Raspberry Pi detects and recognizes a license plate.

 

#### To use the SMTP services on Raspberry Pi, we first have to install the SMTP library on Pi. Use the below command to install the same:

### sudo apt-get install ssmtp
 

Now we have to edit the configure file. For that, open Configuration file using the below command:

### sudo nano /etc/ssmtp/ssmtp.conf
 

A new window opens up and add the below lines there. Don’t forget to add your email and email password. After writting use keyboard's shift^O to save the below data in 'ssmtp.conf' file 

### root=postmail
### mailhub=smpt.gmail.com:587
### AuthUser=youremail@gmail.com
### AuthPass=youremailpassword
### FromLineOverride=YES
### UseSTARTTLS=YES
### DEBUG=YES
