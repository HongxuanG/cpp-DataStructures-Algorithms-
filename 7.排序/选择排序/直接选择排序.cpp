#include <basicStructure.h>
// 直接选择排序 不稳定 时间复杂度O(n^2)
void SelectSort(Seqlist R, int n){
  int i,j,k;
  // 遍历n-1趟，从下标为1开始，因为第一个不需要排序
  for (i = 1; i < n;i++){
    // 先初始化k
    k = i;
    // 找出剩余待排序的数组里面最小值 下标赋给K
    for (j = i + 1; j <= n;j++){
      if(R[j].key<R[k].key){
        k = j;
      }
    }
    // 交换位置 这里存在可能交换相同元素的问题，所以不稳定
    if(k!=i){
      R[0] = R[i];
      R[i] = R[k];
      R[k] = R[0];
    }
  }
}
