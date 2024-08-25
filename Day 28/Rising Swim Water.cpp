class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        
        auto compare = [](pair<int, pair<int, int>> a, pair<int, pair<int, int>> b) {
            return a.first > b.first;
        };
        
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, decltype(compare)> pq(compare);
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        
        pq.push({grid[0][0], {0, 0}});
        visited[0][0] = true;
        
        while (!pq.empty()) {
            int t = pq.top().first;
            int r = pq.top().second.first;
            int c = pq.top().second.second;
            pq.pop();
            
            if (r == n - 1 && c == n - 1) {
                return t;
            }
            
            for (auto& dir : directions) {
                int nr = r + dir[0];
                int nc = c + dir[1];
                
                if (nr >= 0 && nr < n && nc >= 0 && nc < n && !visited[nr][nc]) {
                    visited[nr][nc] = true;
                    pq.push({max(t, grid[nr][nc]), {nr, nc}});
                }
            }
        }
        
        return -1;
    }
};
