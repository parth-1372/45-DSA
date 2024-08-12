class StockSpanner {
public:
    stack<pair<int,int>> s;
    int index;
    StockSpanner() {
        index=0;
    }
    
    int next(int price) {
        while(!s.empty() && price>=s.top().first)s.pop();
        int ans=index+1;
        if(!s.empty()){
            ans=index-s.top().second;
        }
        s.push({price,index});
        index++;
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */