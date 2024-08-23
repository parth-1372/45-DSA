class Solution {
public:
    void dfs(int curr, int parent, vector<vector<int>>& adj, vector<vector<int>>& ans, 
             vector<int>& low, vector<int>& disc, vector<int>& vis, int& time) {
        vis[curr] = 1;
        disc[curr] = low[curr] = ++time;
        
        for (int neighbour : adj[curr]) {
            if (neighbour == parent) continue; 
            if (!vis[neighbour]) {
                dfs(neighbour, curr, adj, ans, low, disc, vis, time);
                
          
                low[curr] = min(low[curr], low[neighbour]);
                
                if (low[neighbour] > disc[curr]) {
                    ans.push_back({curr, neighbour});
                }
            } else {
                low[curr] = min(low[curr], disc[neighbour]);
            }
        }
    }

    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> ans;
        vector<vector<int>> adj(n);
        for (const auto& conn : connections) {
            adj[conn[0]].push_back(conn[1]);
            adj[conn[1]].push_back(conn[0]);
        }

        vector<int> low(n, -1), disc(n, -1), vis(n, 0);
        int time = 0;

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                dfs(i, -1, adj, ans, low, disc, vis, time);
            }
        }

        return ans;
    }
};
