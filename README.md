# gtk4-test-2
Learning how to write a GUI program using GTK4 - First GUI from scratch,
iteration #2

Goals for this iteration:
- Restructure the project to separate the UI from the main code.

  done

- Refactor the names to something other than My-this and my-that.

  done

- Add timebase functionality to the main code. This doesn't really have
anything to do with the UI, but for me it would be desireable to have
the ability to call some functions behind the UI at a regular interval.

  done

 - Update GtkLabel text from the main code.

  done through the imain-window interface.

 - Interface between main and UI code

   Almost there.. problem with interface/ui setting text after window
   has closed. Need to detect window close and stop trying to update
   the UI in the GtkApplication idle loop function I added.