class Solution {
public:
    void dfs(int curr, vector<int> adj[], vector<int>& vis, stack<int>& st) {
        if (vis[curr]) return;
        vis[curr] = 1;
        
        for (int child : adj[curr]) {
            if (!vis[child]) {
                dfs(child, adj, vis, st);
            }
        }
        st.push(curr);
    }
    
    vector<int> topoSort(int n, vector<int> adj[]) {
        vector<int> vis(n, 0);
        stack<int> st;
        vector<int> ans;
        
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                dfs(i, adj, vis, st);
            }
        }
        
        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        
        return ans;
    }
};