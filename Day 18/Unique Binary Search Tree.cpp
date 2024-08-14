class Solution {
public:
    int helper(int left,int right,int n){
        if(left>right)return 0;
        if(left==right)return 1;
        int ans=0;
        for(int i=left;i<=right;i++){
            if(i==left){
                ans+=helper(left+1,right,n);
            }
            else if(i==right){
                ans+=helper(left,right-1,n);
            }
            else{
              int temp1=helper(left,i-1,n);
              int temp2=helper(i+1,right,n);
              ans+=(temp1*temp2);
            }
        }
        return ans;
    }
    int numTrees(int n) {
        return helper(1,n,n);
    }
};