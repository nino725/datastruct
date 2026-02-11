#include <iostream>
#include <vector>
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

//7
bool reverseNum(SqList& L,int l,int r){
    if(l > r){
        return false;
    }
    for(int i = 0; i < (r - l + 1) / 2; i++){
        ElemType temp = L.data[i + l];
        L.data[i + l] = L.data[r - i];
        L.data[r - i] = temp;
    }
    return true;
}

bool reverseBtoA(SqList& A, int m, int n){
    reverseNum(A,0,m+n-1);
    reverseNum(A,0,m-1);
    reverseNum(A,m,m+n-1);
    return true;
}

//8
void BS(int arr[],int x){
    int l = 0, r = arr.size() - 1;
    while(l <= r){
        int mid = (l + r) / 2;
        if(arr[mid] < x){
            l = mid + 1;
        }else{
            r = mid - 1;
        }
    }
    if(arr[l] == x && l != r - 1){
        int temp = arr[l+1];
        arr[l] = arr[l+1];
        arr[l+1] = temp;
    }else{
        for(int i = r; i >= l; i--){
            arr[i+1] = arr[i];
        }
        arr[l] = x;
    }
}

//9
/*
算法思想：
A [1,4,6,7,8,9]
B [1,2,4,5,6,8]
C [2,3,5,6,7,8]

*/

void findTheSame(int A[],int B[],int C[]){
    int n;
    vector<int> ans;
    int i = 0, j = 0, k = 0;
    int max_num = 0;
    while(i < n && j < n && k < n){
        int x = A[i] > B[j] ? A[i] : B[j];
        max_num = x > C[k] ? x : C[k];

        while(i < n && A[i] < max_num){
            i++;
        }
        while(j < n && B[j] < max_num){
            j++;
        }
        while(k < n && C[k] < max_num){
            k++;
        }
        if(A[i] == B[j] && B[j] == C[k]){
            ans.push_back(A[i]);
            i++;
            j++;
            k++;
        }
        for(int p = 0; i < n; i++){
            cout<<p<<endl;
        }
    }
}

