class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool dfs(vector<int> adj[],vector<int>& vis,int curr,int prev){
    vis[curr]=1;
    for(int i=0;i<adj[curr].size();i++){
        if(adj[curr][i]!=prev){
            if(vis[adj[curr][i]]) return false; // cycle detected
            if(!dfs(adj, vis, adj[curr][i], curr)) return false;
        }
    }
    return true;
}

    bool isCycle(int V, vector<int> adj[]) {
    vector<int> vis(V,0);
    for(int i=0;i<V;i++){
        if(vis[i]==0){
            if(!dfs(adj,vis,i,-1)) return true; // cycle detected
        }
    }
    return false; // no cycle detected
}

};