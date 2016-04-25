#include <gtk/gtk.h>
#include <cairo.h>
#include <math.h>
#include <string>
#include "viewport.h"
#include "window.h"
#include "displayFile.h"
#include "polygon.h"
#include "point.h"
#include "cohenSutherland.h"
#include <iostream>

DisplayFile *displayFile;
GtkBuilder  *mainBuilder;
GtkWidget   *mainWindow, *smallerChoice;
GtkEntry    *xStartInput, *yStartInput, *xEndInput, *yEndInput,
            *newPolyX, *newPolyY, *newPolyName, *newLineName,
            *newPointX, *newPointY, *newPointName, *translateX,
            *translateY, *scaleFactor, *rotationAngle, 
            *rotationCenterX, *rotationCenterY;
GraphObj    *selectedObj;
Viewport    *viewportData;
Window      *windowData;
Polygon     *newPoly;
CohenSutherland *cs;

point origin;

enum {
  COL_X = 0, COL_Y, NUM_COLS
};

enum {
  COL_NAME = 0, COL_POINTER, NUM_COLS_NAME
};

double STEP = 10.0;
double ZOOM = 1.05;
double lineThickness = 0.05;
double pointThickness = 0.1;
double thicknessIncrement = 10.0;

double transformY(double y) {
  double yvp = (1-((y - windowData->getYMin()) / (windowData->getYMax() - windowData->getYMin())))*viewportData->getYMax();
  return yvp;
}

double transformX(double x) {
  double xvp = ((x - windowData->getXMin()) / (windowData->getXMax() - windowData->getXMin()))*viewportData->getXMax();
  return xvp;
}

void connectTwoPoints(cairo_t *cr, point *start, point *end) {
  cairo_move_to(cr, transformX(start->x), transformY(start->y));
  cairo_line_to(cr, transformX(end->x), transformY(end->y));
  cairo_stroke(cr);
}

void drawCircle(cairo_t *cr, point *center, double radius) {
  cairo_arc(cr, transformX(center->x), transformY(center->y), radius, 0, 2 * M_PI);
  cairo_stroke_preserve(cr);
}

void drawPoint(cairo_t *cr, GraphObj* g) {
  Point* p = static_cast<Point*>(g);
  drawCircle(cr, p->getPoint(), pointThickness*thicknessIncrement);
  cairo_fill(cr); 
}

void drawPolygon(cairo_t *cr, GraphObj* g) {
  Polygon* p = static_cast<Polygon*>(g);
  cs->clip(p);
  std::list<point>* points = p->getClippedPoints();
  point first = points->front();
  point tempStart, tempEnd;

  for (std::list<point>::const_iterator it = points->begin();
    it != points->end();
    ++it) {
      tempStart = tempEnd;
      tempEnd = *it; 
      if(it != points->begin()){
        connectTwoPoints(cr, &tempStart, &tempEnd);
      }
  }
  //fecha o poligono
  connectTwoPoints(cr, &tempEnd, &first);
}
void clearList() {
  GtkListStore *listStoreObjects = GTK_LIST_STORE(
      gtk_builder_get_object( mainBuilder, "listStoreObjects"));
  gtk_list_store_clear(listStoreObjects);
}

void addObjectToList(const char* name){
  GtkListStore *listStoreObjects = GTK_LIST_STORE(
      gtk_builder_get_object( mainBuilder, "listStoreObjects"));
  GtkTreeIter iter;
  gtk_list_store_append(listStoreObjects, &iter);
  gtk_list_store_set(listStoreObjects, &iter, 0, name, -1);  
}

static void do_drawing(cairo_t *cr)
{
  cairo_set_source_rgb(cr, 0, 0, 0);
  cairo_set_line_width(cr, lineThickness*thicknessIncrement);

  GtkTreeIter iter_objects;
  GraphObj *g;
  type t;
  
  clearList();

  std::list<GraphObj*>* objectList= displayFile->getObjects();
    
  for (std::list<GraphObj*>::const_iterator it = objectList->begin();
    it != objectList->end();
    ++it) {
    g = *it;
    t = g->getType();

    addObjectToList(g->getName().c_str());

    switch(t) {
      case type::POLYGON:
        drawPolygon(cr, g);
        break;
      case type::POINT:
        drawPoint(cr, g);
        break;
    }
  }
}


static gboolean on_draw_event(GtkWidget *widget, cairo_t *cr, 
    gpointer user_data)
{
  do_drawing(cr);

  return FALSE;
}

static gboolean moveUp(GtkWidget *widget, GdkEventButton *event,
    gpointer user_data)
{
    windowData->moveY(STEP);
    gtk_widget_queue_draw((GtkWidget*) user_data);
    return TRUE;
}

static gboolean moveDown(GtkWidget *widget, GdkEventButton *event,
    gpointer user_data)
{
    windowData->moveY(-STEP);
    gtk_widget_queue_draw((GtkWidget*) user_data);
    return TRUE;
}

static gboolean moveRight(GtkWidget *widget, GdkEventButton *event,
    gpointer user_data)
{
    windowData->moveX(STEP);    
    gtk_widget_queue_draw((GtkWidget*) user_data);
    return TRUE;
}

static gboolean moveLeft(GtkWidget *widget, GdkEventButton *event,
    gpointer user_data)
{
    windowData->moveX(-STEP);    
    gtk_widget_queue_draw((GtkWidget*) user_data);
    return TRUE;
}

static gboolean zoomIn(GtkWidget *widget, GdkEventButton *event,
    gpointer user_data)
{
    thicknessIncrement += 1.0;
    windowData->zoomIn(ZOOM);    
    gtk_widget_queue_draw((GtkWidget*) user_data);
    return TRUE;
}

static gboolean zoomOut(GtkWidget *widget, GdkEventButton *event,
    gpointer user_data)
{
    if(thicknessIncrement > 5.0)
      thicknessIncrement -= 1.0;
    windowData->zoomOut(ZOOM);    
    gtk_widget_queue_draw((GtkWidget*) user_data);
    return TRUE;
}


static GraphObj* getSelected() {
  GtkTreeSelection *selection = gtk_tree_view_get_selection(
      GTK_TREE_VIEW(gtk_builder_get_object( mainBuilder, "objTree")));
  GtkTreeModel *model;
  GtkTreeIter iter;
  
  if(gtk_tree_selection_get_selected(selection, &model, &iter)) {
    
    gchar *name;        
    gtk_tree_model_get(model, &iter, COL_NAME, &name, -1);
    
    if(displayFile->getByName((std::string)name) != NULL){
      GraphObj *selectedObj;
      selectedObj = displayFile->getByName((std::string)name);
      g_free(name);
      return selectedObj;

    } else {
      
      GtkDialogFlags flags = GTK_DIALOG_DESTROY_WITH_PARENT;
      GtkWidget *dialog = gtk_message_dialog_new(
          GTK_WINDOW(gtk_builder_get_object( mainBuilder, "mainWindow" )),
          flags, GTK_MESSAGE_ERROR, GTK_BUTTONS_CLOSE, "Select an object");
      gtk_dialog_run(GTK_DIALOG(dialog));
      gtk_widget_destroy(dialog);
    }
  }
  return selectedObj;
}

static gboolean translate(GtkWidget *widget, GdkEventButton *event,
    gpointer user_data)
{
    point pivot;
    pivot.x = atof(gtk_entry_get_text(GTK_ENTRY(translateX)));
    pivot.y = atof(gtk_entry_get_text(GTK_ENTRY(translateY)));

    point center = selectedObj->getCenter();
    point vector = Utils::translationVector(center, pivot);

    std::list<point>* points = selectedObj->getPoints();
    std::list<point>* translated = new std::list<point>();
    point translatedPoint;

    for (std::list<point>::const_iterator it = points->begin();
    it != points->end();
    ++it) {
      translatedPoint = Utils::translatePoint(*it, vector);
      translated->push_back(translatedPoint);
    } 

    selectedObj->setPoints(translated);

    gtk_widget_destroy((GtkWidget*) user_data);
    return TRUE;
}

