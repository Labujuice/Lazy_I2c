#include <Arduino.h>
#include "Lazy_i2c.h"
#include "Wire.h"

//====================================================================================================
//Class LazyI2C
//====================================================================================================
LazyI2C::LazyI2C(uint8_t address_in)
{
  Wire.begin();
  address = address_in;
}

void LazyI2C::memory_write(uint8_t mem_add, uint8_t *buf, uint16_t size)
{
  Wire.beginTransmission(address);
  Wire.write(mem_add);
  Wire.write(buf, size);
  Wire.endTransmission();
}

void LazyI2C::memory_read(uint8_t mem_add, uint8_t *buf, uint16_t size)
{
  Wire.beginTransmission(address);
  Wire.write(mem_add);
  Wire.endTransmission();

  Wire.beginTransmission(address);
  Wire.requestFrom(address, size);
  for (uint16_t i = 0; i < size; i++)
  {
    buf[i] = Wire.read();
  }
  Wire.endTransmission();
}

void LazyI2C::write(uint8_t *buf, uint16_t size)
{
  Wire.beginTransmission(address);
  Wire.write(buf, size);
  Wire.endTransmission();
}

void LazyI2C::read(uint8_t *buf, uint16_t size)
{
  Wire.beginTransmission(address);
  Wire.requestFrom(address, size);
  for (uint16_t i = 0; i < size; i++)
  {
    buf[i] = Wire.read();
  }
  Wire.endTransmission();
}
