#ifndef ULTRALCD_IMPLEMENTATION_RIGIDPANEL_H
#define ULTRALCD_IMPLEMENTATION_RIGIDPANEL_H

/**
* Implementation of the LCD display routines for the Invent-A-Part RigidPanel LCD controller.
**/

extern volatile uint8_t buttons;  //the last checked buttons in a bit array.

////////////////////////////////////
// Setup button and encode mappings for each panel (into 'buttons' variable)
//
// This is just to map common functions (across different panels) onto the same 
// macro name. The mapping is independent of whether the button is directly connected or 
// via a shift/i2c register.

// All Ultipanels might have an encoder - so this is always be mapped onto first two bits
#define BLEN_B 1
#define BLEN_A 0

#define EN_B (1<<BLEN_B) // The two encoder pins are connected through BTN_EN1 and BTN_EN2
#define EN_A (1<<BLEN_A)

#if defined(BTN_ENC) && BTN_ENC > -1
  // encoder click is directly connected
  #define BLEN_C 2 
  #define EN_C (1<<BLEN_C) 
#endif 
  
//
// Setup other button mappings of each panel
//
  #define B_LE (1<<7)    
  #define B_UP (1<<6)
  #define B_DW (1<<4)
  #define B_RI (1<<3)
  
//  #define LCD_CLICKED (buttons&EN_C || buttons&B_RI)
  #define LCD_CLICKED (buttons&EN_C)

////////////////////////
// Setup Rotary Encoder Bit Values (for two pin encoders to indicate movement)
// These values are independent of which pins are used for EN_A and EN_B indications
// The rotary encoder part is also independent to the chipset used for the LCD
#if defined(EN_A) && defined(EN_B)
  #ifndef ULTIMAKERCONTROLLER
    #define encrot0 0
    #define encrot1 2
    #define encrot2 3
    #define encrot3 1
  #else
    #define encrot0 0
    #define encrot1 1
    #define encrot2 3
    #define encrot3 2
  #endif
#endif 


////////////////////////////////////
// Create LCD class instance and chipset-specific information
#if defined(LCD_I2C_TYPE_PCF8575)
  // note: these are register mapped pins on the PCF8575 controller not Arduino pins
  #define LCD_I2C_PIN_BL  3
  #define LCD_I2C_PIN_EN  2
  #define LCD_I2C_PIN_RW  1
  #define LCD_I2C_PIN_RS  0
  #define LCD_I2C_PIN_D4  4
  #define LCD_I2C_PIN_D5  5
  #define LCD_I2C_PIN_D6  6
  #define LCD_I2C_PIN_D7  7

  #include <Wire.h>
  #include <LCD.h>
  #include <LiquidCrystal_I2C.h>
  #define LCD_CLASS LiquidCrystal_I2C
  LCD_CLASS lcd(LCD_I2C_ADDRESS,LCD_I2C_PIN_EN,LCD_I2C_PIN_RW,LCD_I2C_PIN_RS,LCD_I2C_PIN_D4,LCD_I2C_PIN_D5,LCD_I2C_PIN_D6,LCD_I2C_PIN_D7);

#elif defined(LCD_I2C_TYPE_MCP23017)
  //for the LED indicators (which maybe mapped to different things in lcd_implementation_update_indicators())
  #define LED_A 0x04 //100
  #define LED_B 0x02 //010
  #define LED_C 0x01 //001

  #define LCD_HAS_STATUS_INDICATORS

  #include <Wire.h>
  #include <LiquidTWI2.h>
  #define LCD_CLASS LiquidTWI2
  LCD_CLASS lcd(LCD_I2C_ADDRESS);
  
#elif defined(LCD_I2C_TYPE_MCP23008)
  #include <Wire.h>
  #include <LiquidTWI2.h>
  #define LCD_CLASS LiquidTWI2
  LCD_CLASS lcd(LCD_I2C_ADDRESS);  
  
