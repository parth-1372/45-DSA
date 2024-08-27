class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n+1,0);
        for(int i=1;i<=n;i++){
            bitset<32> temp(i);
            int num1=0;
            for(int j=0;j<32;j++)if(temp[j]==1)num1++;
            ans[i]=num1;
        }
        return ans;
    }
};