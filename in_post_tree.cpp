#include "bits/stdc++.h"
using namespace std;

typedef struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
}TreeNode;


TreeNode* buildTreeUtil(vector<int> &inorder, vector<int> &postorder, int in_start, int in_end, int* pIdx, unordered_map<int,int> &mp) {
    if(in_start > in_end) return NULL;
    int root = postorder[*pIdx];
    (*pIdx)--;
    TreeNode* node = new TreeNode(root);

    if(in_start == in_end) return node;

    int rootPos = mp[root];
    node->right = buildTreeUtil(inorder, postorder, rootPos+1, in_end, pIdx, mp);
    node->left = buildTreeUtil(inorder, postorder, in_start, rootPos-1, pIdx, mp);
    return node;
}

TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    if(!inorder.size() || !postorder.size()) return NULL;

    unordered_map<int, int> inMap;
    int n = inorder.size();
    for(int i = 0; i < n; i++) inMap[inorder[i]] = i;
    int pIdx = n-1;
    return buildTreeUtil(inorder, postorder, 0, n - 1, &pIdx, inMap);
}