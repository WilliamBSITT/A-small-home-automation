Arduino Light and Weather Station
This project is an Arduino-based light and weather station. It uses a photoresistor to control a lamp automatically based on ambient light levels and displays temperature and humidity on an LCD screen.

Components
Arduino Uno
LiquidCrystal LCD (16x2)
DHT Sensor (DHT11 or DHT22)
Photoresistor
Resistors
Push button
Breadboard and jumper wires
LED or Lamp
220-ohm resistor (for LED/lamp)

Circuit Diagram
    

    DHT Sensor:
    [VCC] -> 5V
    [GND] -> GND
    [DATA] -> Digital pin (specified in the code as 'dhtPin')

    Photoresistor:
    One lead to 5V, other lead to A0 with a 10k-ohm resistor to GND

    LED/Lamp:
    Positive lead to pin 7 via 220-ohm resistor
    Negative lead to GND

    Button:
    One pin to GND
    Other pin to a digital input pin (specified in the code as 'buttonNext') with a pull-up resistor

    LCD:
    [VSS] -> GND
    [VDD] -> 5V
    [V0]  -> Potentiometer (contrast control)
    [RS]  -> Arduino pin 12
    [RW]  -> GND
    [E]   -> Arduino pin 11
    [D4]  -> Arduino pin 5
    [D5]  -> Arduino pin 4
    [D6]  -> Arduino pin 3
    [D7]  -> Arduino pin 2
    [A]   -> 5V
    [K]   -> GND

Setup
Install the DHT library:

Open the Arduino IDE.
Go to Sketch -> Include Library -> Manage Libraries.
Search for "DHT" and install the DHT sensor library by Adafruit.
Connect the components:

Follow the circuit diagram to connect the LCD, DHT sensor, photoresistor, LED/lamp, and button to the Arduino.
Upload the code:

Open the provided Arduino code in the Arduino IDE.
Make sure to set the correct dhtPin and buttonNext pin numbers according to your wiring.
Connect your Arduino to your computer and upload the code.

Functions
setup(): Initializes the LCD and sets up pin modes.
get_meteo(): Reads temperature and humidity from the DHT sensor and displays them on the LCD.
lumos_automata(): Reads the photoresistor value and turns the lamp on or off based on the light level.
switch_window(): Reads the button state to switch between the light control and weather display modes.
loop(): Main loop that switches between the two modes every 500ms based on the button state.

Usage
The system starts in light control mode, automatically turning the lamp on or off based on ambient light.
Press the button to switch to weather display mode, showing temperature and humidity on the LCD.
Press the button again to switch back to light control mode.
