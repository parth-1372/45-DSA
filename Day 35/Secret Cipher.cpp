class Solution {
public:
    string compress(string s) {
        int n = s.length();
        stack<char> st;
        int i = n - 1;

        // Constants for hashing
        const int p = 31; // A prime number for base
        const int m = 1e9 + 7; // A large prime number for modulus

        // Precompute the powers of p
        vector<long long> p_pow(max(n, 1) + 1, 1);
        for (int j = 1; j <= n; j++) {
            p_pow[j] = (p_pow[j - 1] * p) % m;
        }

        // Compute hash values for all prefixes
        vector<long long> prefix_hash(n + 1, 0);
        for (int j = 0; j < n; j++) {
            prefix_hash[j + 1] = (prefix_hash[j] + (s[j] - 'a' + 1) * p_pow[j]) % m;
        }

        // Hashing function
        auto hash = [&](int l, int r) {
            long long hash_value = (prefix_hash[r + 1] - prefix_hash[l] + m) % m;
            hash_value = (hash_value * p_pow[n - r - 1]) % m;
            return hash_value;
        };

        while (i >= 0) {
            if (i % 2 == 0) {
                st.push(s[i]);
                i--;
            } else {
                int mid = (i + 1) / 2;
                int left_start = 0;
                int left_end = mid - 1;
                int right_start = mid;
                int right_end = i;

                if (hash(left_start, left_end) == hash(right_start, right_end)) {
                    st.push('*');
                    i = mid - 1;
                } else {
                    st.push(s[i]);
                    i--;
                }
            }
        }

        string ans = "";
        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }
        return ans;
    }
};