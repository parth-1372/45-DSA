class NestedIterator {
public:
    queue<int> q;

    // Helper function to flatten the list
    void helper(const vector<NestedInteger> &nestedList) {
        for (const auto& ni : nestedList) {
            if (ni.isInteger()) {
                q.push(ni.getInteger());
            } else {
                helper(ni.getList());
            }
        }
    }

    // Constructor
    NestedIterator(vector<NestedInteger> &nestedList) {
        helper(nestedList);
    }
    
    int next() {
        int val = q.front();
        q.pop();
        return val;
    }
    
    bool hasNext() {
        return !q.empty();
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
