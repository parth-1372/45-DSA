class Solution{
    public:
    void f(int index,vector<int>& arr,int& sum1,int& mini,int totalSum,int taken,int& ans){
        int n = arr.size();
        if(index == n){
            int sum2 = totalSum - sum1;
            if(n%2==0 && mini >  abs(sum1-sum2) && taken==n/2){
                mini = abs(sum1-sum2);
                ans=sum1;
            }
            if(n%2!=0 && mini >  abs(sum1-sum2) && (taken==n/2 || taken==n/2 +1)){
                mini = abs(sum1-sum2);
                ans=sum1;
            }
            return;
        }
        
        f(index+1,arr,sum1,mini,totalSum,taken,ans);
        sum1+=arr[index];
        taken++;
        f(index+1,arr,sum1,mini,totalSum,taken,ans);
        sum1-=arr[index];
        taken--;
    }
     vector<vector<int>> minDifference(vector<int>& arr, int n){
        //Code here
        int totalSum=0;
        for(int i=0;i<n;i++)totalSum+=arr[i];
        int mini = INT_MAX;
        int sum1 = 0;
        int ans = 0;
        f(0,arr,sum1,mini,totalSum,0,ans);
        sum1=ans;
        int sum2 = totalSum-sum1;
        vector<int> first ,second;
        if(sum1>=sum2){
            first.push_back(sum2);
            second.push_back(sum1);
        }else{
            first.push_back(sum1);
            second.push_back(sum2);
        }
       vector<vector<int>> qwe;
       qwe.push_back(first);
       qwe.push_back(second);
       return qwe;
    }
};