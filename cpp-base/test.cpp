#include <iostream>
using namespace std;
void SwapValue(int a, int b){
  int tmp;
  tmp = a;
  a = b;
  b = tmp;
  cout << "在SwapValue()函数中\t\ta=" << a << ",b=" << b << endl;
}
void SwapRef(int &a, int &b){
  int tmp;
  tmp = a;
  a = b;
  b = tmp;
  cout << "在SwapRef()函数中\t\ta=" << a << ",b=" << b << endl;
}
int main()
{
  int a = 10, b = 20;
  cout << "数据交换前:\t\ta="<<a<<",b="<<b << endl<<endl;
  SwapValue(a, b);
  cout << "调用SwapValue()后:\t\ta="<<a<<",b="<<b << endl<<endl;
  a = 10;
  b = 20;
  SwapRef(a, b);
  cout << "调用SwapRef()后:\t\ta="<<a<<",b="<<b << endl<<endl;
  return 0;
}