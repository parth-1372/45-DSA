class Solution {
public:
    bool helper(vector<vector<char>>& board,string word,int index,int row,int col,vector<vector<int>>& visited){
         int m=board.size(),n=board[0].size(),wordLength=word.length();
        if(row<0||row>=m||col<0||col>=n) return false;
        if(index==wordLength)return true;
        
        visited[row][col]=1;
        vector<int> rowAdd = {0,0,1,-1};
        vector<int> colAdd = {1,-1,0,0};
        
        for(int i=0;i<4;i++){
            if(row+rowAdd[i]>=0 && row+rowAdd[i]<m && col+colAdd[i]>=0 && col+colAdd[i]<n &&                       board[row+rowAdd[i]][col+colAdd[i]]==word[index] && 
              visited[row+rowAdd[i]][col+colAdd[i]]==0){
               if( helper(board,word,index+1,row+rowAdd[i],col+colAdd[i],visited))return true;
            }
        }
        visited[row][col]=0;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m=board.size(),n=board[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]==word[0]){
                    vector<vector<int>> visited(m,vector<int>(n,0));
                     if(helper(board,word,1,i,j,visited)) return true;
                }
            }
        }
        return false;
    }