#else
  // Standard directly connected LCD implementations
  #if LANGUAGE_CHOICE == 6
    #include "LiquidCrystalRus.h"
    #define LCD_CLASS LiquidCrystalRus
  #else 
    #include "LiquidCrystalFast_Mod.h"
    #define LCD_CLASS LiquidCrystalFast
  #endif  
  LiquidCrystalFast lcd(LCD_PINS_RS, LCD_PINS_ENABLE, LCD_PINS_D4, LCD_PINS_D5,LCD_PINS_D6,LCD_PINS_D7);  //RS,Enable,D4,D5,D6,D7
#endif //defined(LCD_I2C_TYPE_PCF8575)

/* Custom characters defined in the first 8 characters of the LCD */
#define LCD_STR_BEDTEMP     "\x00"
#define LCD_STR_DEGREE      "\x01"
#define LCD_STR_THERMOMETER "\x02"
#define LCD_STR_UPLEVEL     "\x03"
#define LCD_STR_REFRESH     "\x04"
#define LCD_STR_FOLDER      "\x05"
#define LCD_STR_FEEDRATE    "\x06"
#define LCD_STR_CLOCK       "\x07"
#define LCD_STR_ARROW_RIGHT "\x7E"  /* from the default character set */

static void lcd_implementation_init()
{
    byte bedTemp[8] =
    {
        B00000,
        B11111,
        B10101,
        B10001,
        B10101,
        B11111,
        B00000,
        B00000
    }; //thanks Sonny Mounicou
    byte degree[8] =
    {
        B01100,
        B10010,
        B10010,
        B01100,
        B00000,
        B00000,
        B00000,
        B00000
    };
    byte thermometer[8] =
    {
        B00100,
        B01010,
        B01010,
        B01010,
        B01010,
        B10001,
        B10001,
        B01110
    };
    byte uplevel[8]={
        B00100,
        B01110,
        B11111,
        B00100,
        B11100,
        B00000,
        B00000,
        B00000
    }; //thanks joris
    byte refresh[8]={
        B00000,
        B00110,
        B11001,
        B11000,
        B00011,
        B10011,
        B01100,
        B00000,
    }; //thanks joris
    byte folder [8]={
        B00000,
        B11100,
        B11111,
        B10001,
        B10001,
        B11111,
        B00000,
        B00000
    }; //thanks joris
    byte feedrate [8]={
        B11100,
        B10000,
        B11000,
        B10111,
        B00101,
        B00110,
        B00101,
        B00000
    }; //thanks Sonny Mounicou
    byte clock [8]={
        B00000,
        B01110,
        B10011,
        B10101,
        B10001,
        B01110,
        B00000,
        B00000
    }; //thanks Sonny Mounicou

#if defined(LCDI2C_TYPE_PCF8575)
    lcd.begin(LCD_WIDTH, LCD_HEIGHT);
  #ifdef LCD_I2C_PIN_BL
    lcd.setBacklightPin(LCD_I2C_PIN_BL,POSITIVE);
    lcd.setBacklight(HIGH);
  #endif
  
#elif defined(LCD_I2C_TYPE_MCP23017)
    lcd.setMCPType(LTI_TYPE_MCP23017);
    lcd.begin(LCD_WIDTH, LCD_HEIGHT);
    lcd.setBacklight(0); //set all the LEDs off to begin with
    
#elif defined(LCD_I2C_TYPE_MCP23008)
    lcd.setMCPType(LTI_TYPE_MCP23008);
    lcd.begin(LCD_WIDTH, LCD_HEIGHT);
    
#else
    lcd.begin(LCD_WIDTH, LCD_HEIGHT);
#endif //LCDI2C_TYPE_PCF8575

    lcd.createChar(LCD_STR_BEDTEMP[0], bedTemp);
    lcd.createChar(LCD_STR_DEGREE[0], degree);
    lcd.createChar(LCD_STR_THERMOMETER[0], thermometer);
    lcd.createChar(LCD_STR_UPLEVEL[0], uplevel);
    lcd.createChar(LCD_STR_REFRESH[0], refresh);
    lcd.createChar(LCD_STR_FOLDER[0], folder);
    lcd.createChar(LCD_STR_FEEDRATE[0], feedrate);
    lcd.createChar(LCD_STR_CLOCK[0], clock);
    lcd.clear();
}

