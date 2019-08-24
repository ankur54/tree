#include "bits/stdc++.h"
using namespace std;

typedef struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
} TreeNode;

typedef struct node {
    TreeNode* node;
    int depth;
} couple;

TreeNode* addOneRow(TreeNode* root, int v, int d) {
    if(!root) return NULL;
    if(d == 1) {
        TreeNode* node = new TreeNode(v);
        node->left = root;
        return node;
    }

    queue<couple> q;
    q.push({root, 1});
    while(!q.empty()) {
        couple temp = q.front();
        q.pop();

        if(temp.node) {
            q.push({temp.node->left, temp.depth + 1});
            q.push({temp.node->right, temp.depth + 1});
            
            if(temp.depth == d-1) {
                TreeNode* left = temp.node->left;
                TreeNode* right = temp.node->right;
                temp.node->left = new TreeNode(v);
                temp.node->right = new TreeNode(v);
                temp.node->left->left = left;
                temp.node->right->right = right;
            }

            if(temp.depth == d) break;
        }
    }

    return root;
}