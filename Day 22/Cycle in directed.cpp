class Solution {
public:
    bool dfs(vector<int> adj[], int curr, vector<int>& vis) {
        if (vis[curr] == 1) return true;  
        if (vis[curr] == 2) return false; 
        
        vis[curr] = 1; 
        
        for (int neighbor : adj[curr]) {
            if (dfs(adj, neighbor, vis)) return true;
        }
        
        vis[curr] = 2;
        return false;
    }
    
    bool isCyclic(int V, vector<int> adj[]) {
        vector<int> vis(V, 0);
        
        for (int i = 0; i < V; i++) {
            if (vis[i] == 0) {
                if (dfs(adj, i, vis)) return true;
            }
        }
        return false;
    }
};