static void lcd_implementation_clear() { lcd.clear(); }

/* Arduino < 1.0.0 is missing a function to print PROGMEM strings, so we need to implement our own */
char lcd_printPGM(const char* str) {
  char c, n = 0;
  while ((c = pgm_read_byte(str++))) n += c;
  return n;
}

char lcd_print(char* str) {
  char c, n = 0;
  unsigned char i = 0;
  while ((c = str[i++])) n += c;
  return n;
}

unsigned lcd_print(char c) { return c; }

/*
Possible status screens:
16x2   |0123456789012345|
       |000/000 B000/000|
       |Status line.....|

16x4   |0123456789012345|
       |000/000 B000/000|
       |SD100%    Z000.0|
       |F100%     T--:--|
       |Status line.....|

20x2   |01234567890123456789|
       |T000/000D B000/000D |
       |Status line.........|

20x4   |01234567890123456789|
       |T000/000D B000/000D |
       |X+000.0 Y+000.0 Z+000.0|
       |F100%  SD100% T--:--|
       |Status line.........|

20x4   |01234567890123456789|
       |T000/000D B000/000D |
       |T000/000D     Z000.0|
       |F100%  SD100% T--:--|
       |Status line.........|
*/
static void lcd_implementation_status_screen()
{
    int tHotend=int(degHotend(0) + 0.5);
    int tTarget=int(degTargetHotend(0) + 0.5);

  #define LCD_TEMP_ONLY(T1,T2) \
    lcd.print(itostr3(T1 + 0.5)); \
    lcd.print('/'); \
    lcd.print(itostr3left(T2 + 0.5))

  #define LCD_TEMP(T1,T2,PREFIX) \
    lcd.print(PREFIX); \
    LCD_TEMP_ONLY(T1,T2); \
    lcd_printPGM(PSTR(LCD_STR_DEGREE " ")); \
    if (T2 < 10) lcd.print(' ')

  //
  // Line 1
  //

  lcd.setCursor(0, 0);
  lcd.print(LCD_STR_THERMOMETER[0]);
  lcd.print(itostr3(tHotend));
  lcd.print('/');
  lcd.print(itostr3left(tTarget));
  lcd_printPGM(PSTR(LCD_STR_DEGREE " "));
  if (tTarget < 10)
    lcd.print(' ');

  #if LCD_WIDTH < 20

    //
    // Hotend 0 Temperature
    //
    LCD_TEMP_ONLY(degHotend(0), degTargetHotend(0));

    //
    // Hotend 1 or Bed Temperature
    //
    #if EXTRUDERS > 1 || TEMP_SENSOR_BED != 0

      lcd.setCursor(8, 0);
      #if EXTRUDERS > 1
        lcd.print(LCD_STR_THERMOMETER[0]);
        LCD_TEMP_ONLY(degHotend(1), degTargetHotend(1));
      #else
        lcd.print(LCD_STR_BEDTEMP[0]);
        LCD_TEMP_ONLY(degBed(), degTargetBed());
      #endif

    #endif // EXTRUDERS > 1 || TEMP_SENSOR_BED != 0

  #else // LCD_WIDTH >= 20

    //
    // Hotend 0 Temperature
    //
    LCD_TEMP(degHotend(0), degTargetHotend(0), LCD_STR_THERMOMETER[0]);

    //
    // Hotend 1 or Bed Temperature
    //
    #if EXTRUDERS > 1 || TEMP_SENSOR_BED != 0
      lcd.setCursor(10, 0);
      #if EXTRUDERS > 1
        LCD_TEMP(degHotend(1), degTargetHotend(1), LCD_STR_THERMOMETER[0]);
      #else
        LCD_TEMP(degBed(), degTargetBed(), LCD_STR_BEDTEMP[0]);
      #endif

    #endif  // EXTRUDERS > 1 || TEMP_SENSOR_BED != 0

  #endif // LCD_WIDTH >= 20

  //
  // Line 2
  //

  #if LCD_HEIGHT > 2

    #if LCD_WIDTH < 20

      #ifdef SDSUPPORT
        lcd.setCursor(0, 2);
        lcd_printPGM(PSTR("SD"));
        if (IS_SD_PRINTING)
          lcd.print(itostr3(card.percentDone()));
        else
          lcd_printPGM(PSTR("---"));
          lcd.print('%');
      #endif // SDSUPPORT

    #else // LCD_WIDTH >= 20

      lcd.setCursor(0, 1);

      #if EXTRUDERS > 1 && TEMP_SENSOR_BED != 0

        // If we both have a 2nd extruder and a heated bed,
        // show the heated bed temp on the left,
        // since the first line is filled with extruder temps
        LCD_TEMP(degBed(), degTargetBed(), LCD_STR_BEDTEMP[0]);

      #else

        lcd.print('X');
        if (axis_known_position[X_AXIS])
          lcd.print(ftostr3(current_position[X_AXIS]));
        else
          lcd_printPGM(PSTR("---"));

        lcd_printPGM(PSTR("  Y"));
        if (axis_known_position[Y_AXIS])
          lcd.print(ftostr3(current_position[Y_AXIS]));
        else
          lcd_printPGM(PSTR("---"));

      #endif // EXTRUDERS > 1 || TEMP_SENSOR_BED != 0

    #endif // LCD_WIDTH >= 20

    lcd.setCursor(LCD_WIDTH - 8, 1);
    lcd.setCursor(11, 1);
    lcd.print('Z');
    if (axis_known_position[Z_AXIS])
      lcd.print(ftostr32sp(current_position[Z_AXIS] + 0.00001));
    else
      lcd_printPGM(PSTR("---.--"));

  #endif // LCD_HEIGHT > 2

  //
  // Line 3
  //

  #if LCD_HEIGHT > 3

    lcd.setCursor(0, 2);
    lcd.print(LCD_STR_FEEDRATE[0]);
    lcd.print(itostr3(feedrate_multiplier));
    lcd.print('%');

    #if LCD_WIDTH > 19 && defined(SDSUPPORT)

      lcd.setCursor(6, 2);
      lcd_printPGM(PSTR("USB"));
      if (IS_SD_PRINTING)
        lcd.print(itostr3(card.percentDone()));
      else
        lcd_printPGM(PSTR("---"));
      lcd.print('%');

    #endif // LCD_WIDTH > 19 && SDSUPPORT

    lcd.setCursor(LCD_WIDTH - 6, 2);
    lcd.print(LCD_STR_CLOCK[0]);
    if (print_job_start_ms != 0) {
      uint16_t time = millis()/60000 - print_job_start_ms/60000;
      lcd.print(itostr2(time/60));
      lcd.print(':');
      lcd.print(itostr2(time%60));
    }
    else {
      lcd_printPGM(PSTR("--:--"));
    }

  #endif // LCD_HEIGHT > 3

  //
  // Last Line
  // Status Message (which may be a Progress Bar or Filament display)
  //

  lcd.setCursor(0, LCD_HEIGHT - 1);

  #ifdef LCD_PROGRESS_BAR

    if (card.isFileOpen()) {
      // Draw the progress bar if the message has shown long enough
      // or if there is no message set.
      if (millis() >= progress_bar_ms + PROGRESS_BAR_MSG_TIME || !lcd_status_message[0]) {
        int tix = (int)(card.percentDone() * LCD_WIDTH * 3) / 100,
          cel = tix / 3, rem = tix % 3, i = LCD_WIDTH;
        char msg[LCD_WIDTH+1], b = ' ';
        msg[i] = '\0';
        while (i--) {
          if (i == cel - 1)
            b = LCD_STR_PROGRESS[2];
          else if (i == cel && rem != 0)
            b = LCD_STR_PROGRESS[rem-1];
          msg[i] = b;
        }
        lcd.print(msg);
        return;
      }
    } //card.isFileOpen

  #elif defined(FILAMENT_LCD_DISPLAY)

    // Show Filament Diameter and Volumetric Multiplier %
    // After allowing lcd_status_message to show for 5 seconds
    if (millis() >= previous_lcd_status_ms + 5000) {
      lcd_printPGM(PSTR("Dia "));
      lcd.print(ftostr12ns(filament_width_meas));
      lcd_printPGM(PSTR(" V"));
      lcd.print(itostr3(100.0*volumetric_multiplier[FILAMENT_SENSOR_EXTRUDER_NUM]));
  	  lcd.print('%');
  	  return;
    }

  #endif // FILAMENT_LCD_DISPLAY

  lcd_print(lcd_status_message);
}

