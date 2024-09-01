#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& arr) {
        if (arr.empty()) return 0;
        
        sort(arr.begin(), arr.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });
        
        int n = arr.size();
        int end = arr[0][1];
        int ans = 0;
        
        for (int i = 1; i < n; ++i) {
            if (arr[i][0] < end) {
                ans++;
            } else {
                end = arr[i][1];
            }
        }
        
        return ans;
    }
};
