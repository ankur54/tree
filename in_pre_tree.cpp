#include "bits/stdc++.h"
using namespace std;

typedef struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
}TreeNode;

int search(vector<int> arr, int strt, int end, int value) { 
    int i; 
    for (i = strt; i <= end; i++) { 
        if (arr[i] == value) 
            break; 
    } 
    return i; 
} 

TreeNode* buildTreeUtil(vector<int> inorder, vector<int> postorder, int in_start, int in_end, int* pIdx) {
    if(in_start > in_end) return NULL;
    int root = postorder[*pIdx];
    (*pIdx)++;
    TreeNode* node = new TreeNode(root);

    if(in_start == in_end) return node;

    int rootPos = search(inorder, in_start, in_end, root);
    node->left = buildTreeUtil(inorder, postorder, in_start, rootPos-1, pIdx);
    node->right = buildTreeUtil(inorder, postorder, rootPos+1, in_end, pIdx);
    return node;
}

TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    if(!inorder.size() || !postorder.size()) return NULL;
    int n = inorder.size();
    int pIdx = 0;
    return buildTreeUtil(inorder, postorder, 0, n - 1, &pIdx);
}