static void lcd_implementation_drawmenu_generic(bool sel, uint8_t row, const char* pstr, char pre_char, char post_char) {
  char c;
  uint8_t n = LCD_WIDTH - 2;
  lcd.setCursor(0, row);
  lcd.print(sel ? pre_char : ' ');
  while ((c = pgm_read_byte(pstr)) && n > 0) {
    n -= lcd_print(c);
    pstr++;
  }
  while(n--) lcd.print(' ');
  lcd.print(post_char);
}

static void lcd_implementation_drawmenu_setting_edit_generic(bool sel, uint8_t row, const char* pstr, char pre_char, char* data) {
  char c;
  uint8_t n = LCD_WIDTH - 2 - lcd_strlen(data);
  lcd.setCursor(0, row);
  lcd.print(sel ? pre_char : ' ');
  while ((c = pgm_read_byte(pstr)) && n > 0) {
    n -= lcd_print(c);
    pstr++;
  }
  lcd.print(':');
  while (n--) lcd.print(' ');
  lcd_print(data);
}

static void lcd_implementation_drawmenu_setting_edit_generic_P(bool sel, uint8_t row, const char* pstr, char pre_char, const char* data) {
  char c;
  uint8_t n = LCD_WIDTH - 2 - lcd_strlen_P(data);
  lcd.setCursor(0, row);
  lcd.print(sel ? pre_char : ' ');
  while ((c = pgm_read_byte(pstr)) && n > 0) {
    n -= lcd_print(c);
    pstr++;
  }
  lcd.print(':');
  while (n--) lcd.print(' ');
  lcd_printPGM(data);
}

