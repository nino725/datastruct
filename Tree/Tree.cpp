#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <unordered_map>

using namespace std;
#define Elemtype int
typedef struct BiTNode{
    Elemtype data;
    struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;

BiTree createBiTree(BiTree& root){
    int val;
    cin>>val;
    if(val == -1){
        return nullptr;
    }

    root = (BiTNode*)malloc(sizeof(BiTNode));
    root->data = val;
    root->lchild = createBiTree(root->lchild);
    root->rchild = createBiTree(root->rchild);
    return root;
}
unordered_map<int,int> index_num;
BiTree preIn(vector<int> preorder, int pre_s, int pre_e,vector<int> inorder, int in_s, int in_e){
    if(pre_s > pre_e){
        return nullptr;
    }
    int val = preorder[pre_s];
    BiTNode* root = (BiTNode*)malloc(sizeof(BiTNode));
    root->data = val;

    int index_in = index_num[val];

    int left_size = index_in - in_s;

    root->lchild = preIn(preorder, pre_s + 1, pre_s + left_size, inorder, in_s, index_in - 1);

    root->rchild = preIn(preorder, pre_s + left_size + 1, pre_e, inorder, index_in + 1, in_e);

    return root;

}

BiTree BuildTreePreIn(vector<int> preorder, vector<int> inorder){
    int n = inorder.size();
    for(int i = 0; i < n; i++){
        index_num[inorder[i]] = i;
    }
    return preIn(preorder,0,n-1,inorder,0,n-1);
}


void InPrint(BiTree T){
    if(T == nullptr){
        return;
    }
    cout<<T->data<<" ";
    InPrint(T->lchild);
    InPrint(T->rchild);
}

void LevelOrder(BiTree T){
    queue<BiTNode*> q;
    q.push(T);
    while(!q.empty()){
        BiTNode* p = q.front();
        q.pop();
        cout<<p->data<<" ";
        if(p->lchild != nullptr) q.push(p->lchild);
        if(p->rchild != nullptr) q.push(p->rchild);
    }
}

int main() {
    vector<int> preorder = {1, 2, 4, 7, 3, 5, 8, 9, 6, 10};
    vector<int> inorder = {4, 7, 2, 1, 8, 5, 9, 3, 6, 10};
    vector<int> suforder;
    BiTree T;
    T = BuildTreePreIn(preorder, inorder);
    // createBiTree(T);
    // InPrint(T);
    LevelOrder(T);
    return 0;
}