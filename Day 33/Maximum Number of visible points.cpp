#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

class Solution {
public:
    int visiblePoints(std::vector<std::vector<int>>& points, int angless, std::vector<int>& location) {
        int n = points.size();
        vector<double> angle;
        int count = 0;
        const double pi = M_PI;

        double angleLimit = angless * (pi / 180.0);

        for(int i = 0; i < n; i++){
            double dx = points[i][0] - location[0];
            double dy = points[i][1] - location[1];
            
            if(dx == 0 && dy == 0){
                count++;
                continue;
            }

            double theta = atan2(dy, dx);
            angle.push_back(theta);
        }
        if(count==n)return n;
        sort(angle.begin(), angle.end());

        for(int i = 0; i < n; i++){
            angle.push_back(angle[i] + 2 * pi);
        }

        int maxCount = 0;
        int i = 0, j = 0;
        n = angle.size();

        while(i < n / 2 && j < n){
            while(j < n && angle[j] - angle[i] <= angleLimit){
                j++;
            }
            maxCount = max(maxCount, j - i);
            i++;
        }

        return maxCount + count;
    }
};