static gboolean translateWindow(GtkWidget *widget, GdkEventButton *event,
    gpointer user_data) {
  
  selectedObj = getSelected();

  GtkBuilder *builder;
  GError *error = NULL;
  
  builder = gtk_builder_new();

  if (!gtk_builder_add_from_file(builder, "translate.glade", &error)) {
    g_warning("%s", error->message);
    g_free(error);
  }

  GtkWidget *translateWindow = GTK_WIDGET( gtk_builder_get_object( builder, "translateWindow" ) );
  translateX = (GtkEntry*) GTK_WIDGET(gtk_builder_get_object(builder, "translateX"));
  translateY = (GtkEntry*) GTK_WIDGET(gtk_builder_get_object(builder, "translateY"));
  
  GtkWidget* okButton = GTK_WIDGET(gtk_builder_get_object(builder, "okButton"));

  g_signal_connect(G_OBJECT(okButton), "clicked", G_CALLBACK(translate), translateWindow);
  
  gtk_builder_connect_signals(builder, NULL);
  g_object_unref(G_OBJECT(builder));
  gtk_widget_show_all(translateWindow);
  gtk_main();

  return TRUE;
}

static gboolean scale(GtkWidget *widget, GdkEventButton *event,
    gpointer user_data)
{
  double factor = atof(gtk_entry_get_text(GTK_ENTRY(scaleFactor)));

  if(gtk_toggle_button_get_active( GTK_TOGGLE_BUTTON(smallerChoice))){
    std::cout << "smaller" << "\n";
    factor = 1/factor;
  }

  point center = selectedObj->getCenter();
  point vectorToOrigin = Utils::translationVector(center, origin);
  point vectorToCenter = Utils::translationVector(origin, center);

  std::list<point>* points = selectedObj->getPoints();
  std::list<point>* scaled = new std::list<point>();
  point scaledPoint;

  for (std::list<point>::const_iterator it = points->begin();
  it != points->end();
  ++it) {
    scaledPoint = Utils::scalePoint(*it, factor, vectorToOrigin, vectorToCenter);
    scaled->push_back(scaledPoint);
  } 

  selectedObj->setPoints(scaled);
  gtk_widget_destroy((GtkWidget*) user_data);
  return TRUE;
}

static gboolean scaleWindow(GtkWidget *widget, GdkEventButton *event,
    gpointer user_data) {
  selectedObj = getSelected();

  GtkBuilder *builder;
  GError *error = NULL;
  
  builder = gtk_builder_new();

  if (!gtk_builder_add_from_file(builder, "scale.glade", &error)) {
    g_warning("%s", error->message);
    g_free(error);
  }

  GtkWidget *scaleWindow;

  scaleWindow = GTK_WIDGET( gtk_builder_get_object( builder, "scaleWindow" ) );
  scaleFactor = (GtkEntry*) GTK_WIDGET(gtk_builder_get_object(builder, "scaleFactor"));
  smallerChoice = GTK_WIDGET( gtk_builder_get_object( builder, "smaller" ));
  
  GtkWidget* okButton = GTK_WIDGET(gtk_builder_get_object(builder, "okButton"));

  g_signal_connect(G_OBJECT(okButton), "clicked", G_CALLBACK(scale), scaleWindow);
  
  gtk_builder_connect_signals(builder, NULL);
  g_object_unref(G_OBJECT(builder));
  gtk_widget_show_all(scaleWindow);
  gtk_main();

  return TRUE;
}

