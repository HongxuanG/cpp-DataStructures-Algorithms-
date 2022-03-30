#include <iostream>
using namespace std;
int main(){
  double values[] = {1.23, 20.3456, 423.2, 74894.51, 15.654, 78.31};
  cout.fill('*');
  for (int i = 0; i < sizeof(values) / sizeof(double);i++){
    cout << "values[" << i << "]=(";
    cout.width(10);
    cout << values[i] << ")" << endl;
  }
  cout.fill(' ');
  for (int j = 0; j < sizeof(values) / sizeof(double);j++){
    cout << "values[" << j << "]=(";
    cout.width(10);   // 宽度是10
    cout.precision(j + 3);   // 保留有效数字
    cout << values[j] << ")" << endl;
  }
  return 0;
}
// values[0]=(******1.23)
// values[1]=(***20.3456)
// values[2]=(*****423.2)
// values[3]=(***74894.5)
// values[4]=(****15.654)
// values[5]=(*****78.31)
// values[0]=(      1.23)
// values[1]=(     20.35)
// values[2]=(     423.2)
// values[3]=(   74894.5)
// values[4]=(    15.654)
// values[5]=(     78.31)