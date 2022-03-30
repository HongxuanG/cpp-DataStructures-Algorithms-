#include <iostream>
using namespace std;
const double PI = 3.14159;
class Point{
  private:
    double x, y;
  public:
    Point(double i,double j){
      x = i;
      y = j;
    }
    virtual double area(){
      return 0;
    }
};
class Circle:public Point{
  private:
    double radius;
  public:
    Circle(double a, double b,double r):Point(a,b){
      radius = r;
    }
    double area(){
      return PI * radius * radius;
    }
};
void display(Point *p){
  cout << p->area() << endl;
}
void display(Point &a){
  cout << a.area() << endl;
}
int main(){
  Point a(1.5, 6.7);
  Circle c(1.5, 6.7, 2.5);
  Point *p = &c;
  Point &rc = c;
  display(a); // 基类对象调用基类虚函数area 输出0
  display(p); // 指针调用派生类虚函数area 输出19.6349
  display(rc); // 指针调用派生类虚函数area 输出19.6349
  return 0;
}
// 0
// 19.6349
// 19.6349