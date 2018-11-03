#include <gtk/gtk.h>
#include "Functions.h"

void Desarrolladores (GtkWidget *widget, gpointer   data )
{
 GtkWidget *window, * desarrollado_por, *button;
 button = gtk_button_new();
 window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
 gtk_window_set_title (GTK_WINDOW (window), "Desarrolladores.");
 gtk_window_set_default_size(GTK_WINDOW(window), 300, 400);
 desarrollado_por = gtk_image_new_from_file ("Desarrollado_por.png");

 gtk_container_add ((GtkContainer *) button, desarrollado_por);
 gtk_container_add(GTK_CONTAINER(window), button );

 g_signal_connect_swapped (G_OBJECT (button), "clicked",
                           G_CALLBACK (gtk_widget_destroy),
                           G_OBJECT (window));

 gtk_widget_show_all (window);
 g_signal_connect (G_OBJECT (window), "destroy", G_CALLBACK (gtk_main_quit), NULL);
 gtk_main ();
}

void Ayuda (GtkWidget *widget, gpointer   data )
{
 GtkWidget *window, * Ayuda, * button;
 Ayuda = gtk_image_new_from_file ("Ayuda.png");
 button = gtk_button_new();
 window = gtk_window_new (GTK_WINDOW_TOPLEVEL);

 gtk_window_set_title (GTK_WINDOW (window), "Ayuda");
 gtk_window_set_default_size(GTK_WINDOW(window), 400, 500);

 gtk_container_add ((GtkContainer *) button, Ayuda);
 gtk_container_add(GTK_CONTAINER(window), button );

 g_signal_connect_swapped (G_OBJECT (button), "clicked",
                           G_CALLBACK (gtk_widget_destroy),
                           G_OBJECT (window));
 g_signal_connect (G_OBJECT (window), "destroy", G_CALLBACK (gtk_main_quit), NULL);
 gtk_widget_show_all (window);
 gtk_main ();
}

void Acerca ( GtkWidget *widget, gpointer   data )
{
  GtkWidget *window, * Fondo_Historia;
  GtkWidget * Contenedor_Botones;

  GtkWidget * B_Desarrolladores, * B_Ayuda;
  GtkWidget * IM_Desarrolladores, * IM_Ayuda;


  Contenedor_Botones = gtk_fixed_new();


  B_Desarrolladores = gtk_button_new();
  B_Ayuda = gtk_button_new();

  IM_Desarrolladores = gtk_image_new_from_file ("desarrolladores.png");
  IM_Ayuda = gtk_image_new_from_file ("ayuda.png");


  Fondo_Historia = gtk_image_new_from_file ("HistoriaF.png");
  window = gtk_window_new (GTK_WINDOW_TOPLEVEL);

  gtk_window_set_title((GtkWindow *) window, "Acerca de");
  gtk_window_set_default_size(GTK_WINDOW(window), 500, 600);

  gtk_fixed_put(GTK_FIXED(Contenedor_Botones), Fondo_Historia, 0,0);


  gtk_fixed_put(GTK_FIXED(Contenedor_Botones), B_Desarrolladores, 20,40);
  gtk_fixed_put(GTK_FIXED(Contenedor_Botones), B_Ayuda, 350,50);

  gtk_container_add ((GtkContainer *) B_Desarrolladores, IM_Desarrolladores);
  gtk_container_add ((GtkContainer *) B_Ayuda, IM_Ayuda);

  g_signal_connect (G_OBJECT (B_Desarrolladores), "clicked",
                    G_CALLBACK (Desarrolladores), NULL);

  g_signal_connect (G_OBJECT (B_Ayuda), "clicked",
                    G_CALLBACK (Ayuda), NULL);



  gtk_container_add(GTK_CONTAINER(window), Contenedor_Botones );
  gtk_widget_show_all (window);
  g_signal_connect (G_OBJECT (window), "destroy", G_CALLBACK (gtk_main_quit), NULL);
  gtk_main ();

}

void Juego( GtkWidget *widget, gpointer   data )
{

        GtkWidget *window, * Te_la_creiste;
        Te_la_creiste = gtk_image_new_from_file ("Te_la_creiste.jpg");
        window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
        gtk_container_add(GTK_CONTAINER(window), Te_la_creiste);
        gtk_widget_show_all (window);
        g_signal_connect (G_OBJECT (window), "destroy", G_CALLBACK (gtk_main_quit), NULL);
        gtk_main ();
}
