DAC
===

This particular ino file on this branch will deal with taking inputs from the ADC of the arduino itself (am supplying a signal from a function generator) and thenceforth processing it and outputting it via a DAC (MCP4921) and viewing the processed signal on an oscilloscope and comparing them. This will help build good realtime DSP filters.

I started this work on 15-JUL-2014 at the MIT Media Labs Hyderabad workshop ("Engineering the eye") and I'm using an ATTEN ATF20B function generator and a RIGOL DS1102E 2-channel oscilloscope.

18-JUL-2014: I hav added this new branch which implements a very nice IIR DC removal filter, which seems to work very well on the arduino for frequencies upto about 700Hz. The response time seems to be quite fast.
