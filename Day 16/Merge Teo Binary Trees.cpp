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
    TreeNode* helper(TreeNode* root1, TreeNode* root2,TreeNode* ans1,char side){
        if(root1==nullptr && root2==nullptr)return nullptr;
        if(root1==nullptr && root2!=nullptr)return root2;
        if(root1!=nullptr && root2==nullptr)return root1;
        
        TreeNode* ans = new TreeNode(root1->val+root2->val);
        if(side=='L'){
            ans1->left=ans;
        }
        else{
            ans1->right=ans;
        }
        ans->left=helper(root1->left,root2->left,ans,'L');
        ans->right=helper(root1->right,root2->right,ans,'R');
        return ans;
    }
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
       if(root1==nullptr && root2==nullptr)return nullptr;
        if(root1==nullptr && root2!=nullptr)return root2;
        if(root1!=nullptr && root2==nullptr)return root1;
        
        TreeNode* ans = new TreeNode(root1->val+root2->val);
        ans->left=helper(root1->left,root2->left,ans,'L');
        ans->right=helper(root1->right,root2->right,ans,'R');
        return ans;
    }
};