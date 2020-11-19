# invisible_wah
Invisible expression pedal that sends midi signals

## Schematic
#### Ingredients:
Adafruit Itsy Bitsy (32u4), conductive surface(copper plate, tin foil), at least one foot, resistor (1 MOhm reccomended), physical container to hold everything.

TODO: picture

## Firmware
#### Libraries:
MIDIUSB, CapacitiveSensor

#### Tips:
If arduino is to be used, create a new project and copy the contents of main.cpp into the .ino file.

Change `sendPin` and `receivePin` according to the physical pins used in the schematic.
Change `midiMessage` to the desired midi control change controlled by the expression pedal.
For some crazy effects, set `smooth` to false.
When `smooth` is true, `smoothness` controls how smooth the expression pedal changes. Although the more smooth it is, the slower the reaction time is.
