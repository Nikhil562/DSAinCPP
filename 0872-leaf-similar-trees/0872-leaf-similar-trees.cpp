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
    void inOrder(TreeNode* root,vector<int>&v){
        if(root){
            inOrder(root->left,v);
            if(root->left==nullptr && root->right==nullptr) v.push_back(root->val);
            inOrder(root->right,v);
        }
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> v;
        vector<int> w;
        inOrder(root1,v);
        inOrder(root2,w);
        int n=v.size();
        int m=w.size();
        if(n!=m) return false;
        for(int i=0;i<n;i++){
            if(v[i]!=w[i]) return false;
        }
        return true;
    }
};