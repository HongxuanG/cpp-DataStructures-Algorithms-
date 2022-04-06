#include<basicStructure.h>
// 希尔排序，通常数组越大，希尔排序的效果越明显，因为他是一个逐渐减少元素之间比较和移动次数的方法
// 传入一个增量dk 一个数组长度n 待排序数组R
void ShellInsert(Seqlist R, int dk, int n){
  int i, j;
  // 内部分组就是一个直接插入排序
  for (i = dk + 1; i <= n;i++){
    if(R[i].key < R[i-dk].key){
      R[0] = R[i];
      j = i - dk;
      // i == 0时，j有可能是负数
      while (j > 0 && R[0].key < R[j].key){
        R[j + dk] = R[j];
        j = j - dk;
      }
      R[j + dk] = R[0];
    }
  }
}
void ShellSort(Seqlist R, int d[], int t, int n){
  int k;
  // 遍历增量序列 逐个调用ShellInsert
  for (k = 0; k < t;k++){
    ShellInsert(R, d[k], n);
  }
}
