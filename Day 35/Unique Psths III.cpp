class Solution {
public:
    void backtrack(int r, int c, int er, int ec, vector<vector<int>>& grid, int& count, vector<vector<bool>>& vis, int remaining) {
        int m = grid.size(), n = grid[0].size();
        
        

        if (r == er && c == ec) {
            if (remaining == 0) { 
                count++;
            }
            return;
        }
        
        vis[r][c] = true;
        
        vector<int> rowAdd = {0, 0, 1, -1};
        vector<int> colAdd = {1, -1, 0, 0};
        for (int i = 0; i < 4; i++) {
            int nr = r + rowAdd[i];
            int nc = c + colAdd[i];
            if (nr >= 0 && nr < m && nc >= 0 && nc < n && !vis[nr][nc] && grid[nr][nc] != -1) {
                backtrack(nr, nc, er, ec, grid, count, vis, remaining - 1);
            }
        }
        
        vis[r][c] = false;
    }
    
    int uniquePathsIII(vector<vector<int>>& grid) {
        int sr, sc, er, ec, m = grid.size(), n = grid[0].size();
        int totalCells = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    sr = i;
                    sc = j;
                }
                if (grid[i][j] == 2) {
                    er = i;
                    ec = j;
                }
                if (grid[i][j] != -1) {
                    totalCells++;
                }
            }
        }
        
        int count = 0;
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        backtrack(sr, sc, er, ec, grid, count, vis, totalCells - 1);
        
        return count;
    }
};
