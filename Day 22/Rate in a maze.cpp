class Solution {
  public:
    void f(vector<string>& ans,vector<vector<int>> &maze,
           vector<vector<int>> &vis,int cr,int cl,string s){
       
       int n=maze.size();
       if(cr<0 || cr>=n || cl<0 || cl>=n || vis[cr][cl]==1 || 
       maze[cr][cl]==0)return;
       if(cr==n-1 && cl==n-1){
           ans.push_back(s);
           return;
       }
       vis[cr][cl]=1;
       f(ans,maze,vis,cr+1,cl,s+'D');
       f(ans,maze,vis,cr-1,cl,s+'U');
       f(ans,maze,vis,cr,cl+1,s+'R');
       f(ans,maze,vis,cr,cl-1,s+'L');
       vis[cr][cl]=0;
       
    }
    vector<string> findPath(vector<vector<int>> &mat) {
        // Your code goes here
        int n=mat.size();
        vector<string> ans;
        vector<vector<int>> vis(n,vector<int>(n,0));
        string s="";
        f(ans,mat,vis,0,0,s);
        return ans;
    }
};