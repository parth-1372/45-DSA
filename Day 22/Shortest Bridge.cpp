class Solution {
public:
    void dfs(vector<vector<int>>& grid, vector<vector<int>>& vis, queue<pair<int, int>>& q, int r, int c, vector<int>& rowAdd, vector<int>& colAdd) {
        int n = grid.size();
        vis[r][c] = 1;
        q.push({r, c});

        for (int i = 0; i < 4; i++) {
            int nr = r + rowAdd[i];
            int nc = c + colAdd[i];
            if (nr >= 0 && nr < n && nc >= 0 && nc < n && grid[nr][nc] == 1 && !vis[nr][nc]) {
                dfs(grid, vis, q, nr, nc, rowAdd, colAdd);
            }
        }
    }

    int shortestBridge(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> vis(n, vector<int>(n, 0));
        queue<pair<int, int>> q;
        vector<int> rowAdd = {0, 0, 1, -1};
        vector<int> colAdd = {1, -1, 0, 0};
        bool found = false;

        // Find the first island and start DFS to mark it
        for (int i = 0; i < n && !found; i++) {
            for (int j = 0; j < n && !found; j++) {
                if (grid[i][j] == 1) {
                    dfs(grid, vis, q, i, j, rowAdd, colAdd);
                    found = true;
                }
            }
        }

        // BFS to find the shortest path to the second island
        int ans = 0;
        while (!q.empty()) {
            int qsize = q.size();
            ans++;
            while (qsize--) {
                int r = q.front().first;
                int c = q.front().second;
                q.pop();
                for (int i = 0; i < 4; i++) {
                    int nr = r + rowAdd[i];
                    int nc = c + colAdd[i];
                    if (nr >= 0 && nr < n && nc >= 0 && nc < n && !vis[nr][nc]) {
                        if (grid[nr][nc] == 1) {
                            return ans-1;
                        }
                        vis[nr][nc] = 1;
                        q.push({nr, nc});
                    }
                }
            }
        }

        return -1; // This should never be reached
    }
};
