#pragma once
//---------------------
#include "standard_includes.h"


void print_in_color(string s, int color_number);
void print_in_color(string s, string back_color_name, string text_color_name);
int color_picker(string back, string text);
void print_line_in_color(unsigned int space_count, string color_name);
void go_fullscreen();
void cls();
void pause();
void disable_ctrl_c();
void enable_ctrl_c();

void print_vasat(string s, string back, string text, int columns);
int console_columns_count();

void delay(unsigned int mss);

void leaving_in(unsigned int seconds, string back_color, string text_color);

