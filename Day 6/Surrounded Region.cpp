#include <vector>
using namespace std;

class Solution {
public:
    void dfs(vector<vector<char>>& board, int cr, int cl) {
        int m = board.size();
        int n = board[0].size();

        if (cr < 0 || cr >= m || cl < 0 || cl >= n || board[cr][cl] != 'O')
            return;
        
        board[cr][cl] = '1'; // Mark the cell as visited
        vector<int> rowAdd = {0, 1, 0, -1};
        vector<int> colAdd = {1, 0, -1, 0};

        for (int i = 0; i < 4; ++i) {
            dfs(board, cr + rowAdd[i], cl + colAdd[i]);
        }
    }

    void solve(vector<vector<char>>& board) {
        if (board.empty()) return;

        int m = board.size();
        int n = board[0].size();

        // Mark boundary-connected 'O's
        for (int i = 0; i < n; ++i) {
            if (board[0][i] == 'O') {
                dfs(board, 0, i);
            }
            if (board[m - 1][i] == 'O') {
                dfs(board, m - 1, i);
            }
        }
        for (int i = 1; i < m - 1; ++i) {
            if (board[i][0] == 'O') {
                dfs(board, i, 0);
            }
            if (board[i][n - 1] == 'O') {
                dfs(board, i, n - 1);
            }
        }

        // Convert remaining 'O' to 'X' and '1' back to 'O'
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                } else if (board[i][j] == '1') {
                    board[i][j] = 'O';
                }
            }
        }
    }
};
