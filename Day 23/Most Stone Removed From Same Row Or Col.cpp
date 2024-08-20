#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <utility>

using namespace std;

class Solution {
public:
    // Custom hash function for pair<int, int> to use with unordered_set
    struct hash_pair { 
        template <class T1, class T2> 
        size_t operator()(const pair<T1, T2>& p) const {
            auto hash1 = hash<T1>{}(p.first);
            auto hash2 = hash<T2>{}(p.second);
            return hash1 ^ hash2;
        }
    };

    int countStone(unordered_map<int, vector<int>>& rAdj, unordered_map<int, vector<int>>& cAdj,
                   int cr, int cl, unordered_set<pair<int, int>, hash_pair>& vis) {
        if (vis.count({cr, cl})) return 0;
        int fromRow = 0, fromCol = 0;
        vis.insert({cr, cl});
        for (int nc : rAdj[cr]) {
            if (!vis.count({cr, nc})) {
                fromRow += countStone(rAdj, cAdj, cr, nc, vis);
            }
        }
        for (int nr : cAdj[cl]) {
            if (!vis.count({nr, cl})) {
                fromCol += countStone(rAdj, cAdj, nr, cl, vis);
            }
        }
        return fromRow + fromCol + 1;
    }

    int removeStones(vector<vector<int>>& stones) {
        if (stones.size() == 1) return 0;
        
        unordered_map<int, vector<int>> rAdj, cAdj;
        unordered_set<pair<int, int>, hash_pair> vis;
        
        for (const auto& stone : stones) {
            rAdj[stone[0]].push_back(stone[1]);
            cAdj[stone[1]].push_back(stone[0]);
        }
        
        int ans = 0;
        for (const auto& stone : stones) {
            if (!vis.count({stone[0], stone[1]})) {
                int temp = countStone(rAdj, cAdj, stone[0], stone[1], vis);
                if (temp >= 1) {
                    ans += temp - 1;
                }
            }
        }
        return ans;
    }
};
