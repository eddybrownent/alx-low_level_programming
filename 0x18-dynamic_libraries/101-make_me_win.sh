#!/bin/bash

# Download the raw file
wget -P /tmp/ https://raw.githubusercontent.com/eddybrownent/alx-low_level_programming/master/0x18-dynamic_libraries/libinjection.so

# Set the LD_PRELOAD environment variable
export LD_PRELOAD="/tmp/libinjection.so"
