#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

#define int long long
using namespace std;

#define pb push_back
#define fri(n) for (int i = 0; i < n; i++)
#define sortv(v) sort((v).begin(), (v).end())
const int mod = 1e9 + 7;

bool canAllocate(vector<int> &arr, int mid, int cows) {
    int count = 1; // Placing the first cow
    int last_position = arr[0];

    for (int i = 1; i < arr.size(); i++) {
        if (arr[i] - last_position >= mid) {
            count++;
            last_position = arr[i];
        }
        if (count >= cows) return true;
    }
    return false;
}

void solve() {
    int n, cows;
    cin >> n >> cows;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    sort(arr.begin(), arr.end());

    int left = 1, right = arr[n - 1] - arr[0];
    int result = 0;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (canAllocate(arr, mid, cows)) {
            result = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    cout << result << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) solve();

    return 0;
}
