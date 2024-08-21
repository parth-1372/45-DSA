#include <unordered_map>
#include <vector>
#include <string>
#include <set>

class Solution {
public:
    void f(unordered_map<string,vector<pair<string,double>>>& map, string curr, string target, set<string>& vis, double& ans, bool& found) {
        if (vis.find(curr) != vis.end()) return; 
        if (curr == target) { 
            found = true; 
            return; 
        }
        vis.insert(curr);
        
        for (auto& neighbor : map[curr]) {
            string nextNode = neighbor.first;
            double weight = neighbor.second;
            if (vis.find(nextNode) == vis.end()) {
                ans *= weight;
                f(map, nextNode, target, vis, ans, found);
                if (found) return; 
                ans /= weight;
            }
        }
    }

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string,vector<pair<string,double>>> map;
        set<string> validS;

        for (int i = 0; i < equations.size(); ++i) {
            string f = equations[i][0];
            string s = equations[i][1];
            double valfs = values[i];
            double valsf = 1.0 / values[i];
            map[f].push_back({s, valfs});
            map[s].push_back({f, valsf});
            validS.insert(f);
            validS.insert(s);
        }

        vector<double> ans;

        for (auto& query : queries) {
            string f1 = query[0];
            string s = query[1];

            // Check validity
            if (validS.find(f1) == validS.end() || validS.find(s) == validS.end()) {
                ans.push_back(-1.0);
                continue;
            }

            set<string> vis;
            double tempAns = 1.0;
            bool found = false;
            f(map, f1, s, vis, tempAns, found);
            ans.push_back(found ? tempAns : -1.0);
        }

        return ans;
    }
};
