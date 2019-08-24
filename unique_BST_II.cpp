#include "bits/stdc++.h"
using namespace std;

typedef struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
} TreeNode;

vector<TreeNode*> uniqueBSTUtil(int start, int end) {
    if(start > end) return vector<TreeNode*> {NULL};

    vector<TreeNode*> tree;
    for(int i = start; i <= end; i++) {
        vector<TreeNode*> left = uniqueBSTUtil(start, i - 1);
        vector<TreeNode*> right = uniqueBSTUtil(i + 1, end);
        for(auto l: left) {
            for(auto r: right) {
                TreeNode* root = new TreeNode(i);
                root->left = l;
                root->right = r;
                tree.push_back(root);
            }
        }
    }

    return tree;
}