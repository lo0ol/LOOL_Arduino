/**
 * \par Copyright (C), 2012-2015, MakeBlock
 * \class LOOL_Wifi
 * \brief   Driver for Me wifi device.
 * @file    LOOL_Wifi.h
 * @author  MakeBlock
 * @version V1.0.0
 * @date    2015/09/09
 * @brief   Header for for LOOL_Wifi.cpp module
 *
 * \par Copyright
 * This software is Copyright (C), 2012-2015, MakeBlock. Use is subject to license \n
 * conditions. The main licensing options available are GPL V2 or Commercial: \n
 *
 * \par Open Source Licensing GPL V2
 * This is the appropriate option if you want to share the source code of your \n
 * application with everyone you distribute it to, and you also want to give them \n
 * the right to share who uses it. If you wish to use this software under Open \n
 * Source Licensing, you must contribute all your source code to the open source \n
 * community in accordance with the GPL Version 2 when your application is \n
 * distributed. See http://www.gnu.org/copyleft/gpl.html
 *
 * \par Description
 * This file is a drive for Me wifi device, The wifi inherited the 
 * LOOL_Serial class from SoftwareSerial.
 *
 * \par Method List:
 *  inherited from LOOL_Serial
 *
 * \par History:
 * <pre>
 * `<Author>`         `<Time>`        `<Version>`        `<Descr>`
 * Mark Yan         2015/09/09     1.0.0            Rebuild the old lib.
 * </pre>
 *
 */

#ifndef LOOL_Wifi_H
#define LOOL_Wifi_H

#include <stdint.h>
#include <stdbool.h>
#include <arduino.h>
#include "LOOL_Config.h"
#include "LOOL_Serial.h"

#ifdef LOOL_PORT_DEFINED
#include "LOOL_Port.h"
#endif /* LOOL_PORT_DEFINED */

/**
 * Class: LOOL_Wifi
 * \par Description
 * Declaration of Class LOOL_Wifi.
 */
#ifndef LOOL_PORT_DEFINED
class LOOL_Wifi
#else /* !LOOL_PORT_DEFINED */
class LOOL_Wifi : public LOOL_Serial
#endif  /* !LOOL_PORT_DEFINED */
{
public:
#ifdef LOOL_PORT_DEFINED
/**
 * Alternate Constructor which can call your own function to map the Me wifi to arduino port,
 * no pins are used or initialized here.
 * \param[in]
 *   None
 */
  LOOL_Wifi();

/**
 * Alternate Constructor which can call your own function to map the Me wifi to arduino port,
 * If the hardware serial was selected, we will used the hardware serial.
 * \param[in]
 *   port - RJ25 port from PORT_1 to M2
 */
  LOOL_Wifi(uint8_t port);
#else // LOOL_PORT_DEFINED
/**
 * Alternate Constructor which can call your own function to map the Me wifi to arduino port,
 * If the hardware serial was selected, we will used the hardware serial.
 * \param[in]
 *   receivePin - the rx pin of serial(arduino port)
 * \param[in]
 *   transmitPin - the tx pin of serial(arduino port)
 * \param[in]
 *   inverse_logic - Whether the Serial level need inv.
 */
  LOOL_Wifi(uint8_t receivePin, uint8_t transmitPin, bool inverse_logic);
#endif // LOOL_PORT_DEFINED
};
#endif

