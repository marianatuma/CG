#include <gtk/gtk.h>
#include <cairo.h>
#include "displayFile.h"
#include "line.h"
#include <iostream>

/*
struct {
  int count;
  double coordx[100];
  double coordy[100];
} glob;
*/
DisplayFile *df;

static void do_drawing(cairo_t *cr)
{
  cairo_set_source_rgb(cr, 0, 0, 0);
  cairo_set_line_width(cr, 0.5);

  int size = df->getSize();

    Line* g = (Line*)df->getNextObject();
    point* start = g->getStart();

    double x = start->x;

    //point* end = g->getEnd();
    //cairo_move_to(cr, start->x, start->y);
    //cairo_line_to(cr, end->x, end->y);

    //cairo_stroke(cr);

    //free(s);
    //free(e);
  
/*
  int i, j;
  for (i = 0; i <= glob.count - 1; i++ ) {
      for (j = 0; j <= glob.count - 1; j++ ) {
      	std::cout << i << " " << j << "\n";
          cairo_move_to(cr, glob.coordx[i], glob.coordy[i]);
          cairo_line_to(cr, glob.coordx[j], glob.coordy[j]);
      }
  }

  cairo_stroke(cr);    
  */
}

static gboolean on_draw_event(GtkWidget *widget, cairo_t *cr, 
    gpointer user_data)
{
  do_drawing(cr);

  return FALSE;
}

static gboolean clicked(GtkWidget *widget, GdkEventButton *event,
    gpointer user_data)
{
    gtk_widget_queue_draw(widget);
    
    return TRUE;
}

int main(int argc, char **argv)
{
    GtkBuilder *builder;
    GtkWidget  *window, *viewport;
    GError     *error = NULL;
    df = new DisplayFile(); 

/*    
    glob.count = 0;

    glob.coordx[0] = 1;
    glob.coordy[0] = -2;
    glob.count++;

    glob.coordx[1] = 40;
    glob.coordy[1] = -40;
    glob.count++;

    glob.coordx[2] = 55;
    glob.coordy[2] = 77;
    glob.count++;

    glob.coordx[3] = 10;
    glob.coordy[3] = 70;
    glob.count++;
 */   
    Line* l = new Line(type::LINE, "line");
    l->setStart(2, 30);
    l->setEnd(2, -30);

    df->add(l);
    /* Init GTK+ */

    gtk_init( &argc, &argv );

    /* Create new GtkBuilder object */
    builder = gtk_builder_new();
    /* Load UI from file. If error occurs, report it and quit application.
     * Replace "tut.glade" with your saved project. */
    if( ! gtk_builder_add_from_file( builder, "interface.glade", &error ) )
    {
        g_warning( "%s", error->message );
        g_free( error );
        return 1;
    }

    /* Get main window pointer from UI */
    window = GTK_WIDGET( gtk_builder_get_object( builder, "mainWindow" ) );
    viewport = GTK_WIDGET(gtk_builder_get_object(builder, "viewport"));

    g_signal_connect(G_OBJECT(viewport), "draw", G_CALLBACK(on_draw_event), NULL); 

    /* Connect signals */
    gtk_builder_connect_signals( builder, NULL );
   
    /* Destroy builder, since we don't need it anymore */
    g_object_unref( G_OBJECT( builder ) );

    /* Show window. All other widgets are automatically shown by GtkBuilder */
    gtk_widget_show( window );


    /* Start main loop */
    gtk_main();

    return 0;
}