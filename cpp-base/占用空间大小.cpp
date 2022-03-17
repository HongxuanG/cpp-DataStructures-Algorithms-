#include <iostream>
using namespace std;
class Base{
  public:
    int b;
    void show(){
      cout << b << endl;
    }
  
};
class Test: public Base{
  public:
    int i;
    void show(){
      cout << i << endl;
    }
};
int main(){
  cout << sizeof(Base) << endl;
  cout << sizeof(Test) << endl;
}