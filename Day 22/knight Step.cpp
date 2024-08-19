class Solution 
{
public:
    int minStepToReachTarget(vector<int>& KnightPos, vector<int>& TargetPos, int N) {
        int tr = N - TargetPos[1], tcl = TargetPos[0] - 1;
        int cr = N - KnightPos[1], cl = KnightPos[0] - 1;

        if (tr == cr && tcl == cl) return 0;
        
        vector<vector<int>> board(N, vector<int>(N, INT_MAX));
        vector<int> rowAdd = {-1,-1,-2,-2,1,1,2,2};
        vector<int> colAdd = {-2,2,-1,1,-2,2,-1,1};

        queue<pair<int, int>> q;
        q.push({cr, cl});
        board[cr][cl] = 0;

        while (!q.empty()) {
           pair<int,int> p = q.front();
           int r=p.first;
           int c=p.second;
            q.pop();

            for (int i = 0; i < 8; ++i) {
                int newRow = r + rowAdd[i];
                int newCol = c + colAdd[i];

                if (newRow >= 0 && newRow < N && newCol >= 0 && newCol < N && board[newRow][newCol] == INT_MAX) {
                    board[newRow][newCol] = board[r][c] + 1;

                    if (newRow == tr && newCol == tcl) {
                        return board[newRow][newCol];
                    }

                    q.push({newRow, newCol});
                }
            }
        }

        return -1;  // If no path is found (shouldn't happen on a normal chessboard)
    }
}