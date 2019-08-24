#include "bits/stdc++.h"
using namespace std;

typedef struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
} TreeNode;

typedef struct triple {
    int val, left, right; 
} triple;

int t;
unordered_map<string, int> getUID;
unordered_map<int, int> uidCount;

int uniqueID(TreeNode* root, vector<TreeNode*> &ans) {
    if(!root) return 0;
    string serial = to_string(root->val) + "," + to_string(uniqueID(root->left, ans)) + "," + to_string(uniqueID(root->right, ans));
    // triple serial = {root->val, uniqueID(root->left, ans), uniqueID(root->right, ans)};
    int uid = getUID[serial];
    if(uid == 0) uid = getUID[serial] = ++t;
    ++uidCount[uid];
    if(uidCount[uid] == 2) ans.push_back(root);
    return uid;
}

vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
    if(!root) return vector<TreeNode*> {};
    vector<TreeNode*> duplicate;
    uniqueID(root, duplicate);
    return duplicate;
}