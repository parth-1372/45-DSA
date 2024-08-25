class Solution {
  public:
    int maxLen(vector<int>& arr, int n) {
        // Your code here
        bool isNeg=false,isPos=false;
        unordered_map<int,int> map;
        int sum=0,ans=INT_MIN;
        for(int i=0;i<n;i++){
            if(arr[i]<0)isNeg=true;
            if(arr[i]>0)isPos=true;
            sum+=arr[i];
            if(sum==0)ans=max(ans,i+1);
            if(map.find(sum)!=map.end()&&isPos&&isNeg){
                ans=max(ans,i-map[sum]);
            }
            if(map.find(sum)==map.end())map[sum]=i;
        }
        int conZero=0,i=0;
       while(i<n){
            if(arr[i]==0){
                int count=0;
                while(i<n && arr[i]==0){
                    count++;
                    i++;
                }
                conZero=max(conZero,count);
            }else{
                i++;
            }
        }
        ans=max(ans,conZero);
        return ans;
    }
};