/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    
public:
    TreeNode* construct(int s, int e,vector<int>const &postorder,int &pindex,unordered_map<int,int>&mp){
        if(s>e) return nullptr;
        TreeNode *root=new TreeNode (postorder[pindex--]);
        int index=mp[root->val];
        root->right=construct(index+1,e,postorder,pindex,mp);
        root->left=construct(s,index-1,postorder,pindex,mp);
        return root;
    }
    TreeNode* constructBT(vector<int>const &inorder, vector<int>const &postorder){
        int n=inorder.size();
        unordered_map<int, int> mp;
        for(int i=0;i<n;i++){
            mp[inorder[i]]=i;
        }
        int pindex=n-1;
        return construct(0,n-1,postorder,pindex,mp);
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        TreeNode *root=constructBT(inorder,postorder);
        return root;
    }
};