#ifndef IMAIN_WINDOW_H
#define IMAIN_WINDOW_H

#include <stdbool.h>

typedef struct _INainWindow
{
  const char *col_header_label0;
  const char *col_header_label1;

  const char *data_display_label0;
  const char *data_display_label1;
  const char *data_display_label2;
  const char *data_display_label3;
  const char *data_display_label4;
  const char *data_display_label5;
  const char *data_display_label6;
  const char *data_display_label7;
  const char *data_display_label8;
  const char *data_display_label9;
  const char *data_display_label10;
  const char *data_display_label11;
  const char *data_display_label12;
  const char *data_display_label13;
  const char *data_display_label14;
  const char *data_display_label15;
  
  bool button0; // bottom button

  bool button1; // first column of buttons
  bool button2;
  bool button3;
  bool button4;
  bool button5;
  bool button6;
  bool button7;
  bool button8;

  bool button9; // second column of buttons
  bool button10;
  bool button11;
  bool button12;
  bool button13;
  bool button14;
  bool button15;
  bool button16;

} IMainWindow;

const char *get_col_header_label0(void);
const char *get_col_header_label1(void);
const char *get_data_display_label0(void);
const char *get_data_display_label1(void);
const char *get_data_display_label2(void);
const char *get_data_display_label3(void);
const char *get_data_display_label4(void);
const char *get_data_display_label5(void);
const char *get_data_display_label6(void);
const char *get_data_display_label7(void);
const char *get_data_display_label8(void);
const char *get_data_display_label9(void);
const char *get_data_display_label10(void);
const char *get_data_display_label11(void);
const char *get_data_display_label12(void);
const char *get_data_display_label13(void);
const char *get_data_display_label14(void);
const char *get_data_display_label15(void);

void set_data_display_label0(const char *text);
void set_data_display_label1(const char *text);
void set_data_display_label2(const char *text);
void set_data_display_label3(const char *text);
void set_data_display_label4(const char *text);
void set_data_display_label5(const char *text);
void set_data_display_label6(const char *text);
void set_data_display_label7(const char *text);
void set_data_display_label8(const char *text);
void set_data_display_label9(const char *text);
void set_data_display_label10(const char *text);
void set_data_display_label11(const char *text);
void set_data_display_label12(const char *text);
void set_data_display_label13(const char *text);
void set_data_display_label14(const char *text);
void set_data_display_label15(const char *text);

#endif