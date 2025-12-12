Activity 1:
External Power supply pin: VSYS
With varying voltages from 1.8V - 5V

Activity 2:
WAKE_EN0 = 0xFFF WAKE_EN1 = 0x3FFF
SLEEP_EN = 0xFFF SLEEP_EN1 = 0x3FFF
ENABLED0 = 0x0000 ENABLED1 0x0000

Activity 3:

- Blink Test w/ sleep_ms
V = 3.3 
I = .032 
Across 120 ohm resistor

- Blink Test w/ thread
V = 3.3 
I = 0.036
Across 120 ohm resistor

- Busy loop 
V = 3.3
I = 0.0284
Across 120 ohm resistor

- Interrupt with toggle GPIO
1KHZ: V = 3.3 I = 0.0281
10KHZ: V = 3.3 I = 0.0282
100KHZ: V = 3.3 I = 0.0282
1MHZ: V = 3.3 I = 0.0291

- Sleep demo
V = 3.3
Initially I = 0.016
Later I = 0.008
Then keep cycling between those values

- Dormant Demo
V = 3.3 
Initially I = 0.012
Later I = 0.017