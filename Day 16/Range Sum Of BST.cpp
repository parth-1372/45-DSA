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
    int rangeSumBST(TreeNode* root, int low, int high) {
        if(root==nullptr)return 0;
        int left=0;
        int right=0;
        if(root->val>high)
           left=rangeSumBST(root->left,low,high);
        if(root->val<low)
           right=rangeSumBST(root->right,low,high);
        if(root->val>=low && root->val<=high){
            left=rangeSumBST(root->left,low,high);
            right=rangeSumBST(root->right,low,high);
        }
        int add = 0;
        if(root->val>=low && root->val<=high)add=root->val;
        // cout<<left<<"  "<<right<<" "<<add<<endl;
        return left+right+add;
    }
};