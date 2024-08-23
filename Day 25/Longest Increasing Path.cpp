class Solution {
public:
    int dfs(vector<vector<int>>& matrix,vector<vector<int>>& vis,int cr,int cl){
        int m=matrix.size(),n=matrix[0].size();
        if(cr<0 || cr>=m ||cl<0 || cl>=n)return 0;
        if(vis[cr][cl]!=0)return vis[cr][cl];
        int curr=0;
        vector<int> rowAdd = {0,0,+1,-1};
        vector<int> colAdd = {+1,-1,0,0};

        for(int i=0;i<4;i++){
            int nr=cr+rowAdd[i];
            int nc=cl+colAdd[i];
            if(nr<0 || nr>=m || nc<0 || nc>=n)continue;
            if(matrix[cr][cl]>matrix[nr][nc]){
                if(vis[nr][nc]==0){
                    curr=max(curr,dfs(matrix,vis,nr,nc));
                }else{
                    curr=max(curr,vis[nr][nc]);
                }
            }
        } 
        vis[cr][cl]=curr+1;
        return vis[cr][cl];
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m=matrix.size(),n=matrix[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));
        int ans=1;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(vis[i][j]==0){
                    vis[i][j]=dfs(matrix,vis,i,j);
                }
                ans=max(ans,vis[i][j]);
            }
        }
        return ans;
    }
};