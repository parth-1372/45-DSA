class Solution {
public:
    // Function to find maximum of minimums of every window size.
    vector<int> maxOfMin(int arr[], int n) {
        vector<int> leftSmaller(n, -1), rightSmaller(n, n);
        stack<int> sl, sr;

        // Finding right smaller elements
        for (int i = 0; i < n; i++) {
            while (!sr.empty() && arr[sr.top()] > arr[i]) {
                rightSmaller[sr.top()] = i;
                sr.pop();
            }
            sr.push(i);  // Push index instead of element
        }

        // Finding left smaller elements
        for (int i = n - 1; i >= 0; i--) {
            while (!sl.empty() && arr[sl.top()] > arr[i]) {
                leftSmaller[sl.top()] = i;
                sl.pop();
            }
            sl.push(i);  // Push index instead of element
        }

        // Initialize the answer array
        vector<int> ans(n + 1, 0);

        // Fill the answer array
        for (int i = 0; i < n; i++) {
            int w = rightSmaller[i] - leftSmaller[i] - 1;
            ans[w] = max(ans[w], arr[i]);
        }

        // Fill the remaining entries
        for (int i = n - 1; i >= 1; i--) {
            ans[i] = max(ans[i], ans[i + 1]);
        }

        // Remove the 0th element as the window size starts from 1
        ans.erase(ans.begin());
        
        return ans;
    }
};
