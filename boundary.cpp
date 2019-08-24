#include "bits/stdc++.h"
using namespace std;

typedef struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
} TreeNode;

void leftBoundaryTraversal(TreeNode* root) {
    if(root) {
        cout << root->val << " ";
        leftBoundaryTraversal(((root->left) ? root->left : root->right));
    }
}

void leftBoundaryTraversal(TreeNode* root) {
    if(root) {
        leftBoundaryTraversal(((root->right) ? root->right : root->left));
        cout << root->val << " ";
    }
}

void leafTraversal(TreeNode* root) {
    if(root) {
        leafTraversal(root->left);
        if(!(root->left) && !(root->right)) cout << root->data << " ";
        leafTraversal(root->right);
    }
}

void boundaryTraversal(TreeNode* root) {
    if(!root) return;

    cout << root->data << " ";
    leftBoundaryTraversal(root->left);
    leafTraversal(root);
    rightBoundaryTraversal(root->right);
}