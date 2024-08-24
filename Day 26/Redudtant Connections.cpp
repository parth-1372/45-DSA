class Solution {
public:
    bool allVisted(vector<int> arr) {
        int n = arr.size();
        // Adjusted to check only the relevant range [1, n-1]
        for (int i = 1; i < n; i++) {
            if (arr[i] == 0) return false;
        }
        return true;
    }

    void dfs(int curr, vector<vector<int>>& adj, vector<int>& vis, int& count) {
        if (vis[curr]) return;
        vis[curr] = 1;
        ++count;
        cout << curr << " ";
        for (int i = 1; i < adj[curr].size(); i++) {
            if (adj[curr][i] == 1 && !vis[i]) {
                dfs(i, adj, vis, count);
            }
        }
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<vector<int>> adj(n + 1, vector<int>(n + 1, 0));

        for (int i = 0; i < n; i++) {
            adj[edges[i][0]][edges[i][1]] = 1;
            adj[edges[i][1]][edges[i][0]] = 1;
        }

        for (int i = n - 1; i >= 0; i--) {
            adj[edges[i][0]][edges[i][1]] = 0;
            adj[edges[i][1]][edges[i][0]] = 0;

            vector<int> vis(n + 1, 0);
            int count = 0;

            cout << "DFS Path " << i << ": ";
            dfs(1, adj, vis, count);
            cout << " Count: " << count << endl;

            if (count == n) {
                return edges[i];
            }

            adj[edges[i][0]][edges[i][1]] = 1;
            adj[edges[i][1]][edges[i][0]] = 1;
        }

        return {};
    }
};
