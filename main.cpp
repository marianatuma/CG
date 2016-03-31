#include <gtk/gtk.h>
#include <cairo.h>
#include "displayFile.h"
#include "line.h"
#include <iostream>

DisplayFile *df;
double vOffset, hOffset;
double zoom;
double STEP = 10.0;
double VPMAX_X = 80.0;
double VPMAX_Y = 80.0;
double WMAX_X = 80.0;
double WMAX_Y = 80.0;


double transformY(double y) {
  double yvp = (1-(y/WMAX_Y))*VPMAX_Y;
  return yvp;
}

double transformX(double x) {
  double xvp = (x/(WMAX_X))*VPMAX_X;
  return xvp;
}

void drawLine(cairo_t *cr, GraphObj* g) {
  Line* l = static_cast<Line*>(g);
  cairo_move_to(cr, transformX(l->getStart()->x), transformY(l->getStart()->y));
  cairo_line_to(cr, transformX(l->getEnd()->x), transformY(l->getEnd()->y));
  cairo_stroke(cr);
}

static void do_drawing(cairo_t *cr)
{
  cairo_set_source_rgb(cr, 0, 0, 0);
  cairo_set_line_width(cr, 0.5);

  std::list<GraphObj*>* objectList= df->getObjects();
    
  for (std::list<GraphObj*>::const_iterator it = objectList->begin();
    it != objectList->end();
    ++it) {
    GraphObj* g = *it;
    if(type::LINE == g->getType()) {
      drawLine(cr, g);
    }
  }
}


static gboolean on_draw_event(GtkWidget *widget, cairo_t *cr, 
    gpointer user_data)
{
  do_drawing(cr);

  return FALSE;
}

/*
static gboolean clicked(GtkWidget *widget, GdkEventButton *event,
    gpointer user_data)
{
    gtk_widget_queue_draw(widget);
    
    return TRUE;
}
*/

static gboolean moveUp(GtkWidget *widget, GdkEventButton *event,
    gpointer user_data)
{
    vOffset += STEP;    
    return TRUE;
}

static gboolean moveDown(GtkWidget *widget, GdkEventButton *event,
    gpointer user_data)
{
    vOffset -= STEP;    
    return TRUE;
}

static gboolean moveRight(GtkWidget *widget, GdkEventButton *event,
    gpointer user_data)
{
    hOffset += STEP;    
    return TRUE;
}

static gboolean moveLeft(GtkWidget *widget, GdkEventButton *event,
    gpointer user_data)
{
    hOffset -= STEP;    
    return TRUE;
}


int main(int argc, char **argv)
{
    GtkBuilder *builder;
    GtkWidget  *window, *viewport, *buttonUp,
     *buttonDown, *buttonLeft, *buttonRight, *zoomIn, *zoomOut;
    GtkDrawingArea *drawingArea;
    GError     *error = NULL;
    
    df = new DisplayFile(); 
    vOffset = 0.0;
    hOffset = 0.0;
    zoom = 0.0;

    Line* l = new Line(type::LINE, "line");
    l->setStart(0, 0);
    l->setEnd(800, 800);

    df->add(l);

    l = new Line(type::LINE, "line");
    l->setStart(8, 60);
    l->setEnd(8, 110);

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
    drawingArea = GTK_DRAWING_AREA(gtk_builder_get_object(builder, "drawingarea"));
    buttonUp = GTK_WIDGET(gtk_builder_get_object(builder, "buttonUp"));
    buttonLeft = GTK_WIDGET(gtk_builder_get_object(builder, "buttonLeft"));
    buttonRight = GTK_WIDGET(gtk_builder_get_object(builder, "buttonRight"));
    buttonDown = GTK_WIDGET(gtk_builder_get_object(builder, "buttonDown"));

    g_signal_connect(G_OBJECT(drawingArea), "draw", G_CALLBACK(on_draw_event), NULL); 
    g_signal_connect(G_OBJECT(buttonUp), "clicked", G_CALLBACK(moveUp), NULL);
    g_signal_connect(G_OBJECT(buttonDown), "clicked", G_CALLBACK(moveDown), NULL);
    g_signal_connect(G_OBJECT(buttonLeft), "clicked", G_CALLBACK(moveLeft), NULL);
    g_signal_connect(G_OBJECT(buttonRight), "clicked", G_CALLBACK(moveRight), NULL);

    /* Connect signals */
    gtk_builder_connect_signals( builder, NULL );
   
    /* Destroy builder, since we don't need it anymore */
    g_object_unref( G_OBJECT( builder ) );

    /* Show window. All other widgets are automatically shown by GtkBuilder */
    gtk_widget_show_all( window );

    /* Start main loop */
    gtk_main();

    return 0;
}