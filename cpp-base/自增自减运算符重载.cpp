#include <iostream>
using namespace std;
class CDemo{
  private:
    int n;
  public:
    CDemo(int i = 0) : n(i){};
    CDemo &operator++();
    CDemo operator++(int);
    operator int() { return n; }; // 强制类型转换重载
    friend CDemo &operator--(CDemo &);
    friend CDemo operator--(CDemo &, int);
};
CDemo & CDemo::operator++(){
  n++;
  return *this;
}
CDemo CDemo::operator++(int k){
  CDemo temp(*this);
  n++;
  return temp;
}
CDemo & operator--(CDemo &d){
  d.n--;
  return d;
}
CDemo operator--(CDemo &d, int k){
  CDemo temp(d);
  d.n++;
  return temp;
}
int main(){
  CDemo d(10);
  cout << (d++) << ",";
  cout << d << ",";
  cout << (++d) << ",";
  cout << d << ",";
  cout << (d--) << ",";
  cout << d << ",";
  cout << (--d) << ",";
  cout << d << endl;
  return 0;
}