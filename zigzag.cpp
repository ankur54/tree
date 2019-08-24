#include "bits/stdc++.h"
using namespace std;

typedef struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
} TreeNode;


vector<vector<int>> zigzagLevel(vector<TreeNode*> nodes, bool rev = false) {
    vector<int> curr;
    vector<TreeNode*> next;
    vector<vector<int>> levels;

    if(nodes.size() == 0) return levels;

    for(auto x:nodes) {
        curr.push_back(x->val);
        if(x->left) next.push_back(x->left);
        if(x->right) next.push_back(x->right);
    }

    if(rev) reverse(curr.begin(), curr.end());
    levels.push_back(curr);
    vector<vector<int>> nextLevels = zigzagLevel(next, ~rev);
    for(auto x:nextLevels) levels.push_back(x);

    return levels;
}

vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    vector<TreeNode*> currLevel;
    if(root) currLevel.push_back(root);
    return zigzagLevel(currLevel);
}