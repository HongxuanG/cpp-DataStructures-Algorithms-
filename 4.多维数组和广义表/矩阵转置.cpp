void trsmat(int a[5][8], int b[8][5], int m,int n){
  int i, j;
  for (i = 0; i < m;i++){
    for (j = 0; j < n;j++){
      b[j][i] = a[i][j];
    }
  }
}
