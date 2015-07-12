/**
 * English
 *
 * LCD Menu Messages
 * Se also documentation/LCDLanguageFont.md
 *
 */
#ifndef LANGUAGE_EN_H
#define LANGUAGE_EN_H

#if !( defined(MAPPER_NON)|| defined(MAPPER_C2C3)|| defined(MAPPER_D0D1)|| defined(MAPPER_D0D1_MOD)|| defined(MAPPER_E382E383) )
  #define MAPPER_NON         // For direct ASCII codes
#endif

//#define SIMULATE_ROMFONT //Comment in to see what is seen on the character based displays
#if !( defined(SIMULATE_ROMFONT)|| defined(DISPLAY_CHARSET_ISO10646_1)|| defined(DISPLAY_CHARSET_ISO10646_5)|| defined(DISPLAY_CHARSET_ISO10646_KANA)|| defined(DISPLAY_CHARSET_ISO10646_CN) )
  #define DISPLAY_CHARSET_ISO10646_1 // use the better font on full graphic displays.
#endif


#ifndef WELCOME_MSG
#define WELCOME_MSG                         MACHINE_NAME " ready."
#endif
#ifndef MSG_SD_INSERTED
#define MSG_SD_INSERTED                     "Card inserted"
#endif
#ifndef MSG_SD_REMOVED
#define MSG_SD_REMOVED                      "Card removed"
#endif
#ifndef MSG_MAIN
#define MSG_MAIN                            "Main"
#endif
#ifndef MSG_AUTOSTART
#define MSG_AUTOSTART                       "Autostart"
#endif
#ifndef MSG_DISABLE_STEPPERS
#define MSG_DISABLE_STEPPERS                "Disable steppers"
#endif
#ifndef MSG_AUTO_HOME
#define MSG_AUTO_HOME                       "Auto home"
#endif
#ifndef MSG_SET_HOME_OFFSETS
#define MSG_SET_HOME_OFFSETS                "Set home offsets"
#endif
#ifndef MSG_SET_ORIGIN
#define MSG_SET_ORIGIN                      "Set origin"
#endif
#ifndef MSG_PREHEAT_PLA
#define MSG_PREHEAT_PLA                     "Preheat PLA"
#endif
#ifndef MSG_PREHEAT_PLA_N
#define MSG_PREHEAT_PLA_N                   MSG_PREHEAT_PLA " "
#endif
#ifndef MSG_PREHEAT_PLA_ALL
#define MSG_PREHEAT_PLA_ALL                 MSG_PREHEAT_PLA " All"
#endif
#ifndef MSG_PREHEAT_PLA_BEDONLY
#define MSG_PREHEAT_PLA_BEDONLY             MSG_PREHEAT_PLA " Bed"
#endif
#ifndef MSG_PREHEAT_PLA_SETTINGS
#define MSG_PREHEAT_PLA_SETTINGS            MSG_PREHEAT_PLA " conf"
#endif
#ifndef MSG_PREHEAT_ABS
#define MSG_PREHEAT_ABS                     "Preheat ABS"
#endif
#ifndef MSG_PREHEAT_ABS_N
#define MSG_PREHEAT_ABS_N                   MSG_PREHEAT_ABS " "
#endif
#ifndef MSG_PREHEAT_ABS_ALL
#define MSG_PREHEAT_ABS_ALL                 MSG_PREHEAT_ABS " All"
#endif
#ifndef MSG_PREHEAT_ABS_BEDONLY
#define MSG_PREHEAT_ABS_BEDONLY             MSG_PREHEAT_ABS " Bed"
#endif
#ifndef MSG_PREHEAT_ABS_SETTINGS
#define MSG_PREHEAT_ABS_SETTINGS            MSG_PREHEAT_ABS " conf"
#endif
#ifndef MSG_H1
#define MSG_H1                              "1"
#endif
#ifndef MSG_H2
#define MSG_H2                              "2"
#endif
#ifndef MSG_H3
#define MSG_H3                              "3"
#endif
#ifndef MSG_H4
#define MSG_H4                              "4"
#endif
#ifndef MSG_COOLDOWN
#define MSG_COOLDOWN                        "Cooldown"
#endif
#ifndef MSG_SWITCH_PS_ON
#define MSG_SWITCH_PS_ON                    "Switch power on"
#endif
#ifndef MSG_SWITCH_PS_OFF
#define MSG_SWITCH_PS_OFF                   "Switch power off"
#endif
#ifndef MSG_EXTRUDE
#define MSG_EXTRUDE                         "Extrude"
#endif
#ifndef MSG_RETRACT
#define MSG_RETRACT                         "Retract"
#endif
#ifndef MSG_MOVE_AXIS
#define MSG_MOVE_AXIS                       "Move axis"
#endif
#ifndef MSG_LEVEL_BED
#define MSG_LEVEL_BED                       "Level bed"
#endif
#ifndef MSG_MOVE_X
#define MSG_MOVE_X                          "Move X"
#endif
#ifndef MSG_MOVE_Y
#define MSG_MOVE_Y                          "Move Y"
#endif
#ifndef MSG_MOVE_Z
#define MSG_MOVE_Z                          "Move Z"
#endif
#ifndef MSG_MOVE_E
#define MSG_MOVE_E                          "Extruder"
#endif
#ifndef MSG_MOVE_01MM
#define MSG_MOVE_01MM                       "Move 0.1mm"
#endif
#ifndef MSG_MOVE_1MM
#define MSG_MOVE_1MM                        "Move 1mm"
#endif
#ifndef MSG_MOVE_10MM
#define MSG_MOVE_10MM                       "Move 10mm"
#endif
#ifndef MSG_SPEED
#define MSG_SPEED                           "Speed"
#endif
#ifndef MSG_NOZZLE
#define MSG_NOZZLE                          "Nozzle"
#endif
#ifndef MSG_N0
#define MSG_N0                              " 0"
#endif
#ifndef MSG_N1
#define MSG_N1                              " 1"
#endif
#ifndef MSG_N2
#define MSG_N2                              " 2"
#endif
#ifndef MSG_N3
#define MSG_N3                              " 3"
#endif
#ifndef MSG_N4
#define MSG_N4                              " 4"
#endif
#ifndef MSG_BED
#define MSG_BED                             "Bed"
#endif
#ifndef MSG_FAN_SPEED
#define MSG_FAN_SPEED                       "Fan speed"
#endif
#ifndef MSG_FLOW
#define MSG_FLOW                            "Flow"
#endif
#ifndef MSG_CONTROL
#define MSG_CONTROL                         "Control"
#endif
#ifndef MSG_MIN
#define MSG_MIN                             " "LCD_STR_THERMOMETER " Min"
#endif
#ifndef MSG_MAX
#define MSG_MAX                             " "LCD_STR_THERMOMETER " Max"
#endif
#ifndef MSG_FACTOR
#define MSG_FACTOR                          " "LCD_STR_THERMOMETER " Fact"
#endif
#ifndef MSG_AUTOTEMP
#define MSG_AUTOTEMP                        "Autotemp"
#endif
#ifndef MSG_ON
#define MSG_ON                              "On "
#endif
#ifndef MSG_OFF
#define MSG_OFF                             "Off"
#endif
#ifndef MSG_PID_P
#define MSG_PID_P                           "PID-P"
#endif
#ifndef MSG_PID_I
#define MSG_PID_I                           "PID-I"
#endif
#ifndef MSG_PID_D
#define MSG_PID_D                           "PID-D"
#endif
#ifndef MSG_PID_C
#define MSG_PID_C                           "PID-C"
#endif
#ifndef MSG_E2
#define MSG_E2                              " E2"
#endif
#ifndef MSG_E3
#define MSG_E3                              " E3"
#endif
#ifndef MSG_E4
#define MSG_E4                              " E4"
#endif
#ifndef MSG_ACC
#define MSG_ACC                             "Accel"
#endif
#ifndef MSG_VXY_JERK
#define MSG_VXY_JERK                        "Vxy-jerk"
#endif
#ifndef MSG_VZ_JERK
#define MSG_VZ_JERK                         "Vz-jerk"
#endif
#ifndef MSG_VE_JERK
#define MSG_VE_JERK                         "Ve-jerk"
#endif
#ifndef MSG_VMAX
#define MSG_VMAX                            "Vmax "
#endif
#ifndef MSG_X
#define MSG_X                               "x"
#endif
#ifndef MSG_Y
#define MSG_Y                               "y"
#endif
#ifndef MSG_Z
#define MSG_Z                               "z"
#endif
#ifndef MSG_E
#define MSG_E                               "e"
#endif
#ifndef MSG_VMIN
#define MSG_VMIN                            "Vmin"
#endif
#ifndef MSG_VTRAV_MIN
#define MSG_VTRAV_MIN                       "VTrav min"
#endif
#ifndef MSG_AMAX
#define MSG_AMAX                            "Amax "
#endif
#ifndef MSG_A_RETRACT
#define MSG_A_RETRACT                       "A-retract"
#endif
#ifndef MSG_A_TRAVEL
#define MSG_A_TRAVEL                        "A-travel"
#endif
#ifndef MSG_XSTEPS
#define MSG_XSTEPS                          "Xsteps/mm"
#endif
#ifndef MSG_YSTEPS
#define MSG_YSTEPS                          "Ysteps/mm"
#endif
#ifndef MSG_ZSTEPS
#define MSG_ZSTEPS                          "Zsteps/mm"
#endif
#ifndef MSG_ESTEPS
#define MSG_ESTEPS                          "Esteps/mm"
#endif
#ifndef MSG_TEMPERATURE
#define MSG_TEMPERATURE                     "Temperature"
#endif
#ifndef MSG_MOTION
#define MSG_MOTION                          "Motion"
#endif
#ifndef MSG_VOLUMETRIC
#define MSG_VOLUMETRIC                      "Filament"
#endif
#ifndef MSG_VOLUMETRIC_ENABLED
#define MSG_VOLUMETRIC_ENABLED              "E in mm3"
#endif
#ifndef MSG_FILAMENT_SIZE_EXTRUDER_0
#define MSG_FILAMENT_SIZE_EXTRUDER_0        "Fil. Dia. 1"
#endif
#ifndef MSG_FILAMENT_SIZE_EXTRUDER_1
#define MSG_FILAMENT_SIZE_EXTRUDER_1        "Fil. Dia. 2"
#endif
#ifndef MSG_FILAMENT_SIZE_EXTRUDER_2
#define MSG_FILAMENT_SIZE_EXTRUDER_2        "Fil. Dia. 3"
#endif
#ifndef MSG_FILAMENT_SIZE_EXTRUDER_3
#define MSG_FILAMENT_SIZE_EXTRUDER_3        "Fil. Dia. 4"
#endif
#ifndef MSG_CONTRAST
#define MSG_CONTRAST                        "LCD contrast"
#endif
#ifndef MSG_STORE_EPROM
#define MSG_STORE_EPROM                     "Store memory"
#endif
#ifndef MSG_LOAD_EPROM
#define MSG_LOAD_EPROM                      "Load memory"
#endif
#ifndef MSG_RESTORE_FAILSAFE
#define MSG_RESTORE_FAILSAFE                "Restore failsafe"
#endif
#ifndef MSG_REFRESH
#define MSG_REFRESH                         "Refresh"
#endif
#ifndef MSG_WATCH
#define MSG_WATCH                           "Info screen"
#endif
#ifndef MSG_PREPARE
#define MSG_PREPARE                         "Prepare"
#endif
#ifndef MSG_TUNE
#define MSG_TUNE                            "Tune"
#endif
#ifndef MSG_PAUSE_PRINT
#define MSG_PAUSE_PRINT                     "Pause print"
#endif
#ifndef MSG_RESUME_PRINT
#define MSG_RESUME_PRINT                    "Resume print"
#endif
#ifndef MSG_STOP_PRINT
#define MSG_STOP_PRINT                      "Stop print"
#endif
#ifndef MSG_CARD_MENU
#define MSG_CARD_MENU                       "Print from SD"
#endif
#ifndef MSG_NO_CARD
#define MSG_NO_CARD                         "No SD card"
#endif
#ifndef MSG_DWELL
#define MSG_DWELL                           "Sleep..."
#endif
#ifndef MSG_USERWAIT
#define MSG_USERWAIT                        "Wait for user..."
#endif
#ifndef MSG_RESUMING
#define MSG_RESUMING                        "Resuming print"
#endif
#ifndef MSG_PRINT_ABORTED
#define MSG_PRINT_ABORTED                   "Print aborted"
#endif
#ifndef MSG_NO_MOVE
#define MSG_NO_MOVE                         "No move."
#endif
#ifndef MSG_KILLED
#define MSG_KILLED                          "KILLED. "
#endif
#ifndef MSG_STOPPED
#define MSG_STOPPED                         "STOPPED. "
#endif
#ifndef MSG_CONTROL_RETRACT
#define MSG_CONTROL_RETRACT                 "Retract mm"
#endif
#ifndef MSG_CONTROL_RETRACT_SWAP
#define MSG_CONTROL_RETRACT_SWAP            "Swap Re.mm"
#endif
#ifndef MSG_CONTROL_RETRACTF
#define MSG_CONTROL_RETRACTF                "Retract  V"
#endif
#ifndef MSG_CONTROL_RETRACT_ZLIFT
#define MSG_CONTROL_RETRACT_ZLIFT           "Hop mm"
#endif
#ifndef MSG_CONTROL_RETRACT_RECOVER
#define MSG_CONTROL_RETRACT_RECOVER         "UnRet +mm"
#endif
#ifndef MSG_CONTROL_RETRACT_RECOVER_SWAP
#define MSG_CONTROL_RETRACT_RECOVER_SWAP    "S UnRet+mm"
#endif
#ifndef MSG_CONTROL_RETRACT_RECOVERF
#define MSG_CONTROL_RETRACT_RECOVERF        "UnRet  V"
#endif
#ifndef MSG_AUTORETRACT
#define MSG_AUTORETRACT                     "AutoRetr."
#endif
#ifndef MSG_FILAMENTCHANGE
#define MSG_FILAMENTCHANGE                  "Change filament"
#endif
#ifndef MSG_INIT_SDCARD
#define MSG_INIT_SDCARD                     "Init. SD card"
#endif
#ifndef MSG_CNG_SDCARD
#define MSG_CNG_SDCARD                      "Change SD card"
#endif
#ifndef MSG_ZPROBE_OUT
#define MSG_ZPROBE_OUT                      "Z probe out. bed"
#endif
#ifndef MSG_POSITION_UNKNOWN
#define MSG_POSITION_UNKNOWN                "Home X/Y before Z"
#endif
#ifndef MSG_ZPROBE_ZOFFSET
#define MSG_ZPROBE_ZOFFSET                  "Z Offset"
#endif
#ifndef MSG_BABYSTEP_X
#define MSG_BABYSTEP_X                      "Babystep X"
#endif
#ifndef MSG_BABYSTEP_Y
#define MSG_BABYSTEP_Y                      "Babystep Y"
#endif
#ifndef MSG_BABYSTEP_Z
#define MSG_BABYSTEP_Z                      "Babystep Z"
#endif
#ifndef MSG_ENDSTOP_ABORT
#define MSG_ENDSTOP_ABORT                   "Endstop abort"
#endif
#ifndef MSG_HEATING_FAILED_LCD
#define MSG_HEATING_FAILED_LCD              "Heating failed"
#endif
#ifndef MSG_ERR_REDUNDANT_TEMP
#define MSG_ERR_REDUNDANT_TEMP              "Err: REDUNDANT TEMP ERROR"
#endif
#ifndef MSG_THERMAL_RUNAWAY
#define MSG_THERMAL_RUNAWAY                 "THERMAL RUNAWAY"
#endif
#ifndef MSG_ERR_MAXTEMP
#define MSG_ERR_MAXTEMP                     "Err: MAXTEMP"
#endif
#ifndef MSG_ERR_MINTEMP
#define MSG_ERR_MINTEMP                     "Err: MINTEMP"
#endif
#ifndef MSG_ERR_MAXTEMP_BED
#define MSG_ERR_MAXTEMP_BED                 "Err: MAXTEMP BED"
#endif
#ifndef MSG_ERR_MINTEMP_BED
#define MSG_ERR_MINTEMP_BED                 "Err: MINTEMP BED"
#endif
#ifndef MSG_END_HOUR
#define MSG_END_HOUR                        "hours"
#endif
#ifndef MSG_END_MINUTE
#define MSG_END_MINUTE                      "minutes"
#endif

