#include "Arduino.h"
#include <MIDIUSB.h>
#include <CapacitiveSensor.h>

const int sendPin = 2;
const int receivePin = 6;
const int midiMessage = 44;

CapacitiveSensor cs_2_6 = CapacitiveSensor(sendPin,receivePin);

int wiggleremover(int input, int output, int maxDif = 1) {
  int diff = input - output;
  if (diff > maxDif)
    return output + maxDif;
  if (diff < -maxDif)
    return output - maxDif;
  else
    return input;
}

void controlChange(byte channel, byte control, byte value) {
  midiEventPacket_t event = {0x0B, 0xB0 | channel, control, value};
  MidiUSB.sendMIDI(event);
}

void setup() {
  cs_2_6.set_CS_AutocaL_Millis(0xFFFFFFFF);
}

void loop() {
  static int c_plate;
  static int c_plate_smooth;

  c_plate = min(127, cs_2_6.capacitiveSensor(10));
  c_plate_smooth = wiggleremover(c_plate, c_plate_smooth, 1);
  controlChange(1, midiMessage, c_plate_smooth);
}