#define lcd_implementation_drawmenu_setting_edit_int3(sel, row, pstr, pstr2, data, minValue, maxValue) lcd_implementation_drawmenu_setting_edit_generic(sel, row, pstr, '>', itostr3(*(data)))
#define lcd_implementation_drawmenu_setting_edit_float3(sel, row, pstr, pstr2, data, minValue, maxValue) lcd_implementation_drawmenu_setting_edit_generic(sel, row, pstr, '>', ftostr3(*(data)))
#define lcd_implementation_drawmenu_setting_edit_float32(sel, row, pstr, pstr2, data, minValue, maxValue) lcd_implementation_drawmenu_setting_edit_generic(sel, row, pstr, '>', ftostr32(*(data)))
#define lcd_implementation_drawmenu_setting_edit_float43(sel, row, pstr, pstr2, data, minValue, maxValue) lcd_implementation_drawmenu_setting_edit_generic(sel, row, pstr, '>', ftostr43(*(data)))
#define lcd_implementation_drawmenu_setting_edit_float5(sel, row, pstr, pstr2, data, minValue, maxValue) lcd_implementation_drawmenu_setting_edit_generic(sel, row, pstr, '>', ftostr5(*(data)))
#define lcd_implementation_drawmenu_setting_edit_float52(sel, row, pstr, pstr2, data, minValue, maxValue) lcd_implementation_drawmenu_setting_edit_generic(sel, row, pstr, '>', ftostr52(*(data)))
#define lcd_implementation_drawmenu_setting_edit_float51(sel, row, pstr, pstr2, data, minValue, maxValue) lcd_implementation_drawmenu_setting_edit_generic(sel, row, pstr, '>', ftostr51(*(data)))
#define lcd_implementation_drawmenu_setting_edit_long5(sel, row, pstr, pstr2, data, minValue, maxValue) lcd_implementation_drawmenu_setting_edit_generic(sel, row, pstr, '>', ftostr5(*(data)))
#define lcd_implementation_drawmenu_setting_edit_bool(sel, row, pstr, pstr2, data) lcd_implementation_drawmenu_setting_edit_generic_P(sel, row, pstr, '>', (*(data))?PSTR(MSG_ON):PSTR(MSG_OFF))

