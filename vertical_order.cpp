#include "bits/stdc++.h"
using namespace std;

typedef struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
}TreeNode;

typedef struct location {
    int x, y, val;
    location(int x, int y, int val): x(x), y(y), val(val) {}
} location;

class Solution {
public:
    vector<location> loc;

    void dfs(TreeNode* root, int x, int y) {
        if(root) {
            loc.push_back(location(x, y, root->val));
            dfs(root->left, x-1, y+1);
            dfs(root->right, x+1, y+1);
        }
    }

    vector<vector<int>> usingDFS(TreeNode* root) {
        dfs(root, 0, 0);

        sort(loc.begin(), loc.end(), [](const location &a, const location &b)->bool {
            if(a.x != b.x) return a.x < b.x;
            else if(a.y != b.y) return a.y < b.y;
            else return a.val < b.val;
        });

        // for(int i = 0; i < loc.size(); i++) cout << loc[i].x << " " << loc[i].y << " " << loc[i].val << endl;

        vector<vector<int>> result;
        int prev = loc[0].x;
        result.push_back({});

        for(location l:loc) {
            // cout << "Size: " << result.size() << endl;
            if(l.x == prev) result[result.size()-1].push_back(l.val);
            else {
                prev = l.x;
                result.push_back({l.val});
            }
        }
        return result;
    }

    vector<vector<int>> usingBFS(TreeNode* root) {
        vector<vector<int>> ans;
        map<int,vector<int>> mp;
        if(!root) return ans;

        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        while(!q.empty()) {
            TreeNode* tmp = q.front().first;
            int x = q.front().second;
            q.pop();
            mp[x].push_back(tmp->val);
            if(tmp->left) q.push({tmp->left, x-1});
            if(tmp->right) q.push({tmp->right, x+1});
        }

        for(auto x: mp) ans.push_back(x.second);
        return ans;
    }

    vector<vector<int>> verticalTraversal(TreeNode* root) {
        
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

int main() {
    string line;
    while (getline(cin, line)) {
        TreeNode* root = stringToTreeNode(line);
        
        vector<vector<int>> ret = Solution().verticalTraversal(root);

        for(int i = 0; i < ret.size(); i++) {
            for(int j = 0; j < ret[i].size(); j++) cout << ret[i][j] << " ";
            cout << endl;
        }
    }
    return 0;
}