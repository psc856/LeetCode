class Solution {
public:
    long long brute(vector<int>& nums) {
        long long ans=0;
        int n=nums.size();
        for(int i=0;i<n;i++ ){
            int smallest=nums[i];
            int greatest=nums[i];
            //store the greatest and smallest element
            for(int j=i+1;j<n;j++){
                greatest=max(greatest,nums[j]);
                smallest=min(smallest,nums[j]);
                ans+=greatest-smallest;
            }
        }
        return ans;
    }
    long long subArrayRanges(vector<int>& nums) {
        int n=nums.size();
        vector<int> nxtGrt(n,n),prevGrt(n,-1);
        stack<int> stk;
        //next Greater

        stk.push(n-1);

        for(int i=n-2;i>=0;i--){
            while(!stk.empty() && nums[i]>nums[stk.top()]){
                stk.pop();
            }
            //2 conditions -> either empty if none greater available or greater at top of stack;
            nxtGrt[i]= stk.empty() ? n : stk.top();
            //push current in stack
            stk.push(i);
        }
        
        //empty the stack
        while(!stk.empty()){
            stk.pop();
        }
        //prev Greater
        stk.push(0);
        for(int i=1;i<n;i++){
            //pop until stack has smaller element than current
            while(!stk.empty() && nums[stk.top()] <=nums[i]){
                stk.pop();
            }
            //2 conditions -> either empty if none greater available or greater at top of stack;
            prevGrt[i] = stk.empty() ? -1 : stk.top();
            //push current in stack
            stk.push(i);
        }
        //empty the stack
        while(!stk.empty()){
            stk.pop();
        }

        vector<int> nxtSml(n,n),prevSml(n,-1);
        //next Smaller
        stk.push(n-1);
        for(int i=n-2;i>=0;i--){
            while(!stk.empty() && nums[i] < nums[stk.top()]){
                stk.pop();
            }
            //2 conditions -> either empty if none smaller available or smaller at top of stack;
            nxtSml[i]=stk.empty() ? n : stk.top();
            //push current in stack
            stk.push(i);
        }
        //empty the stack
        while(!stk.empty()){
            stk.pop();
        }

         //prev Smaller
        stk.push(0);
        for(int i=1;i<n;i++){
            while(!stk.empty() && nums[i] <= nums[stk.top()]){
                stk.pop();
            }
            //2 conditions -> either empty if none smaller available orsmaller at top of stack;
            prevSml[i]=stk.empty() ? -1 : stk.top();
            //push current in stack
            stk.push(i);
        }
        long long minn=0,maxx=0;
        for(int i=0;i<n;i++){
            long long left=i-prevSml[i];            
            long long right=nxtSml[i] - i;
            minn+= left*right*nums[i];
            
            long long leftt=i-prevGrt[i];
            long long rightt=nxtGrt[i]-i;            
            maxx+=leftt*rightt*nums[i];
        }
        return maxx-minn;
    }
};