class Solution {
public:
    void dfs(vector<vector<int>>& ans, int cr, int cl, int color, int prev) {
        int m = ans.size(), n = ans[0].size();
        if (cr < 0 || cr >= m || cl < 0 || cl >= n || ans[cr][cl] != prev || ans[cr][cl] == color) {
            return;
        }
        
        ans[cr][cl] = color;
        vector<int> rowAdd = {0, 0, 1, -1};
        vector<int> colAdd = {1, -1, 0, 0};
        
        for (int i = 0; i < 4; ++i) {
            int newRow = cr + rowAdd[i];
            int newCol = cl + colAdd[i];
            dfs(ans, newRow, newCol, color, prev);
        }
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if (image[sr][sc] == color) return image;  // Early return if the starting pixel is already the target color
        int prev = image[sr][sc];
        vector<vector<int>> ans = image;
        dfs(ans, sr, sc, color, prev);
        return ans;
    }
};
