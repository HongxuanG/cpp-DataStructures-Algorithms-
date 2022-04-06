#include <basicStructure.h>
// 冒泡排序  相邻两个元素进行比较，不符合顺序就交换位置，第一趟就已经得到了最小值，最多n-1趟
// 同样的R[0]也是哨兵，不过这里的作用只有存储要交换的元素
// 另外：判断排序是否结束有两种情况
// 1. 循环到某一趟的时候，没有交换任何数
// 2. 已经走了n-1趟
void BubbleSort(Seqlist R, int n){
  int i, j, flag;
  for (i = 1; i < n;i++){
    flag = 0;
    for (j = n; j >= i + 1;j--){
      if(R[j].key < R[j-1].key){
        R[0] = R[j];
        R[j] = R[j - 1];
        R[j - 1] = R[0];
        flag = 1;
      }
    }
    if(flag == 0)
      return;
  }
}
