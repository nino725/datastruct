#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef struct SNode{
    int data[50];
    int top;
}SNode,*SqStack;

bool InitStack(SqStack& S){
    S->top = -1;
    return true;
}

bool isEmpty(SqStack S){
    return S->top == -1;
}

void push(SqStack S, int x){
    S->data[++S->top] = x;
}

int pop(SqStack S){
    int x = S->data[S->top--];
    return x;
}

int main() {
    SqStack S = new SNode;
    InitStack(S);
    cout<<isEmpty(S)<<endl;
    push(S,9);
    push(S,5);
    push(S,3);
    push(S,7);
    push(S,1);
    cout<<pop(S)<<endl;
    cout<<pop(S)<<endl;
    cout<<pop(S)<<endl;
    cout<<pop(S)<<endl;
    return 0;
}