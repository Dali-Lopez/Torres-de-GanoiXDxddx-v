#include <gtk/gtk.h>

/* Para agilizar el trabajo, se usarán algunas variables globales para
 * guardar la posición del widget dentro del contenedor fixed */
gint x = 50;
gint y = 50;

/* Esta función mueve el botón a una nueva posición
 * del contenedor Fixed. */
void move_button( GtkWidget *widget,
                  GtkWidget *fixed )
{
  x = (x + 30) % 300;
  y = (y + 50) % 300;
  gtk_fixed_move (GTK_FIXED (fixed), widget, x, y);
}

int main( int   argc,
          char *argv[] )
{
  /* GtkWidget es el tipo utilizado para widgets */
  GtkWidget *window;
  GtkWidget *fixed;
  GtkWidget *button;
  gint i;

  /* Inicializa GTK */
  gtk_init (&argc, &argv);

  /* Crea una ventana */
  window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title (GTK_WINDOW (window), "Fixed Container");

  /* Conecta el evento "destroy" a un manejador de señales */
  g_signal_connect (G_OBJECT (window), "destroy",
                    G_CALLBACK (gtk_main_quit), NULL);

  /* Establece la anchura del borde de la ventana. */
  gtk_container_set_border_width (GTK_CONTAINER (window), 10);

  /* Crea un Contenedor Fixed */
  fixed = gtk_fixed_new ();
  gtk_container_add (GTK_CONTAINER (window), fixed);
  gtk_widget_show (fixed);

  for (i = 1 ; i <= 3 ; i++) {
    /* Crea un botón con la etiqueta "Press me" */
    button = gtk_button_new_with_label ("Press me");

    /* Cuando el botón recive la señal "clicked", se llama a la función
     * move_button() pasando el Contenedor Fixed como argumento */
    g_signal_connect (G_OBJECT (button), "clicked",
                      G_CALLBACK (move_button), (gpointer) fixed);

    /* Coloca el botón dentro de la ventana de los contenedores fixed. */
    gtk_fixed_put (GTK_FIXED (fixed), button, i*50, i*50);

    /* El último paso es mostrar el nuevo widget que se ha creado. */
    gtk_widget_show (button);
  }

  /* Muestra la ventana */
  gtk_widget_show (window);

  /* Entra en el bucle de eventos */
  gtk_main ();

  return 0;
}
