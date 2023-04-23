#ifndef _VIDEO_H
#define _VIDEO_H

#include <stdbool.h>

int get_cursor_pos();
void printtext(char*,char,char,bool);
void printchar(char,char,char);
void scroll();
void rm_char_in_pos(int);
#endif  
