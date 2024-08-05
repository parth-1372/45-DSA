class Solution {
public:
    long long findPages(int n, int arr[], int m) {
        if (m > n) return -1;

        int left = *max_element(arr, arr + n);
        long long right = accumulate(arr, arr + n, 0LL);

        while (left < right) {
            int mid = left + (right - left) / 2;
            if (canAllocate(arr, n, m, mid)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }

private:
    bool canAllocate(int arr[], int n, int m, int maxPages) {
        int students = 1;
        long long currentPages = 0;

        for (int i = 0; i < n; i++) {
            if (currentPages + arr[i] > maxPages) {
                students++;
                currentPages = arr[i];
                if (students > m) return false;
            } else {
                currentPages += arr[i];
            }
        }
        return true;
    }
};
