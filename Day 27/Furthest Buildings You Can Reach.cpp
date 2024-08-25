#include <vector>
#include <queue>
#include <functional> // For std::greater
using namespace std;

class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int n = heights.size();
        priority_queue<int, vector<int>, greater<int>> pq; 

        int sum = 0; 
        int i = 0; 

        for (i = 1; i < n; ++i) {
            int need = heights[i] - heights[i - 1];
            
            if (need <= 0) {
                continue;
            }

           
            pq.push(need);
             
             if (pq.size() > ladders) {
                sum += pq.top();
                pq.pop();
            }

            if (sum > bricks) {
                break; 
            }
        }

        return i - 1;
    }
};
