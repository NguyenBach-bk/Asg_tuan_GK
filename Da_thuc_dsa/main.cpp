#include <iostream>

using namespace std;

double
power (double base, int exponent)
{
  double result = 1;
  for (int i = 0; i < exponent; ++i)
    {
      result *= base;
    }
  return result;
}

double
f (double x)
{
  return 5 * power (x, 10) + 1;
}

double
g (double x)
{
  return 10 * power (x, 15) - 2 * power (x, 7) + 3 * power (x, 2) - 7;
}

int
main ()
{
  double x;
  cout << "Nhap gia tri x: ";
  cin >> x;

  double fx = f (x);
  double gx = g (x);

  cout << "f(x) = 5*x^10 + 1 = " << fx << endl;
  cout << "g(x) = 10*x^15 - 2*x^7 + 3*x^2 - 7 = " << gx << endl;

  double hx = fx + gx;

  cout << "h(x) = f(x) + g(x) = " << hx << endl;

  return 0;
}
