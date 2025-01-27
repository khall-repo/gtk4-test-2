/**
 * @file main.c
 * @brief GTK4 Test 2
 * @date 01-26-2025
 * @par The second iteration of the GTK4 test project.
 * Goals:
 * - Restructure the project to separate the UI from the main code.
 *    done
 * - Refactor the names to something other than My-this and my-that.
 *    done
 * - Add timebase functionality to the main code. This doesn't really have
 *   anything to do with the UI, but for me it would be desireable to have
 *   the ability to call some functions behind the UI at a regular interval.
 *    done
 * - Update GtkLabel text from the main code.
 *    done through the imain-window interface.
 * - Interface between main and UI code
 *    Almost there.. problem with interface/ui setting text after window
 *    has closed. Need to detect window close and stop trying to update
 *    the UI in the GtkApplication idle loop function I added.
 */
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <time.h>
#include "config.h"
#include "imain-window.h"
#include "main-window.h"

timer_t timebase_timerid;

// Signal handler for the timebase timer
void timebase_handler(int signum, siginfo_t *info, void *context)
{
  static int count = 0;
  printf("Timer expired %d times\n", ++count);

  // try to print a data label from the main window.
  // 5 seconds ensures window won't be "null" when we try to use it.
  if (5 == count) { // try to set the data label
    set_data_display_label0("Farts");
    printf("\tData label 0 was set\n");
  }
  else if (6 == count) { // try to print the data label again
    printf("\tNew Data label 0: %s\n", get_data_display_label0());
  }
  else if (30 == count) { // Stop timer after 10 expirations to test timer_delete
    if (timer_delete(timebase_timerid) == -1) {
      perror("timer_delete");
      exit(EXIT_FAILURE);
    }
  }
}

// Start the timebase timer, 1 hz
int timebase_start(void)
{
  struct sigaction sa;
  struct sigevent sev;
  struct itimerspec its;

  // Install timebase_handler as the signal handler for SIGALRM
  sa.sa_flags = SA_SIGINFO;
  sa.sa_sigaction = timebase_handler;
  sigemptyset(&sa.sa_mask);
  if (sigaction(SIGALRM, &sa, NULL) == -1) {
    perror("sigaction");
    return -1;
  }

  // Create the timer
  sev.sigev_notify = SIGEV_SIGNAL;
  sev.sigev_signo = SIGALRM;
  sev.sigev_value.sival_ptr = &timebase_timerid;
  if (timer_create(CLOCK_REALTIME, &sev, &timebase_timerid) == -1) {
    perror("timer_create");
    return -1;
  }

  // Start the timer
  its.it_value.tv_sec = 1;
  its.it_value.tv_nsec = 0;
  its.it_interval.tv_sec = 1;
  its.it_interval.tv_nsec = 0;
  if (timer_settime(timebase_timerid, 0, &its, NULL) == -1) {
    perror("timer_settime");
    return -1;
  }
  return 0;
}

int main(int argc, char *argv[])
{
  if(0 != timebase_start()) {
    return -1;
  }

  int status = run_gui_application(argc, argv);
  return status;
}
