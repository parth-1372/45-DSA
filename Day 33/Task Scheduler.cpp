class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26, 0);
        for (char task : tasks) {
            freq[task - 'A']++;
        }

        sort(freq.begin(), freq.end());

        int maxFreq = freq[25];
        int maxFreqCount = 0;

        for (int i = 25; i >= 0 && freq[i] == maxFreq; --i) {
            maxFreqCount++;
        }

        int intervals = (maxFreq - 1) * (n + 1) + maxFreqCount;

        return max(intervals, (int)tasks.size());
    }
};
