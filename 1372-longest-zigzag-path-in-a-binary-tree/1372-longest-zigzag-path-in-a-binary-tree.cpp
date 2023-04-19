class Solution {
public:
    int ans=0;    //store final answer
    
    void helper(TreeNode *root,int flag,int nodes){             //flag is condition for 0 and 1 and nodes stores path information
        if(root==NULL) return;          //base case
        ans=max(ans,nodes);            
        if(flag){
            helper(root->right,0,nodes+1);        //if right node is present and previous was left node
            helper(root->left,1,1);                      //if right node is null then it will start from 1 again and in same direction
        }
        else {helper(root->left,1,nodes+1);     //if left node is present and previous was right node
        helper(root->right,0,1);}                     //if left node is null then it will start from 1 again and in same direction
    }
    
    int longestZigZag(TreeNode* root) {
        
        helper(root,1,0);
        helper(root,0,0);
        return ans;
    }
};