#include <iostream>
using namespace std;

#define MaxSize 50
#define ElemType int
typedef struct{
    ElemType data[MaxSize];
    int length;
}SqList;
void initList(SqList& L);

typedef struct{
    ElemType *data;
    int length;
    int Size;
}SeqList;
void initSeqList(SeqList& L);

int main() {
    
    return 0;
}

void initList(SqList& L){
    L.length = 0;
}

void initSeqList(SeqList& L){
    L.data = new int[MaxSize];
    //L.data = (ElemType*)malloc(MaxSize*sizeof(ElemType));
    L.length = 0;
    L.Size = MaxSize;
}