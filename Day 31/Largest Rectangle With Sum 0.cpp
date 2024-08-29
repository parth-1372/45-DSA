class Solution {
public:
    vector<vector<int>> sumZeroMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> prefixSum(n, vector<int>(m, 0));

        // Calculate prefix sums for each row
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                prefixSum[i][j] = mat[i][j] + (j > 0 ? prefixSum[i][j - 1] : 0);
            }
        }

        int maxArea = 0;
        vector<int> resultBounds; // Will store {startRow, endRow, startCol, endCol}

        // Iterate over all pairs of columns
        for (int left = 0; left < m; left++) {
            for (int right = left; right < m; right++) {
                unordered_map<int, int> sumMap;
                sumMap[0] = -1;
                int currentSum = 0;
                for (int row = 0; row < n; row++) {
                    int prev = left > 0 ? prefixSum[row][left - 1] : 0;
                    currentSum += prefixSum[row][right] - prev;

                    if (sumMap.find(currentSum) != sumMap.end()) {
                        int startRow = sumMap[currentSum] + 1;
                        int area = (right - left + 1) * (row - startRow + 1);
                        if (area > maxArea ||
                            (area == maxArea && left < resultBounds[2]) ||
                            (area == maxArea && left == resultBounds[2] && (right - left) < (resultBounds[3] - resultBounds[2]))) {
                            maxArea = area;
                            resultBounds = {startRow, row, left, right};
                        }
                    } else {
                        sumMap[currentSum] = row;
                    }
                }
            }
        }

        // Extract the result matrix
        vector<vector<int>> result;
        if (maxArea > 0) {
            for (int i = resultBounds[0]; i <= resultBounds[1]; i++) {
                vector<int> row;
                for (int j = resultBounds[2]; j <= resultBounds[3]; j++) {
                    row.push_back(mat[i][j]);
                }
                result.push_back(row);
            }
        }

        return result;
    }
};