# Pocket ECG Monitor

![Sample User ECG](/images/User_ECG_Screenshot_1.jpg )

------------

Get your ECG on the go using the Device and your Smart Phone.

It uses AD8232 ECG Module to read the electrical impulse of the Heart with each beat and sends the data to Android application.

------------

### Libraries Required

You need to download the following:

- ESP: [https://github.com/esp8266/Arduino](https://github.com/esp8266/Arduino "https://github.com/esp8266/Arduino") ( Follow the instructions on this page)
- Android Application: Can get it from the repository or from [here](https://raw.githubusercontent.com/sam-tj/Pocket-ECG-Monitor/master/Android%20Application/ECG%20Plus.apk "here") 

------------

### List of components used:
- NodeMCU 1.0
- AD8232
- Android Mobile

------------

### About
This project is a DIY ECG Monitor which displays the Graph on your andoird phone and can share it directly to your Doctors or healt  experts.

------------
### Tutorial
1. Get the code
2. Get the libraries
3. Attach everything
4. Upload the code
5. Install the Android Application
🔥🔥🔥🔥🔥

------------

### Connections
|  NodeMCU  |  AD8232  |
|  ------------ |  ------------ |
|  A0  |  OUTPUT  |
|  D0  |  LO-  |
|  D1  |  LO+  |
|  3.3V  |  3.3V  |
|  GND  |  GND  |

![Connections](/images/connections.png "Connections")
