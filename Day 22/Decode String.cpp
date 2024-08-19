class Solution {
public:
    string decodeString(string s) {
        vector<pair<int, string>> vec;
        int i = 0;

        while (i < s.length()) {
            int num = 0;

            // Handle the number
            while (i < s.length() && isdigit(s[i])) {
                num = num * 10 + (s[i] - '0');
                i++;
            }

            string temp = "";

            // Handle the case for '['
            if (i < s.length() && s[i] == '[') {
                i++;
                int count = 1;
                while (i < s.length() && count != 0) {
                    if (s[i] == '[') count++;
                    if (s[i] == ']') count--;
                    if (count) temp += s[i];
                    i++;
                }
                vec.push_back({num, decodeString(temp)});
            } 
            // Handle regular characters
            else {
                while (i < s.length() && isalpha(s[i])) {
                    temp += s[i];
                    i++;
                }
                vec.push_back({1, temp});
            }
        }

        string ans="";
        for(int i=0;i<vec.size();i++){
            for(int j=0;j<vec[i].first;j++){
                ans+=vec[i].second;
            }
        }
        return ans;  
    }
};
