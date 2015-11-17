#ifndef LOOL_Buzzer_H
#define LOOL_Buzzer_H

#include <stdint.h>
#include <stdbool.h>
#include <arduino.h>
#include "LOOL_Config.h"

#ifdef LOOL_PORT_DEFINED
#include "LOOL_Port.h"
#endif // LOOL_PORT_DEFINED

///@brief Class for LOOL_Buzzer module
class LOOL_Buzzer : public LOOL_Port
{
public:
#ifdef LOOL_PORT_DEFINED
  LOOL_Buzzer();
  LOOL_Buzzer(uint8_t port);
  LOOL_Buzzer(uint8_t port, uint8_t slot);
#else // LOOL_PORT_DEFINED
  LOOL_Buzzer(int pin);
#endif // LOOL_PORT_DEFINED
  void setpin(int pin);
  void tone(int pin, uint16_t frequency, uint32_t duration);
  void tone(uint16_t frequency, uint32_t duration = 0);
  void noTone(int pin);
  void noTone();
};

#endif
