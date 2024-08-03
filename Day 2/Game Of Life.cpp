class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m=board.size(),n=board[0].size();
        vector<int> rowAdd ={-1,-1,-1,0,0,1,1,1}; 
        vector<int> colAdd ={-1,0,1,-1,1,-1,0,1};
        vector<vector<int>> updated=board;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int live=0;
                for(int k=0;k<8;k++){
                   int row=i+rowAdd[k];
                   int col=j+colAdd[k];
                   if(row>=0 && row<m && col>=0 && col<n){
                       if(board[row][col]==1)live++;
                   }
                }
                // cout<<i<<" "<<j<<" "<<live<<endl;
                if(board[i][j]==0){
                    if(live==3)updated[i][j]=1;
                }else{
                    if(live<2 || live>3)updated[i][j]=0;
                }
            }
        }
       board=updated;
    }
};