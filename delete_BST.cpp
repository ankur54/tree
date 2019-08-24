#include "bits/stdc++.h"
using namespace std;

typedef struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
} TreeNode;

TreeNode* search(TreeNode* root, int key) {
    if(!root) return NULL;
    if(root->val == key) return root;
    if(key < root->val) return search(root->left, key);
    return search(root->right, key);
}

TreeNode* insert(TreeNode* root, TreeNode* node) {
    if(!root) return node;
    if(!node) return root;
    if(root->val < node->val) root->right = insert(root->right, node);
    else root->left = insert(root->left, node);
    return root;
}

TreeNode* findParent(TreeNode* root, TreeNode* node) {
    if(!root | root->val == node->val) return NULL;
    if((root->left && root->left->val == node->val) || (root->right && root->right->val == node->val)) return root;
    if(root->val > node->val) return findParent(root->left, node);
    return findParent(root->right, node);
}


TreeNode* deleteNode(TreeNode* root, int key) {
    if(!root) return NULL;
    
    TreeNode* subtree = search(root, key);
    if(!subtree) return root;

    TreeNode* parent = findParent(root, subtree);
    if(!parent) {
        if(subtree->right) {
            TreeNode* left = subtree->left;
            subtree = subtree->right;
            if(left) insert(subtree, left);
            return subtree;
        } else return subtree->left;
    }

    if(parent->left == subtree) {
        if(subtree->right) {
            TreeNode* left = subtree->left;
            parent->left = subtree->right;
            if(subtree->right->left) left = insert(subtree->left, subtree->right->left);
            parent->left->left = left;
        }
        else parent->left = subtree->left;
    } else {
        if(subtree->left) {
            TreeNode* right = subtree->right;
            parent->right = subtree->left;
            if(subtree->left->right) right = insert(subtree->right, subtree->left->right);
            parent->right->right = right;
        }
        else parent->right = subtree->right;
    }

    return root;
}


/*[8,0,31,null,6,28,45,1,7,25,30,32,49,null,4,null,null,9,26,29,null,null,42,47,null,2,5,null,12,null,27,null,null,41,43,46,48,null,3,null,null,10,19,null,null,33,null,null,44,null,null,null,null,null,null,null,11,18,20,null,37,null,null,null,null,14,null,null,22,36,38,13,15,21,24,34,null,null,39,null,null,null,16,null,null,23,null,null,35,null,40,null,17] */