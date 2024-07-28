class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> leftSmaller(n, 0), rightSmaller(n, n - 1);
        stack<int> s, s1;
        
        for (int i = 0; i < n; i++) {
            while (!s.empty() && heights[s.top()] >= heights[i])
                s.pop();
            leftSmaller[i] = (s.empty() ? 0 : s.top() + 1);
            s.push(i);
        }
        
        for (int i = n - 1; i >= 0; i--) {
            while (!s1.empty() && heights[s1.top()] >= heights[i])
                s1.pop();
            rightSmaller[i] = (s1.empty() ? n - 1 : s1.top() - 1);
            s1.push(i);
        }
        
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans = max(ans, (rightSmaller[i] - leftSmaller[i] + 1) * heights[i]);
        }
        
        return ans;
    }
};
