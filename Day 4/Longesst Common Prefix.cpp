class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans="";
        int m=INT_MAX;
        for(int i=0;i<strs.size();i++){
            int temp=strs[i].length();
            m=min(m,temp);
        }
        for(int i=0;i<m;i++){
            for(int j=1;j<strs.size();j++){
                if(strs[j][i]!=strs[j-1][i]){
                    return ans;
                }
            }
            ans+=strs[0][i];
        }
        return ans;
    }
};