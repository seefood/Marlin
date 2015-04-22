// To ease merging with Marlin Development, I'm moving some of the Rigidbot settings out here to a seperate file.

undef STRING_CONFIG_H_AUTHOR
#define STRING_CONFIG_H_AUTHOR "(Seefood@Github, RigidBot config)"

#define RIGIDBOT
#define RIGIDBOT_SIZE 1 // 1 for regular, 2 for big

// This determines the communication speed of the printer
// :[2400,9600,19200,38400,57600,115200,250000]
#undef BAUDRATE
#define BAUDRATE 230400 // seems to work while 250000 doesn't.

#undef TEMP_SENSOR_0 TEMP_SENSOR_1 TEMP_SENSOR_2 TEMP_SENSOR_3 TEMP_SENSOR_BED
#define TEMP_SENSOR_0 1
#define TEMP_SENSOR_1 1
#define TEMP_SENSOR_2 0
#define TEMP_SENSOR_3 0
#define TEMP_SENSOR_BED 1

// RigidBot, from pid autotune
#define DEFAULT_Kp 14.36
#define DEFAULT_Ki 0.66
#define DEFAULT_Kd 79.25

//RigidBot bed, from pid autotune
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

#ifndef ENDSTOPPULLUPS
  // fine endstop settings: Individual pullups. will be ignored if ENDSTOPPULLUPS is defined
  #define ENDSTOPPULLUP_XMAX
  #define ENDSTOPPULLUP_YMAX
  #define ENDSTOPPULLUP_ZMAX
  #define ENDSTOPPULLUP_XMIN
  #define ENDSTOPPULLUP_YMIN
  #define ENDSTOPPULLUP_ZMIN
  #define ENDSTOPPULLUP_ZPROBE
#endif

#undef INVERT_X_DIR
#define INVERT_X_DIR true

#undef INVERT_E0_DIR
#define INVERT_E0_DIR true
#undef INVERT_E1_DIR
#define INVERT_E1_DIR true

#if EXTRUDERS == 1
  #define X_DUAL_REDUCTION 0
#elif EXTRUDERS == 2
  #define X_DUAL_REDUCTION 57
#else
  #define X_DUAL_REDUCTION 350 // Prevent head crashes if EXTRUDERS > 2
#endif

#undef X_MAX_POS
#undef Y_MAX_POS
#undef Z_MAX_POS

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

#ifdef ENABLE_AUTO_BED_LEVELING
  #ifdef AUTO_BED_LEVELING_GRID // Check if Probe_Offset * Grid Points is greater than Probing Range
    #if X_PROBE_OFFSET_FROM_EXTRUDER < 0
      #if (-(X_PROBE_OFFSET_FROM_EXTRUDER * AUTO_BED_LEVELING_GRID_POINTS) >= (RIGHT_PROBE_BED_POSITION - LEFT_PROBE_BED_POSITION))
         #error "The X axis probing range is not enough to fit all the points defined in AUTO_BED_LEVELING_GRID_POINTS"
      #endif
    #else
      #if ((X_PROBE_OFFSET_FROM_EXTRUDER * AUTO_BED_LEVELING_GRID_POINTS) >= (RIGHT_PROBE_BED_POSITION - LEFT_PROBE_BED_POSITION))
         #error "The X axis probing range is not enough to fit all the points defined in AUTO_BED_LEVELING_GRID_POINTS"
      #endif
    #endif
    #if Y_PROBE_OFFSET_FROM_EXTRUDER < 0
      #if (-(Y_PROBE_OFFSET_FROM_EXTRUDER * AUTO_BED_LEVELING_GRID_POINTS) >= (BACK_PROBE_BED_POSITION - FRONT_PROBE_BED_POSITION))
         #error "The Y axis probing range is not enough to fit all the points defined in AUTO_BED_LEVELING_GRID_POINTS"
      #endif
    #else
      #if ((Y_PROBE_OFFSET_FROM_EXTRUDER * AUTO_BED_LEVELING_GRID_POINTS) >= (BACK_PROBE_BED_POSITION - FRONT_PROBE_BED_POSITION))
         #error "The Y axis probing range is not enough to fit all the points defined in AUTO_BED_LEVELING_GRID_POINTS"
      #endif
    #endif
  #endif
