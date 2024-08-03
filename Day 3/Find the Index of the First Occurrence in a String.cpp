class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size() , m= needle.size();
        for(int i=0;i<n-m+1;i++){
            if(haystack[i]==needle[0]){
                string s(haystack.begin()+i,haystack.begin()+i+m);
                if(s==needle)return i;
            }
        }
        return -1;
    }
};