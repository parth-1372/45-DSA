class Solution {
public:
    void dfs(int curr, vector<vector<int>>& adj, vector<int>& vis) {
        if (vis[curr]) return;
        vis[curr] = 1;
        for (int i = 0; i < adj[curr].size(); i++) {
            if (vis[adj[curr][i]] == 0) {
                dfs(adj[curr][i], adj, vis);
            }
        }
    }

    void startScc(vector<vector<int>>& adj, int curr, stack<int>& st, vector<int>& vis) {
        if (vis[curr]) return;
        vis[curr] = 1;
        for (int i = 0; i < adj[curr].size(); i++) {
            if (vis[adj[curr][i]] == 0) {
                startScc(adj, adj[curr][i], st, vis);
            }
        }
        st.push(curr);
    }

    int kosaraju(int n, vector<vector<int>>& adj) {
        stack<int> st;
        vector<int> visScc(n, 0);

        // Step 1: Perform DFS and push nodes to stack based on finish time
        for (int i = 0; i < n; i++) {
            if (!visScc[i]) {
                startScc(adj, i, st, visScc);
            }
        }

        // Step 2: Reverse the graph
        vector<vector<int>> reverseEdge(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < adj[i].size(); j++) {
                reverseEdge[adj[i][j]].push_back(i);
            }
        }

        // Step 3: Process all nodes in the order defined by the stack
        int ans = 0;
        vector<int> vis(n, 0);
        while (!st.empty()) {
            int node = st.top();
            st.pop();
            if (!vis[node]) {
                ans++;
                dfs(node, reverseEdge, vis);  // Use the reversed graph here
            }
        }

        return ans;
    }
};
