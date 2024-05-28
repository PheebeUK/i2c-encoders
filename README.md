# i2c-encoders
Uses a low cost microcontroller to provide I2C interface to multiple encoders with buttons. This is intended for user controls where encoder rates are relatively slow.

## Configuration
Pretty much everything happens in I2CEncoder.h. The default configuration is:
* Arduino Pro Mini board.
* Five encoders with buttons.
* I2C address of 0x55.

## Communication
The device will respond on the I2C address you specified. 
You should read the number of encoders +1 bytes worth of data.

The device will return a signed byte for each encoder. This delta value represents how much the value has changed position since the last read.
After all encoder data is transmitted there will be a byte that contains a bitfield of which buttons were pressed.

After a read has occured, encoder delta and bitfield will be reset.

## Known limitations
- A maximum of 8 encoders are supported, as that's when you'll run out of bitfield to hold button presses.
- You need to read often enough to prevent counter wraps.