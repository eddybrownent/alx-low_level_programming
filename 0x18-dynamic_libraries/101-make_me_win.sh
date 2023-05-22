#!/bin/bash
wget -P 0x18-dynamic_libraries/libinjection.so https://github.com/eddybrownent/alx-low_level_programming/blob/master/0x18-dynamic_libraries/100-operations.so
export LD_PRELOAD="$PWD/libinjection.so"
