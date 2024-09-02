class Solution {
public:
    bool check(int r,int c,vector<string>& board){
        int n=board.size();
        //Vertical Up Checked
        for(int j=r-1;j>=0;j--){
            if(board[j][c]=='Q')return false;
        }
        //left-Up Dignoal
        int i=r-1,j=c-1;
        while(i>=0 && j>=0 && i<n && j<n){
            if(board[i][j]=='Q')return false;
            i--;
            j--;
        }
        //Right - Up Dignoal
         i=r-1,j=c+1;
        while(i>=0 && j>=0 && i<n && j<n){
            if(board[i][j]=='Q')return false;
            i--;
            j++;
        }
        return true;

    }
    void f(vector<vector<string>>& ans,vector<string>& board,int r){
        int n = board.size();
        if(r==n){
            ans.push_back(board);
            return;
        }
        
        for(int i=0;i<n;i++){
            if(check(r,i,board)){
                board[r][i]='Q';
                f(ans,board,r+1);
                board[r][i]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n, string(n, '.'));
        f(ans,board,0);
        return ans;
    }
};