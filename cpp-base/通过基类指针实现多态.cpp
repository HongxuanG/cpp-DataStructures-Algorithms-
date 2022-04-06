#include <iostream>
using namespace std;
class A{
  public:
    virtual void Print(){     // 虚函数  运行时绑定
      cout << "A::Print" << endl;
    }
};
class B:public A{
  public:
    virtual void Print(){
      cout << "B::Print" << endl;
    }
};
class D:public A{
  public:
    virtual void Print(){
      cout << "D::Print" << endl;
    }
};
class E:public B{
  public:
    virtual void Print(){
      cout << "E::Print" << endl;
    }
};
int main(){
  A a;
  B b;
  D d;
  E e;
  A *pa = &a;
  B *pb = &b;
  pa->Print();
  pa = pb;       // 派生类指针赋值给基类指针，pa指向派生类的对象B
  pa->Print();
  pa = &d;     // 基类指针pa指向派生对象d
  pa->Print();
  pa = &e;    // 基类指针pa指向派生对象e
  pa->Print();
  return 0;
}
// A::Print
// B::Print
// D::Print
// E::Print
