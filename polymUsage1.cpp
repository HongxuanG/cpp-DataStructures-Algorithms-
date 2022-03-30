#include<iostream>
using namespace std;
class A{
  public:
    virtual void hello(){
      cout << "A::hello()" << endl;
    }
    virtual void bye(){
      cout << "A::bye()" << endl;
    }
};
class B:public A{
  public:
    virtual void hello(){
      cout << "B::hello()" << endl;
    }
    B(){
      hello(); // 为什么调用这个，不调用C的hello()，因为这时候C还没被初始化
    }
    ~B(){       // 不会多态，因为在析构函数里面调用虚函数，
      bye();
    }
};
// 初始化执行过程：A  B  C  
// 析构过程：C  B  A
class C:public B{
  public:
    virtual void hello(){
      cout << "C::hello()" << endl;
    }
};
int main(){
  C obj;
  return 0;
}
// B::hello()
// A::bye()  