#include "bits/stdc++.h"
using namespace std;

typedef struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
}TreeNode;

typedef struct Node {
    TreeNode* head;
    long long int pos, level;
    Node(TreeNode* h, long long int l, long long int p) : head(h), level(l), pos(p) {}
} AnnotatedNode;


int widthOfBinaryTree(TreeNode* root) {
    queue<AnnotatedNode*> q;
    q.push(new AnnotatedNode(root, 0, 0));
    long long int currLevel = 0, left = 0, ans = 0;

    while(!q.empty()) {
        AnnotatedNode* node = q.front();
        q.pop();   
        
        if(node->head) {
            q.push(new AnnotatedNode(node->head->left, node->level + 1, 2*node->pos));
            q.push(new AnnotatedNode(node->head->right, node->level + 1, 2*node->pos + 1));
        
            if(node->level != currLevel) {
                currLevel = node->level;
                left = node->pos;
            }
            ans = max(ans, node->pos-left+1);
        }
    }
    return ans;
}


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

int main() {
    string line;
    while (getline(cin, line)) {
        TreeNode* root = stringToTreeNode(line);
        
        int ret = widthOfBinaryTree(root);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}