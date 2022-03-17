#include <iostream>
using namespace std;
class Base{
  private:
    int x;
    const int a;        // // const 也是在外面初始化，通过初始化列表的形式
    static const int b; // const 静态常数据成员需要在类外初始化
    const int& r;       // const 也是在外面初始化，通过初始化列表的形式
  public:
    Base(int, int);
    void Show(){
      cout << x << "," << a << "," << b << "," << r << endl;
    }
    void Display(const double &r){
      cout << r << endl;
    }
};
const int Base::b = 125;   // 初始化静态成员常量 通过类名.成员名
Base::Base(int i, int j) : x(i), a(j), r(x){};
int main(){
  Base a1(104, 118), a2(119, 140);
  a1.Show();
  a2.Show();
  a2.Display(3.14159);
  return 0;
}