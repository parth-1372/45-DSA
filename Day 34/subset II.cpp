class Solution {
public:
    void f(vector<int>& nums,int index,set<vector<int>>& s,vector<vector<int>>& ans,
          vector<int>& currVec){
          int n=nums.size();
          if(index==n){
            if(s.find(currVec)==s.end()){
                s.insert(currVec);
                ans.push_back(currVec);
            }
            return;
          }
          f(nums,index+1,s,ans,currVec);
          currVec.push_back(nums[index]);
          f(nums,index+1,s,ans,currVec);
          currVec.pop_back();
        }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        set<vector<int>> s;
        vector<vector<int>> ans;
        vector<int> currVec;
        f(nums,0,s,ans,currVec);
        return ans;
    }
};