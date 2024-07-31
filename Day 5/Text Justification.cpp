#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ans;
        int n = words.size();
        int i = 0;

        while (i < n) {
            int lineLength = 0, count = 0;
            int j = i;
            while (j < n && lineLength + words[j].size() + count <= maxWidth) {
                lineLength += words[j].size();
                count++;
                j++;
            }
            
            int spaceSlots = count - 1;
            string line;
            if (j == n || spaceSlots == 0) {
                // Last line or a line with a single word (left-justified)
                for (int k = i; k < j; k++) {
                    line += words[k];
                    if (k < j - 1) line += " ";
                }
                line += string(maxWidth - line.size(), ' ');
            } else {
                // Fully justify the line
                int totalSpaces = maxWidth - lineLength;
                int spaces = totalSpaces / spaceSlots;
                int extraSpaces = totalSpaces % spaceSlots;
                
                for (int k = i; k < j - 1; k++) {
                    line += words[k];
                    line += string(spaces + (k - i < extraSpaces ? 1 : 0), ' ');
                }
                line += words[j - 1]; // Last word in the line
            }
            
            ans.push_back(line);
            i = j;
        }
        
        return ans;
    }
};
