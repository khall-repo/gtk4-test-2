
#include <gtk/gtk.h>
#include "config.h"
#include "imain-window.h"
#include "main-window.h"

extern IMainWindow imain_window;

// This is the handle for the idle function that updates the main window 
static guint window_update_fn_source_id = 0;

typedef struct _MainWindow
{
  GtkApplicationWindow parent_instance;

  GtkWidget *col_header_label0;
  GtkWidget *col_header_label1;

  GtkWidget *data_display_label0;
  GtkWidget *data_display_label1;
  GtkWidget *data_display_label2;
  GtkWidget *data_display_label3;
  GtkWidget *data_display_label4;
  GtkWidget *data_display_label5;
  GtkWidget *data_display_label6;
  GtkWidget *data_display_label7;
  GtkWidget *data_display_label8;
  GtkWidget *data_display_label9;
  GtkWidget *data_display_label10;
  GtkWidget *data_display_label11;
  GtkWidget *data_display_label12;
  GtkWidget *data_display_label13;
  GtkWidget *data_display_label14;
  GtkWidget *data_display_label15;
  
  GtkWidget *button0; // bottom button

  GtkWidget *button1;
  GtkWidget *button2;
  GtkWidget *button3;
  GtkWidget *button4;
  GtkWidget *button5;
  GtkWidget *button6;
  GtkWidget *button7;
  GtkWidget *button8;

  GtkWidget *button9;
  GtkWidget *button10;
  GtkWidget *button11;
  GtkWidget *button12;
  GtkWidget *button13;
  GtkWidget *button14;
  GtkWidget *button15;
  GtkWidget *button16;

} MainWindow;

typedef struct _MainWindowClass
{
  GtkApplicationWindowClass parent_class;
} MainWindowClass;

// This macro will actually take the string "my_app_window" and converts it to
// "main_window_app_class_init" and "main_app_window_init", and stores those
// names internally. That is how GTK knows where to find the class and init
// functions in here! Terrible for the uninitiated.
// It seems to care that MainWindowClass struct is named after MainWindow
// struct.. with "Class" appended to the end.
G_DEFINE_TYPE(MainWindow, main_window, GTK_TYPE_APPLICATION_WINDOW)
// moved this down here to make it clearer that below line is related to the
// line above.
#define MAIN_WINDOW_TYPE (main_window_get_type())

#define MAIN_WINDOW(obj) (G_TYPE_CHECK_INSTANCE_CAST((obj), MAIN_WINDOW_TYPE, MainWindow))

static void main_window_class_init(MainWindowClass *class)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS(class);
  GError *error = NULL;
  char *contents;
  gsize length;

  // Load the template from the file. Alternatively, you can compile the UI and
  // store it as a GResource, but that's a bit more complicated. See the howto
  // file I included in this project's root directory called
  // compiled-ui-resources-howto.txt.
  if (g_file_get_contents(PATH_TO_MAIN_WIN_RESOURCE, &contents, &length, &error)) {
    GBytes *template_bytes = g_bytes_new_take(contents, length);
    gtk_widget_class_set_template(widget_class, template_bytes);
    g_bytes_unref(template_bytes);

    gtk_widget_class_bind_template_child(widget_class, MainWindow, col_header_label0);
    gtk_widget_class_bind_template_child(widget_class, MainWindow, col_header_label1);

    gtk_widget_class_bind_template_child(widget_class, MainWindow, data_display_label0);
    gtk_widget_class_bind_template_child(widget_class, MainWindow, data_display_label1);
    gtk_widget_class_bind_template_child(widget_class, MainWindow, data_display_label2);
    gtk_widget_class_bind_template_child(widget_class, MainWindow, data_display_label3);
    gtk_widget_class_bind_template_child(widget_class, MainWindow, data_display_label4);
    gtk_widget_class_bind_template_child(widget_class, MainWindow, data_display_label5);
    gtk_widget_class_bind_template_child(widget_class, MainWindow, data_display_label6);
    gtk_widget_class_bind_template_child(widget_class, MainWindow, data_display_label7);
    gtk_widget_class_bind_template_child(widget_class, MainWindow, data_display_label8);
    gtk_widget_class_bind_template_child(widget_class, MainWindow, data_display_label9);
    gtk_widget_class_bind_template_child(widget_class, MainWindow, data_display_label10);
    gtk_widget_class_bind_template_child(widget_class, MainWindow, data_display_label11);
    gtk_widget_class_bind_template_child(widget_class, MainWindow, data_display_label12);
    gtk_widget_class_bind_template_child(widget_class, MainWindow, data_display_label13);
    gtk_widget_class_bind_template_child(widget_class, MainWindow, data_display_label14);
    gtk_widget_class_bind_template_child(widget_class, MainWindow, data_display_label15);

    gtk_widget_class_bind_template_child(widget_class, MainWindow, button0);
  } else {
    g_error("Failed to load template: %s\n", error->message);
    g_error_free(error);
  }
}

static void main_window_init(MainWindow *self)
{
  gtk_widget_init_template(GTK_WIDGET(self));
}

static void main_window_destroy_cb(GtkWidget *widget, gpointer data)
{
  g_print("MainWindow has been closed.\n");
  // Remove the idle function from the main loop
  if (window_update_fn_source_id != 0) {
    g_source_remove(window_update_fn_source_id);
    window_update_fn_source_id = 0;
  }
}

