class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> map;
        for(int i=0;i<strs.size();i++){
            string temp=strs[i];
            sort(temp.begin(),temp.end());
            map[temp].push_back(strs[i]);
        }
        vector<vector<string>> ans;
        auto it=map.begin();
        for(;it!=map.end();it++){
            ans.push_back((it)->second);
        }
        return ans;
    }
};