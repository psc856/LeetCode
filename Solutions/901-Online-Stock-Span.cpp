class StockSpanner {
public:
    StockSpanner() {
        
    }
    stack<pair<int,int>> stk; //<int,int> ->  < price,span >
    
    int next(int price) {
        int ans=1;
        //popping out smaller ones than current and saving how many popped out by self with it for future refrences to add
        while(!stk.empty() && stk.top().first<=price){
            ans+=stk.top().second;
            stk.pop();
        }
        stk.push({price,ans});
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */