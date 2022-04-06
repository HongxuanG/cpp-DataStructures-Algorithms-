void Merge(SeqList R, SeqList MR, int low, int m, int high){
  int i,j,k;
  i = low;
  j = m + 1;
  k = low;
  while(i <= m && j <= high){
    if (R[i].key <= R[j].key) {
      MR[k++] = R[i++];
    } else {
      MR[k++] = R[j++];
    }
  }
  while(i <= m){
    MR[k++] = R[i++];
  }
  while(j <= high){
    MR[k++] = R[j++];
  }
}
void MergePass(SeqList R, SeqList MR, int len, int n){
  int i, j;
  for (i = 1; i + 2 * len - 1 <= n;i=i+2*len){
    Merge(R, MR, i, i + len - 1, i + 2 * len - 1);
  }
  if(i+len - 1<n){
    Merge(R, MR, i, i + len - 1, n);
  }else{
    for (j = i; j <= n;j++){
      MR[j] =R[j];
    }
  }
}
void MergeSort(SeqList R, SeqList MR, int n){
  int len = 1;
  while(len<n){
    MergePass(R, MR, len, n);
    len = len * 2;
    MergePass(MR, R, len, n);
    len = len * 2;
  }
}
