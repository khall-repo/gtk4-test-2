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
sort of done? Well.. it does work, but I wonder if there's a better way.
Perhaps I should try to find a way to get/set the label text with the
GtkWidget references in the MainWindow struct.
- Interface between main and UI code
    Todo. Currently just talking to the UI code directly.