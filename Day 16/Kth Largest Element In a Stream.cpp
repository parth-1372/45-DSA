class KthLargest {
public:
    set<pair<int,int>> s;  
    int setSize;  
    int index;
    KthLargest(int k, vector<int>& nums){
        setSize=k;
        for (int num : nums) {
            add(num);
        }
    }
    
    int add(int val) {
        if (s.size() < setSize) {
            s.insert({val,index++});
        } else if (val > (*s.begin()).first) {
            s.erase(s.begin());
            s.insert({val,index++});
        }
        return (*s.begin()).first;
    }
};
