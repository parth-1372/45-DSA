class Solution {
public:
    string convertToTitle(int columnNumber) {
        string ans = "";
        while (columnNumber > 0) {
            columnNumber--;  // Decrement columnNumber to handle zero-indexing
            char ch = 'A' + (columnNumber % 26);
            ans = ch + ans;  // Prepend the character to the result
            columnNumber /= 26;
        }
        return ans;
    }
};
