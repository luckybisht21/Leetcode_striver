class Solution {
public:
    int height(TreeNode* root){
        if(root==NULL) return 0;
        int l = height(root->left);
        int r= height(root->right);
        return 1+ max(l,r);
    }
    bool isBalanced(TreeNode* root) {
        if(root==NULL) return true;
        int r = height(root->right);
        int l = height(root->left);
        if (abs(r-l)>1) return false;
        bool re =isBalanced(root->right);
        bool lr= isBalanced(root->left);
        if(!lr || ! re) return false;
        return true;
    }
};