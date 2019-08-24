#include "bits/stdc++.h"
using namespace std;

typedef struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
}TreeNode;

class Solution {
public:
    bool helper_recursive(TreeNode* root, int lower = INT_MAX, int upper = INT_MIN) {
        if(!root) return true;
        if(lower != INT_MAX && root->val < lower) return false;
        if(upper != INT_MIN && root->val > upper) return false;
        return (helper_recursive(root->left, lower, root->val) & 
            helper_recursive(root->right, root->val, upper));
    }

    bool helper_iterative(TreeNode* root) {
        if(!root) return true;
        queue<long> lower, upper;
        queue<TreeNode*> node;
        node.push(root);
        lower.push(LONG_MAX), upper.push(LONG_MIN);

        while(!node.empty()) {
            TreeNode* treenode = node.front();
            int l = lower.front();
            int r = upper.front();

            if(l != LONG_MAX && treenode->val <= l) return false;
            if(r != LONG_MAX && treenode->val >= r) return false;

            node.push(treenode->left), lower.push(l), upper.push(treenode->val);
            node.push(treenode->right), lower.push(treenode->val), upper.push(r);
            node.pop(), lower.pop(), upper.pop();
        }
        return true;
    }

    bool isValidBST(TreeNode* root) {
        // return (!root || (root->val > lower && root->val < upper && isValidBST(root->left, lower, root->val) && isValidBST(root->left, root->val, upper)));
    }
};

void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

TreeNode* stringToTreeNode(string input) {
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    if (!input.size()) {
        return nullptr;
    }

    string item;
    stringstream ss;
    ss.str(input);

    getline(ss, item, ',');
    TreeNode* root = new TreeNode(stoi(item));
    queue<TreeNode*> nodeQueue;
    nodeQueue.push(root);

    while (true) {
        TreeNode* node = nodeQueue.front();
        nodeQueue.pop();

        if (!getline(ss, item, ',')) {
            break;
        }

        trimLeftTrailingSpaces(item);
        if (item != "null") {
            int leftNumber = stoi(item);
            node->left = new TreeNode(leftNumber);
            nodeQueue.push(node->left);
        }

        if (!getline(ss, item, ',')) {
            break;
        }

        trimLeftTrailingSpaces(item);
        if (item != "null") {
            int rightNumber = stoi(item);
            node->right = new TreeNode(rightNumber);
            nodeQueue.push(node->right);
        }
    }
    return root;
}

string boolToString(bool input) {
    return input ? "True" : "False";
}

int main() {
    string line;
    while (getline(cin, line)) {
        TreeNode* root = stringToTreeNode(line);
        
        bool ret = Solution().isValidBST(root);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}