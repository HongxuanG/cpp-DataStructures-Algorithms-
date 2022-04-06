#include <iostream>
using namespace std;
void SwapValue(int a, int b)
{
  int tmp;
  tmp = a;
  a = b;
  b = tmp;
  cout << "在SwapValue()中a=" << a << ",b=" << b << endl
       << endl;
}
void SwapRef(int &m, int &n)
{
  int tmp;
  tmp = m;
  m = n;
  n = tmp;
  cout << "在SwapRef()中m=" << m << ",n=" << n << endl
       << endl;
}
int main()
{
  int a = 10, b = 20;
  cout << "数据变换前:\t\ta=" << a << ",b=" << b << endl
       << endl;
  SwapValue(a, b);
  cout << "调用SwapValue()后:\t\ta=" << a << ",b=" << b << endl
       << endl;
  a = 10;
  b = 20;
  SwapRef(a, b);
  cout << "调用SwapRef()后:\t\ta=" << a << ",b=" << b << endl
       << endl;

  return 0;
}