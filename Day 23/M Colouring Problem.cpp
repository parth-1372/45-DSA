class Solution {
public:
    bool dfs(vector<vector<int>>& adj, vector<int>& vis, int curr, int m) {
        if (vis[curr] != 0) return true;
        for (int color = 1; color <= m; ++color) {
            bool canColor = true;
            for (int neighbor : adj[curr]) {
                if (vis[neighbor] == color) {
                    canColor = false;
                    break;
                }
            }
            if (canColor) {
                vis[curr] = color;
                bool allColored = true;
                for (int neighbor : adj[curr]) {
                    if (vis[neighbor] == 0) {
                        if (!dfs(adj, vis, neighbor, m)) {
                            allColored = false;
                            break;
                        }
                    }
                }
                if (allColored) return true;
                vis[curr] = 0;  // Backtrack
            }
        }
        return false;
    }

    bool graphColoring(bool graph[101][101], int m, int n) {
        vector<vector<int>> adj(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (graph[i][j]) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);  // Assuming an undirected graph
                }
            }
        }
        vector<int> vis(n, 0);
        for (int i = 0; i < n; i++) {
            if (vis[i] == 0) {
                if (!dfs(adj, vis, i, m)) return false;
            }
        }
        return true;
    }
};
