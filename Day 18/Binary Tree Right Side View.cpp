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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(root==nullptr)return ans;
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        int prev=root->val,level=0;
        while(!q.empty()){
            TreeNode* curr = q.front().first;
            int currLevel = q.front().second;
            q.pop();
            if(curr==nullptr)continue;
            q.push({curr->left,currLevel+1});
            q.push({curr->right,currLevel+1});
            if(currLevel>level){
                level=currLevel;
                ans.push_back(prev);
            }
            prev=curr->val;
        }
        ans.push_back(prev);
        return ans;
    }
};