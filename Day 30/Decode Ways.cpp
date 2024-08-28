class Solution {
public:
    int f(int i, string s, unordered_map<int, int>& map) {
        int n = s.length();
        if (i == n) return 1; 
        if (s[i] == '0') return 0;
        if (map.find(i) != map.end()) return map[i]; 

        int currCount = f(i + 1, s, map); 

        if (i + 1 < n) { 
            int num = stoi(s.substr(i, 2)); 
            if (num >= 10 && num <= 26) {
                currCount += f(i + 2, s, map);
            }
        }

        map[i] = currCount; 
        return currCount;
    }

    int numDecodings(string s) {
        unordered_map<int, int> map;
        return s.empty() ? 0 : f(0, s, map);
    }
};
