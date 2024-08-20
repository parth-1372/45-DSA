class Solution {
public:
    void dfs(vector<vector<int>>& adj,vector<int>& vis,
        vector<int>& ans,int curr){
        if(vis[curr])return;
        vis[curr]=1;
        int currColour=0;
        for(int i=1;i<=4;i++){
            bool a=true;
            for(int j=0;j<adj[curr].size() && a;j++){
              if(ans[adj[curr][j]]==i)a=false;
            }
            if(a){
                currColour=i;
                break;
            }
        }
        ans[curr]=currColour;
        
        return;
    }
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<vector<int>> adj(n);
        for(int i=0;i<paths.size();i++){
            adj[paths[i][0]-1].push_back(paths[i][1]-1);
            adj[paths[i][1]-1].push_back(paths[i][0]-1);
        }
        vector<int> vis(n,0);
        //0 means no allocated;
        vector<int> ans(n,-1);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(adj,vis,ans,i);
            }
        }
        return ans;
    }
};