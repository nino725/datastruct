#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct LNode{
    int data;
    struct LNode *next;
}LNode,*LinkList;

bool InitList(LinkList& L){
    L = (LNode*)malloc(sizeof(LNode));
    if(L == nullptr){
        return false;
    }
    /*
    不带头节点
    L = nullptr;
    */
    L->next = nullptr;
    return true;
}

int Length(LinkList& L){
    LNode *p = L;
    int len = 0;
    while(p->next != nullptr){
        p=p->next;
        len++;
    }
    return len;
}

LNode* GetElem(LinkList& L, int i){
    LNode *p = L;
    while(p != nullptr && i--){
        p = p->next;
    }
    return p;
}

LNode* LocateElem(LinkList& L, int e){
    LNode* p = L->next;
    while(p != nullptr && p->data != e){
        p = p->next;
    }
    return p;
}

bool InsertLNode(LinkList& L, int i, int e){
    int j = 0;
    LNode* p = L;
    while(p != nullptr && j < i - 1){
        p = p->next;
        j++;
    }
    if(p == nullptr){
        return false;
    }
    LNode* s = (LNode*)malloc(sizeof(LNode));
    s->data = e;
    s->next = p->next;
    p->next = s;
    return true;
}

bool InsertLNodePre(LinkList& L, int i, int e){
    int j = 0; 
    LNode* p = L;
    while(p != nullptr && j < i - 1){
        p = p->next;
        j++;
    }
    if(p == nullptr){
        return false;
    }

    LNode* s = (LNode*)malloc(sizeof(LNode));
    s->data = p->data;
    p->data = e;
    s->next = p->next;
    p->next = s;
    return true;
}

bool DeleteLNode(LinkList& L, int i, int& e){
    int j = 0;
    LNode* p = L;
    while(p->next != nullptr && j < i - 1){
        p = p->next;
        j++;
    }
    if(p->next == nullptr){
        return false;
    }
    LNode* q = p->next;
    e = q->data;
    p->next = q->next;
    free(q);
    return true;
}

bool DeleteLNodeNow(LinkList& L, int e){
    LNode* p = L->next;
    while(p->next != nullptr && p->data != e){
        p = p->next;
    }
    if(p->next == nullptr){
        return false;
    }
    LNode* q = p->next;
    p->data = q->data;
    p->next = q->next;
    free(q);
    return true;
}

LinkList List_headInsert(LinkList& L){
    L = (LNode*)malloc(sizeof(LNode));
    L->next = nullptr;
    int x;
    cin>>x;
    while(x != -1){
        LNode *s = (LNode*)malloc(sizeof(LNode));
        s->data = x;
        s->next = L->next;
        L->next = s;
        cin >> x;
    }
    return L;
}

LinkList List_TailInsert(LinkList& L){
    L = (LNode*)malloc(sizeof(LNode));
    LNode* p = L;
    int x;
    cin>>x;
    while(x != -1){
        LNode* s = (LNode*)malloc(sizeof(LNode));
        s->data = x;
        p->next = s;
        p = s;
        cin>>x;
    }
    p->next = nullptr;
    return L;
}

bool print(LinkList& L){
    if(L->next == nullptr){
        return false;
    }
    LNode* p = L->next;
    while(p != nullptr){
        cout<<p->data<<" ";
        p = p->next;
    }
    cout<<endl;
    return true;
}

int main() {
    LinkList L;
    List_headInsert(L);
    print(L);
    int e;
    DeleteLNode(L,3,e);
    print(L);
    return 0;
}