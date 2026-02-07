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


//一.返回最小，并用最后替代
bool deleteMinNum(SqList& L,ElemType& e){
    if(L.length == 0){
        return false;
    }
    int flag = 0;
    for(int i = 0; i < L.length; i++){
        if(L.data[i] < L.data[flag]){
            flag = i;
        }
    }
    e = L.data[flag];
    L.data[flag] = L.data[L.length - 1];
    return true;
}

//二.逆序排列
bool reverseNum(SqList& L){
    if(L.length == 0){
        return false;
    }
    for(int i = 0; i < L.length / 2; i++){
        ElemType temp = L.data[i];
        L.data[i] = L.data[L.length - i - 1];
        L.data[L.length - i - 1] = temp;
    }
    return true;
}

//三
bool deleteX(SqList& L,ElemType x){
    //n为长度
    int n = L.length;
    if(n <= 0){
        return false;
    }
    int j = 0;
    for(int i = 0; i < n; i++){
        if(L.data[i] != x){
            L.data[j++] = L.data[i];
        }
    }
    n = j;
    return true;
}

//四
bool deleteSToT(SqList& L, ElemType s, ElemType t){
    if(L.length == 0){
        return false;
    }
    if(s >= t){
        return false;
    }
    for(int i = 0; i < L.length; i++){
        if(L.data[i] >= s && L.data[i] <= t){
            for(int j = i + 1; j < L.length; j++){
                L.data[j-1] = L.data[j];
                L.length--;
            }
        }
    }
    return true;
}

//五。
bool deleteSame(SqList& L){
    if(L.length == 0){
        return false;
    }
    for(int i = 1; i < L.length; i++){
        if(L.data[i] == L.data[i-1]){
            for(int j = i + 1; j < L.length; j++){
                L.data[j-1] = L.data[j];
                L.length--;
            }
        }
    }
    return true;
}

//6
bool merge(SqList P, SqList Q,SqList& S){
    if(P.length + Q.length > S.MAXSIZE){
        return false;
    }
    int i = 0, j = 0;
    while(i < P.length && j < Q.length){
        if(P.data[i] <= Q.data[i]){
            S.data[S.length++] = P.data[i]; 
        }else{
            S.data[S.length++] = Q.data[i];
        }
    }
    while(i != P.length){
        S.data[S.length++] = P.data[i++];
    }
    while(j != Q.length){
        S.data[S.length++] = Q.data[j++];
    }
    return true;
}