// CPP example to illustrate the rotation 
// of a point about another point
#include <iostream>
#include <complex>
 
using namespace std;
 
typedef complex<double> point;
#define x real()
#define y imag()
 
// Constant PI for providing angles in radians
#define PI 3.1415926535897932384626
 
// Function used to display X and Y coordinates of a point
void displayPoint(point P){
  cout << "(" << P.x << ", " << P.y << ")" << endl;
}
 
//Function for Rotation of P about Q by angle theta
point rotate(point P, point Q, double theta){
  return (P-Q) * polar(1.0, theta) +  Q;
}
 
int main()
{
    // Rotate P about Q
    point P(4.0, 3.0);
    point Q(2.0, 2.0);
 
    double theta = 60.0*(PI/180);
    point P_rotated = rotate(P, Q, theta);
    cout<<"Rotating P about Q ";   
    displayPoint(P_rotated);
    return 0;
}
