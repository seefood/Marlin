/****************************************************************************************
 * RigidBot Arduino Mega pin assignment
 *
 ****************************************************************************************/
#define KNOWN_BOARD 1

#define LARGE_FLASH        true

#define X_STEP_PIN         54
#define X_DIR_PIN          55
#define X_ENABLE_PIN       38
#define X_MIN_PIN           3
#define X_MAX_PIN           2

#define Y_STEP_PIN         60
#define Y_DIR_PIN          61
#define Y_ENABLE_PIN       56
#define Y_MIN_PIN          14
#define Y_MAX_PIN          15

#define Z_STEP_PIN         46
#define Z_DIR_PIN          48
#define Z_ENABLE_PIN       62
#define Z_MIN_PIN          18
#define Z_MAX_PIN          19

#define Z2_STEP_PIN        36
#define Z2_DIR_PIN         34
#define Z2_ENABLE_PIN      30

#define E0_STEP_PIN        36 // 26
#define E0_DIR_PIN         34 // 28
#define E0_ENABLE_PIN      30 // 24

#define E1_STEP_PIN        26 //36
#define E1_DIR_PIN         28 //34
#define E1_ENABLE_PIN      24 //30

#define SDPOWER            -1
#define SDSS               53
#define LED_PIN            13

#define FAN_PIN            8 //11 // IO pin. Buffer needed

#define PS_ON_PIN          -1

#define HEATER_0_PIN       9   // EXTRUDER 1
#define HEATER_1_PIN       12    // EXTRUDER 2 (FAN On Sprinter)
#define HEATER_2_PIN       -1
#define TEMP_0_PIN         14   // ANALOG NUMBERING
#define TEMP_1_PIN         13   // ANALOG NUMBERING
#define TEMP_2_PIN         -1   // ANALOG NUMBERING
#define HEATER_BED_PIN     10   // BED
#define TEMP_BED_PIN       15   // ANALOG NUMBERING

#ifdef NUM_SERVOS
  #define SERVO0_PIN         11
  #if NUM_SERVOS > 1
    #define SERVO1_PIN        6
  #endif
  #if NUM_SERVOS > 2
    #define SERVO2_PIN        5
  #endif
  #if NUM_SERVOS > 3
    #define SERVO3_PIN        4
  #endif
#endif

#define STEPPER_RESET_PIN 41 // #define STEPPER_RESET_FIX in Configuration.h to use this during boot

// LCD Panel options for the RigidBoard
#define LCD_PINS_RS          16
#define LCD_PINS_ENABLE      17
#define LCD_PINS_D4          23
#define LCD_PINS_D5          25
#define LCD_PINS_D6          27
#define LCD_PINS_D7          29

#ifdef REPRAP_DISCOUNT_SMART_CONTROLLER
  #define BEEPER 37

  #define BTN_EN1 31
  #define BTN_EN2 33
  #define BTN_ENC 35

  #define SDCARDDETECT 22

  #define KILL_PIN 32

#elif defined(RIGIDPANEL)
  #define BEEPER -1

  #define BTN_UP  37
  #define BTN_DWN 35
  #define BTN_LFT 33
  #define BTN_RT  32

  #define BTN_EN1 -1
  #define BTN_EN2 -1
  #define BTN_ENC 31

  #define SDCARDDETECT 22

  #define KILL_PIN -1

#else
  #define BEEPER 33  // Beeper on AUX-4
  #define KILL_PIN -1

  //buttons are directly attached using AUX-2
  #ifdef REPRAPWORLD_KEYPAD
    #define BTN_EN1 64 // encoder
    #define BTN_EN2 59 // encoder
    #define BTN_ENC 63 // enter button
    #define SHIFT_OUT 40 // shift register
    #define SHIFT_CLK 44 // shift register
    #define SHIFT_LD 42 // shift register
  #else
    #define BTN_UP  37
    #define BTN_DWN 35
    #define BTN_LFT 33
    #define BTN_RT  32
    #define BTN_ENT 31
    //#define BTN_EN1 37
    //#define BTN_EN2 35
    //#define BTN_ENC 31  //the click
  #endif

  #ifdef G3D_PANEL
    #define SDCARDDETECT 49
  #else
    #define SDCARDDETECT -1  // Ramps does not use this port
  #endif

#endif

#ifndef SDSUPPORT
  // these pins are defined in the SD library if building with SD support
  #define MAX_SCK_PIN          52
  #define MAX_MISO_PIN         50
  #define MAX_MOSI_PIN         51
  #define MAX6675_SS       53
#else
  #define MAX6675_SS       49
#endif
