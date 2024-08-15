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
    int widthOfBinaryTree(TreeNode* root) {
        if (root == nullptr) return 0;
        
        int maxWidth = 0;
        queue<pair<TreeNode*, unsigned long long>> q;
        q.push({root, 0});
        
        while (!q.empty()) {
            int size = q.size();
            unsigned long long minIndex = q.front().second; 
            int firstIndex, lastIndex;
            
            for (int i = 0; i < size; ++i) {
                unsigned long long currIndex = q.front().second - minIndex; 
                TreeNode* currNode = q.front().first;
                q.pop();
                
                if (i == 0) firstIndex = currIndex;
                if (i == size - 1) lastIndex = currIndex;
                
                if (currNode->left) q.push({currNode->left, 2 * currIndex + 1});
                if (currNode->right) q.push({currNode->right, 2 * currIndex + 2});
            }
            
            maxWidth = max(maxWidth, lastIndex - firstIndex + 1);
        }
        
        return maxWidth;
    }
};
