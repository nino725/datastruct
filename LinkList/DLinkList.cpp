#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct DNode{
    int data;
    struct DNode *prior,*next;
}DNode,*DLinkList;

bool InitDLinkList(DLinkList& D){
    D = (DNode*)malloc(sizeof(DNode));
    D->prior = nullptr;
    D->next = nullptr;
    return true;
}

DLinkList List_headInsert(DLinkList& D){
    int x;
    cin>>x;
    while(x != -1){
        DNode *s = (DNode*)malloc(sizeof(DNode));
        s->data = x;
        s->next = D->next;
        if(D->next != nullptr){
            D->next->prior = s;
        }
        D->next = s;
        s->prior = D;
        cin >> x;
    }
    return D;
}

bool deleteDNode(DLinkList& D, int i, int& e){
    DNode* p = D;
    int j = 0;
    while(p->next != nullptr && j < i - 1){
        p=p->next;
        j++;
    }
    if(j != i - 1){
        return false;
    }
    DNode* q = p->next;
    p->next = q->next;
    q->next->prior = p;
    free(q);
    return true;
}

void print(DLinkList D){
    DNode *p = D->next;
    while(p != nullptr){
        cout<<p->data<<" ";
        p = p->next;
    }
    cout<<endl;
}

int main() {
    DLinkList D;
    //³õÊ¼»¯
    InitDLinkList(D);   
    print(List_headInsert(D)); 
    int e = 0;
    deleteDNode(D,3,e);
    print(D);
    return 0;
}