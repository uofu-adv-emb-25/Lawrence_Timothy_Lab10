For the first blink test of just pure sleep_ms, we used a voltage source of 3.3 volts and .032 amps of current the measured voltage was from .424 to 1.550 volts, the current was 5.4 mA. This was using a 120 ohm resistor in series with an led. 

For the second blink test that used threads, we used a 3.3 voltage source with a current of .036 amps. The measured voltage across the led was 1.125 to .720 volts, the current was 2.84 milliamps.

For the third blink test we kept the thread and rand a busy loop. We used the same power config as before and got 1.841 to 2.410 volts across the led and a current of 1.35 milliamps.