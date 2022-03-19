#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
int main(){
  char id[11], name[21];
  int score;
  ifstream inFile.open("score.txt", ios::in);
  inFile;
  if(!inFile){
    cout << "打开文件失败" << endl;
    return 0;
  }
  cout << "学生学号 姓名\t\t\t成绩\n"; // \t 是隔空8个字符
  while(inFile>>id>>name>>score){ // 因为inFile是流对象所以可以用>>这么用
    cout << left << setw(10) << id << setw(20) << name << setw(3) << score << endl;
  }
  inFile.close();
  return 0;
}