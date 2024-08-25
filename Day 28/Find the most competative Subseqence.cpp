class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        int prev=-1,n=nums.size(),curr=n-k;
       priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
       for(int i=0;i<=curr;i++){
        pq.push({nums[i],i});
       }
      curr++;
      vector<int> ans;
      while(!pq.empty() && curr<n){
        if(prev!=-1){
            while(!pq.empty() && pq.top().second<prev){
                pq.pop();
            }
        }
        int element = pq.top().first;
        int index = pq.top().second;
        prev=index;
        ans.push_back(element);
        pq.pop();
        pq.push({nums[curr],curr});
        curr++;
      }
       while(!pq.empty() && pq.top().second<prev){
                pq.pop();
        }
      ans.push_back(pq.top().first);
      return ans;
    }
};