#include<iostream>
using namespace std;
class A{
  public:
    void func1(){
      cout << "A::func1()" << endl;
    }
    virtual void func2(){
      cout << "A::func2()" << endl;
    }
};
class B:public A{
  public:
    virtual void func1(){
      cout << "B::func1()" << endl;
    }
    void func2(){
      cout << "B::func2()" << endl;
    }
};
// 初始化执行过程：A  B  C  
// 析构过程：C  B  A
class C:public B{
  public:
    void func1(){
      cout << "C::func1()" << endl;
    }
    void func2(){   // func2自动成为虚函数
      cout << "C::func2()" << endl;
    }
};
int main(){
  C obj;
  A *pa = &obj;
  B *pb = &obj;
  // 怎么看？
  // pa 是 A类的，现在A类找fun2  找到了是virtual，遇到virtual我们看等号右边&obj
  // &obj是C类的对象，所以我们在C类找func2，所以输出 C::func2
  pa->func2(); // 多态
  pa->func1(); // 不是多态
  pb->func1(); // 多态
  return 0;
}
// C::func2()
// A::func1()
// C::func1()