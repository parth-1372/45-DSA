class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        set<int> s;
        int n=nums.size();
        unordered_map<int,int> map;
        vector<int> ans;
        for(int i=0;i<k;i++){
          map[nums[i]]++;
          s.insert(nums[i]);
        }
        ans.push_back((*s.rbegin()));
        for(int i=k;i<n;i++){
           map[nums[i-k]]--;
           if(map[nums[i-k]]==0){
            s.erase(nums[i-k]);
           }
           map[nums[i]]++;
           s.insert(nums[i]);
           ans.push_back((*s.rbegin()));
        }
        return ans;
    }
};