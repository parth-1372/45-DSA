class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        unordered_map<int,int> degree;
        unordered_map<int,vector<int>> adjcent;
        set<int> st;
        int n = adjacentPairs.size();
        for(int i=0;i<n;i++){
            int f = adjacentPairs[i][0];
            int s = adjacentPairs[i][1];
            degree[f]++;
            degree[s]++;
            adjcent[f].push_back(s);
            adjcent[s].push_back(f);
            if(degree[f]==1)st.insert(f);
            else st.erase(f);
            if(degree[s]==1)st.insert(s);
            else st.erase(s);
        }
        vector<int> ans;
        ans.push_back(*st.begin());
        ans.push_back(adjcent[*st.begin()][0]);
        while(ans.size()!=n+1){
            int last = ans[ans.size()-1];
            int lasttolast= ans[ans.size()-2];
            vector<int> curr = adjcent[last];
            for(int i=0;i<curr.size();i++){
                if(curr[i]!=lasttolast)ans.push_back(curr[i]);
            }
        }
        return ans;
    }
};