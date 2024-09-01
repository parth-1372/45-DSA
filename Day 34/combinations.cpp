class Solution {
public:
    void f(int n,int k,vector<vector<int>>& ans,vector<int>& currvec,int curr){
        if(k==0){
            ans.push_back(currvec);
            return;
        }
        for(int i=curr+1;i<=n;i++){
            currvec.push_back(i);
            f(n,k-1,ans,currvec,i);
            currvec.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> currvec;
        f(n,k,ans,currvec,0);
        return ans;
    }
};