#ifndef RIGIDPANEL_H
#define RIGIDPANEL_H

#include "Marlin.h"

#ifdef RIGIDPANEL
  int lcd_strlen(char *s);
  int lcd_strlen_P(const char *s);
  void lcd_update();
  void lcd_init();
  bool lcd_hasstatus();
  void lcd_setstatus(const char* message, const bool persist=false);
  void lcd_setstatuspgm(const char* message, const uint8_t level=0);
  void lcd_setalertstatuspgm(const char* message);
  void lcd_reset_alert_level();
  bool lcd_detected(void);

  #if defined(LCD_PROGRESS_BAR) && PROGRESS_MSG_EXPIRE > 0
    void dontExpireStatus();
  #endif
  static unsigned char blink = 0;	// Variable for visualisation of fan rotation in GLCD

  #define HIDE_BACK_MENUS			//	Uncomment to hide back menus (left button will still trigger them)

  #define LCD_MESSAGEPGM(x) lcd_setstatuspgm(PSTR(x))
  #define LCD_ALERTMESSAGEPGM(x) lcd_setalertstatuspgm(PSTR(x))

  #define LCD_UPDATE_INTERVAL 100
  #define LCD_STATUS_UPDATE_INTERVAL 1000
  #define LCD_TIMEOUT_TO_STATUS 15000
  #define FILE_SCROLL_START_DELAY	1000
  #define FILE_SCROLL_DELAY		400

  void lcd_buttons_update();
  extern volatile uint8_t buttons;  //the last checked buttons in a bit array.

  extern int plaPreheatHotendTemp;
  extern int plaPreheatHPBTemp;
  extern int plaPreheatFanSpeed;
  extern int absPreheatHotendTemp;
  extern int absPreheatHPBTemp;
  extern int absPreheatFanSpeed;

  extern bool cancel_heatup;
  
  #ifdef FILAMENT_LCD_DISPLAY
    extern millis_t previous_lcd_status_ms;
  #endif

  void lcd_buzz(long duration,uint16_t freq);
  //void lcd_quick_feedback(); // Audible feedback for a button click - could also be visual
  bool lcd_clicked();

  void lcd_ignore_click(bool b=true);

#else  //RIGIDPANEL
 //no LCD
  FORCE_INLINE void lcd_update() {}
  FORCE_INLINE void lcd_init() {}
  FORCE_INLINE bool lcd_hasstatus() { return false; }
  FORCE_INLINE void lcd_setstatus(const char* message, const bool persist=false) {}
  FORCE_INLINE void lcd_setstatuspgm(const char* message, const uint8_t level=0) {}
  FORCE_INLINE void lcd_buttons_update() {}
  FORCE_INLINE void lcd_reset_alert_level() {}
  FORCE_INLINE void lcd_buzz(long duration, uint16_t freq) {}
  FORCE_INLINE bool lcd_detected(void) { return true; }

  #define LCD_MESSAGEPGM(x) do{}while(0)
  #define LCD_ALERTMESSAGEPGM(x) do{}while(0)

#endif //RIGIDPANEL

char *itostr2(const uint8_t &x);
char *itostr31(const int &xx);
char *itostr3(const int &xx);
char *itostr3left(const int &xx);
char *itostr4(const int &xx);

char *ftostr3(const float &x);
char *ftostr31ns(const float &x); // float to string without sign character
char *ftostr31(const float &x);
char *ftostr32(const float &x);
char *ftostr43(const float &x);
char *ftostr12ns(const float &x); 
char *ftostr32sp(const float &x); // remove zero-padding from ftostr32
char *ftostr5(const float &x);
char *ftostr51(const float &x);
char *ftostr52(const float &x);

#endif //RIGIDPANEL_H
