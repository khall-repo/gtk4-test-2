#include "imain-window.h"

IMainWindow imain_window;

// get imain_window.col_header_label0
const char *get_col_header_label0(void)
{
  return imain_window.col_header_label0;
}

// get imain_window.col_header_label1
const char *get_col_header_label1(void)
{
  return imain_window.col_header_label1;
}

// get imain_window.data_display_label0
const char *get_data_display_label0(void)
{
  return imain_window.data_display_label0;
}

// get imain_window.data_display_label1
const char *get_data_display_label1(void)
{
  return imain_window.data_display_label1;
}

// set imain_window.data_display_label0
void set_data_display_label0(const char *text)
{
  imain_window.data_display_label0 = text;
}

// set imain_window.data_display_label1
void set_data_display_label1(const char *text)
{
  imain_window.data_display_label1 = text;
}
