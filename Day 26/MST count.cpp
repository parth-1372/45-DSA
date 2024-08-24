class Solution {
public:
    // Function to compute the determinant of a matrix
    int determinant(const std::vector<std::vector<int>>& matrix, int n) {
        if (n == 1)
            return matrix[0][0];
        
        if (n == 2)
            return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
        
        int det = 0;
        std::vector<std::vector<int>> submatrix(n - 1, std::vector<int>(n - 1));

        for (int x = 0; x < n; ++x) {
            int subi = 0;
            for (int i = 1; i < n; ++i) {
                int subj = 0;
                for (int j = 0; j < n; ++j) {
                    if (j == x)
                        continue;
                    submatrix[subi][subj++] = matrix[i][j];
                }
                ++subi;
            }
            det += (x % 2 == 0 ? 1 : -1) * matrix[0][x] * determinant(submatrix, n - 1);
        }
        
        return det;
    }

    // Function to get the minor matrix after removing row `row` and column `col`
    std::vector<std::vector<int>> getMinorMatrix(const std::vector<std::vector<int>>& matrix, int row, int col, int n) {
        std::vector<std::vector<int>> submatrix(n - 1, std::vector<int>(n - 1));
        int minor_i = 0, minor_j;

        for (int i = 0; i < n; ++i) {
            if (i == row)
                continue;
            
            minor_j = 0;
            for (int j = 0; j < n; ++j) {
                if (j == col)
                    continue;
                
                submatrix[minor_i][minor_j++] = matrix[i][j];
            }
            ++minor_i;
        }

        return submatrix;
    }

    // Function to calculate the cofactor of an element at position (row, col)
    int cofactor(const std::vector<std::vector<int>>& matrix, int row, int col, int n) {
        std::vector<std::vector<int>> submatrix = getMinorMatrix(matrix, row, col, n);
        int minorDet = determinant(submatrix, n - 1);
        return (row + col) % 2 == 0 ? minorDet : -minorDet;
    }

    // Function to count spanning trees using the cofactor method
    int countSpanningTrees(std::vector<std::vector<int>>& graph, int n, int m) {
        std::vector<std::vector<int>> adjMatrix(n, std::vector<int>(n, 0));
        
        // Fill adjacency matrix
        for (int i = 0; i < m; i++) {
            adjMatrix[graph[i][0]][graph[i][1]] = 1;
            adjMatrix[graph[i][1]][graph[i][0]] = 1;
        }
        
        // Fill diagonal with degree of nodes
        for (int i = 0; i < n; i++) {
            int count = 0;
            for (int j = 0; j < n; j++) {
                if (adjMatrix[i][j]) count++;
            }
            adjMatrix[i][i] = count;
        }
        
        // Replace non-diagonal 1's with -1
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i != j && adjMatrix[i][j] == 1) {
                    adjMatrix[i][j] = -1;
                }
            }
        }
        
        // Return the cofactor of the first element
        return cofactor(adjMatrix, 0, 0, n);
    }
};