// This is where you would update data display labels in the main window
// based on the data in the IMainWindow struct.
static gboolean update_main_window(MainWindow *self)
{
  // I could update the column headers and button text, but the window elements
  // intended to be static should be set in the .ui file, not here. No sense in
  // wasting resources to update things that never change on every frame.
  //gtk_label_set_text(GTK_LABEL(self->col_header_label0), imain_window.col_header_label0);
  //gtk_label_set_text(GTK_LABEL(self->col_header_label1), imain_window.col_header_label1);
  
  gtk_label_set_text(GTK_LABEL(self->data_display_label0), imain_window.data_display_label0);
  gtk_label_set_text(GTK_LABEL(self->data_display_label1), imain_window.data_display_label1);
  gtk_label_set_text(GTK_LABEL(self->data_display_label2), imain_window.data_display_label2);
  gtk_label_set_text(GTK_LABEL(self->data_display_label3), imain_window.data_display_label3);
  gtk_label_set_text(GTK_LABEL(self->data_display_label4), imain_window.data_display_label4);
  gtk_label_set_text(GTK_LABEL(self->data_display_label5), imain_window.data_display_label5);
  gtk_label_set_text(GTK_LABEL(self->data_display_label6), imain_window.data_display_label6);
  gtk_label_set_text(GTK_LABEL(self->data_display_label7), imain_window.data_display_label7);
  gtk_label_set_text(GTK_LABEL(self->data_display_label8), imain_window.data_display_label8);
  gtk_label_set_text(GTK_LABEL(self->data_display_label9), imain_window.data_display_label9);
  gtk_label_set_text(GTK_LABEL(self->data_display_label10), imain_window.data_display_label10);
  gtk_label_set_text(GTK_LABEL(self->data_display_label11), imain_window.data_display_label11);
  gtk_label_set_text(GTK_LABEL(self->data_display_label12), imain_window.data_display_label12);
  gtk_label_set_text(GTK_LABEL(self->data_display_label13), imain_window.data_display_label13);
  gtk_label_set_text(GTK_LABEL(self->data_display_label14), imain_window.data_display_label14);
  gtk_label_set_text(GTK_LABEL(self->data_display_label15), imain_window.data_display_label15);

  // Return TRUE to keep the idle function running
  return TRUE;
  // Or return FALSE to stop the idle function
  //return FALSE;
}

static void button0_clicked_cb(GtkButton *button, MainWindow *self)
{
  gtk_label_set_text(GTK_LABEL(self->data_display_label0), "Button0 was clicked!");
}

static void activate_cb(GtkApplication *app, gpointer user_data)
{
  MainWindow *window = g_object_new(main_window_get_type(), "application", app, NULL);

  // Store the MainWindow instance in the GtkApplicationWindow
  g_object_set_data(G_OBJECT(window), "main-window-instance", window);

  // Connect the button0 signal its the callback function
  g_signal_connect(window->button0, "clicked", G_CALLBACK(button0_clicked_cb), window);
  // Connect the destroy signal to detect when the window is closed
  g_signal_connect(window, "destroy", G_CALLBACK(main_window_destroy_cb), NULL);

  gtk_window_present(GTK_WINDOW(window));

  // Add idle function to the main loop
  window_update_fn_source_id = g_idle_add((GSourceFunc)update_main_window, window);
  // Alternatively, you could use g_timeout_add() to update the window at a
  // regular interval. The function would be called every 1000 milliseconds.
  //window_update_fn_source_id = g_timeout_add(1000, (GSourceFunc)update_main_window, window);
}

int run_gui_application(int argc, char *argv[])
{
  GtkApplication *main_app;
  int status;

  // Disable accessibility so we don't get a bunch of warnings about it.
  g_setenv("GTK_A11Y", "none", TRUE);

  // On the RPi OS, it complains that G_APPLICATION_FLAGS_NONE is deprecated,
  // and that we should use instead use G_APPLICATION_DEFAULT_FLAGS.
  // But on Linux mint AMD64, that doesn't even exist.
  main_app = gtk_application_new("com.example.myapp", G_APPLICATION_FLAGS_NONE);
  g_signal_connect(main_app, "activate", G_CALLBACK(activate_cb), NULL);
  status = g_application_run(G_APPLICATION(main_app), argc, argv);

  g_object_unref(main_app);
  return status;
}


// Here is some scrap code.. It works so I'm leaving it here for my own
// reference.
/*MainWindow *_get_main_window_instance(void)
{
  GtkApplicationWindow *window = GTK_APPLICATION_WINDOW(gtk_application_get_active_window(main_app));
  return MAIN_WINDOW(g_object_get_data(G_OBJECT(window), "main-window-instance"));
}

// Function to retrieve the text from data_display_label0
const char *_get_data_display_label0_text(MainWindow *window)
{
  return gtk_label_get_text(GTK_LABEL(window->data_display_label0));
}

// Example usage of get_data_display_label0_text
const char *get_data_display_label0_text(void)
{
  MainWindow *window = _get_main_window_instance();
  if (window) {
    const char *text = _get_data_display_label0_text(window);
    return text;
  } else {
    g_print("Failed to retrieve MainWindow instance\n");
  }
  return "\0";
}

int set_data_display_label0_text(const char *text)
{
  MainWindow *window = _get_main_window_instance();
  if (window) {
    gtk_label_set_text(GTK_LABEL(window->data_display_label0), text);
    return 0;
  } else {
    g_print("Failed to retrieve MainWindow instance\n");
  }
  return -1;
}

// Function to retrieve the text from a GtkLabel
const char *_get_main_window_gtklabel_text(GtkWidget *label)
{
  return gtk_label_get_text(GTK_LABEL(label));
}
*/