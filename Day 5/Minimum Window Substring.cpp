class Solution {
public:
    string minWindow(string s, string t) {
        if (t.empty() || s.size() < t.size()) return "";
        
        unordered_map<char, int> target;
        for (char c : t) {
            target[c]++;
        }
        
        unordered_map<char, int> window;
        int required = target.size();
        int formed = 0;
        
        int l = 0, r = 0;
        int minLen = INT_MAX, start = 0;
        
        while (r < s.size()) {
            char c = s[r];
            window[c]++;
            
            if (target.count(c) && window[c] == target[c]) {
                formed++;
            }
            
            while (l <= r && formed == required) {
                c = s[l];
                
                if (r - l + 1 < minLen) {
                    minLen = r - l + 1;
                    start = l;
                }
                
                window[c]--;
                if (target.count(c) && window[c] < target[c]) {
                    formed--;
                }
                
                l++;
            }
            
            r++;
        }
        
        return minLen == INT_MAX ? "" : s.substr(start, minLen);
    }
};
