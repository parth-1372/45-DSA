#include <vector>
#include <queue>
#include <set>
using namespace std;

class Solution {
public:
    int spanningTree(int n, vector<vector<int>> graph[]) {
        // Construct adjacency list from the graph array
        vector<vector<pair<int, int>>> adj(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < graph[i].size(); j++) {
                int u = i;
                int v = graph[i][j][0];
                int weight = graph[i][j][1];
                adj[u].push_back({v, weight});
                adj[v].push_back({u, weight});
            }
        }
        
        // Priority queue for selecting the edge with minimum weight
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
        int mst = 0;
        set<int> verticesTaken;
        pq.push({0, 0});  // Starting with node 0
        
        while (!pq.empty()) {
            int currDist = pq.top().first;
            int currNode = pq.top().second;
            pq.pop();
            
            if (verticesTaken.find(currNode) == verticesTaken.end()) {
                verticesTaken.insert(currNode);
                mst += currDist;
            } else {
                continue;
            }
            
            for (auto &neighbor : adj[currNode]) {
                int newNode = neighbor.first;
                int newDist = neighbor.second;
                if (verticesTaken.find(newNode) == verticesTaken.end()) {
                    pq.push({newDist, newNode});
                }
            }
        }
        
        return mst;
    }
};
