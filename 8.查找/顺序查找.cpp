#include <basicStructure.h>
int SeqSearch(SeqList R, KeyType k, int n){
  R[0].key = k;
  int i = n;
  while(R[i].key != k){
    i--;
  }
  return i; 
}
// 如果顺序表基本有序，可以做以下改进
// 假设顺序表已经是递增，从尾部循环，i--，当索引为i的关键字小于要查找的值k时，就没必要继续往下查找了因为已经不存在了
int SeqSearch1(SeqList R, KeyType k, int n){
  int i = n;
  while(R[i].key > k){
    i--;
  }
  if(R[i].key == k){
    return i;
  }
  return 0; // 没查找到
}
