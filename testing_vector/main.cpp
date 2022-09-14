#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    const double PI= 3.14159265;

    double x = 0.0;
    double y = 0.0;

    double vecx = 1.0;
    double vecy = 1.0;


    double result;
    double vec = (vecx*vecx) + (vecy*vecy);

    double dis = 4;

   //double angle = sin(210 * PI / 180);

   double angle = 89.99;

    x += dis*vecx/(sqrt(vec));
    y += dis*vecy/(sqrt(vec));
    //cout << x << endl << y;

    result = vecx*cos(PI * angle/180)-vecy*sin(PI * angle/180);

    cout << result;
}
