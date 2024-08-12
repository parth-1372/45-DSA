
class Solution {
public:
    // Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> arr(m, vector<int>(n, INT_MAX));
        set<pair<int, pair<int, int>>> s;
        vector<int> rowAdd = {0, 0, 1, -1}, colAdd = {1, -1, 0, 0};
        
        // Initialize rotten oranges and set their distance to 0.
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) {
                    arr[i][j] = 0;
                    s.insert({0, {i, j}});
                }
            }
        }
        
        // Process the grid using a BFS-like approach.
        while (!s.empty()) {
            auto it = s.begin();
            int currDist = it->first;
            int cr = it->second.first, cl = it->second.second;
            s.erase(it);
            
            for (int i = 0; i < 4; i++) {
                int newR = cr + rowAdd[i], newC = cl + colAdd[i];
                
                // Check if the neighboring cell is within bounds and is a fresh orange.
                if (newR >= 0 && newR < m && newC >= 0 && newC < n && grid[newR][newC] == 1) {
                    // If the orange at the new position can be rotted in shorter time.
                    if (arr[newR][newC] > currDist + 1) {
                        // Update the time to rot and insert into the set.
                        if (arr[newR][newC] != INT_MAX) {
                            s.erase({arr[newR][newC], {newR, newC}});
                        }
                        arr[newR][newC] = currDist + 1;
                        s.insert({currDist + 1, {newR, newC}});
                    }
                }
            }
        }
        
        int ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // If there is a fresh orange left that cannot be rotted, return -1.
                if (grid[i][j] == 1) {
                    if (arr[i][j] == INT_MAX) return -1;
                    ans = max(ans, arr[i][j]);
                }
            }
        }
        return ans;
    }
};