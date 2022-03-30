#include<iostream>
using namespace std;
class CBase
{
public:
  void func1(){
    cout << "CBase:func1()" << endl;
    func2();   // 先是就近原则，找到的是CBase的func2，一看是virtual
    // 调用的是CDerived的func() 
    func3(); // 先是就近原则，找到的是CBase的func3，所以就调用它
  }
  virtual void func2(){
    cout << "CBase:func2()" << endl;
  }
  void func3(){
    cout << "CBase:func3()" << endl;
  }
};
class CDerived:public CBase{
  public:
    virtual void func2(){
      cout << "CDerived:func2()" << endl;
    }
    void func3(){
      cout << "CDerived:func3()" << endl;
    }
};
int main(){
  CDerived d;
  d.func1(); // func1在CDerived没有所以调用继承过来的CBase里面的func1()
  return 0;
}
