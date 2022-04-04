#include <iostream>
using namespace std;
class CBase{
  protected:
    int n;

  public:
    CBase(int i) : n(i){};
    void print() { cout << "CBase:n=" << n << endl; };
};
class CDerived:public CBase{
  public:
    int v;
    CDerived(int i) : CBase(i), v(2 * i){};
    void Func(){};
    void print(){
      cout << "CDerived:n=" << n << endl;
      cout << "CDerived:v=" << v << endl;
    }
};
int main(){
  CDerived objDerived(3); // 用3初始化CDervied
  CBase objBase(5); // 用5初始化CBase
  CBase *pBase = &objDerived; // 使用基类指针指向派生类对象
  CDerived *pDerived;
  pDerived = &objDerived;
  cout << "使用派生类指针调用函数" << endl;
  pDerived->print();
  pBase = pDerived;
  cout << "使用基类指针调用函数" << endl;
  pBase->print();
  pDerived = (CDerived *)pBase;        // 强制类型转换 pBase指针转换成 CDerived
  cout << "使用派生类指针调用函数" << endl;
  pDerived->print();
  return 0;
}