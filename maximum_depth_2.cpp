#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(): val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* l, TreeNode* r): val(x), left(l), right(r) {}
};

class Solution{
public:
    int maxDepth(TreeNode* root){
        if(root==NULL) return 0;
        int left= maxDepth(root->left);
        int right= maxDepth(root->right);
        return max(left,right)+1;
    }

};

int main(){
    // Example tree:
    //      1
    //     / \
    //    2   3
    //   /     \
    //  4       5
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->right->right = new TreeNode(5);

    Solution sol;
    cout << sol.maxDepth(root) << '\n';
    return 0;
}