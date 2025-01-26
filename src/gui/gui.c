#include <gtk/gtk.h>
#include "config.h"
#include "gui.h"

typedef struct _NainWindow
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
#define MY_APP_WINDOW_TYPE (main_window_get_type())

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

static void button0_clicked_cb(GtkButton *button, MainWindow *self)
{
  gtk_label_set_text(GTK_LABEL(self->data_display_label0), "Button0 was clicked!");
}

static void activate_cb(GtkApplication *app, gpointer user_data)
{
  MainWindow *window = g_object_new(main_window_get_type(), "application", app, NULL);

  // Connect the button0 signal its the callback function
  g_signal_connect(window->button0, "clicked", G_CALLBACK(button0_clicked_cb), window);
  gtk_window_present(GTK_WINDOW(window));
}

int run_gui_application(int argc, char *argv[])
{
  GtkApplication *app;
  int status;

  // Disable accessibility
  g_setenv("GTK_A11Y", "none", TRUE);

  // So this is weird.. on the RPi OS, it complains that
  // G_APPLICATION_FLAGS_NONE is deprecated, and that we should use
  // G_APPLICATION_DEFAULT_FLAGS. But on Linux mint AMD64, that doesn't even
  // exist.
  app = gtk_application_new("com.example.myapp", G_APPLICATION_FLAGS_NONE);
  g_signal_connect(app, "activate", G_CALLBACK(activate_cb), NULL);
  status = g_application_run(G_APPLICATION(app), argc, argv);
  g_object_unref(app);

  return status;
}