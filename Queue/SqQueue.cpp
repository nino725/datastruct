#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct LinkNode{
    int data;
    struct LinkNode* next;
}LinkNode;
typedef struct{
    LinkNode *front,*rear;
}SeqQueue;

void InitQueue(SeqQueue& Q){
    Q.front = Q.rear = (LinkNode*)malloc(sizeof(LinkNode));
    Q.front->next = nullptr;
}

bool QueueEmpty(SeqQueue Q){
    if(Q.front == Q.rear){
        return true;
    }
    return false;
}

void PushQueue(SeqQueue& Q, int x){
    LinkNode *s = (LinkNode*)malloc(sizeof(LinkNode));
    s->data = x;
    Q.rear->next = s;
    s->next = nullptr;
    Q.rear = s;
}

bool PopQueue(SeqQueue& Q,int& x){
    if(QueueEmpty(Q)){
        return false;
    }
    LinkNode* s = Q.front->next;
    x = s->data;
    Q.front->next = s->next;
    if(Q.rear == s){
        Q.rear = Q.front;
    }
    free(s);
    return true;
}

int main() {
    SeqQueue Q;
    InitQueue(Q);
    PushQueue(Q,3);
    PushQueue(Q,8);
    PushQueue(Q,5);
    PushQueue(Q,1);
    PushQueue(Q,7);
    int x;
    PopQueue(Q,x);
    cout<<x<<endl;
    PopQueue(Q,x);
    cout<<x<<endl;
    PopQueue(Q,x);
    cout<<x<<endl;
    PopQueue(Q,x);
    cout<<x<<endl;
    return 0;
}

