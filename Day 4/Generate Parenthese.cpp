class Solution {
public:
    void helper(int n, vector<string>& ans, string curr, int open, int close) {
        if (curr.length() == 2 * n) {
            ans.push_back(curr);
            return;
        }
        
        if (open < n) {
            helper(n, ans, curr + '(', open + 1, close);
        }
        if (close < open) {
            helper(n, ans, curr + ')', open, close + 1);
        }
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        helper(n, ans, "", 0, 0);
        return ans;
    }
};
