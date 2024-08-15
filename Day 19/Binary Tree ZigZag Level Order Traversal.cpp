class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (root == nullptr) return ans;
        
        queue<TreeNode*> q;
        q.push(root);
        bool isFromRight = false;
        
        while (!q.empty()) {
            vector<int> currAns;
            int size = q.size();
            
            for (int i = 0; i < size; ++i) {
                TreeNode* currNode = q.front();
                q.pop();
                currAns.push_back(currNode->val);
                
                if (currNode->left) q.push(currNode->left);
                if (currNode->right) q.push(currNode->right);
            }
            
            if (isFromRight) {
                reverse(currAns.begin(), currAns.end());
            }
            
            isFromRight = !isFromRight;
            ans.push_back(currAns);
        }
        
        return ans;
    }
};
