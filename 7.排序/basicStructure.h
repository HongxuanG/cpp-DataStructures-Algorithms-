#define MAXSIZE 100
typedef int KeyType;
typedef struct {
  KeyType key;
  InfoType otherinfo;

} RecType; 
typedef RecType SeqList[MAXSIZE + 1]; // 0 元素空着或者作为哨兵单元
SeqList R;      // 一个数组
