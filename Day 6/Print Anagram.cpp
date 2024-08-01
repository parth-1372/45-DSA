class Solution{
  public:
    vector<vector<string> > Anagrams(vector<string>& string_list) {
        //code here
        unordered_map<string,vector<string>> map;
        int n=string_list.size();
        for(int i=0;i<n;i++){
            string temp = string_list[i];
            sort(temp.begin(),temp.end());
            map[temp].push_back(string_list[i]);
        }
        vector<vector<string>> ans;
        for(auto it=map.begin();it!=map.end();it++){
           ans.push_back(it->second);
        }
        return ans;
    }
};