
class Solution {
  public:
    // Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& mat) {
        // code here
        int  n = mat.size();
        for(int i=0;i<n;i++){
            int countRow=0;
            int countCol=0;
            for(int j=0;j<n;j++){
                if(mat[i][j])countRow++;
                if(mat[j][i])countCol++;
            }
           if(countRow==0 && countCol==n-1)return i;
        }
       
        return -1;
    }
};