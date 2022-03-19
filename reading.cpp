#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
int main(){
  char ch, filename[20];
  int count = 0;
  bool newline = true;
  cout << "请输入文件名：";
  cin >> filename;
  ifstream inFile(filename, ios::in);
  if(!inFile){
    cout << "打开文件失败" << endl;
    return 0;
  }
  while((ch = inFile.get())!=EOF){   // 这个EOF是end of file的意思，是文件结束标志
    if(newline){
      cout << setw(4) << ++cout << ':';  // 开宽度为4个空间
      newline = false;
    }
    if(ch == '\n'){         // 字符为换行符\n 那么将newline = true
      newline = true;
    }
    cout << ch;        // 一个一个输出字符
  }
  inFile.close();    // 关闭文件
  return 0;
}