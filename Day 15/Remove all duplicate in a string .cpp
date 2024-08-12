class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<string> st;
        int n = s.length();
        string curr="";
        for(int i=0;i<n;i++){
           if(curr.length()==0){
            curr+=s[i];
            continue;
        }
        if(curr[curr.length()-1]==s[i]){
            curr+=s[i];
            if(curr.length()==k){
                if(st.empty())curr="";
                else{
                    curr=st.top();
                    st.pop();
                }
            }
        }else{
            st.push(curr);
            curr="";
            curr+=s[i];
        }
        }
        string ans=curr;
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
       reverse(ans.begin(),ans.end());
       return ans;
    }
};