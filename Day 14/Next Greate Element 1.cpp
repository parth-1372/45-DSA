class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size(),n2=nums2.size();
          vector<int> ans(n1);
        // for(int i=0;i<n1;i++){
        //     bool currFind=false;
        //     int nextGreater=-1;
        //     for(int j=0;j<n2;j++){
        //         if(nums2[j]==nums1[i]){
        //             currFind=true;
        //         }
        //         if(nums2[j]>nums1[i] && currFind){
        //             nextGreater=nums2[j];
        //             break;
        //         }
        //     }
        //     ans.push_back(nextGreater);
        // }
        unordered_map<int,int> map;
        for(int i=0;i<n1;i++){
            map[nums1[i]]=i;
        }
        stack<int> s;
        for(int i=n2-1;i>=0;i--){
            int curr = nums2[i];
            while( !s.empty()&&curr>s.top()){
                s.pop();
            }
            if(map.find(curr)!=map.end()){
              if(!s.empty())ans[map[curr]]=s.top();
              else ans[map[curr]]= -1;
            }
            
            s.push(curr);
        }
        return ans;
    }
};