static gboolean rotate(GtkWidget *widget, GdkEventButton *event,
    gpointer user_data)
{
  double angle = atof(gtk_entry_get_text(GTK_ENTRY(rotationAngle)));

  point center;

  if(gtk_entry_get_text_length (GTK_ENTRY(rotationCenterX)) == 0 && 
    gtk_entry_get_text_length (GTK_ENTRY(rotationCenterY)) == 0) {
    center = selectedObj->getCenter();
  } else {
    center.x = atof(gtk_entry_get_text(GTK_ENTRY(rotationCenterX)));
    center.y = atof(gtk_entry_get_text(GTK_ENTRY(rotationCenterX)));
  }

  point vectorToOrigin = Utils::translationVector(center, origin);
  point vectorToCenter = Utils::translationVector(origin, center);

  std::list<point>* points = selectedObj->getPoints();
  std::list<point>* rotated = new std::list<point>();
  point rotatedPoint;

  for (std::list<point>::const_iterator it = points->begin();
  it != points->end();
  ++it) {
    rotatedPoint = Utils::rotatePoint(*it, angle, vectorToOrigin, vectorToCenter);
    rotated->push_back(rotatedPoint);
  } 

  selectedObj->setPoints(rotated);
  gtk_widget_destroy((GtkWidget*) user_data);
  return TRUE;
}

static gboolean rotateWindow(GtkWidget *widget, GdkEventButton *event,
    gpointer user_data) {
  selectedObj = getSelected();

  GtkBuilder *builder;
  GError *error = NULL;
  
  builder = gtk_builder_new();

  if (!gtk_builder_add_from_file(builder, "rotate.glade", &error)) {
    g_warning("%s", error->message);
    g_free(error);
  }

  GtkWidget *rotateWindow;

  rotateWindow = GTK_WIDGET( gtk_builder_get_object( builder, "rotateWindow" ) );
  rotationAngle = (GtkEntry*) GTK_WIDGET( gtk_builder_get_object( builder, "rotationAngle" ) );
  rotationCenterX = (GtkEntry*) GTK_WIDGET( gtk_builder_get_object( builder, "centerX" ) );
  rotationCenterY = (GtkEntry*) GTK_WIDGET( gtk_builder_get_object( builder, "centerY" ) );
  GtkWidget* okButton = GTK_WIDGET(gtk_builder_get_object(builder, "okButton"));

  g_signal_connect(G_OBJECT(okButton), "clicked", G_CALLBACK(rotate), rotateWindow);
  
  gtk_builder_connect_signals(builder, NULL);
  g_object_unref(G_OBJECT(builder));
  gtk_widget_show_all(rotateWindow);
  gtk_main();

  return TRUE;
}

static gboolean addNewLine(GtkWidget *widget, GdkEventButton *event,
    gpointer user_data)
{
  double startX = atof(gtk_entry_get_text(GTK_ENTRY(xStartInput)));
  double startY = atof(gtk_entry_get_text(GTK_ENTRY(yStartInput)));
  double endX = atof(gtk_entry_get_text(GTK_ENTRY(xEndInput)));
  double endY = atof(gtk_entry_get_text(GTK_ENTRY(yEndInput)));

  Polygon* newLine = new Polygon(gtk_entry_get_text(GTK_ENTRY(newLineName)));
  newLine->addPoint(startX, startY);
  newLine->addPoint(endX, endY);

  displayFile->add(newLine);
  gtk_widget_destroy((GtkWidget*) user_data);

  return TRUE;
}

static gboolean addNewPoint(GtkWidget *widget, GdkEventButton *event,
    gpointer user_data)
{
  double x = atof(gtk_entry_get_text(GTK_ENTRY(newPointX)));
  double y = atof(gtk_entry_get_text(GTK_ENTRY(newPointY)));

  Point* newPoint = new Point(gtk_entry_get_text(GTK_ENTRY(newPointName)));
  newPoint->setPoint(x, y);
  
  displayFile->add(newPoint);
  gtk_widget_destroy((GtkWidget*) user_data);

  return TRUE;
}

