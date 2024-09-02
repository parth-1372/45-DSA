class Solution {
public:
    bool isPalindrome(string& s){
        string t=s;
        reverse(t.begin(),t.end());
        return s==t;
    }
    void f(string s,vector<vector<string>>& ans,vector<string>& curr){
        if(s.length()==0){
            ans.push_back(curr);
            return;
        }
        string temp = "";
        for(int i=0;i<s.length();i++){
            temp+=s[i];
            if(isPalindrome(temp)){
                curr.push_back(temp);
                string temp2 = s.substr(i+1);
                f(temp2,ans,curr);
                curr.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
       vector<vector<string>> ans;
       vector<string> curr;
       f(s,ans,curr);
       return ans;
    }
};