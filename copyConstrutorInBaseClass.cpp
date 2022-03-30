#include <iostream>
using namespace std;
class A
{
private:
  int i;
public:
  A();
  A(const A &);
  ~A();
};

A::A()
{
  i = 100;
  cout << "类A默认构造函数" << endl; // 1、2
}
A::A(const A &s){
  i = s.i;
  cout << "类A复制构造函数" << endl; // 4
}

A::~A()
{
}
class B:public A{
  private:
    float f;
  public:
    B();
    B(const B &v) : A(v), f(v.f){
      cout << "类B复制构造函数" << endl; // 5
    }
};
B::B(){
  f = 20.1;
  cout << "类B默认构造函数" << endl; // 3
}
int main(){
  A a;
  B b;
  B bb(b);
  return 0;
}
// 类A默认构造函数
// 类A默认构造函数
// 类B默认构造函数
// 类A复制构造函数
// 类B复制构造函数