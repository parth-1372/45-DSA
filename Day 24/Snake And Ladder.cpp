class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        vector<int> edges(n * n + 1, 0), vis(n * n + 1, INT_MAX);

        vector<vector<int>> givenum(n, vector<int>(n, 0));
        int num = 1;

        for (int i = n - 1; i >= 0; i--) {
            if ((n - i) % 2 == 1) {
                for (int j = 0; j < n; j++) {
                    givenum[i][j] = num++;
                }
            } else {
                for (int j = n - 1; j >= 0; j--) {
                    givenum[i][j] = num++;
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int start = givenum[i][j];
                if (board[i][j] == -1) {
                    edges[start] = start;
                } else {
                    edges[start] = board[i][j];
                }
            }
        }

        queue<int> q;
        q.push(1);
        vis[1] = 0;

        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            int moves = vis[curr];

            for (int i = 1; i <= 6; i++) {
                int next = curr + i;
                if (next <= n * n) {
                    next = edges[next];
                    if (vis[next] > moves + 1) {
                        vis[next] = moves + 1;
                        q.push(next);
                    }
                }
            }
        }

        return vis[n * n] == INT_MAX ? -1 : vis[n * n];
    }
};
