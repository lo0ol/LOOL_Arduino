/**
 * \par Copyright (C), 2012-2015, MakeBlock
 * \class LOOL_Serial
 * \brief   Driver for serial.
 * @file    LOOL_Serial.h
 * @author  MakeBlock
 * @version V1.0.0
 * @date    2015/09/08
 * @brief   Header for for LOOL_Serial.cpp module
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
 * This file is a drive for serial, It support hardware and software serial
 *
 * \par Method List:
 *
 *    1. void LOOL_Serial::setHardware(bool mode)
 *    2. void LOOL_Serial::begin(long baudrate)
 *    3. void LOOL_Serial::end(void)
 *    4. size_t LOOL_Serial::write(uint8_t byte)
 *    5. int16_t LOOL_Serial::read(void)
 *    6. int16_t LOOL_Serial::available(void)
 *    7. bool LOOL_Serial::listen(void)
 *    8. bool LOOL_Serial::isListening(void)
 *    9. int16_t LOOL_Serial::poll(void)
 *
 * \par History:
 * <pre>
 * `<Author>`         `<Time>`        `<Version>`        `<Descr>`
 * Mark Yan         2015/09/08     1.0.0            Rebuild the old lib.
 * </pre>
 */
#ifndef LOOL_Serial_H
#define LOOL_Serial_H

#include <stdint.h>
#include <stdbool.h>
#include <arduino.h>
#include "LOOL_Config.h"

#ifdef LOOL_PORT_DEFINED
#include "LOOL_Port.h"
#endif // LOOL_PORT_DEFINED

/**
 * Class: LOOL_Serial
 * \par Description
 * Declaration of Class LOOL_Serial.
 */
#ifndef LOOL_PORT_DEFINED
class LOOL_Serial
#else // !LOOL_PORT_DEFINED
class LOOL_Serial : public LOOL_Port, public SoftwareSerial
#endif // !LOOL_PORT_DEFINED
{
public:
#ifdef LOOL_PORT_DEFINED
/**
 * Alternate Constructor which can call your own function to map the serial to arduino port,
 * no pins are used or initialized here. hardware serial will be used by default.
 * \param[in]
 *   None
 */
  LOOL_Serial(void);
	
/**
 * Alternate Constructor which can call your own function to map the serial to arduino port,
 * If the hardware serial was selected, we will used the hardware serial.
 * \param[in]
 *   port - RJ25 port from PORT_1 to M2
 */
  LOOL_Serial(uint8_t port);
#else // LOOL_PORT_DEFINED
/**
 * Alternate Constructor which can call your own function to map the serial to arduino port,
 * If the hardware serial was selected, we will used the hardware serial.
 * \param[in]
 *   receivePin - the rx pin of serial(arduino port)
 * \param[in]
 *   transmitPin - the tx pin of serial(arduino port)
 * \param[in]
 *   inverse_logic - Whether the Serial level need inv.
 */
  LOOL_Serial(uint8_t receivePin, uint8_t transmitPin, bool inverse_logic = false);
#endif /* LOOL_PORT_DEFINED */

/**
 * \par Function
 *   setHardware
 * \par Description
 *   if need change the hardware and software serial, this function can be used.
 * \param[in]
 *   mode - if need use hardware serial this value should set to true, or set it false.
 * \par Output
 *   None
 * \return
 *   None
 * \par Others
 *   None
 */
  void setHardware(bool mode);

/**
 * \par Function
 *   begin
 * \par Description
 *   Sets the speed (baud rate) for the serial communication. Supported baud 
 *   rates are 300, 600, 1200, 2400, 4800, 9600, 14400, 19200, 28800, 31250, 
 *   38400, 57600, and 115200.
 * \param[in]
 *   baudrate - he baud rate (long)
 * \par Output
 *   None
 * \return
 *   None
 * \par Others
 *   None
 */
  void begin(long baudrate);

/**
 * \par Function
 *   write
 * \par Description
 *   Writes binary data to the serial port. This data is sent as a byte or series of bytes; 
 * \param[in]
 *   byte - a value to send as a single byte
 * \par Output
 *   None
 * \return
 *   it will return the number of bytes written, though reading that number is optional
 * \par Others
 *   None
 */
  size_t write(uint8_t byte);

/**
 * \par Function
 *   read
 * \par Description
 *   Return a character that was received on the RX pin of the software serial port. 
 *   Note that only one SoftwareSerial instance can receive incoming data at a time 
 *  (select which one with the listen() function).
 * \par Output
 *   None
 * \return
 *   The character read, or -1 if none is available
 * \par Others
 *   None
 */
  int16_t read(void);

/**
 * \par Function
 *   available
 * \par Description
 *   Get the number of bytes (characters) available for reading from a software
 *   serial port. This is data that's already arrived and stored in the serial 
 *   receive buffer.
 * \par Output
 *   None
 * \return
 *   The number of bytes available to read
 * \par Others
 *   None
 */
  int16_t available(void);

/**
 * \par Function
 *   poll
 * \par Description
 *   If we used the serial as software serial port, and set the _polling mask true.
 *   we beed use this function to read the serial data.
 * \par Output
 *   None
 * \return
 *   The character read, or -1 if none is available
 * \par Others
 *   None
 */
  int16_t poll(void);

/**
 * \par Function
 *   end
 * \par Description
 *   Stop listening and release the object
 * \par Output
 *   None
 * \return
 *   None
 * \par Others
 *   None
 */
  void end(void);

/**
 * \par Function
 *   listen
 * \par Description
 *   Enables the selected software serial port to listen, used for software serial.
 *   Only one software serial port can listen at a time; data that arrives for other 
 *   ports will be discarded. Any data already received is discarded during the call 
 *   to listen() (unless the given instance is already listening).
 * \par Output
 *   None
 * \return
 *   This function sets the current object as the "listening"
 *   one and returns true if it replaces another
 * \par Others
 *   None
 */
  bool listen(void);

/**
 * \par Function
 *   isListening
 * \par Description
 *   Tests to see if requested software serial port is actively listening.
 * \par Output
 *   None
 * \return
 *   Returns true if we were actually listening.
 * \par Others
 *   None
 */
  bool isListening(void);
	
/**
 * \par Function
 *   sendString
 * \par Description
 *   Send a string as a series of bytes, used for printf().
 * \param[in]
 *   str - A string to send as a series of bytes
 * \par Output
 *   None
 * \return
 *   None
 * \par Others
 *   None
 */
  void sendString(char *str);

/**
 * \par Function
 *   printf
 * \par Description
 *   Printf format string (of which "printf" stands for "print formatted") 
 *   refers to a control parameter used by a class of functions in the 
 *   string-processing libraries of various programming languages.
 * \param[in]
 *   fmt - A string that specifies the format of the output. The formatting 
 *   string determines what additional arguments you need to provide.
 * \par Output
 *   None
 * \return
 *   None
 * \par Others
 *   None
 */
  void printf(char *fmt,...);

  boolean dataLineAvailable(void);
  String readDataLine(void);
  String concatenateWith(String s1,String s2);
  char letterOf(int i,String s);
  int stringLength(String s);
  boolean equalString(String s1,String s2);
  float getValue(String key);

protected:
  bool _hard;
  bool _polling;
  bool _scratch;
  int16_t _bitPeriod;
  int16_t _byte;
  long _lastTime;
  char buffer[64];
  String lastLine;
  int bufferIndex;

private:
  static volatile uint8_t _RxPin;
  static volatile uint8_t _TxPin; 
};
#endif

