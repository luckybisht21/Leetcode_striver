#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int path(TreeNode* root, int &maxi) {
        if (root == nullptr) return 0;
        int l = max(0, path(root->left, maxi));
        int r = max(0, path(root->right, maxi));
        maxi = max(maxi, l + r + root->val);
        return max(l, r) + root->val;
    }

    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN;
        path(root, maxi);
        return maxi;
    }
};

int main() {
    Solution s;
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(12);
    root->right = new TreeNode(3);
    cout << s.maxPathSum(root) << endl;
    return 0;
}