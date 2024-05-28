#include "I2CEncoder.h"

int8_t position[NUMENCODERS] = {0};
uint8_t presses = 0;

void I2C_TxHandler(void)
{
  for (uint8_t n=0; n<NUMENCODERS;n++)
  {
    Wire.write(position[n]);
    position[n] = 0;
  }
  Wire.write(presses);
  presses = 0;
}

void enc_Handler(EncoderButton& eb)
{
  int16_t incamount = eb.increment();
  position[eb.userId()] += incamount;
}

void click_Handler(EncoderButton& eb)
{
  presses |=  1<<(eb.userId());
}

void encclick_Handler(EncoderButton& eb)
{
  int16_t incamount = eb.increment();
  position[eb.userId()] += incamount;
  presses |=  1<<(eb.userId());
}


void setup() {
  Wire.begin(I2CADDRESS);
  Wire.onRequest(I2C_TxHandler);

for ( uint8_t b=0; b<NUMENCODERS; b++ ) {
    // Set button identity
    buttonRow[b].setUserId(b);
    // Set handlers for events
    buttonRow[b].setEncoderHandler(enc_Handler);
    buttonRow[b].setReleasedHandler(click_Handler);
    buttonRow[b].setEncoderReleasedHandler(encclick_Handler);
  }
}

void loop() {
  for ( uint8_t b=0; b<NUMENCODERS; b++ ) {
    buttonRow[b].update();
  }
}
