class Solution {
public:
    void helper(vector<pair<int,int>>& arr , vector<int>& ans , int left , int right){
        if(left>=right) return;
        int mid = left + (right-left)/2;
        helper(arr,ans,left,mid);
        helper(arr,ans,mid+1,right);
        
        int i=left, j=mid+1, count=0;
        vector<pair<int,int>> temp(right-left+1);
        int k = 0;
        
        while(i<=mid && j<=right){
            if(arr[i].first > arr[j].first){
                count++;
                temp[k++] = arr[j++];
            }else{
                ans[arr[i].second] += count;
                temp[k++] = arr[i++];
            }
        }
        
        while(i<=mid){
            ans[arr[i].second] += count;
            temp[k++] = arr[i++];
        }
        
        while(j<=right){
            temp[k++] = arr[j++];
        }
        
        for(int p=0; p<k; p++){
            arr[left+p] = temp[p];
        }
    }
    
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int,int>> arr(n);
        for(int i=0; i < n; i++){
            arr[i] = {nums[i], i};
        }
        vector<int> ans(n, 0);
        helper(arr, ans, 0, n-1);
        return ans;
    }
};
