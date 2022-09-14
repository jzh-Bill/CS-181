/** \file
 * @brief  Demo of some basic GL: window, viewport, points, function plot
 * @author John Neitzke
 * @version 20 November 2019
 *
 */
//  Demo of basic OpenGL
//  A bit more organized
//using namespace std;
#include <GL/glut.h>
#include <math.h>
const double PI = 3.1415972;
// initial sizes for window.
unsigned const WIDTH = 1000;
unsigned const HEIGHT = 800;

// initial position for window.
unsigned const WINDOW_LEFT = 120;
unsigned const WINDOW_TOP = 60;

/** \brief Cartesian points in 2D
 *
 * @author John Neitzke
 * @version 20 November 2019
 *
 */
class Point
{
private:
  double x;
  double y;
public:
  /** \brief Null constructor, sets to origin
   *
   */
  Point();

  /** \brief general constructor
  * @param x_coordinate
  * @param y_coordinate
  */
  Point (double x_coordinate, double y_coordinate);

  /** \brief accessor for x-coordinate
  * @return x value of point
  */
  double get_x_coordinate();

  /** \brief accessor for y-coordinate
  * @return y value of point
  */
  double get_y_coordinate();

  /** \brief mutator for x-coordinate
  * @param new_x new x value
  */
  void set_x_coodinate (double new_x);

  /** \brief mutator for y-coordinate
  * @param new_y new y value
  */
  void set_y_coordinate (double new_y);

  /** \brief mutator for x and y coordinates
  * @param new_x new x value
  * @param new_y new y value
  */
  void set_coordinates (double new_x, double new_y);
};

/** \brief show on viewport if possible
* @param p a member of class Point
*/
void draw_point (Point p);

/** \brief show on viewport if possible line from p to q
* @param p a member of class Point
 * @param q a member of class Point
*/
void draw_line (Point p, Point q);

/** \brief Utility to set world window, an aligned rectangle
* @param left x coordinate of left side
* @param right x coordinate of right side
* @param bottom y coordinate of bottom side
* @param top y coordinate of top side
*/
void set_window (double left, double right, double bottom, double top);

/** \brief Utility to set viewport, an aligned rectangle
* @param left x coordinate of left side
* @param right x coordinate of right side
* @param bottom y coordinate of bottom side
* @param top y coordinate of top side
*/
void set_viewport ( int left,  int right,  int bottom,  int top);

/** \brief quintic to use to test graphing. <p> Has no significance
* @param  x a number
* @return  a number
*/
double f (double x);

/** \brief Initializations specific to this program
*
*/
void my_init (void);

/** \brief Callback function to redraw window
*
*/
void my_display (void);

/** \brief Main program:  initializations and enter loop
* @param  argc a number.  Required but not used
* @param  argv a string pointer.  Required but not used
* @return  0 for normal
*
*/
int main (int argc, char** argv)
{
  glutInit (&argc, argv); // initialize the tooklit
  glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB); //  set the display mode
  glutInitWindowSize (WIDTH, HEIGHT ); //  set initial window size
  glutInitWindowPosition ( WINDOW_LEFT,
                           WINDOW_TOP); // set initial window position on screen
  glutCreateWindow ("  Graphics Window  "); // open the window
  // Some initial values; likely superseded.
  glMatrixMode (GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D (-900, WIDTH, -900, HEIGHT);// set projection mode for window: lrbt
  //  register the callback functions
  //  glutReshapeFunc(my_reshape);
  // glutMouseFunc(my_mouse);
  // glutKeyboardFunc(my_keyboard);
  glutDisplayFunc ( my_display);
  glViewport (0, 0, WIDTH, HEIGHT);   // sets screen window from lower left
  my_init(); // additional initializations as needed
  glutMainLoop(); // go into a perpetual loop
  return 0;
}

Point::Point()
{
  x = 0;
  y = 0;
}
Point::Point (double x_coordinate, double y_coordinate)
{
  x = x_coordinate;
  y = y_coordinate;
}
double Point::get_x_coordinate()
{
  return x;
}
double Point::get_y_coordinate()
{
  return y;
}

void Point::set_x_coodinate (double new_x)
{
  x = new_x;
}
void Point::set_y_coordinate (double new_y)
{
  y = new_y;
}
void Point::set_coordinates (double new_x, double new_y)
{
  x = new_x;
  y = new_y;
}

void draw_point (Point p)
{
  glBegin (GL_POINTS);
  glVertex2f (p.get_x_coordinate(), p.get_y_coordinate() );
  glEnd();
}

void draw_line (Point p, Point q)
{
  glBegin (GL_LINE_STRIP);
  glVertex2f (p.get_x_coordinate(), p.get_y_coordinate() );
  glVertex2f (q.get_x_coordinate(), q.get_y_coordinate() );
  glEnd();
}

void set_window (double left, double right, double bottom, double top)
{
  glMatrixMode (GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D (left, right, bottom, top);
}

void set_viewport ( int left,  int right,  int bottom,  int top)
{
  glViewport (left, bottom, right - left, top - bottom);
}

double f (double x)
{
  return 2 * x * x * x - 3 * x - 2;
}

void my_init (void)
{
  glLineWidth (1.0);
  glPointSize (40.0);
  glClearColor (1.0, 1.0, 1.0, 0.0); // background color
  glColor3f (0.0, 0.0, 1.0);       // drawing color: blue
}
void my_display (void)
{

    // draw one point at (100, 100);
    Point p (100, 100) ;
    draw_point (p);
    Point q (20, 20);
    Point r ( 300, 300);
    draw_line (q, r);
    glColor3f (0.9, 0.1, 0.9);
   // draw_line ( Point (700, 600), Point() );

/*
  // part 2:  incompatible with part 1
  // function plot
    set_window(-14, 4, -12, 12);
    set_viewport(0, 700, 20, 600);
    for (double x = -3; x < 3.5; x += 0.0001)
    {
      draw_point(Point(x, f(x)));
    }
*/
/*
// part 3:  tiling
  set_window (-4, 4, -12, 12);
    for ( double h = 0; h < 900; h += 100)
    {
      for (double v = 0; v < 700; v += 52)
      {
        set_viewport (h, h + 100, v, v + 50);
        for (double x = -3; x < 3.5; x += 0.01)
        {
          draw_point (Point (x, f (x) ) );
        }
      }
    }
*/
  // part 4:  zooming
  /*set_viewport (0, 900, 0, 700);
  for ( double s = 10; s > 0; s -= 0.4)
  {
    set_window (-s, s, -3 * s, 3 * s);
    for (double x = -3; x < 3.5; x += 0.01)
    {
      draw_point (Point (x, f (x) ) );
    }
  }
  */
  glFlush();

}