static gboolean addNewPointToPoly(GtkWidget *widget, GdkEventButton *event,
    gpointer user_data)
{
  newPoly->addPoint(atof(gtk_entry_get_text(GTK_ENTRY(newPolyX))), atof(gtk_entry_get_text(GTK_ENTRY(newPolyY))));
  gtk_entry_set_text(newPolyX, "");
  gtk_entry_set_text(newPolyY, "");
  return TRUE;
}

static gboolean closeNewPoly(GtkWidget *widget, GdkEventButton *event,
    gpointer user_data)
{
  //.c_str()
  newPoly->changeName(gtk_entry_get_text(GTK_ENTRY(newPolyName)));
  displayFile->add(newPoly);
  gtk_widget_destroy((GtkWidget*) user_data);
}

static gboolean newLineWindow(GtkWidget *widget, gpointer user_data)
{
  GtkBuilder *builder;
  GError *error = NULL;
  
  builder = gtk_builder_new();

  if (!gtk_builder_add_from_file(builder, "newLine.glade", &error)) {
    g_warning("%s", error->message);
    g_free(error);
  }

  GtkWidget *windowLine = GTK_WIDGET( gtk_builder_get_object( builder, "newLineWindow" ) );
  xStartInput = (GtkEntry*) GTK_WIDGET(gtk_builder_get_object(builder, "startX"));
  yStartInput = (GtkEntry*) GTK_WIDGET(gtk_builder_get_object(builder, "startY"));
  xEndInput = (GtkEntry*) GTK_WIDGET(gtk_builder_get_object(builder, "endX"));
  yEndInput = (GtkEntry*) GTK_WIDGET(gtk_builder_get_object(builder, "endY"));
  newLineName = (GtkEntry*) GTK_WIDGET(gtk_builder_get_object(builder, "newLineName"));

  GtkWidget* okButton = GTK_WIDGET(gtk_builder_get_object(builder, "okButton"));

  g_signal_connect(G_OBJECT(okButton), "clicked", G_CALLBACK(addNewLine), windowLine);

  gtk_builder_connect_signals(builder, NULL);
  g_object_unref(G_OBJECT(builder));
  gtk_widget_show_all(windowLine);
  gtk_main();

  return TRUE;
}

static gboolean newPolygonWindow(GtkWidget *widget, gpointer user_data)
{
  GtkBuilder *builder;
  GError *error = NULL;
  
  builder = gtk_builder_new();

  if (!gtk_builder_add_from_file(builder, "newPolygon.glade", &error)) {
    g_warning("%s", error->message);
    g_free(error);
  }

  GtkWidget *windowPoly = GTK_WIDGET( gtk_builder_get_object( builder, "newPolygonWindow" ) );
  newPolyX = (GtkEntry*) GTK_WIDGET(gtk_builder_get_object(builder, "newPolyX"));
  newPolyY = (GtkEntry*) GTK_WIDGET(gtk_builder_get_object(builder, "newPolyY"));
  newPolyName = (GtkEntry*) GTK_WIDGET(gtk_builder_get_object(builder, "newPolyName"));
  
  GtkWidget* addButton = GTK_WIDGET(gtk_builder_get_object(builder, "addPolyPoint"));
  GtkWidget* doneButton = GTK_WIDGET(gtk_builder_get_object(builder, "donePoly"));

  newPoly = new Polygon("");
  g_signal_connect(G_OBJECT(addButton), "clicked", G_CALLBACK(addNewPointToPoly), NULL);
  g_signal_connect(G_OBJECT(doneButton), "clicked", G_CALLBACK(closeNewPoly), windowPoly);

  gtk_builder_connect_signals(builder, NULL);
  g_object_unref(G_OBJECT(builder));
  gtk_widget_show_all(windowPoly);
  gtk_main();

  return TRUE;
}

