#include <iostream>
using namespace std;

#define MaxSize 50
#define ElemType int
typedef struct{
    ElemType data[MaxSize];
    int length;
}SqList;
void initList(SqList& L);
bool ListInsert(SqList &L, int i, ElemType e);
bool ListDelete(SqList& L, int i, ElemType& e);

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

bool ListInsert(SqList &L, int i, ElemType e){
    if(i < 1 || i > L.length + 1){
        return false;
    }
    if(L.length >= MaxSize){
        return false;
    }
    for(int j = L.length; j >= i; j--){
        L.data[j] = L.data[j-1];
    }
    L.data[i-1] = e;
    L.length++;
    return true;
}

bool ListDelete(SqList& L, int i, ElemType& e){
    if(i < 1 || i > L.length){
        return false;
    }
    e = L.data[i-1];
    for(int j = i; j < L.length; j++){
        L.data[j-1] = L.data[j];
    }
    L.length--;
    return true;
}