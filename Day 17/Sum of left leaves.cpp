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
    void helper(TreeNode* root,char ch,int& ans){
        if(root==nullptr)return;

        if(ch=='L' && root->left==nullptr && root->right==nullptr){
            ans+=root->val;
        }
        helper(root->left,'L',ans);
        helper(root->right,'R',ans);
    }
    int sumOfLeftLeaves(TreeNode* root) {
        if(root==nullptr)return 0;
        int ans=0;
        helper(root->left,'L',ans);
        helper(root->right,'R',ans);
        return ans;
    }
};