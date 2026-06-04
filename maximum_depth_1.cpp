
class Solution {
public:
    int maxDepth(TreeNode* root) {
        vector<vector<int>>ans;
        if(root==NULL) return 0;
        queue<TreeNode*>q;
        int depth=0;
        q.push(root);
        while(!q.empty()){
            int n= q.size();
            //vector<int>level;
            for(int i=0;i<n;i++){
                TreeNode * node= q.front();
                q.pop();
                if(node->left!=NULL) q.push(node->left);
                if(node->right !=NULL) q.push(node->right);
                //level.push_back(node->val);
            }
            //ans.push_back(level);
            depth++;
        }
        return depth;
        
    }
};