//Add version for callback functions
#define lcd_implementation_drawmenu_setting_edit_callback_int3(sel, row, pstr, pstr2, data, minValue, maxValue, callback) lcd_implementation_drawmenu_setting_edit_generic(sel, row, pstr, '>', itostr3(*(data)))
#define lcd_implementation_drawmenu_setting_edit_callback_float3(sel, row, pstr, pstr2, data, minValue, maxValue, callback) lcd_implementation_drawmenu_setting_edit_generic(sel, row, pstr, '>', ftostr3(*(data)))
#define lcd_implementation_drawmenu_setting_edit_callback_float32(sel, row, pstr, pstr2, data, minValue, maxValue, callback) lcd_implementation_drawmenu_setting_edit_generic(sel, row, pstr, '>', ftostr32(*(data)))
#define lcd_implementation_drawmenu_setting_edit_callback_float43(sel, row, pstr, pstr2, data, minValue, maxValue, callback) lcd_implementation_drawmenu_setting_edit_generic(sel, row, pstr, '>', ftostr43(*(data)))
#define lcd_implementation_drawmenu_setting_edit_callback_float5(sel, row, pstr, pstr2, data, minValue, maxValue, callback) lcd_implementation_drawmenu_setting_edit_generic(sel, row, pstr, '>', ftostr5(*(data)))
#define lcd_implementation_drawmenu_setting_edit_callback_float52(sel, row, pstr, pstr2, data, minValue, maxValue, callback) lcd_implementation_drawmenu_setting_edit_generic(sel, row, pstr, '>', ftostr52(*(data)))
#define lcd_implementation_drawmenu_setting_edit_callback_float51(sel, row, pstr, pstr2, data, minValue, maxValue, callback) lcd_implementation_drawmenu_setting_edit_generic(sel, row, pstr, '>', ftostr51(*(data)))
#define lcd_implementation_drawmenu_setting_edit_callback_long5(sel, row, pstr, pstr2, data, minValue, maxValue, callback) lcd_implementation_drawmenu_setting_edit_generic(sel, row, pstr, '>', ftostr5(*(data)))
#define lcd_implementation_drawmenu_setting_edit_callback_bool(sel, row, pstr, pstr2, data, callback) lcd_implementation_drawmenu_setting_edit_generic_P(sel, row, pstr, '>', (*(data))?PSTR(MSG_ON):PSTR(MSG_OFF))

void lcd_implementation_drawedit(const char* pstr, char* value) {
  lcd.setCursor(1, 1);
  lcd_printPGM(pstr);
  lcd.print(':');
   #if LCD_WIDTH < 20
      lcd.setCursor(LCD_WIDTH - strlen(value), 1);
    #else
      lcd.setCursor(LCD_WIDTH -1 - strlen(value), 1);
   #endif
  lcd_print(value);
}

static void lcd_implementation_drawmenu_sdfile_base(uint8_t row, const char* pstr, const char* filename, char* longFilename, uint8_t item, bool isFolder, bool isSelected )
{
	static uint32_t scrollDelay;
	static uint8_t offset;
	static uint8_t lastItem = -1;
	static bool scrollDone = false;
	
	static const char* lastPstr = '\0';
	
	
	if (longFilename[0] != '\0')
		filename = longFilename;
	
	char c;
	uint8_t n = LCD_WIDTH - 1;
	lcd.setCursor(0, row);
	if ( isSelected )
	{
		if( item != lastItem )
		{
			offset = 0;
			scrollDone = false;
			scrollDelay = millis() + FILE_SCROLL_START_DELAY;
		}
		lastItem = item;
		filename += offset;
		lcd.print('>');
	}
	else
	{
		lcd.print(' ');
	}
	if ( isFolder )
	{
		lcd.print(LCD_STR_FOLDER[0]);
		n--;
	}
	while( ((c = *filename) != '\0') && (n>0) )
	{
		lcd.print(c);
		filename++;
		n--;
	}
	if ( millis() > scrollDelay )
	{
		if ( scrollDone )
		{
			offset = 0;
			scrollDone = false;
			scrollDelay = millis() + FILE_SCROLL_START_DELAY;
		}
		else
		{
			offset++;
			scrollDelay = millis() + FILE_SCROLL_DELAY;
		}
	}
	while(n--)
	{
		lcd.print(' ');
		if ( isSelected & !scrollDone )
		{
			scrollDone = true;
			scrollDelay = millis() + FILE_SCROLL_START_DELAY;
		}
	}
}

