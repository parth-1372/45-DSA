#include <vector>
#include <set>

class Solution {
public:
    int nthUglyNumber(int n) {
        if (n <= 0) return 0;
        
        std::set<long long> st;  
        st.insert(1); 
        
        long long ans = 1;
        
        for (int i = 1; i < n; ++i) {
            ans = *st.begin();  
            st.erase(st.begin());  
            
            st.insert(ans * 2);
            st.insert(ans * 3);
            st.insert(ans * 5);
        }
        
        ans = *st.begin(); 
        
        return static_cast<int>(ans);
    }
};
