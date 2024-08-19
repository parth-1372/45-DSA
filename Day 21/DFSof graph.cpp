class Solution {
  public:
    void dfs(int curr, vector<int> adj[],vector<int>& ans,vector<int>& vis){
        if(vis[curr])return;
        vis[curr]=1;
        ans.push_back(curr);
        for(int i=0;i<adj[curr].size();i++){
            int child = adj[curr][i];
            if(vis[child]==0)dfs(child,adj,ans,vis);
        }
    }
    
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        vector<int> ans;
        vector<int> vis(V,0);
        dfs(0,adj,ans,vis);
        return ans;
    }
};