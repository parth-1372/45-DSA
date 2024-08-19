class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        vector<int> ans;
        vector<bool> visited(V, false);
        queue<int> q;
        
        q.push(0);
        visited[0] = true;
        
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            ans.push_back(curr);
            
            for (int i = 0; i < adj[curr].size(); i++) {
                int neighbor = adj[curr][i];
                if (!visited[neighbor]) {
                    q.push(neighbor);
                    visited[neighbor] = true; 
                }
            }
        }
        return ans;
    }
};