class Solution {
  public:
    void helper(vector<int> &arr,vector<int> &curr,set<vector<int>>& s,
           vector<int>& vis,vector<vector<int>>& ans)
           {
               if(curr.size()==arr.size()){
                   if(s.find(curr)==s.end()){
                       s.insert(curr);
                       ans.push_back(curr);
                   }
                   return;
               }
               int n=arr.size();
               
               for(int i=0;i<n;i++){
                   if(vis[i]==0){
                       vis[i]=1;
                       curr.push_back(arr[i]);
                       helper(arr,curr,s,vis,ans);
                       vis[i]=0;
                       curr.pop_back();
                   }
                   
               }
           }
    vector<vector<int>> uniquePerms(vector<int> &arr ,int n) {
        // code here
        set<vector<int>> s;
        vector<vector<int>> ans;
        sort(arr.begin(),arr.end());
        vector<int> curr,visited(n,0);
        helper(arr,curr,s,visited,ans);
        return ans;
    }
};