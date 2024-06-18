#!/bin/bash

FREQUENCY=1090e6
SAMPLE_RATE=2000000
GAIN=48

rtl_sdr -f $FREQUENCY -s $SAMPLE_RATE -g $GAIN - | ./bit_stream_analyzer | python3 adsb_decoder.py
