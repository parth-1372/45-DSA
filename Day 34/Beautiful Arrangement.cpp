class Solution {
public:
    void f(int n, int i, int& count, vector<int>& vis) {
        if (i > n) {
            count++;
            return;
        }
        for (int j = 1; j <= n; j++) {  // Fix the loop range
            if (vis[j] == 0 && (i % j == 0 || j % i == 0)) {
                vis[j] = 1;
                f(n, i + 1, count, vis);
                vis[j] = 0;
            }
        }
    }

    int countArrangement(int n) {
        int count = 0;
        vector<int> vis(n + 1, 0);
        f(n, 1, count, vis);
        return count;
    }
};
