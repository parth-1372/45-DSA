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
    int ans;
    int helper(TreeNode* root){
        if(root==nullptr)return 0;
        int left=helper(root->left);
        int right=helper(root->right);
        ans=max(ans,left+right);
        return max(left,right)+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        ans=0;
        if(root==nullptr)return 0;
        helper(root);
        return ans;
    }
};