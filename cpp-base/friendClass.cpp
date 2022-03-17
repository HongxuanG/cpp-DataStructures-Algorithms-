#include<iostream>
using namespace std;
class Two{
  int y;
  public:
    friend class One;
};
class One{
  int x;
  public:
    One(int a, Two &r,int b){ // 都是Two的友元函数
      x = a;
      r.y = b;
    }
    void Display(Two &);  // 都是Two的友元函数
};
void One::Display(Two &r){
  cout << x << "" << r.y << endl;
};
int main(){
  Two Obj2;
  One Obj1(23, Obj2, 55);
  Obj1.Display(Obj2);
  return 0;
}