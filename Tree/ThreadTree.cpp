#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct ThreadNode{
    int data;
    struct ThreadNode *left, *right;
    int ltag, rtag;
}ThreadNode,*ThreadTree;


//创建一棵树同时初始化线索指针
ThreadTree createTree(ThreadTree& T){
    int val;
    cout<<"请输入节点的值："<<endl;
    cin >> val;
    if(val == -1){
        return nullptr;
    }
    T = (ThreadNode*)malloc(sizeof(ThreadNode));
    T->data = val;

    T->ltag = 0;
    T->rtag = 0;

    T->left = createTree(T->left);
    T->right = createTree(T->right);
    return T;
}

ThreadNode* pre = nullptr;
//初始化当前节点
void ThreadNodeNow(ThreadNode* T){
    if(T->left == nullptr){
        T->left = pre;
        T->ltag = 1;
    }
    if(pre != nullptr && pre->right == nullptr){
        pre->right = T;
        pre->rtag = 1;
    }
    pre = T;
}

void createInThread(ThreadTree& T){ //中序线索化
    if(T != nullptr){
        createInThread(T->left); //找到第一个节点
        ThreadNodeNow(T);
        createInThread(T->right);
    }
}

void createPreThread(ThreadTree& T){
    if(T == nullptr){
        return;
    }
    ThreadNodeNow(T);
    if(T->ltag == 0){
        createPreThread(T->left);
    }
    if(T->rtag == 0){
        createPreThread(T->right);
    }
}

void createPostThread(ThreadTree& T){
    if(T == nullptr){
        return;
    }
    createPostThread(T->left);
    createPostThread(T->right);

    ThreadNodeNow(T);
}

void InPrint(ThreadTree T){
    if(T == nullptr){
        return;
    }
    InPrint(T->left);
    cout<<T->data<<" ";
    InPrint(T->right);
}

//中序线索遍历
ThreadNode* FirstNode(ThreadNode* T){
    ThreadNode* p = T;
    while(p->ltag == 0){
        p = p->left;
    }
    return p;
}
ThreadNode* NextNode(ThreadNode* T){
    if(T->rtag == 0){
        return FirstNode(T->right);
    }
    return T->right;
}
void InThread(ThreadTree T){
    ThreadNode* p = FirstNode(T);
    while(p != nullptr){
        cout<<p->data<<" ";
        p = NextNode(p);
    }
}

//先序线索遍历
void preThreadPrint(ThreadTree T){
    ThreadNode* p = T;
    while(p != nullptr){
        cout<<p->data<<" ";
        if(p->ltag == 0){
            p = p->left;
        }else{
            p = p->right;
        }
    }
}

int main() {
    ThreadTree T; /* 3 1 4 -1 -1 1 -1 -1 5 9 2 -1 -1 -1 6 -1 -1*/
    createTree(T);
    createPreThread(T);
    if(pre != nullptr){
        pre->right = nullptr;
        pre->rtag = 1;
    }
    preThreadPrint(T);
    return 0;
}