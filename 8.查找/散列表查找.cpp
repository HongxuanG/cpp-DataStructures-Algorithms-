// 散列的概念  通过散列函数决定键值和存储地址之间的关系来实现存储和查找

// 假设 散列函数H(key) = key % m 可以求出关键字的散列地址  m 一般取小于或等于散列表长度的最大素数
// 有线性表 A = (31,62,74,36,49,77)
// 那么散列地址：
/*
  H(31) = 31 % 11 = 9
  H(62) = 62 % 11 = 7
  H(74) = 74 % 11 = 8
  H(36) = 36 % 11 = 3
  H(49) = 49 % 11 = 5
  H(77) = 77 % 11 = 0
*/

// 0   1   2   3   4   5   6   7   8   9   10
// 77  88       36     49          74  31   


// 当插入88 和 7 那么会产生冲突  因为88要查到0   7 要查到7的位置 但是都被沾满了

// 这时候要解决冲突
// 散列技术要解决两个问题 1. 如何构造出均匀的散列函数(冲突越少越好)  2. 用什么方法解决冲突


/*
散列函数的构造方法有：
  1. 直接地址法
  利用关键字加上一个常数C来计算出他的散列地址
    - 浪费空间 只适合关键字连续的数列
    - 因为不连续的话，关键字和C之间就产生了空间浪费
  2. 数字分析法
  适合序列的每个关键字有n位数字组成，从中提取数字分布比较均匀的若干位作为散列地址
  3. 除余数法 :seed:
  上面提到的除余 比如：H(key) = key % m  m是小于等于表长的最大素数 比如表长是12  那么取m为11  表长为13  取m为13
  4. 平方取中法

  5. 折叠法
  适合关键字比较长 的表
  例如：关键字K = 98123658  散列地址取3位  将关键字从左往右每3位进行划分一段 得到981 236 58
  然后叠加在一起  981 + 236 + 58 = 1275  那么275就是关键字K = 98123658 的散列地址
*/
/*
处理冲突的方法
1. 开放定址法：

  1. 线性探测法
  思路：如果插入的位置有值，则探测后一个位置，如果还有值就继续探测，直到探测的位置 == m 表长为止
2. 拉链法：
指针数组 表长多长 指针数组就有多长
通过链表把冲突的关键字连起来 求平均查找长度

散列表的查找

*/
#define M 997
typedef char DataType;
typedef int KeyType;
typedef struct {     // 散列表里面的结点类型
  KeyType key;
  DataType data;
} NodeType;
typedef NodeType HashTable[M]; // 散列表类型
// 线性探查法解决冲突的查找方法
int HashSearch1(HashTable HT, KeyType K, int m){
  int d, temp;
  d = K % m;   // 求出散列地址
  temp = d;   // temp的作用就是哨兵，一个轮回下来再次查找到temp的时候 还没查找到，查找终止
  while(HT[d].key != -32768){
    if(HT[d].key == K){
      return d;
    }else{
      d = (d + 1) % m;
    }
    if(d == temp){
      return -1;
    }
  }
  return d;  // 最后返回的是空位的下标
}
// 线性探查法解决冲突的插入方法
int HashInsert1(HashTable HT, NodeType S, int m){
  int d = HashSearch1(HT, S.key, m);
  if(d == -1){     // 线性表已经已经满了 返回-1
    return -1;
  }else{
    if(HT[d].key == S.key){   // 这个位置有相同的值 返回-1
      return -1;
    }else{
      HT[d] = S;  // 
      return 0;
    }
  }
}
// 拉链法的数据结构
#include <iostream>
typedef struct node
{
  KeyType key;
  DataType data;
  struct node *next;  // 指向链表的头结点
}HTNode;
typedef HTNode *HT[M]; // 指针数组
// 查找方法
HTNode HashSearch2(HT T, KeyType K, int m){
  int d = K % m;
  HTNode *p = T[d];
  while(p != NULL && p->key != K){
    p = p->next;
  }
  return p;
}
// 插入 采用 头插法
int HashInsert2(HT T, HTNode *S, int m){
  int d;
  HTNode *p = HashSearch2(T, S->key, m);
  if(p!=NULL){   // 找得到，说明已经有相同的值在链表里面了返回0
    return 0;
  }else{         // 找不到，说明可以插入，这里用的头插法
    d = S->key % m;   // 算出散列地址
    S->next = T[d];
    T[d] = S;
    return 1;
  }
}
// 算出线性表探测法查找成功和失败的平均查找长度

// 算出拉链表探测法查找成功和失败的平均查找长度

// 算出二分查找法查找成功和失败的平均查找长度

// 装填因子 α = 结点个数n / 散列表长度m

// 小结：一般应付考试只需要掌握计算查找成功的平均查找长度就可以了
