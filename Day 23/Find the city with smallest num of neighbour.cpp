class Solution {
public:
   int findNumCity( vector<vector<pair<int,int>>>& adj,int th,int curr){
       set<int> s;
       priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
       q.push({0,curr});
       int n=adj.size();
       vector<int> vis(n,0);
       while(!q.empty()){
         int currNode=q.top().second;
         int currDist=q.top().first;
         q.pop();
         vis[currNode]=1;
         if(currDist>th)break;
         else{
            s.insert(currNode);
         } 

         for(int i=0;i<adj[currNode].size();i++){
            int newDist=currDist+adj[currNode][i].second;
            int child=adj[currNode][i].first;
            if(!vis[child] && newDist<=th){
                q.push({newDist,child});
            }
         }
       }
       return s.size()-1;
   }
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<pair<int,int>>> adj(n);
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
            adj[edges[i][1]].push_back({edges[i][0],edges[i][2]});
        }
        int ans=-1,prevNum=INT_MAX;
        for(int i=0;i<n;i++){
            cout<<i<<endl;
            int temp=findNumCity(adj,distanceThreshold,i);
            cout<<endl<<i<<"  "<<temp<<endl;
            if(temp<=prevNum){
                prevNum=temp;
                ans=i;
            }
        }
        return ans;
    }
};