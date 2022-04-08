// 每年必考
// 递归写法
int BinSearch(SeqList R, KeyType k, int low, int high){
  int mid;
  if(low <= high){
    mid = (low + high) / 2;
    if(R[mid].key == k){
      return mid;
    }else if(R[mid].key > k){
      return BinSearch(R, k, low, mid - 1);
    }else if(R[mid].key < k){
      return BinSearch(R, k, mid + 1, high);
    }
  }
  else
  {
    return 0;
  }
}
// 非递归写法，内部用while循环
int BinSearch1(SeqList R, KeyType k, int n){
  int mid, low = 1, high = n;
  while(low <= high){
    mid = (low + high) / 2
    if(R[mid].key == k){
      return mid;
    }
    else if (R[mid].key > k)
    {
      high = mid - 1;
    }
    else if (R[mid].key < k)
    {
      low = mid + 1;
    }
  }
  return 0;
}
