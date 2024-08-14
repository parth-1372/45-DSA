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
    vector<TreeNode*> helper(int left,int right,int n){
        if(left>right || right>n){
            vector<TreeNode*> arr;
            return arr;
        }
        if(left==right){
            TreeNode* a = new TreeNode(left);
            vector<TreeNode*> arr;
            arr.push_back(a);
            return arr;
        }
        vector<TreeNode*> ans;
        for(int i=left;i<=right;i++){
           if(i==left){
              vector<TreeNode*> tempAns = helper(i+1,right,n);
              for(int j=0;j<tempAns.size();j++){
                 TreeNode* root = new TreeNode(i);
                 root->right=tempAns[j];
                 ans.push_back(root);
              }
           }
           else if(i==right){
             vector<TreeNode*> tempAns=helper(left,i-1,n);
             for(int j=0;j<tempAns.size();j++){
                 TreeNode* root = new TreeNode(i);
                 root->left=tempAns[j];
                 ans.push_back(root);
              }
           }
           else{
            vector<TreeNode*> tempLeft=helper(left,i-1,n);
            vector<TreeNode*> tempRight=helper(i+1,right,n);
            vector<TreeNode*> tempAns;
            for(int j=0;j<tempLeft.size();j++){
                 for(int k=0;k<tempRight.size();k++){
                    TreeNode* root = new TreeNode(i);
                    root->left=tempLeft[j];
                    root->right=tempRight[k];
                    ans.push_back(root);
                 }
              }
           }
        }
        return ans;
    }
    vector<TreeNode*> generateTrees(int n) {
        return helper(1,n,n);
    }
};