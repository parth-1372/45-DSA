class Solution {
public: 
    pair<int, int> preCompute(vector<vector<int>>& adjList, vector<int>& countChild, int parent, int curr) {
        int currCountChild = 0, CurrDist = 0;
        for (int i = 0; i < adjList[curr].size(); i++) {
            int child = adjList[curr][i];
            if (child != parent) {
                pair<int, int> temp = preCompute(adjList, countChild, curr, child);
                CurrDist += temp.first;
                currCountChild += temp.second;
            }
        }
        countChild[curr] = currCountChild + 1;
        return {CurrDist + countChild[curr] - 1, countChild[curr]};
    }

    void findAllDist(vector<vector<int>>& adjList, vector<int>& Dist, vector<int>& countChild, int rootDist, int curr, int parent) {
        for (int i = 0; i < adjList[curr].size(); i++) {
            int child = adjList[curr][i];
            if (child != parent) {
                Dist[child] = Dist[curr] - countChild[child] + (adjList.size() - countChild[child]);
                findAllDist(adjList, Dist, countChild, rootDist, child, curr);
            }
        }
    }

    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adjList(n);
        for (int i = 0; i < edges.size(); i++) {
            adjList[edges[i][0]].push_back(edges[i][1]);
            adjList[edges[i][1]].push_back(edges[i][0]);
        }
        vector<int> countChild(n, 0);
        int rootDist = preCompute(adjList, countChild, -1, 0).first;
        vector<int> Dist(n, 0);
        Dist[0] = rootDist;
        findAllDist(adjList, Dist, countChild, rootDist, 0, -1);
        return Dist;
    }
};
