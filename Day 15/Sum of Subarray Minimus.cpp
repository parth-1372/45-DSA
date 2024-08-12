class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        long long int ans = 0;
        long long int mod = 1e9 + 7;
        
        // Arrays to store the distance to the previous and next less elements
        vector<int> left(n), right(n);
        stack<int> s;
        
        // Find the previous less element for each element
        for (int i = 0; i < n; i++) {
            while (!s.empty() && arr[s.top()] > arr[i])
                s.pop();
            left[i] = (s.empty()) ? i + 1 : i - s.top();
            s.push(i);
        }
        
        // Clear the stack to reuse it for the next less element
        while (!s.empty()) s.pop();
        
        // Find the next less element for each element
        for (int i = n - 1; i >= 0; i--) {
            while (!s.empty() && arr[s.top()] >= arr[i])
                s.pop();
            right[i] = (s.empty()) ? n - i : s.top() - i;
            s.push(i);
        }
        
        // Calculate the result using the number of subarrays where arr[i] is the minimum
        for (int i = 0; i < n; i++) {
            ans = (ans + (long long)arr[i] * left[i] * right[i]) % mod;
        }
        
        return ans;
    }
};
