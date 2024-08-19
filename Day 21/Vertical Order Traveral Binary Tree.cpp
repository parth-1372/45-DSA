#include <vector>
#include <map>
#include <queue>
#include <algorithm>

using namespace std;

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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, vector<pair<int, int>>> nodes; // {column: [(row, value)]}
        queue<pair<TreeNode*, pair<int, int>>> todo; // {node, {row, column}}
        
        todo.push({root, {0, 0}});
        
        while (!todo.empty()) {
            auto p = todo.front();
            todo.pop();
            
            TreeNode* node = p.first;
            int row = p.second.first;
            int col = p.second.second;
            
            nodes[col].push_back({row, node->val});
            
            if (node->left) {
                todo.push({node->left, {row + 1, col - 1}});
            }
            if (node->right) {
                todo.push({node->right, {row + 1, col + 1}});
            }
        }
        
        vector<vector<int>> result;
        
        for (auto& [col, vec] : nodes) {
            sort(vec.begin(), vec.end()); 
            vector<int> colValues;
            for (auto& [row, value] : vec) {
                colValues.push_back(value);
            }
            result.push_back(colValues);
        }
        
        return result;
    }
};