static gboolean newPointWindow(GtkWidget *widget, gpointer user_data)
{
  GtkBuilder *builder;
  GError *error = NULL;
  
  builder = gtk_builder_new();

  if (!gtk_builder_add_from_file(builder, "newPoint.glade", &error)) {
    g_warning("%s", error->message);
    g_free(error);
  }

  GtkWidget *windowPoint = GTK_WIDGET( gtk_builder_get_object( builder, "newPointWindow" ) );
  newPointX = (GtkEntry*) GTK_WIDGET(gtk_builder_get_object(builder, "pointX"));
  newPointY = (GtkEntry*) GTK_WIDGET(gtk_builder_get_object(builder, "pointY"));
  newPointName = (GtkEntry*) GTK_WIDGET(gtk_builder_get_object(builder, "newPointName"));
  
  GtkWidget* okButton = GTK_WIDGET(gtk_builder_get_object(builder, "okButton"));

  g_signal_connect(G_OBJECT(okButton), "clicked", G_CALLBACK(addNewPoint), windowPoint);
  
  gtk_builder_connect_signals(builder, NULL);
  g_object_unref(G_OBJECT(builder));
  gtk_widget_show_all(windowPoint);
  gtk_main();

  return TRUE;
}

static GtkTreeModel* create_and_fill_model() {
  GtkListStore *store;
  store = gtk_list_store_new(NUM_COLS_NAME, G_TYPE_STRING, G_TYPE_POINTER);
  return GTK_TREE_MODEL(store);
}

static GtkWidget* create_view_and_model() {
  GtkCellRenderer *renderer;
  GtkTreeModel *model;
  GtkWidget *view;
  
  view = gtk_tree_view_new();

  renderer = gtk_cell_renderer_text_new();
  gtk_tree_view_insert_column_with_attributes(GTK_TREE_VIEW(view), -1, "Object: ", renderer, "text", COL_NAME, NULL);

  model = create_and_fill_model();
  gtk_tree_view_set_model(GTK_TREE_VIEW(view), model);
  g_object_unref(model);

  return view;
}

static void exit_app(GtkWidget* widget, gpointer data) {
  gtk_main_quit();
}

