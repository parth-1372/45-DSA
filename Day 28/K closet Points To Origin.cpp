class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> ans;
        priority_queue<pair<double,int>> pq;
        int n=points.size();
        for(int i=0;i<n;i++){
            double dist = sqrt(pow(points[i][0],2)+pow(points[i][1],2));
            pq.push({dist,i});
            if(pq.size()>k)pq.pop();
        }
        while(!pq.empty()){
            ans.push_back(points[pq.top().second]);
            pq.pop();
        }
        return ans;
    }
};