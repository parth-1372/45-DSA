
class Solution 
{
    public:
    //Function to find the minimum number of swaps required to sor
	int minSwaps(vector<int>&nums)
	{
	    // Code here
	    unordered_map<int,int> map;
	    vector<int> arr=nums;
	    sort(arr.begin(),arr.end());
	    int n=nums.size();
	    int ans = 0;
	    for(int i=0;i<n;i++){
	        map[nums[i]]=i;
	    }
	    for(int i=0;i<n;i++){
	        int index = map[arr[i]];
	        if(index!=i){
	            ans++;
	            swap(nums[i],nums[index]);
	            map[arr[i]]=i;
	            map[nums[index]]=index;
	        }
	    }
	    return ans;
	}
};
