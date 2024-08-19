class Solution {
public:
    void dfs(vector<vector<char>>& grid,vector<vector<int>>& vis,int row,int col){
        int m=grid.size(),n=grid[0].size();
        if(row<0 || col<0 || row>=m || col>=n ||vis[row][col])return;
        vis[row][col]=1;
        if(grid[row][col]=='0')return;
        vector<int> rowAdd={0,0,+1,-1};
        vector<int> colAdd={+1,-1,0,0};
        for(int i=0;i<4;i++){
            dfs(grid,vis,row+rowAdd[i],col+colAdd[i]);
        }
        
    }
    int numIslands(vector<vector<char>>& grid) {
        int ans=0,m=grid.size(),n=grid[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(vis[i][j]==0 && grid[i][j]=='1'){
                    ans++;
                    dfs(grid,vis,i,j);
                }
            }
        }
        return ans;
    }
};