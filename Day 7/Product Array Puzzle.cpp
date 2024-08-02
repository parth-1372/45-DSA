class Solution {
  public:
    // nums: given vector
    // return the Product vector P that hold product except self at each index
    vector<long long int> productExceptSelf(vector<long long int>& nums) {

        // code here
        int n=nums.size();
        vector<long long int> ans(n,0);
        unsigned long long a = 1;
        int zeroCount=0;
        for(int i=0;i<n;i++){
            if(nums[i]!=0){
                a=a*nums[i];
            }else{
                zeroCount++;
            }
        }
        if(zeroCount==0){
            for(int i=0;i<n;i++){
            long long int x = a/nums[i];
            ans[i]=x;
          }
        }
         else if(zeroCount==1){
             for(int i=0;i<n;i++){
           if(nums[i]==0)ans[i]=a;
           }
         }
        return ans;
    }
};