#include <iostream>
#include <string>
using namespace std;
class myDate
{
public:
  myDate();
  myDate(int, int, int);
  void setDate(myDate);
  myDate getDate();
  void setYear(int);
  int getMonth();
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
void myDate::setDate(myDate oneD)
{
  year = oneD.year;
  month = oneD.month;
  day = oneD.day;
}
myDate myDate::getDate()
{
  return *this;
}
void myDate::setYear(int y)
{
  year = y;
  return;
}
int myDate::getMonth()
{
  return month;
}
void myDate::printDate() const
{
  cout << year << "/" << month << "/" << day;
  return;
}
class Student
{
private:
  /* data */
  string name;
  myDate birthday;

public:
  void setStudent(string, myDate);
  void setName(string);
  string getName();
  void setBirthday(myDate);
  myDate getBirthday();
  void printStudent() const;
};

void Student::setStudent(string s, myDate d)
{
  name = s;
  birthday = d;
}
void Student::setName(string s)
{
  name = s;
  return;
}
string Student::getName()
{
  return name;
}
void Student::setBirthday(myDate d)
{
  birthday = d;
  return;
}
myDate Student::getBirthday()
{
  return birthday;
}
void Student::printStudent() const
{
  cout << "姓名：" << name << "\t生日：";
  birthday.printDate();
  cout << endl;
}
int main()
{
  Student ss;
  int y, m, d;
  string name_;
  cout << "请输入学生的姓名和生日，生日以\"年月日\"的次序输入：";
  cin >> name_ >> y >> m >> d;
  ss.setStudent(name_, myDate(y, m, d));
  ss.printStudent();
  return 0;
}