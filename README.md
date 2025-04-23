Method for Measuring Switching Parameters The standard test method for measuring switching parameters of Si, SiC, and GaN MOSFETs and IGBTs is the double pulse Test (DPT). Double pulse testing can be used to measure energy loss during device turn-on and turn-off, as well as reverse recovery parameters. A good explanation can be found here: https://www.tek.com/en/documents/application-note/double-pulse-test-tektronix-afg31000-arbitrary-function-generator?anv=2

Program runs on an Raspberry Pi Zero as bare metal program (tested on a Pi ZeroW V1.1). Minimum pulsewith = 0,4 micro second, resolution 80nsec

Sending a Json like: {"pulseInterval": 500, "pulseWidth1": 10, "interPulseDelay": 200, "pulseWidth2": 10} via the serial port (115200 baud, n, 8, 1) generates 
               _____________                   ____________ 
pulseInterval | pulseWidth1 | interPulseDelay | pulseWith2 | pulseInterval
                    10       ______ 200 ______      10      _____ 500 _____

Software is partly used from Teensy 4.0 Signal Generator, Electronics Workshop, Robin O'Reilly.
For JSON extraction thanks to https://github.com/zserge/jsmn/. 
For starting with the bare metal programming https://github.com/dwelch67/raspberrypi-zero.
