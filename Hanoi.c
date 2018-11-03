#include <gtk/gtk.h>
#include "Functions.h"

int main(int argc, char *argv[])
{

    GtkWidget * window;
    GtkWidget * Fondo;
    GtkWidget * contenedor;

    GtkWidget * B_button_Juego;
    GtkWidget * B_button_Acerca_de;
    GtkWidget * B_button_Solucion;
    GtkWidget * Juego_imagen, * Acerca_de, * Solucion;

     gtk_init(&argc, &argv);
     window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
     contenedor = gtk_fixed_new();

     B_button_Juego = gtk_button_new();
     B_button_Acerca_de = gtk_button_new();
     B_button_Solucion = gtk_button_new();

     Fondo = gtk_image_new_from_file ("FondoFinal.png");
     Juego_imagen = gtk_image_new_from_file ("Juego.png");
     Acerca_de = gtk_image_new_from_file ("Acerca_de.png");
     Solucion = gtk_image_new_from_file ("Solucion.png");

     gtk_window_set_title((GtkWindow *) window, "Torres de Hanoi");
     gtk_window_set_default_size(GTK_WINDOW(window), 1000, 800);

     gtk_fixed_put(GTK_FIXED(contenedor), Fondo, 0,0);
     gtk_fixed_put(GTK_FIXED(contenedor), B_button_Juego, 380, 355);
     gtk_fixed_put(GTK_FIXED(contenedor), B_button_Acerca_de, 135, 500);
     gtk_fixed_put(GTK_FIXED(contenedor), B_button_Solucion, 635,500);

     gtk_container_add ((GtkContainer *) B_button_Juego, Juego_imagen);
     gtk_container_add ((GtkContainer *) B_button_Acerca_de, Acerca_de);
     gtk_container_add ((GtkContainer *) B_button_Solucion, Solucion);


     g_signal_connect (G_OBJECT (B_button_Juego), "clicked", G_CALLBACK (Juego), NULL);
     g_signal_connect (G_OBJECT (B_button_Acerca_de), "clicked", G_CALLBACK (Acerca), NULL);

     gtk_container_add(GTK_CONTAINER(window), contenedor );

     gtk_widget_show_all (window);
     g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);
     gtk_main();
    return 0;
}
