void LCD_Init (void);
void LCD_CMD(unsigned char cmnd);
void LCD_TEXT (unsigned char char_data);
void LCD_STR (char *str);
void LCD_CLR();
char*Convert(int num, char* str, int base);
void reverse(char str[], int length);