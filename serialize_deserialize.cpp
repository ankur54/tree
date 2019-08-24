#include "bits/stdc++.h"
using namespace std;

typedef struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
} TreeNode;


string serialize(TreeNode* root) {
    if(!root) return "#";
    return to_string(root->val) + "," + serialize(root->left) + "," + serialize(root->right);
}

TreeNode* deserializeHelper(vector<int> &nodes, int *pos) {
    if(nodes[*pos] == '#') return NULL;
    TreeNode* root = new TreeNode(nodes[*pos]);
    (*pos)++;

    root->left = deserializeHelper(nodes, pos);
    root->right = deserializeHelper(nodes, pos);
    return root;
}

TreeNode* deserialize(string s) {
    int n = s.length();
    int pos = 0;
    vector<int> arr;
    for(int i = 0; i < n; i++) 
        if(s[i] != ',') arr.push_back(s[i]-'0');
    return deserializeHelper(arr, &pos);
}