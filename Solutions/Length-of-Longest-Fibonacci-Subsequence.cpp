class Solution {
public:
    int recur(vector<int> &nums,int i,int j,unordered_map<int,int> &cache){
        int req = nums[j] - nums[i];
        if(cache.count(req) && cache[req] <i){
            return recur(nums,cache[req],i,cache) + 1;
        }
        return 2;
    }
    int memo(vector<int> &nums,int i,int j,unordered_map<int,int> &cache,vector<vector<int>> &dp){
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        int req = nums[j] - nums[i];
        if(cache.count(req) && cache[req] <i){
            return dp[i][j] = memo(nums,cache[req],i,cache,dp) + 1;
        }
        return dp[i][j] = 2;
    }
    int lenLongestFibSubseq(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int> cache;
        vector<vector<int>> dp(n,vector<int>(n,-1));
        int result =0;
        //mapping
        //  element -> index
        for(int i=0;i<n;i++){
            cache[nums[i]]=i;
        }
        //
        for(int i=1;i<n;i++){
            for(int j=i+1;j<n;j++){
                int ans = memo(nums,i,j,cache,dp);
                result=max(result,ans);
            }
        }
        return result>2 ? result : 0;        
    }
};