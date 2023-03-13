class Solution {
public:
    bool isSymmetric(TreeNode* root) 
    {
        queue<TreeNode*> q;
        if(root->left == NULL || root->right == NULL)
            return root->left == root->right;
        
        q.push(root->left);
        q.push(root->right);
        while(!q.empty())
        {
            TreeNode* left = q.front(); q.pop();
            TreeNode* right = q.front(); q.pop();
            
            if(left==NULL && right==NULL)
                continue;
            if(left==NULL || right==NULL)
                return false;
            if(left->val != right->val) 
                return false;
            
            q.push(left->left);
            q.push(right->right);
            q.push(left->right);
            q.push(right->left);
        }
        return true;
    }
};
