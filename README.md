
# Smart Soil Sensor

##📌A smart soil moisture sensor project built using a  hardware setup and code to monitor plant health by its moisture levels

##🛠️ Hardware Used
*OLED Display (I2C)
*3 different coloured LED lights(green, blue, red preffered)
*3 220 ohm resistors
*1 10k resistor

##🔌 Wiring and Hardware Connections

This project uses a DIY resistive soil moisture sensor setup. Two jumper wires act as probes inside the soil, forming a voltage divider circuit with a 10kΩ resistor to read soil resistance changes via an analog pin.

### Connection Table

*Red LED
LED Long Leg (Positive Anode) ──> 220Ω Resistor` ──> D4 (Digital Output Pin)
LED Short Leg (Negative Cathode) ──> GND Pin

*Green Led
Red LED
LED Long Leg (Positive Anode) ──> 220Ω Resistor` ──> D5 (Digital Output Pin)
LED Short Leg (Negative Cathode) ──> GND Pin

*Blue Led
Red LED
LED Long Leg (Positive Anode) ──> 220Ω Resistor` ──> D14 (Digital Output Pin)
LED Short Leg (Negative Cathode) ──> GND Pin
 
| **Power Probe** | 3V3 Pin | Straight into the soil |
| **Sensor Probe** | D34 (Analog Input Pin) | Straight into the soil |
| **Pull-down Resistor** | D34 (Analog Input Pin) | In series with a 10kΩ Resistor to GND |

###🔧 How It Works
1. The '3V3 pin' sends constant voltage into the soil via the power probe
2. Pin 'D34' reads the voltage passing through the soil to determine moisture based on electrical resistance
3. The '10kΩ resistor' connects pin D34 to 'GND', acting as a pull-down resistor to stabilize the readings

## Challenges Faced & Engineering Tradeoffs
*Rapid Probe Corrosion (Electrolysis): Sending a continuous current through wet soil causes raw jumper wires to oxidize quickly affecting readings over time. (Fix: Power the probe only during active reading intervals)

## 📝 Small Note
*Resistor Choice: A 10kΩ resistor works best for typical houseplants, but if the soil is consistently packed with dense clay, a different  resistor value might be needed to scale voltage reading properly