#endif // ENABLE_AUTO_BED_LEVELING

#undef HOMING_FEDERATE
#define HOMING_FEEDRATE {50*60, 50*60, 15*60, 0}

#undef DEFAULT_AXIS_STEPS_PER_UNIT DEFAULT_MAX_FEEDRATE DEFAULT_MAX_ACCELERATION
#define DEFAULT_AXIS_STEPS_PER_UNIT   {44.3090,22.1545,1600,53.5}  // default steps per unit for Ultimaker
#define DEFAULT_MAX_FEEDRATE          {500, 500, 4, 25}    // (mm/sec)
#define DEFAULT_MAX_ACCELERATION      {800,600,100,10000}    // X, Y, Z, E maximum start speed for accelerated moves. E default values are good for Skeinforge 40+, for older versions raise them a lot.

#undef DEFAULT_ACCELERATION DEFAULT_RETRACT_ACCELERATION
#define DEFAULT_ACCELERATION          600    // X, Y, Z and E max acceleration in mm/s^2 for printing moves
#define DEFAULT_RETRACT_ACCELERATION  1000   // X, Y, Z and E max acceleration in mm/s^2 for retracts

#undef DEFAULT_XYJERK DEFAULT_ZJERK DEFAULT_EJERK
#define DEFAULT_XYJERK                5.0    // (mm/sec)
#define DEFAULT_ZJERK                 0.4    // (mm/sec)
#define DEFAULT_EJERK                 5.0    // (mm/sec)

// Disable stepper drivers until voltage has stabilized
#define STEPPER_RESET_FIX

#ifdef CUSTOM_M_CODES
  #ifdef ENABLE_AUTO_BED_LEVELING
    #undef CUSTOM_M_CODE_SET_Z_PROBE_OFFSET Z_PROBE_OFFSET_RANGE_MIN Z_PROBE_OFFSET_RANGE_MAX
    #define CUSTOM_M_CODE_SET_Z_PROBE_OFFSET 851
    #define Z_PROBE_OFFSET_RANGE_MIN -15
    #define Z_PROBE_OFFSET_RANGE_MAX -5
  #endif
#endif

#define EEPROM_SETTINGS
#define EEPROM_CHITCHAT // please keep turned on if you can.

// Preheat Constants
#undef PLA_PREHEAT_HOTEND_TEMP PLA_PREHEAT_HPB_TEMP PLA_PREHEAT_FAN_SPEED
#undef ABS_PREHEAT_HOTEND_TEMP ABS_PREHEAT_HPB_TEMP ABS_PREHEAT_FAN_SPEED

#define PLA_PREHEAT_HOTEND_TEMP 200
#define PLA_PREHEAT_HPB_TEMP 70
#define PLA_PREHEAT_FAN_SPEED 255   // Insert Value between 0 and 255

#define ABS_PREHEAT_HOTEND_TEMP 230
#define ABS_PREHEAT_HPB_TEMP 100
#define ABS_PREHEAT_FAN_SPEED 255   // Insert Value between 0 and 255


// RigidBot Panel V1.0
// http://www.inventapart.com/
//#define RIGIDPANEL

#if defined(RIGIDPANEL)
  #define ULTIPANEL
  #define SDSPEED  SPI_EIGHTH_SPEED        //  full/half/quarter/sixteenth, or 0-6 (0 = full speed)
  #define SDSUPPORT
  #define ULTRA_LCD
  #define LCD_WIDTH 20
  #define LCD_HEIGHT 4
  #define USB_LCD       // Get USB-centric strings from language.h
#endif
