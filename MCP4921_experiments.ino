/*
 Example 36.2 - SPI bus device demo using a Microchip MCP4921 DAC [http://bit.ly/j3TSak]
 http://tronixstuff.com/tutorials > chapter 36 | CC by-sa-nc | John Boxall
 */

#include "SPI.h" // necessary library
int del=0; // used for various delays
word outputValue = 0; // a word is a 16-bit number
byte data = 0; // and a byte is an 8-bit number

void setup()
{
  //set pin(s) to input and output
  pinMode(10, OUTPUT);
  SPI.begin(); // wake up the SPI bus.
  SPI.setBitOrder(MSBFIRST);
}

void loop()
{
    float voltage = 3.3;  // the actual voltage that we want out, in floating point decimal
    int a = (3.3/5.0)*4096;  // the 12-bit representation of the voltage we want to send out
    outputValue = a;
    digitalWrite(10, LOW);
    data = highByte(outputValue);
    data = 0b00001111 & data;
    data = 0b00110000 | data;
    SPI.transfer(data);
    data = lowByte(outputValue);
    SPI.transfer(data);
    digitalWrite(10, HIGH);
  /*
  for (int a=0; a<=4095; a++)
  {
    outputValue = a;
    digitalWrite(10, LOW);
    data = highByte(outputValue);
    data = 0b00001111 & data;
    data = 0b00110000 | data;
    SPI.transfer(data);
    data = lowByte(outputValue);
    SPI.transfer(data);
    digitalWrite(10, HIGH);
    delay(del);
  }
  delay(del+25);
  for (int a=4095; a>=0; --a)
  {
    outputValue = a;
    digitalWrite(10, LOW);
    data = highByte(outputValue);
    data = 0b00001111 & data;
    data = 0b00110000 | data;
    SPI.transfer(data);
    data = lowByte(outputValue);
    SPI.transfer(data);
    digitalWrite(10, HIGH);
    delay(del);
  }
  delay(del+25);
  */
}
