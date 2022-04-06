#include <basicStructure.h>
// 快速排序 
void Partition(Seqlist R, int i, int j){
  RecType x = R[i]; // x 基准
  while(i < j){
    while(i < j && R[j].key>=x.key){
      j--;
    }
    if(i < j){
      R[i] = R[j];
      i++;
    }
    while(i < j && R[i].key <= x.key){
      i++;
    }
    if(i < j){
      R[j] = R[i];
      j--;
    }
  }
  R[i] = x;
  return i;
}
// 快速排序
void QuickSort(Seqlist R, int low , int high){
  int p;
  if(low<high){
    p = Partition(R, low, high);
    QuickSort(R, low, p - 1);
    QuickSort(R, p + 1, high);
  }
}
