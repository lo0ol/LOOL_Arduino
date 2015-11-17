#ifndef LOOL_MbotDCMotor_H
#define LOOL_MbotDCMotor_H

#include <stdint.h>
#include <stdbool.h>
#include <arduino.h>
#include "LOOL_Config.h"

#ifdef LOOL_PORT_DEFINED
#include "LOOL_Port.h"
#endif

#ifdef LOOL_PORT_DEFINED
#include "LOOL_DCMotor.h"

class LOOL_MBotDCMotor : public LOOL_DCMotor
{
public:
  LOOL_MBotDCMotor(uint8_t port);

  void move(int direction, int speed);
};
#endif //LOOL_PORT_DEFINED
#endif //MeMbotDCMotor_H

