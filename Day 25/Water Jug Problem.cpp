class Solution {
public:
    bool f(int currX, int currY, int capX, int capY, int target, set<pair<int,int>>& vis) {
        if (currX == target || currY == target || currX+currY==target) return true;
        if (vis.find({currX, currY}) != vis.end()) return false;

        vis.insert({currX, currY});
        bool currAns = false;

        // Fill second jug
        if (vis.find({currX, capY}) == vis.end())
            currAns = currAns || f(currX, capY, capX, capY, target, vis);
        if (currAns) return true;

        // Empty second jug
        if (vis.find({currX, 0}) == vis.end())
            currAns = currAns || f(currX, 0, capX, capY, target, vis);
        if (currAns) return true;

        // Fill first jug
        if (vis.find({capX, currY}) == vis.end())
            currAns = currAns || f(capX, currY, capX, capY, target, vis);
        if (currAns) return true;

        // Empty first jug
        if (vis.find({0, currY}) == vis.end())
            currAns = currAns || f(0, currY, capX, capY, target, vis);
        if (currAns) return true;

        // First to second jug
        if (currY + currX <= capY) {
            if (vis.find({0, currY + currX}) == vis.end())
                currAns = currAns || f(0, currY + currX, capX, capY, target, vis);
            if (currAns) return true;
        } else {
            if (vis.find({currX - (capY - currY), capY}) == vis.end())
                currAns = currAns || f(currX - (capY - currY), capY, capX, capY, target, vis);
            if (currAns) return true;
        }

        // Second to first jug
        if (currY + currX <= capX) {
            if (vis.find({currX + currY, 0}) == vis.end())
                currAns = currAns || f(currX + currY, 0, capX, capY, target, vis);
            if (currAns) return true;
        } else {
            if (vis.find({capX, currY - (capX - currX)}) == vis.end())
                currAns = currAns || f(capX, currY - (capX - currX), capX, capY, target, vis);
            if (currAns) return true;
        }

        return false;
    }

    bool canMeasureWater(int x, int y, int target) {
        if(target>x+y)return false;
        set<pair<int, int>> vis;
        return f(0, 0, x, y, target, vis);
    }
};
