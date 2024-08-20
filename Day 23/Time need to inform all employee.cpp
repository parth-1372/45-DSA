class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<vector<int>> adjList(n);
        for(int i=0;i<n;i++){
            if(i!=headID)adjList[manager[i]].push_back(i);
        }
        int ans=0;
        queue<pair<int,int>> q;
        q.push({headID,informTime[headID]});
        while(!q.empty()){
            int currNode = q.front().first;
            int currTime = q.front().second;
            q.pop();
            ans= max(ans,currTime);

            for(int i=0;i<adjList[currNode].size();i++){
                q.push({adjList[currNode][i],currTime+informTime[adjList[currNode][i]]});
            }
        }
        return ans;
    }
};