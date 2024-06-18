ADS-B Tracker Project
Overview:
-	This project sets up an ADS-B tracker using a Raspberry Pi with an RTL-SDR dongle and antenna. The tracker captures and decodes ADS-B signals transmitted by aircraft, allowing you to track aircraft in real-time. The project includes a C program for analyzing bit streams and a Python script for decoding ADS-B messages.

Components
Hardware:
-	Raspberry Pi
-	RTL-SDR dongle
-	Antenna

Software:
-	bit_stream_analyzer.c: A C program that reads and analyzes the bit streams from ADS-B signals.
-	adsb_decoder.py: A Python script that decodes ADS-B messages using the pyModeS library.
-	adsb_tracker.sh: A shell script to run the complete setup with configurable parameters.
  
Setup and Installation

Hardware Setup:
-	Connect the RTL-SDR dongle to the Raspberry Pi.
-	Attach the antenna to the RTL-SDR dongle.
  
Software Installation:

-	Ensure you have rtl-sdr tools installed. You can install them using the following command:
- Ensure you have `rtl-sdr` tools installed. You can install them using the following command:
```sh 
sudo apt-get install rtl-sdr 
``` 
- Install the `pyModeS` Python library: 
```sh 
pip3 install pyModeS 
``` 
- Compile the C program: 
```sh 
gcc -o bit_stream_analyzer bit_stream_analyzer.c 
``` 
- Make the shell script executable: 
```sh 
chmod +x adsb_tracker.sh 
```
## Usage
To run the ADS-B tracker, execute the shell script:
```sh
./adsb_tracker.sh
```
This script sets up the RTL-SDR dongle with the specified frequency, sample rate, and gain, and pipes the output through the bit stream analyzer and the ADS-B decoder.
Customization
You can customize the RTL-SDR parameters by modifying the 
adsb_tracker.sh script:
-	Frequency: Adjust the FREQUENCY variable.
-	Sample Rate: Adjust the SAMPLE_RATE variable.
-	Gain: Adjust the GAIN variable.
