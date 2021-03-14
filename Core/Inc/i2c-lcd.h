#include "stm32f1xx_hal.h"

void lcd_init (void);   // initialize lcd

void lcd_send_cmd (char cmd);  // send command to the lcd

void lcd_send_data (char data);  // send data to the lcd

void lcd_send_string (char *str);  // send string to the lcd

void lcd_put_cur(int row, int col);  // put cursor at the entered position row (0 or 1), col (0-15);

void lcd_clear (void);

//for second LCD display

void lcd2_init (void);   // initialize lcd2

void lcd2_send_cmd (char cmd);  // send command to the lcd2

void lcd2_send_data (char data);  // send data to the lcd2

void lcd2_send_string (char *str);  // send string to the lcd2

void lcd2_put_cur(int row, int col);  // put cursor at the entered position row (0 or 1), col (0-15);

void lcd2_clear (void);
