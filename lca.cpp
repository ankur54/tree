#include "bits/stdc++.h"
using namespace std;

typedef struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
}TreeNode;

TreeNode* lca = NULL;

bool recurseTree(TreeNode* root, int p, int q) {
    if(!root) return false;
    int left = recurseTree(root->left, p, q) ? 1 : 0;
    int right = recurseTree(root->right, p, q) ? 1 : 0;
    int porq = (root->val == p || root->val == q) ? 1 : 0;

    if(porq && p == q) lca = root;
    else if(left + right + porq >= 2) lca = root;
    return (left | right | porq);
}

int lowestCommonAncestor(TreeNode* root, int p, int q) {
    recurseTree(root, p, q);
    int ans = (!lowestCommonAncestor) ? -1 : lca->val;
    lca = NULL;
    return ans;
}