static void lcd_implementation_drawmenu_sdfile(bool sel, uint8_t row, const char* pstr, const char* filename, char* longFilename) {
  lcd_implementation_drawmenu_sd(sel, row, pstr, filename, longFilename, 2, ' ');
}

static void lcd_implementation_drawmenu_sddirectory(bool sel, uint8_t row, const char* pstr, const char* filename, char* longFilename) {
  lcd_implementation_drawmenu_sd(sel, row, pstr, filename, longFilename, 2, LCD_STR_FOLDER[0]);
}

#define lcd_implementation_drawmenu_back(sel, row, pstr, data) lcd_implementation_drawmenu_generic(sel, row, pstr, LCD_STR_UPLEVEL[0], LCD_STR_UPLEVEL[0])
#define lcd_implementation_drawmenu_submenu(sel, row, pstr, data) lcd_implementation_drawmenu_generic(sel, row, pstr, '>', LCD_STR_ARROW_RIGHT[0])
#define lcd_implementation_drawmenu_gcode(sel, row, pstr, gcode) lcd_implementation_drawmenu_generic(sel, row, pstr, '>', ' ')
#define lcd_implementation_drawmenu_function(sel, row, pstr, data) lcd_implementation_drawmenu_generic(sel, row, pstr, '>', ' ')

static void lcd_implementation_quick_feedback()
{
#ifdef LCD_USE_I2C_BUZZER
    lcd.buzz(60,1000/6);
#elif defined(BEEPER) && BEEPER > -1
    SET_OUTPUT(BEEPER);
    for(int8_t i=0;i<10;i++)
    {
      WRITE(BEEPER,HIGH);
      delay(3);
      WRITE(BEEPER,LOW);
      delay(3);
    }
#endif
}

#ifdef LCD_HAS_STATUS_INDICATORS

  static void lcd_implementation_update_indicators() {
    #if defined(LCD_I2C_PANELOLU2) || defined(LCD_I2C_VIKI)
      // Set the LEDS - referred to as backlights by the LiquidTWI2 library
      static uint8_t ledsprev = 0;
      uint8_t leds = 0;
      if (target_temperature_bed > 0) leds |= LED_A;
      if (target_temperature[0] > 0) leds |= LED_B;
      if (fanSpeed) leds |= LED_C;
      #if EXTRUDERS > 1
        if (target_temperature[1] > 0) leds |= LED_C;
      #endif
      if (leds != ledsprev) {
        lcd.setBacklight(leds);
        ledsprev = leds;
      }
    #endif
  }

#endif // LCD_HAS_STATUS_INDICATORS

#ifdef LCD_HAS_SLOW_BUTTONS

  extern millis_t next_button_update_ms;

  static uint8_t lcd_implementation_read_slow_buttons() {
    #ifdef LCD_I2C_TYPE_MCP23017
      uint8_t slow_buttons;
      // Reading these buttons this is likely to be too slow to call inside interrupt context
      // so they are called during normal lcd_update
      slow_buttons = lcd.readButtons() << B_I2C_BTN_OFFSET; 
      #ifdef LCD_I2C_VIKI
        if ((slow_buttons & (B_MI|B_RI)) && millis() < next_button_update_ms) // LCD clicked
          slow_buttons &= ~(B_MI|B_RI); // Disable LCD clicked buttons if screen is updated
      #endif
      return slow_buttons;
    #endif
  }

#endif // LCD_HAS_SLOW_BUTTONS

#endif //ULTRALCD_IMPLEMENTATION_RIGIDPANEL_H
