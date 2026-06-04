class Solution{
    private:
    int height(TreeNode* root , int &maxi){
        if(root==NULL) return 0 ;
        int l= height(root->left,maxi);
        int r= height(root->right,maxi);
        maxi= max(maxi ,l+r);
        return max(l,r)+1;
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL) return 0 ;
        int maxi=0;
        height(root, maxi);
        return maxi;
    }
};