class solution{
public:
    bool isleaf(TreeNode* root){
        if(!root->left && !root->right) return true;
        else return false;
    }
    void left(TreeNode* root , vector<int>&res){
        TreeNode* curr = root->left
        while(curr){
            if(!isleaf(curr)) res.push_back(curr->data);
            if(curr->left) cur=cur->left;
            else curr=cur->right;
        }
    }
}    
