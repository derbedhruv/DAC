/*
 Example 36.2 - SPI bus device demo using a Microchip MCP4921 DAC [http://bit.ly/j3TSak]
 http://tronixstuff.com/tutorials > chapter 36 | CC by-sa-nc | John Boxall
 */

#include "SPI.h" // necessary library
int del=0; // used for various delays
word outputValue = 0; // a word is a 16-bit number
byte data = 0; // and a byte is an 8-bit number

// global variables for processing...
float last_filteredValue = 0.0,   filteredValue = 0.0, last_value = 0.0, currentValue = 0.0;

void setup()
{
  //set pin(s) to input and output
  pinMode(10, OUTPUT);
  SPI.begin(); // wake up the SPI bus.
  SPI.setBitOrder(MSBFIRST);
}

void outputKaro(float output) {
    outputValue = output;   // converting an int to a word
    digitalWrite(10, LOW);
    data = highByte(outputValue);
    data = 0b00001111 & data;
    data = 0b00110000 | data;
    SPI.transfer(data);
    data = lowByte(outputValue);
    SPI.transfer(data);
    digitalWrite(10, HIGH);  
}

void loop()
{
    last_filteredValue = filteredValue;
    last_value = currentValue;
    
    // read shit in...and convert to 12-bit from 10-bit asap
    currentValue = (float) analogRead(14)*4; 
        
    // enter processing here...
    // using the DC IIR filter which was given in the Texas instruments implementation of the whole thing...
    filteredValue = 1024 + 0.992*last_filteredValue + currentValue - last_value;
    
    // then we shall send it out to SPI...
    outputKaro(filteredValue);
    
}
