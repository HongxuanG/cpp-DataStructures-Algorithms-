#define ListSize 100
typedef int DataType;
typedef struct 
{
  DataType data[ListSize];
  int length;
} SeqList;

void MaxMin(SeqList L,DataType *max, DataType *min, int *k,int *j){
  int i;
  *max = L.data[0];
  *min = L.data[0];
  *k = *j = 1;
  for (i = 0; i < L.length;i++){
    if(L.data[i] > *max){
      *max = L.data[i];
      *k = i;
    }
    if(L.data[i] < *min){
      *min = L.data[i];
      *j = i;
    }
  }
}
int main(){

}