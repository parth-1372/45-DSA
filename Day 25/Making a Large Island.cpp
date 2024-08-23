class Solution {
public:
    void dfs(vector<vector<int>>& grid, vector<vector<int>>& vis, int& nums, int cr, int cl, int& total,int numIsland) {
        int n = grid.size();
        if (cr < 0 || cr >= n || cl < 0 || cl >= n || vis[cr][cl] != 0 || grid[cr][cl] == 0) return;

        vis[cr][cl] = numIsland; // Mark as visited
        nums++;
        
        vector<int> rowAdd = {0, 0, 1, -1};
        vector<int> colAdd = {1, -1, 0, 0};

        for (int i = 0; i < 4; i++) {
            int nr = cr + rowAdd[i];
            int nc = cl + colAdd[i];
            dfs(grid, vis, nums, nr, nc, total,numIsland);
        }
        
        total = max(total, nums);
    }
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> vis(n, vector<int>(n, 0));
        int ans=0,numIsland=1;
        unordered_map<int,int> map;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (!vis[i][j] && grid[i][j] == 1) {
                    int num = 0;
                    int total = -1;
                    numIsland++;
                    dfs(grid, vis, num, i, j, total,numIsland);
                    ans=max(ans,total);
                    map[numIsland]=total;
                }
            }
        }
        vector<int> rowAdd = {0, 0, 1, -1};
        vector<int> colAdd = {1, -1, 0, 0};
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
               if(grid[i][j]==0){
                set<int> s;
                int canAdd=0;
                for(int k=0;k<4;k++){
                    int nr=i+rowAdd[k];
                    int nc=j+colAdd[k];
                    if(nr>=0 && nr<n && nc>=0 && nc<n && vis[nr][nc]!=0){
                        s.insert(vis[nr][nc]);
                    }
                }
                for(auto it=s.begin();it!=s.end();it++){
                    canAdd+=map[(*it)];
                }
                ans=max(ans,canAdd+1);
               }
            }
        }
        
        return ans;
    }
};
