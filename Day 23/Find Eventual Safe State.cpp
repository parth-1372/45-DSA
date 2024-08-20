#include <vector>
#include <unordered_map>
#include <set>
#include <algorithm>
using namespace std;

class Solution {
public:
    struct pair_hash {
        template <class T1, class T2>
        std::size_t operator () (const std::pair<T1, T2> &p) const {
            auto h1 = std::hash<T1>{}(p.first);
            auto h2 = std::hash<T2>{}(p.second);
            return h1 ^ h2;
        }
    };

    bool checkSafe(vector<vector<int>>& graph, int curr, set<int>& safeNodes,
                   unordered_map<pair<int, int>, bool, pair_hash>& edges, set<int>& path) {
        if (safeNodes.find(curr) != safeNodes.end()) {
            return true;
        }
        if (path.find(curr) != path.end()) {
            return false;
        }

        path.insert(curr);
        bool currAns = true;

        for (int i = 0; i < graph[curr].size(); i++) {
            if (edges.find({curr, graph[curr][i]}) == edges.end()) {
                bool temp = checkSafe(graph, graph[curr][i], safeNodes, edges, path);
                edges[{curr, graph[curr][i]}] = temp;
                currAns = currAns && temp;
            } else {
                currAns = currAns && edges[{curr, graph[curr][i]}];
            }
        }

        path.erase(curr);

        if (currAns) {
            safeNodes.insert(curr);
        }
        return currAns;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        set<int> safeNodes;
        unordered_map<pair<int, int>, bool, pair_hash> edges;
        set<int> path;

        for (int i = 0; i < n; i++) {
            if (graph[i].empty()) {
                safeNodes.insert(i);
            }
        }

        for (int i = 0; i < n; i++) {
            checkSafe(graph, i, safeNodes, edges, path);
        }

        vector<int> result(safeNodes.begin(), safeNodes.end());
        return result;
    }
};
