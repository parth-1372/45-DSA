class Solution {
public:
    bool check(int r, int c, char k, vector<vector<char>>& board) {
        // Check row
        for (int i = 0; i < 9; i++) {
            if (board[r][i] == k) return false;
        }
        // Check column
        for (int i = 0; i < 9; i++) {
            if (board[i][c] == k) return false;
        }
        // Check 3x3 subgrid
        int rs = (r / 3) * 3, cs = (c / 3) * 3;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i + rs][j + cs] == k) return false;
            }
        }
        return true;
    }

    bool solveSudokuHelper(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') {
                    for (char k = '1'; k <= '9'; k++) {
                        if (check(i, j, k, board)) {
                            board[i][j] = k;
                            if (solveSudokuHelper(board)) return true;
                            board[i][j] = '.'; 
                        }
                    }
                    return false; 
                }
            }
        }
        return true; 
    }

    void solveSudoku(vector<vector<char>>& board) {
        solveSudokuHelper(board);
    }
};
