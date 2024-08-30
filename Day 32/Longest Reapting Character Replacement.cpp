class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.length();
        int maxLen = 0;
        int left = 0;
        unordered_map<char, int> freq;
        int maxFreq = 0;
        
        for (int right = 0; right < n; right++) {
            freq[s[right]]++;
             maxFreq = max(maxFreq, freq[s[right]]);
            
           
            while (right - left + 1 - maxFreq > k) {
                freq[s[left]]--;
                left++;
            }
            
            maxLen = max(maxLen, right - left + 1);
        }
        
        return maxLen;
    }
};
