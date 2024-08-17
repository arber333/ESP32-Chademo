#ifndef GLOBALS_H_
#define GLOBALS_H_

#define CHADEMO_IN1 36 //Input1 for chademo
#define CHADEMO_IN2 39 //PP input

#define CHADEMO_OUT1 26 // Contactor
#define CHADEMO_OUT2 27 // Contactor

#define MCP2517_CS 5// CS input of MCP2517
#define MCP2517_INT 15 // INT output of MCP2517
#define MCP2517_SCK 18
//#define MCP2517_QUARTZ_FREQUENCY 40000000
#define MCP2517_MISO 19
#define MCP2517_MOSI 23

#define CAN_BAUD 500000
#define minimum(a, b)           (((a) < (b)) ?  (a) : (b))
#define EEPROM_VALID	0xCC

//These have been moved to eeprom. After initial compile the values will be read from EEPROM.
//These thus set the default value to write to eeprom upon first start up
#define MAX_CHARGE_V	380
#define MAX_CHARGE_A	120
#define TARGET_CHARGE_V	380
#define MIN_CHARGE_A	20
#define CAPACITY 140

typedef struct
{
  uint8_t valid; //a token to store EEPROM version and validity. If it matches expected value then EEPROM is not reset to defaults //0
  float ampHours; //floats are 4 bytes //1
  float kiloWattHours; //5
  float packSizeKWH; //9
  uint16_t maxChargeVoltage; //21
  uint16_t targetChargeVoltage; //23
  uint8_t maxChargeAmperage; //25
  uint8_t minChargeAmperage; //26
  uint8_t capacity; //27
  uint8_t debuggingLevel; //29
  bool useBms;
  bool currentMissmatch;

} EESettings;

extern EESettings settings;
extern float Voltage;
extern float Current;
extern unsigned long CurrentMillis;
extern int Count;
extern bool overrideStart1;
extern bool overrideStart2;
extern bool initShunt;
#endif