int main(int argc, char **argv)
{
    GtkWidget       *viewport, *buttonUp,
     *buttonDown,   *buttonLeft, *buttonRight, *buttonZoomIn,
     *buttonZoomOut, *newLine, *listWindow, *mainBox, *buttonClose,
     *newPolygon, *newPoint, *translateButton, *scaleButton, 
     *rotateButton;
    GtkDrawingArea  *drawingArea;
    GError          *error = NULL;

    origin.x = 0;
    origin.y = 0;

    viewportData = new Viewport(300.0, 350.0);
    windowData = new Window(300.0, 350.0);
    cs = new CohenSutherland(windowData);
    
    displayFile = new DisplayFile(); 
    
    Polygon* l = new Polygon("line");
    l->addPoint(10, 10);
    l->addPoint(50, 100);
    displayFile->add(l);

    l = new Polygon("line2");
    l->addPoint(5, 5);
    l->addPoint(500, 15);
    displayFile->add(l);


    /* Init GTK+ */

    gtk_init( &argc, &argv );

    /* Create new GtkBuilder object */
    mainBuilder = gtk_builder_new();

    /* Load UI from file. If error occurs, report it and quit application.
     * Replace "tut.glade" with your saved project. */
    if( ! gtk_builder_add_from_file( mainBuilder, "interface.glade", &error ) )
    {
        g_warning( "%s", error->message );
        g_free( error );
        return 1;
    }

    /* Get main window pointer from UI */
    mainWindow = GTK_WIDGET( gtk_builder_get_object( mainBuilder, "mainWindow" ) );
    viewport = GTK_WIDGET(gtk_builder_get_object(mainBuilder, "viewport"));
    drawingArea = GTK_DRAWING_AREA(gtk_builder_get_object(mainBuilder, "drawingarea"));
    listWindow = GTK_WIDGET(gtk_builder_get_object(mainBuilder, "listWindow"));
    buttonClose = GTK_WIDGET(gtk_builder_get_object(mainBuilder, "buttonClose"));
    mainBox = GTK_WIDGET(gtk_builder_get_object(mainBuilder, "mainBox"));
    buttonUp = GTK_WIDGET(gtk_builder_get_object(mainBuilder, "buttonUp"));
    buttonLeft = GTK_WIDGET(gtk_builder_get_object(mainBuilder, "buttonLeft"));
    buttonRight = GTK_WIDGET(gtk_builder_get_object(mainBuilder, "buttonRight"));
    buttonDown = GTK_WIDGET(gtk_builder_get_object(mainBuilder, "buttonDown"));
    buttonZoomIn = GTK_WIDGET(gtk_builder_get_object(mainBuilder, "zoomIn"));
    buttonZoomOut = GTK_WIDGET(gtk_builder_get_object(mainBuilder, "zoomOut"));
    translateButton = GTK_WIDGET(gtk_builder_get_object(mainBuilder, "translateButton"));
    scaleButton = GTK_WIDGET(gtk_builder_get_object(mainBuilder, "scaleButton"));
    rotateButton = GTK_WIDGET(gtk_builder_get_object(mainBuilder, "rotateButton"));
    newPolygon = GTK_WIDGET(gtk_builder_get_object(mainBuilder, "newPolygon"));
    newLine = GTK_WIDGET(gtk_builder_get_object(mainBuilder, "newLine"));
    newPoint = GTK_WIDGET(gtk_builder_get_object(mainBuilder, "newPoint"));

    g_signal_connect(mainWindow, "delete_event", G_CALLBACK(exit_app), NULL);
    g_signal_connect(buttonClose, "clicked", G_CALLBACK(exit_app), NULL);
    g_signal_connect(G_OBJECT(drawingArea), "draw", G_CALLBACK(on_draw_event), NULL); 
    g_signal_connect(G_OBJECT(buttonUp), "clicked", G_CALLBACK(moveUp), mainWindow);
    g_signal_connect(G_OBJECT(buttonDown), "clicked", G_CALLBACK(moveDown), mainWindow);
    g_signal_connect(G_OBJECT(buttonLeft), "clicked", G_CALLBACK(moveLeft), mainWindow);
    g_signal_connect(G_OBJECT(buttonRight), "clicked", G_CALLBACK(moveRight), mainWindow);
    g_signal_connect(G_OBJECT(buttonZoomIn), "clicked", G_CALLBACK(zoomIn), mainWindow);
    g_signal_connect(G_OBJECT(buttonZoomOut), "clicked", G_CALLBACK(zoomOut), mainWindow);
    g_signal_connect(G_OBJECT(translateButton), "clicked", G_CALLBACK(translateWindow), mainWindow);
    g_signal_connect(G_OBJECT(rotateButton), "clicked", G_CALLBACK(rotateWindow), mainWindow);
    g_signal_connect(G_OBJECT(scaleButton), "clicked", G_CALLBACK(scaleWindow), mainWindow);
    g_signal_connect(G_OBJECT(newLine), "clicked", G_CALLBACK(newLineWindow), NULL);
    g_signal_connect(G_OBJECT(newPolygon), "clicked", G_CALLBACK(newPolygonWindow), NULL);
    g_signal_connect(G_OBJECT(newPoint), "clicked", G_CALLBACK(newPointWindow), NULL);


    /* Connect signals */
    gtk_builder_connect_signals( mainBuilder, NULL );
   
    /* Destroy builder, since we don't need it anymore */
    //g_object_unref( G_OBJECT( mainBuilder ) );

    /* Show window. All other widgets are automatically shown by GtkBuilder */
    gtk_widget_show_all( mainWindow );

    /* Start main loop */
    gtk_main();

    return 0;
}