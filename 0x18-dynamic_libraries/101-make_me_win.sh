#!/bin/bash
wget -P /tmp/ https://github.com/eddybrownent/alx-low_level_programming/blob/master/0x18-dynamic_libraries/libinjection.so
export LD_PRELOAD="$PWD/../libinjection.so"