class Solution {
public:
    int minCost(string s, vector<int>& arr) {
        int n=arr.size();
        int ans=0,i=0;
        while(i<n){
            char currColour = s[i];
            int j = i,sum=0;
            int maxi=INT_MIN;
            while(j<n && s[j] == currColour ){
                sum+=arr[j];
                maxi=max(maxi,arr[j]);
                j++;
            }
            if(j-i>1){
                ans+=sum-maxi;
            }
            i=j;
        }
    W    return ans;
    }
};