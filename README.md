The Bit stream analyzer is a standalone application designed to process ADS-B bit streams. It filters ADS-B messages with a downlink format of 17, producing a 14-byte hexadecimal value as output. This output can be further analyzed using tools like PyModeS or other decoders.
ADS-B (Automatic Dependent Surveillance-Broadcast) is a surveillance technology used in aviation, while ADS refers to certain types of data transmissions in the aviation context.
In the future, a C version of the decoder will be incorporated into the application to provide additional functionality and flexibility. Updates on this development will be provided as progress is made.

To run the code, ensure that the Raspberry Pi is set up with the dongle and antenna. Then, execute the following command:
rtl_sdr -f 1090e6 -s 2000000 -g 48 - | ./bit_stream_analyzer

adsb_process.c is to be used with dump 1090 on port 30005 (beast data format)
Will need to install dump1090-fa on raspberry pi
https://github.com/flightaware/dump1090.git
Dependencies (for dump1090-fa: raspberry pi 4b):
-	build-essential, fakeroot, debhelper, librtlsdr-dev, pkg-config, libncurses5-dev, libbladerf-dev, libhackrf-dev liblimesuite-dev libsoapysdr-dev
-	sudo apt-get install build-essential fakeroot debhelper librtlsdr-dev pkg-config libncurses5-dev libbladerf-dev libhackrf-dev liblimesuite-dev libsoapysdr-dev 
Dependencies (general dependencies needed for raspberry pi 4b os)
-	devscripts, lighttpd, netcat-openbsd
-	sudo apt-get install devscripts lighttpd netcat-openbsd
Dump1090-fa setup
-	git clone https://github.com/flightaware/dump1090.git
-	cd dump1090
-	./prepare-build.sh bullseye
-	cd package-bullseye
-	dpkg-buildpackage -b --no-sign
-	sudo dpkg -i ../dump1090-fa_*.deb
Terminal 1
-	dump1090 broadcasts on port 30005
-	if device or resource is busy
o	sudo systemctl stop dump1090-fa
-	run dump1090
o	sudo dump1090-fa --net --quiet
-	…
Terminal 2
-	pipe the data into adsb_process using netcat-openbsd
o	nc localhost 30005 | ./adsb_process
