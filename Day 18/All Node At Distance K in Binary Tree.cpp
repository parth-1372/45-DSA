/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<pair<pair<int,char>,TreeNode*>> ans;
    TreeNode* x;
    int helper(TreeNode* root,TreeNode* target){
        if(root==nullptr)return 0;
        if(root->val==target->val){
            x=root;
            return 1;
        }
        int left=helper(root->left,target);
        int right=helper(root->right,target);
        if(left!=0){
            ans.push_back({{left,'L'},root});
            return left+1;
        }
        if(right!=0){
            ans.push_back({{right,'R'},root});
            return right+1;
        }
        return 0;
    }
    void findAtDist(TreeNode* root,int dist,vector<int>& arr){
        if(dist<0 || root==nullptr)return;
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        while(!q.empty()){
            TreeNode* currNode = q.front().first;
            int currD = q.front().second;
            q.pop();
            if(currNode==nullptr)continue;
            if(currD==dist){
                arr.push_back(currNode->val);
                continue;
            }
            q.push({currNode->left,currD+1});
            q.push({currNode->right,currD+1});
        }
        return;
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        helper(root,target);
        vector<int> arr;
        findAtDist(x,k,arr);
        for(int i=0;i<ans.size();i++){
            int currD=ans[i].first.first;
            char dir=ans[i].first.second;
            TreeNode* currNode = ans[i].second;
            if(currD==k){
                arr.push_back(currNode->val);
            }else{
                if(dir=='L'){
                findAtDist(currNode->right,k-currD-1,arr);
            }
            else{
                 findAtDist(currNode->left,k-currD-1,arr);
            }
            }
            
        }
        return arr;
    }
};