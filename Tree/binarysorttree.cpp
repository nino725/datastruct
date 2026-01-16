#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//定义二叉搜素树
typedef struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr){}

}*searchTree;

//创建一颗二叉搜索树
TreeNode* createSearchTree();
//查找操作递归
TreeNode* searchVal(searchTree root, int val);
//查找操作迭代
TreeNode* searchValiteration(searchTree root, int val);
//插入操作递归
TreeNode* insertVal(TreeNode* root,int val);
//插入操作迭代
TreeNode* insertValilteration(TreeNode* root, int val);
//删除一个节点
TreeNode* deleteNode(TreeNode* root, int val);
TreeNode* findMin(TreeNode* root);
int main() {
    
    return 0;
}

TreeNode* createSearchTree(){
    int val;
    cin>>val;
    if(val == -1){
        return nullptr;
    }
    TreeNode* root = new TreeNode(val);
    root->left = createSearchTree();
    root->right = createSearchTree();
    return root;
}

TreeNode* searchVal(searchTree root, int val){
    if(root == nullptr){
        return root;
    }
    if(root->val == val){
        return root;
    }
    if(val < root->val){
        return searchVal(root->left,val);
    }
    return searchVal(root->right,val);
}

TreeNode* searchValiteration(searchTree root, int val){
    TreeNode* p = root;
    while(p!=nullptr && p->val != val){
        if(p->val > val){
            p=p->left;
        }else{
            p=p->right;
        }
    }
    return p;
}

TreeNode* insertVal(TreeNode* root,int val){
    if(root == nullptr){
        return new TreeNode(val);
    }
    if(val < root->val){
        root->left = insertVal(root->left, val);
    }else{
        root->right = insertVal(root->right,val);
    }
    return root;
}

TreeNode* insertValilteration(TreeNode* root, int val){
    TreeNode* parent = root;
    if(root == nullptr){
        return new TreeNode(val);
    }

    TreeNode* p = root;
    while(p != nullptr && p->val != val){
        parent = p;
        if(p->val > val){
            p = p->left;
        }else if(p->val < val){
            p = p->right;
        }else{
            return root;
        }
    }

    TreeNode* s = new TreeNode(val);
    if(val < parent->val){
        parent->left = s;
    }else{
        parent->right = s;
    }

    return root;
}

/*
删除二叉排序树的不同情况
由于二叉排序树始终是遵循左<根<右，所以删除时产生了不同的情况
1.删除的节点为叶子节点，直接删除即可，无需考虑删除之后的顺序问题。

2.被删除的节点只有一个孩子，直接让他的孩子替代他的位置

3.被删除的节点有两个孩子。
可以用其中序后继或者中序前驱来替代他的位置
左边最靠右，右边最靠左。
*/

//找到中序后继
TreeNode* findMin(TreeNode* root){
    while(root && root->left){
        root = root->left;
    }
    return root;
}
TreeNode* deleteNode(TreeNode* root, int val){
    if(root == nullptr){
        return nullptr;
    }

    if(root->val > val){
        root->left = deleteNode(root->left,val);
    }else if(root->val < val){
        root->right = deleteNode(root->right,val);
    }else{
        if(root->left == nullptr){
            TreeNode* temp = root->right;
            delete root;
            return temp;
        }else if(root->right == nullptr){
            TreeNode* temp = root->left;
            delete root;
            return temp;
        }

        TreeNode* temp = findMin(root->right);
        root->val = temp->val;
        root->right = deleteNode(root->right,temp->val);
    }
    return root;
}