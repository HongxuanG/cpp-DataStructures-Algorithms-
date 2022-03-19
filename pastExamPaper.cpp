#include <iostream>
#include <string>
using namespace std;
class School{
  protected:
    int Number;
    string Name;
};
class Student: public School{
  public:
    Student(string name,int number, string classnum, int total): Number(number), Name(name){
      Class_Num = classnum;
      Total = total;
    };
    string Class_Num;
    int Total;
    void Display(){
      cout << Number << Name << Class_Num << Total << endl;
    }
};
int main(){
  Student s1("张小蒙", 2020150601, "四班", 678);
  s1.Display();
  return 0;
}