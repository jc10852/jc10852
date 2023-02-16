#include <Arduino.h>
//need a 1khz clock using Timer 0/Channel B, using Channel A as TOP
//Clock Prescaler is 64, 125 ticks with 8MHz clock gives 1ms.
//Need to use SCL, D3 as per schematic for OC8B

void setup(){
  DDRD |= (1<<0);
  TCCR0A=0b00100011;
  //       xx = Channel A pin is disconnected
  //         xx = Channel B pin is connected
  //           xx = Don't care
  //             xx= 2 bits of wave tiype, Fast PWM, OCR0A TOP
  TCCR0B = 0b00001011;
  //         xxxx = Don't care
  //             x = The other wave bit
  //              xxx - CP divide by 64, Bus each tick
  OCR0A = 123;
  OCR0B = 61;

}

void loop(){

}