#ifdef DELTA_CALIBRATION_MENU
  #ifndef MSG_DELTA_CALIBRATE
  #define MSG_DELTA_CALIBRATE             "Delta Calibration"
  #endif
  #ifndef MSG_DELTA_CALIBRATE_X
  #define MSG_DELTA_CALIBRATE_X           "Calibrate X"
  #endif
  #ifndef MSG_DELTA_CALIBRATE_Y
  #define MSG_DELTA_CALIBRATE_Y           "Calibrate Y"
  #endif
  #ifndef MSG_DELTA_CALIBRATE_Z
  #define MSG_DELTA_CALIBRATE_Z           "Calibrate Z"
  #endif
  #ifndef MSG_DELTA_CALIBRATE_CENTER
  #define MSG_DELTA_CALIBRATE_CENTER      "Calibrate Center"
  #endif
#endif // DELTA_CALIBRATION_MENU

#ifdef USB_LCD
  #undef MSG_SD_INIT_FAIL
  #define MSG_SD_INIT_FAIL "USB Drive init fail"
  #undef MSG_SD_CARD_OK
  #define MSG_SD_CARD_OK "USB Drive ok"
  #undef MSG_SD_PRINTING_BYTE
  #define MSG_SD_PRINTING_BYTE "USB Drive printing byte "
  #undef MSG_SD_NOT_PRINTING
  #define MSG_SD_NOT_PRINTING "Not USB Drive printing"
