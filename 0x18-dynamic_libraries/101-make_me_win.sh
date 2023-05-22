#!/bin/bash
wget -P /tmp/ https://raw.githubusercontent.com/eddybrownent/alx-low_level_programming/master/0x18-dynamic_libraries/libinjection.so
export LD_PRELOAD="/tmp/libinjection.so"
