// To ease merging with Marlin Development, I'm moving some of the Rigidbot settings out here to a seperate file.

#define RIGIDBOT
#define RIGIDBOT_SIZE 1 // 1 for regular, 2 for big

// This determines the communication speed of the printer
// :[2400,9600,19200,38400,57600,115200,250000]
#define BAUDRATE 115200

#define PID_dT ((OVERSAMPLENR * 8.0)/(F_CPU / 64.0 / 256.0)) //sampling period of the temperature routine

// RigidBot
#define DEFAULT_Kp 14.36
#define DEFAULT_Ki 0.66
#define DEFAULT_Kd 79.25

//RigidBot, from pid autotune
#define  DEFAULT_bedKp 355
#define  DEFAULT_bedKi 66.5
#define  DEFAULT_bedKd 480

// Parameters for all extruder heaters
#define THERMAL_RUNAWAY_PROTECTION_PERIOD 40 //in seconds
#define THERMAL_RUNAWAY_PROTECTION_HYSTERESIS 4 // in degree Celsius

// If you want to enable this feature for your bed heater,
// uncomment the 2 defines below:

// Parameters for the bed heater
#define THERMAL_RUNAWAY_PROTECTION_BED_PERIOD 20 //in seconds
#define THERMAL_RUNAWAY_PROTECTION_BED_HYSTERESIS 2 // in degree Celsius


#define ENDSTOPPULLUPS
const bool X_MIN_ENDSTOP_INVERTING = true;
const bool Y_MIN_ENDSTOP_INVERTING = true;
const bool Z_MIN_ENDSTOP_INVERTING = true;
const bool X_MAX_ENDSTOP_INVERTING = true;
const bool Y_MAX_ENDSTOP_INVERTING = true;
const bool Z_MAX_ENDSTOP_INVERTING = true;
const bool Z_PROBE_ENDSTOP_INVERTING = false; // set to true to invert the logic of the endstop.
//#define DISABLE_MAX_ENDSTOPS
//#define DISABLE_MIN_ENDSTOPS

#define X_ENABLE_ON 0
#define Y_ENABLE_ON 0
#define Z_ENABLE_ON 0
#define E_ENABLE_ON 0

#define DISABLE_X false
#define DISABLE_Y false
#define DISABLE_Z false
#define DISABLE_E false
#define DISABLE_INACTIVE_EXTRUDER true

#define INVERT_X_DIR true
#define INVERT_Y_DIR false
#define INVERT_Z_DIR false
#define INVERT_E0_DIR true
#define INVERT_E1_DIR true
#define INVERT_E2_DIR false

#define X_HOME_DIR -1
#define Y_HOME_DIR -1
#define Z_HOME_DIR -1

#define min_software_endstops true
#define max_software_endstops true

#if EXTRUDERS == 1
  #define X_DUAL_REDUCTION 0
#elif EXTRUDERS == 2
  #define X_DUAL_REDUCTION 57
#else
  #define X_DUAL_REDUCTION 350 // Prevent head crashes if EXTRUDERS > 2
#endif

#if RIGIDBOT_SIZE == 1 // 10x10 Regular
  #define X_MAX_POS (254 - X_DUAL_REDUCTION)
  #define Y_MAX_POS 248
  #define Z_MAX_POS 254
#elif RIGIDBOT_SIZE == 2 // 12x16 Big
  #define X_MAX_POS (406 - X_DUAL_REDUCTION)
  #define Y_MAX_POS 304
  #define Z_MAX_POS 254
#endif
#define X_MIN_POS 0
#define Y_MIN_POS 0
#define Z_MIN_POS 0

#define NUM_AXIS 4
#define HOMING_FEEDRATE {50*60, 50*60, 15*60, 0}

#define DEFAULT_AXIS_STEPS_PER_UNIT   {44.3090,22.1545,1600,53.5}  // default steps per unit for Ultimaker
#define DEFAULT_MAX_FEEDRATE          {500, 500, 4, 25}    // (mm/sec)
#define DEFAULT_MAX_ACCELERATION      {800,600,100,10000}    // X, Y, Z, E maximum start speed for accelerated moves. E default values are good for Skeinforge 40+, for older versions raise them a lot.

#define DEFAULT_ACCELERATION          600    // X, Y, Z and E max acceleration in mm/s^2 for printing moves
#define DEFAULT_RETRACT_ACCELERATION  1000   // X, Y, Z and E max acceleration in mm/s^2 for retracts

#define DEFAULT_XYJERK                5.0    // (mm/sec)
#define DEFAULT_ZJERK                 0.4    // (mm/sec)
#define DEFAULT_EJERK                 5.0    // (mm/sec)

// Disable stepper drivers until voltage has stabilized
#define STEPPER_RESET_FIX

#ifdef CUSTOM_M_CODES
  #ifdef ENABLE_AUTO_BED_LEVELING
    #define CUSTOM_M_CODE_SET_Z_PROBE_OFFSET 851
    #define Z_PROBE_OFFSET_RANGE_MIN -15
    #define Z_PROBE_OFFSET_RANGE_MAX -5
  #endif
#endif

#define EEPROM_SETTINGS

#ifdef EEPROM_SETTINGS
  // To disable EEPROM Serial responses and decrease program space by ~1700 byte: comment this out:
  #define EEPROM_CHITCHAT // please keep turned on if you can.
#endif

// Preheat Constants
#define PLA_PREHEAT_HOTEND_TEMP 200
#define PLA_PREHEAT_HPB_TEMP 70
#define PLA_PREHEAT_FAN_SPEED 255   // Insert Value between 0 and 255

#define ABS_PREHEAT_HOTEND_TEMP 230
#define ABS_PREHEAT_HPB_TEMP 100
#define ABS_PREHEAT_FAN_SPEED 255   // Insert Value between 0 and 255


// RigidBot Panel V1.0
// http://www.inventapart.com/
#define RIGIDPANEL

#if defined(RIGIDPANEL)
  #define ULTIPANEL
  #define SDSPEED  SPI_EIGHTH_SPEED        //  full/half/quarter/sixteenth, or 0-6 (0 = full speed)
  #define SDSUPPORT
  #define ULTRA_LCD
  #define LCD_WIDTH 20
  #define LCD_HEIGHT 4
  #define USB_LCD       // Get USB-centric strings from language.h
#endif
