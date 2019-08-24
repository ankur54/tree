#include "bits/stdc++.h"
using namespace std;

typedef struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
} TreeNode;


int inorderSuccessor(TreeNode* root, int n) {
    if(!root) return NULL;

    TreeNode* temp = root;
    int next;
    while(!temp && temp->val != n) {
        if(temp->val > n) next = temp->val, temp = temp->left;
        else temp = temp->right;
    }
    
    if(!temp) return NULL;
    if(!temp->right) return next;
    
    temp = temp->right;
    while(temp->left) temp = temp->left;
    return temp->val;
} 