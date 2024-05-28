#include <Arduino.h>
#define ENCODER_DO_NOT_USE_INTERRUPTS
#include <EncoderButton.h>
#include <Wire.h>



void I2C_TxHandler(void);
void enc_Handler(EncoderButton& eb);
void click_Handler(EncoderButton& e);

// I2C address the device responds to
#define I2CADDRESS 0x55

//How many encoders are defined below
#define NUMENCODERS 5

// Encoder pins are in the form <A>, <B>, <SW>
// If there's no switch, just <A>,<B>
// Or you could just do switch with <SW>
EncoderButton buttonRow[NUMENCODERS] = { 
  EncoderButton(11,12,10),
  EncoderButton(8,9,7),
  EncoderButton(5,6,4),
  EncoderButton(2,3,14),
  EncoderButton(16,15,17)
  };

//#define DEBUG
