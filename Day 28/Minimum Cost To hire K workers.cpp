class Solution {
public:
    static bool comparator(const std::pair<int, int>& a, const std::pair<int, int>& b) {
        double c = static_cast<double>(a.second) / a.first;
        double d = static_cast<double>(b.second) / b.first;
        return c < d; 
    }

    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        int n = quality.size();
        vector<pair<int, int>> arr(n);

        for (int i = 0; i < n; i++) {
            arr[i] = {quality[i], wage[i]};
        }

        sort(arr.begin(), arr.end(), comparator);

        priority_queue<int> pq;
        int sumQuality = 0;
        double minCost = numeric_limits<double>::max();

        for (int i = 0; i < n; i++) {
            sumQuality += arr[i].first;
            pq.push(arr[i].first);

            if (pq.size() > k) {
                sumQuality -= pq.top();
                pq.pop();
            }

            if (pq.size() == k) {
                double cost = static_cast<double>(arr[i].second) / arr[i].first * sumQuality;
                minCost = min(minCost, cost);
            }
        }

        return minCost;
    }
};
