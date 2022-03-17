#include <iostream>
using namespace std;
// 有点像泛型
template <class T>
void Swap(T &x, T &y)
{

  T tmp = x;
  x = y;
  y = tmp;
}
class myDate
{
public:
  myDate();
  myDate(int, int, int);
  void printDate() const;

private:
  int year, month, day;
};
myDate::myDate()
{
  year = 1970;
  month = 1;
  day = 1;
}
myDate::myDate(int y, int m, int d)
{
  year = y;
  month = m;
  day = d;
}
void myDate::printDate() const
{ // 这里面的const 代表是常函数，常函数里面不能赋值，里面调用常函数
  cout << year << "/" << month << "/" << day << endl;
  return;
}
int main()
{
  int n = 1, m = 2;
  Swap(n, m);
  cout << n << " " << m << endl;
  double f = 1.2, g = 2.3;
  Swap(f, g);
  cout << f << " " << g << endl;
  // 对象互换
  myDate d1, d2(2000, 1, 1);
  Swap(d1, d2);
  d1.printDate(); // 2000/1/1
  d2.printDate(); // 1970/1/1
  return 0;
}
// 2 1
// 2.3 1.2
// 2000/1/1
// 1970/1/1