#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;
int find_num(int A[], int n);
int main() {
    int A[] = {1,3,2,3};
    cout<<find_num(A,4);
    return 0;
}

int find_num(int A[], int n){
    int max_num = 0;
    for(int i = 0; i < n; i++){
        max_num = max(A[i], max_num);
    }
    if(max_num == 0){
        return 1;
    }
    int cnt[max_num + 1];
    for(int i = 0; i < n; i++){
        cnt[A[i]]++;
    }
    for(int i = 0; i <= max_num; i++){
        if(cnt[i] == 0){
            return i;
        }
    }
    return max_num + 1;
}

int findMissMin(int A[], int n){
    int i, *B;
    B = (*int)malloc(sizeof(int)*n);
    memset(B,0,sizeof(n));
    for(i = 0; i < n; i++){
        if(A[i] > 0 && A[i] <= n){
            B[A[i] - 1] = 1;
        }
    }
    for(i = 0; i < n; i++){
        if(B[i] == 0) break;
    
    }
    return i+1;
}