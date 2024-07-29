class Solution {
public:
    string smallestWindow (string s, string p) {
        if (s.length() < p.length()) return "-1";

        vector<int> p_count(128, 0), window_count(128, 0);
        for (char c : p) {
            p_count[c]++;
        }

        int have = 0, need = p.length();
        int left = 0, min_len = INT_MAX, start = 0;

        for (int right = 0; right < s.length(); right++) {
            char c = s[right];
            if (p_count[c] > 0) {
                window_count[c]++;
                if (window_count[c] <= p_count[c]) {
                    have++;
                }
            }

            while (have == need) {
                if ((right - left + 1) < min_len) {
                    start = left;
                    min_len = right - left + 1;
                }

                char left_char = s[left];
                if (p_count[left_char] > 0) {
                    window_count[left_char]--;
                    if (window_count[left_char] < p_count[left_char]) {
                        have--;
                    }
                }
                left++;
            }
        }

        if(min_len == INT_MAX) return "-1";
        return s.substr(start, min_len);
    }
};
