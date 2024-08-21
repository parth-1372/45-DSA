class Solution {
public:
    void shortest_distance(vector<vector<int>>& matrix) {
        int n = matrix.size();
        
        // Initialize the matrix to use infinity for unreachable paths
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == -1 && i != j) {
                    matrix[i][j] = INT_MAX;
                }
            }
        }
        
        // Floyd-Warshall algorithm
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (matrix[i][k] != INT_MAX && matrix[k][j] != INT_MAX && matrix[i][j] > matrix[i][k] + matrix[k][j]) {
                        matrix[i][j] = matrix[i][k] + matrix[k][j];
                    }
                }
            }
        }
        
        // Replace INT_MAX back to -1 for no path
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == INT_MAX) {
                    matrix[i][j] = -1;
                }
            }
        }
    }
};
