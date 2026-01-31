#include <iostream>
using namespace std;
#define InitSize 10
#define size 10

//线性表从一开始数

//静态分配
struct SqList{
    int data[InitSize];
    int length;
};
void initList(SqList &L);
bool insertSqList(SqList &L, int i, int e);
int findVal(SqList L, int val);
bool deleteSqList(SqList& L, int e);

//动态分配
struct SeqList{
    int *data;
    int length;
    int MaxSize;
};
void initSeqList(SeqList &L);
bool increaseSeqList(SeqList& L);
bool insertSeqList(SeqList& L, int i, int e);

int main(){
    return 0;
}

void initSqList(SqList &L){
    for(int i = 0; i < InitSize; i++){
        L.data[i] = 0;
    }
    L.length = 0;
}

bool insertSqList(SqList &L, int i, int e){
    if(L.length >= InitSize){
        return false;
    }
    if(i < 1 || i > L.length + 1){
        return false;
    }
    for(int j = L.length; j >= i; j--){
        L.data[j] = L.data[j-1];
    }
    L.data[i-1] = e;
    L.length++;
    return true;
}

int findVal(SqList L, int val){
    for(int i = 0; i < L.length; i++){
        if(L.data[i] == val){
            return i + 1;
        }
    }
    return -1;
}

bool deleteSqList(SqList& L, int e){
    int i = findVal(L,e);
    if(i == -1){
        return false;
    }
    for(int j = i; j <= L.length; j++){
        L.data[j-1] = L.data[j];
    }
    L.length--;
    return true;
}
    
void initSeqList(SeqList &L){
    L.data = new int[InitSize];
    L.length = 0;
    L.MaxSize = InitSize;
}

bool increaseSeqList(SeqList& L){
    L.MaxSize += size;
    int* temp = new int[L.MaxSize];
    if(temp == nullptr){
        return false;
    }
    for(int i = 0; i < L.length; i++){
        temp[i] = L.data[i];
    }
    delete[] L.data;
    L.data = temp;
    return true;
}

bool insertSeqList(SeqList& L, int i, int e){
    if(i < 1 || i > L.length + 1){
        return false;
    }
    if(L.length == L.MaxSize){
        increaseSeqList(L);
    }
    for(int j = L.length; j >= i; j--){
        L.data[j] = L.data[j-1];
    }
    L.data[i-1] = e;
    L.length++;
    return true;
}

