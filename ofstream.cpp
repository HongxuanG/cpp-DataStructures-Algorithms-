#include <iostream>
#include <fstream>
using namespace std;
int main(){
  char id[11], name[21];
  int score;
  ofstream outFile;
  outFile.open("score.txt", ios::out);
  if(!outFile){
    cout << "创建文件失败" << endl;
    return 0;
  }
  cout << "请输入：学号 姓名 成绩(ctrl+z结束输入)\n";
  while(cin>>id>>name>>score){
    outFile << id << "" << name << score << endl;
  }
  outFile.close();
  return 0;
}