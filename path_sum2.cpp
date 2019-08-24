#include "bits/stdc++.h"
using namespace std;

typedef struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
} TreeNode;


vector<vector<int>> pathSum(TreeNode* root, int sum, vector<int> path = {}) {
    vector<vector<int>> paths;
    if(!root) return paths;
    path.push_back(root->val);

    if(!root->left && !root->right && sum == root->val) {
        paths.push_back(path);
        return paths;
    }

    vector<vector<int>> left, right;

    left = pathSum(root->left, sum-root->val, path);
    right = pathSum(root->right, sum-root->val, path);

    for(auto x: left) paths.push_back(x);
    for(auto x: right) paths.push_back(x);
    return paths;
}