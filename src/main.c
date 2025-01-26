/**
 * @file main.c
 * @brief GTK4 Test 2
 * @date 01-26-2025
 * @par The third iteration of the GTK4 test project.
 * Goals:
 * - Restructure the project to separate the UI from the main code.
 * - Refactor the names to something other than My-this and my-that.
 * - Fork GUI code into separate process
 * - Interface between main and UI code
 */

#include "config.h"
#include "gui.h"

int main(int argc, char *argv[])
{
  int status = run_gui_application(argc, argv);
  return status;
}
