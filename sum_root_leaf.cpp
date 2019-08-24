#include "bits/stdc++.h"
using namespace std;

typedef struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
}TreeNode;


vector<int> addition(vector<int> var1, vector<int> var2) {
    if(var1.size() && var2.size()) {
        vector<int> res;
        reverse(var1.begin(), var1.end());
        reverse(var2.begin(), var2.end());

        int carry = 0;
        int n = min(var1.size(), var2.size());
        int i;
        
        for(i = 0; i < n; i++) {
            res.push_back((var1[i]+var2[i]+carry)%10);
            carry = (var1[i]+var2[i]+carry)/10;
        }
        
        while(i < var1.size()) {
            res.push_back((var1[i]+carry)%10);
            carry = (var1[i]+carry)/10;
            i++;
        }
        while(i < var2.size()) {
            res.push_back((var2[i]+carry)%10);
            carry = (var2[i]+carry)/10;
            i++;
        }
        
        if(carry) res.push_back(carry);
        reverse(res.begin(), res.end());
        return res;
    } 
    else if(var1.size()) return var1;
    else if(var2.size()) return var2;
    return vector<int>{};
}

vector<vector<int>> dfs(TreeNode* root, vector<int> path = {}) {
    vector<vector<int>> paths;
    path.push_back(root->val);
    
    if(!root->left && !root->right) {
        paths.push_back(path);
        return paths;
    }

    vector<vector<int>> left, right;
    if(root->left) left = dfs(root->left, path);
    if(root->right) right = dfs(root->right, path);
    for(auto x:left) paths.push_back(x);
    for(auto x:right) paths.push_back(x);
    return paths;
}

int sumNumber(TreeNode* root) {
    if(!root) return 0;
    
    vector<vector<int>> paths = dfs(root);
    vector<int> sum{};
    for(auto path: paths) sum = addition(path, sum); 
    int s = 0;
    for(auto x:sum) s = s*10 + x;
    return s;
}