class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        queue<pair<int, int>> q;
        int num1 = 0, num0 = 0;


        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    q.push({i, j});
                    num1++;
                } else {
                    num0++;
                }
            }
        }

        if (num1 == 0 || num0 == 0) return -1;

        vector<int> rowAdd = {0, 0, 1, -1};
        vector<int> colAdd = {1, -1, 0, 0};
        int maxDist = -1;

        while (!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            for (int i = 0; i < 4; ++i) {
                int nr = r + rowAdd[i];
                int nc = c + colAdd[i];

                if (nr >= 0 && nr < n && nc >= 0 && nc < n && grid[nr][nc] == 0) {
                    grid[nr][nc] = grid[r][c] + 1;
                    maxDist = max(maxDist, grid[nr][nc]);
                    q.push({nr, nc});
                }
            }
        }

        return maxDist - 1;
    }
};
