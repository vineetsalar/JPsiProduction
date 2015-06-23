//Newton-Raphson Root Finding Method

//Algorithm:

//xi+1 = xi - f(xi)/f'(xi)

//Example: find the roots of f(x) = 2x2 -x -21


//% cat newt3.cpp
// Newton-Raphson method for finding the
// roots of f(x) = 0 for a polynomial function
#include <iostream>
using namespace std;
#include <cmath>

double newton(double a, double b, double c, double x0, double crit);

int main()
{
  double a, b, c, root, guess, conv_crit;
 
  cout << "Enter values for a, b, and c :";
  cin >> a >> b >> c;

  cout << "Enter a guess for the root :";
  cin >> guess;
 
  cout << "Enter the convergence criterion: ";
  cin >> conv_crit;
 
  // call function newton

  root = newton(a, b, c, guess, conv_crit);

  // display result
  cout.setf(ios::fixed | ios::showpoint);
  cout.precision(4);

  cout << "One root is " << root << endl;

  return 0;

}

double newton(double a, double b, double c, double x0, double crit)
{
  double x1, delta;
  int iters = 0;

  // use a do-while loop
  do
  {
     x1 = x0 - (a*x0*x0 + b*x0 + c) / ( 2*a*x0 + b);

     delta = fabs ( x1 - x0 );

     x0 = x1;  // new approximation becomes the old
               // approximation for the next iteration

     iters++;  // count the number of iterations

  } while (delta > crit && iters <= 30);
 
  cout << iters << " iterations" << endl;

  return x1;
}


//% a.out
//Enter values for a, b, and c :2 -1 -21
//Enter a guess for the root :10
//Enter the convergence criterion: .0001
//5 iterations
//One root is 3.5000
//% a.out
//Enter values for a, b, and c :2 -1 -21
//Enter a guess for the root :-9
//Enter the convergence criterion: .0001
//5 iterations
//One root is -3.0000
