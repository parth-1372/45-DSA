class Solution {
public:
    bool dfs(int curr, vector<int> adj[], vector<int>& vis, int color) {
        vis[curr] = color;
        
        for(int neighbor : adj[curr]) {
            if(vis[neighbor] == 0) {
                if(!dfs(neighbor, adj, vis, 3 - color)) {
                    return false;
                }
            } else if(vis[neighbor] == color) {
                  return false;
            }
        }
        
        return true;
    }

    bool isBipartite(int n, vector<int> adj[]) {
        vector<int> vis(n, 0);
        for(int i = 0; i < n; i++) {
            if(vis[i] == 0) {
                if(!dfs(i, adj, vis, 1)) {
                    return false;
                }
            }
        }
        
        return true;
    }
};