#endif
// LCD Menu Messages
// Please note these are limited to 17 characters!

	#define WELCOME_MSG MACHINE_NAME    " ready."
	#define MSG_SD_INSERTED             "Card inserted"
	#define MSG_SD_REMOVED              "Card removed"
	#define MSG_MAIN                    "Main"
	#define MSG_AUTOSTART               "Autostart"
	#define MSG_DISABLE_STEPPERS        "Disable steppers"
	#define MSG_AUTO_HOME               "Auto home"
	#define MSG_SET_ORIGIN              "Set origin"
	#define MSG_PREHEAT_PLA             "Preheat PLA"
	#define MSG_PREHEAT_PLA0            "Preheat PLA 1"
	#define MSG_PREHEAT_PLA1            "Preheat PLA 2"
	#define MSG_PREHEAT_PLA2            "Preheat PLA 3"
	#define MSG_PREHEAT_PLA012          "Preheat PLA All"
	#define MSG_PREHEAT_PLA_BEDONLY     "Preheat PLA Bed"
	#define MSG_PREHEAT_PLA_SETTINGS    "Preheat PLA conf"
	#define MSG_PREHEAT_ABS             "Preheat ABS"
	#define MSG_PREHEAT_ABS0            "Preheat ABS 1"
	#define MSG_PREHEAT_ABS1            "Preheat ABS 2"
	#define MSG_PREHEAT_ABS2            "Preheat ABS 3"
	#define MSG_PREHEAT_ABS012          "Preheat ABS All"
	#define MSG_PREHEAT_ABS_BEDONLY     "Preheat ABS Bed"
	#define MSG_PREHEAT_ABS_SETTINGS    "Preheat ABS conf"
	#define MSG_COOLDOWN                "Cooldown"
	#define MSG_SWITCH_PS_ON            "Switch power on"
	#define MSG_SWITCH_PS_OFF           "Switch power off"
	#define MSG_EXTRUDE                 "Extrude"
	#define MSG_RETRACT                 "Retract"
	#define MSG_MOVE_AXIS               "Move axis"
	#define MSG_MOVE_X                  "Move X"
	#define MSG_MOVE_Y                  "Move Y"
	#define MSG_MOVE_Z                  "Move Z"
	#define MSG_MOVE_E                  "Extruder"
	#define MSG_MOVE_E1                 "Extruder2"
	#define MSG_MOVE_E2                 "Extruder3"
	#define MSG_MOVE_01MM               "Move 0.1mm"
	#define MSG_MOVE_1MM                "Move 1mm"
	#define MSG_MOVE_10MM               "Move 10mm"
	#define MSG_SPEED                   "Speed"
	#define MSG_NOZZLE                  "Nozzle"
	#define MSG_NOZZLE1                 "Nozzle2"
	#define MSG_NOZZLE2                 "Nozzle3"
	#define MSG_BED                     "Bed"
	#define MSG_FAN_SPEED               "Fan speed"
	#define MSG_FLOW                    "Flow"
	#define MSG_FLOW0                   "Flow 0"
	#define MSG_FLOW1                   "Flow 1"
	#define MSG_FLOW2                   "Flow 2"
	#define MSG_CONTROL                 "Settings"
	#define MSG_MIN                     " \002 Min"
	#define MSG_MAX                     " \002 Max"
	#define MSG_FACTOR                  " \002 Fact"
	#define MSG_AUTOTEMP                "Autotemp"
	#define MSG_ON                      "On "
	#define MSG_OFF                     "Off"
	#define MSG_PID_P                   "PID-P"
	#define MSG_PID_I                   "PID-I"
	#define MSG_PID_D                   "PID-D"
	#define MSG_PID_C                   "PID-C"
	#define MSG_ACC                     "Accel"
	#define MSG_VXY_JERK                "Vxy-jerk"
	#define MSG_VZ_JERK                 "Vz-jerk"
	#define MSG_VE_JERK                 "Ve-jerk"
	#define MSG_VMAX                    "Vmax "
	#define MSG_X                       "x"
	#define MSG_Y                       "y"
	#define MSG_Z                       "z"
	#define MSG_E                       "e"
	#define MSG_VMIN                    "Vmin"
	#define MSG_VTRAV_MIN               "VTrav min"
	#define MSG_AMAX                    "Amax "
	#define MSG_A_RETRACT               "A-retract"
	#define MSG_XSTEPS                  "Xsteps/mm"
	#define MSG_YSTEPS                  "Ysteps/mm"
	#define MSG_ZSTEPS                  "Zsteps/mm"
	#define MSG_ESTEPS                  "Esteps/mm"
	#define MSG_RECTRACT                "Rectract"
	#define MSG_TEMPERATURE             "Temperature"
	#define MSG_MOTION                  "Motion"
	#define MSG_CONTRAST                "LCD contrast"
	#define MSG_STORE_EPROM             "Store settings"
	#define MSG_LOAD_EPROM              "Load settings"
	#define MSG_RESTORE_FAILSAFE        "Restore defaults"
	#define MSG_REFRESH                 "Refresh"
	#define MSG_WATCH                   "Info screen"
	#define MSG_PREPARE                 "Prepare"
	#define MSG_TUNE                    "Tune"
	#define MSG_PAUSE_PRINT             "Pause print"
	#define MSG_RESUME_PRINT            "Resume print"
	#define MSG_STOP_PRINT              "Stop print"
	#define MSG_CARD_MENU               "Print from SD"
	#define MSG_NO_CARD                 "No SD card"
	#define MSG_DWELL                   "Sleep..."
	#define MSG_USERWAIT                "Wait for user..."
	#define MSG_RESUMING                "Resuming print"
	#define MSG_NO_MOVE                 "No move."
	#define MSG_KILLED                  "KILLED. "
	#define MSG_STOPPED                 "STOPPED. "
	#define MSG_CONTROL_RETRACT         "Retract mm"
	#define MSG_CONTROL_RETRACT_SWAP    "Swap Re.mm"
	#define MSG_CONTROL_RETRACTF        "Retract  V"
	#define MSG_CONTROL_RETRACT_ZLIFT   "Hop mm"
	#define MSG_CONTROL_RETRACT_RECOVER "UnRet +mm"
	#define MSG_CONTROL_RETRACT_RECOVER_SWAP "S UnRet+mm"
	#define MSG_CONTROL_RETRACT_RECOVERF "UnRet  V"
	#define MSG_AUTORETRACT             "AutoRetr."
	#define MSG_FILAMENTCHANGE          "Change filament"
	#define MSG_INIT_SDCARD             "Init. SD card"
	#define MSG_CNG_SDCARD              "Change SD card"
	#define MSG_ZPROBE_OUT              "Z probe out. bed"
	#define MSG_POSITION_UNKNOWN        "Home X/Y before Z"
	#define MSG_ZPROBE_ZOFFSET          "Z Offset"
	#define MSG_BABYSTEP_X              "Babystep X"
	#define MSG_BABYSTEP_Y              "Babystep Y"
	#define MSG_BABYSTEP_Z              "Babystep Z"
	#define MSG_ENDSTOP_ABORT           "Endstop abort"
    #define MSG_HEAT_COOL               "Heat/Cool"
    #define MSG_UTILITIES               "Utilities"

    #ifdef USB_LCD
      #undef  MSG_SD_INSERTED
      #define MSG_SD_INSERTED           "USB inserted"
      #undef  MSG_SD_REMOVED
      #define MSG_SD_REMOVED            "USB removed"
      #undef  MSG_CARD_MENU
      #define MSG_CARD_MENU             "Print from USB"
      #undef  MSG_NO_CARD
      #define MSG_NO_CARD               "No USB drive"
      #undef  MSG_INIT_SDCARD
      #define MSG_INIT_SDCARD           "Init. USB Drive"
      #undef  MSG_CNG_SDCARD
      #define MSG_CNG_SDCARD            "Change USB Drive"
    #endif

#endif // LANGUAGE_EN_H
