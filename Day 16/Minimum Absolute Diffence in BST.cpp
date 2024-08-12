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
    void helper(TreeNode* root,vector<int>& arr){
        if(root==nullptr)return;
        helper(root->left,arr);
        arr.push_back(root->val);
        helper(root->right,arr);
    }
    int getMinimumDifference(TreeNode* root) {
       vector<int> arr;
        helper(root,arr);
        int ans=INT_MAX;
        for(int i=1;i<arr.size();i++){
            ans=min(ans,abs(arr[i]-arr[i-1]));
        }
        return ans;
    }
};