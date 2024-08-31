class Solution {
public:
    int minDeletions(string s) {
        vector<int> freq(26,0);
        int n = s.length(),ans=0;
        for(int i=0;i<n;i++)freq[s[i]-'a']++;
        vector<int> arr;
        for(int i=0;i<26;i++)if(freq[i])arr.push_back(freq[i]);
        sort(arr.rbegin(),arr.rend());
        int i=1;
        while(i!=arr.size()){
            i=1;
            vector<int> temp;
            bool check = true;
            for(;i<arr.size();i++){
            if(arr[i]==arr[i-1]){
                arr[i]--;
                ans++;
                break;
            }
           }
           for(int j=0;j<arr.size();j++){
             if(arr[j])temp.push_back(arr[j]);
           }
           arr=temp;
           sort(arr.begin(),arr.end());
        }
        return ans;
    }
};