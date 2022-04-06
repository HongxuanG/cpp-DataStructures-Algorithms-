#include <iostream>
using namespace std;
class A{
  private:
    int a;
  public:
    virtual void print() = 0; // 纯虚函数
    void func1(){
      cout << "func1" << endl;
    }
};
class B:public A{
  public:
    void print();
    void func1(){
      cout << "B::func1" << endl;
    }
};
void B::print(){
  cout << "B::print" << endl;
}
int main(){
  // A a;   错误，抽象类不能实例化
  // A *p = new A; 不允许使用抽象类类型 "A" 的对象
  // A b[2];  不允许使用抽象类 "A" 数组
  A *pa;                // 正确，可以声明抽象类的指针
  A *pb = new B;        // 使用基类指针指向派生类对象
  pb->print();          // 多态，调用的是类B的函数，输出B::print
  B b;
  A *pc = &b;          // 使用基类指针指向b
  pc->func1();         // 不是虚函数，没有多态，调用的是A中的函数，输出func1
  return 0;
}
// B::print
// func1