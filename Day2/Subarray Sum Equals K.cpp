// https://leetcode.com/problems/subarray-sum-equals-k/

class Solution {
public:
    int subarraySum(vector<int>& num, int k) {
        int ans=0,n=num.size();
        // for(int i=0;i<n;i++){
        //     int sum=0;
        //     for(int j=i;j<n;j++){
        //         sum+=nums[j];
        //         if(sum==k)ans++;
        //     }
        // }
        
        map<int,int> m;
        int sum=0;
        m[0]=1;
        for(int i=0;i<n;i++){
            sum += num[i];
            if (m.find(sum - k) != m.end()) {
                ans += m[sum - k];
            }
            m[sum]++;
        }
        return ans;
    }
};