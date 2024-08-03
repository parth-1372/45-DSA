// https://leetcode.com/problems/spiral-matrix/
class Solution {
public:
    void helper(vector<vector<int>>& matrix, vector<int>& result, int sr) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        // Base case: stop recursion if starting row exceeds halfway point
        if (sr >= (min(m, n) + 1) / 2) return;

        // Traverse from left to right along the top row
        for (int i = sr; i < n - sr; ++i) {
            result.push_back(matrix[sr][i]);
        }
        // Traverse from top to bottom along the right column
        for (int i = sr + 1; i < m - sr; ++i) {
            result.push_back(matrix[i][n - sr - 1]);
        }
        // Traverse from right to left along the bottom row
        if (m - sr - 1 > sr) {
            for (int i = n - sr - 2; i >= sr; --i) {
                result.push_back(matrix[m - sr - 1][i]);
            }
        }
        // Traverse from bottom to top along the left column
        if (n - sr - 1 > sr) {
            for (int i = m - sr - 2; i > sr; --i) {
                result.push_back(matrix[i][sr]);
            }
        }

        // Recur for the inner sub-matrix
        helper(matrix, result, sr + 1);
    }

    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        if (matrix.empty()) return result;  // Handle edge case of empty matrix
        helper(matrix, result, 0);
        return result;
    }
};
