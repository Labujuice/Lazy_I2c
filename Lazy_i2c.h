#ifndef LAZYI2C_HPP_
#define LAZYI2C_HPP_

class LazyI2C
{
public:
  LazyI2C(uint8_t address_in);
  void memory_write(uint8_t mem_add, uint8_t *buf, uint16_t size);
  void memory_read(uint8_t mem_add, uint8_t *buf, uint16_t size);
  void write(uint8_t *buf, uint16_t size);
  void read(uint8_t *buf, uint16_t size);

private:
  uint8_t address;
};

#endif
