#include <iostream>
using namespace std;
template <class T>
class TestClass
{
public:
  T buffer[10];
  T getData(int j);
};
template <class T>
T TestClass<T>::getData(int j)
{
  return *(buffer + j);
}
int main()
{
  // 看起来真的就是TS泛型的定义
  TestClass<char> ClassInstA;
  char cArr[6] = "abcde"; // 这里解说一下为什么这里是6，因为abcde后面还有一个占一个字节的'\0'
  for (int i = 0; i < 5; i++)
  {
    ClassInstA.buffer[i] = cArr[i];
  }
  for (int i = 0; i < 5; i++)
  {
    char res = ClassInstA.getData(i);
    cout << res << " ";
  }
  cout << endl;
  TestClass<double> ClassInstF;
  double fArr[6] = {12.1, 23.2, 34.2, 45.4, 56.3, 67.6};
  for (int i = 0; i < 6; i++)
  {
    ClassInstF.buffer[i] = fArr[i] - 10;
  }
  for (int i = 0; i < 6; i++)
  {
    double res = ClassInstF.getData(i);
    cout << res << " ";
  }
  cout << endl;
  return 0;
}
// a b c d e
// 2.1 13.2 24.2 35.4 46.3 57.6