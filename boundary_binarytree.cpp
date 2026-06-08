// Improved boundary traversal implementation
#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    static bool isLeaf(TreeNode* node) {
        return node && !node->left && !node->right;
    }

    void addLeftBoundary(TreeNode* root, vector<int>& res) {
        TreeNode* cur = root->left;
        while (cur) {
            if (!isLeaf(cur)) res.push_back(cur->val);
            if (cur->left) cur = cur->left;
            else cur = cur->right;
        }
    }

    void addRightBoundary(TreeNode* root, vector<int>& res) {
        TreeNode* cur = root->right;
        vector<int> tmp;
        while (cur) {
            if (!isLeaf(cur)) tmp.push_back(cur->val);
            if (cur->right) cur = cur->right;
            else cur = cur->left;
        }
        for (int i = (int)tmp.size() - 1; i >= 0; --i) res.push_back(tmp[i]);
    }

    void addLeaves(TreeNode* root, vector<int>& res) {
        if (!root) return;
        if (isLeaf(root)) {
            res.push_back(root->val);
            return;
        }
        addLeaves(root->left, res);
        addLeaves(root->right, res);
    }

    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        vector<int> res;
        if (!root) return res;
        if (!isLeaf(root)) res.push_back(root->val);
        addLeftBoundary(root, res);
        addLeaves(root, res);
        addRightBoundary(root, res);
        return res;
    }
};

// Small test harness
int main() {
    // Build a sample tree:
    //        1
    //      /   \
    //     2     3
    //    / \     \
    //   4   5     6
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(6);

    Solution sol;
    vector<int> b = sol.boundaryOfBinaryTree(root);
    for (size_t i = 0; i < b.size(); ++i) {
        if (i) cout << ' ';
        cout << b[i];
    }
    cout << '\n';
    return 0;
}
