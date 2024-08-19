class Solution {
public:
    void dfs(vector<vector<int>>& adjList , vector<int>& vis , int curr){
        vis[curr] = 1;
        for(int nc : adjList[curr]){
            if(!vis[nc]){
                dfs(adjList, vis, nc);
            }
        }
    }

    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size() < n - 1) return -1; 

        vector<vector<int>> adjList(n);
        for(const auto& conn : connections){
            adjList[conn[0]].push_back(conn[1]);
            adjList[conn[1]].push_back(conn[0]);
        }

        vector<int> vis(n, 0);
        int components = 0;
        for(int i = 0; i < n; i++){
            if(!vis[i]){
                components++;
                dfs(adjList, vis, i);
            }
        }
        return components - 1;
    }
};
