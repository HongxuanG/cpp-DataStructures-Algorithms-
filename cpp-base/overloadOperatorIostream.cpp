#include <iostream>
using namespace std;
class Test{
  private:
    int i;
    float f;
    char ch;
  public:
    Test(int i = 0, float f = 0, char ch = '\0') { i = i, f = f, ch = ch; };
    friend ostream &operator<<(ostream, Test);
    friend istream &operator>>(istream &, Test &);
};  
ostream &operator<<(ostream &cout, Test obj){
  cout << obj.i << ",";
  cout << obj.f << ",";
  cout << obj.ch<<endl;
  return cout;
}
istream &operator>>(istream &cin, Test &obj){
  cin >> obj.i;
  cin >> obj.f;
  cin >> obj.ch;
  return cin;
}
int main(){
  Test A(5, 5.5, 'w');
  operator<<(cout, A);
  
}