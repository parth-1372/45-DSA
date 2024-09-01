class Solution{
public:
    bool f(vector<vector<int>>& adjList, int curr, int m, vector<int>& vis) {
        // If all vertices are visited
        if (curr == adjList.size()) return true;

        // Try all colors from 1 to m
        for (int i = 1; i <= m; i++) {
            bool checkColour = true;
            // Check if the current color `i` is valid for the current node
            for (int j = 0; j < adjList[curr].size(); j++) {
                int neighbour = adjList[curr][j];
                if (vis[neighbour] == i) {
                    checkColour = false;
                    break;
                }
            }
            // If valid, assign color `i` to current vertex
            if (checkColour) {
                vis[curr] = i;
                // Recur to check if this leads to a solution
                if (f(adjList, curr + 1, m, vis)) return true;
                // Backtrack if assigning color `i` doesn't lead to a solution
                vis[curr] = -1;
            }
        }
        // If no color can be assigned to the current vertex
        return false;
    }

    bool graphColoring(bool graph[101][101], int m, int n) {
        // Create an adjacency list from the given graph
        vector<vector<int>> adjList(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (graph[i][j]) {
                    adjList[i].push_back(j);
                }
            }
        }

        // Vector to store the colors assigned to each vertex
        vector<int> vis(n, -1); // -1 means unvisited or no color assigned

        // Start the backtracking algorithm from the first vertex
        return f(adjList, 0, m, vis);
    }
};