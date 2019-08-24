#include "bits/stdc++.h"
using namespace std;

typedef struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
} TreeNode;

unordered_map<TreeNode*, TreeNode*> parent;
unordered_set<TreeNode*> vis;

void dfs(TreeNode* root) {
    if(!root) return;
    if(root->left) parent[root->left] = root;
    if(root->right) parent[root->right] = root;
    dfs(root->left); dfs(root->right);
}

void findDistanceK(TreeNode* root, int k, vector<int> &ans) {
    if(!root) return;
    if(k == 0) {
        ans.push_back(root->val);
        return;
    }

    vis.insert(root);
    if(vis.find(root->left) == vis.end()) findDistanceK(root->left, k-1, ans);
    if(vis.find(root->right) == vis.end()) findDistanceK(root->right, k-1, ans);
    if(vis.find(parent[root]) == vis.end()) findDistanceK(parent[root], k-1, ans);
}

vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
    if(!root || !target) return vector<int> {};
    vector<int> ans;
    parent[root] = NULL;
    dfs(root);
    findDistanceK(target, k, ans);
    return ans;
}