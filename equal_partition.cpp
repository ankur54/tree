#include "bits/stdc++.h"
using namespace std;

typedef struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
}TreeNode;

int sum(TreeNode* root, vector<int> &nodeSum) {
    if(!root) return 0;
    nodeSum.push_back(sum(root->left, nodeSum) + sum(root->right, nodeSum) + root->val);
    return nodeSum[nodeSum.size() - 1];
}

bool equalPartition(TreeNode* root) {
    vector<int> nodeSum;
    int total = sum(root, nodeSum);
    nodeSum.pop_back();

    if(total%2 == 0)
        for(auto x: nodeSum) 
            if(x = total-x) return true;

    return false;
}