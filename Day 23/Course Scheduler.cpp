class Solution {
public:
    bool findCycle(vector<vector<int>>& adj, int curr, vector<int>& vis) {
        if(vis[curr] == 2) return false; 
        if(vis[curr] == 1) return true; 
        
        vis[curr] = 1;  
        for(int child : adj[curr]) {
            if(vis[child] == 0) {
                if(findCycle(adj, child, vis)) return true;
            } else if(vis[child] == 1) {  
                return true;
            }
        }
        
        vis[curr] = 2; 
        return false;
    }
    bool canFinish(int n, vector<vector<int>>& pr) {
        int p=pr.size();
        if (n == 0 || p == 0) return true;

        vector<vector<int>> adj(n);
        
        for(int i = 0; i < p; i++) {
            adj[pr[i][0]].push_back(pr[i][1]);
        }
        
        vector<int> vis(n, 0); 
        for(int i = 0; i < n; i++) {
            if(vis[i] == 0) {
                if(findCycle(adj, i, vis)) return false;
            }
        }
        
        return true;
    }
};

