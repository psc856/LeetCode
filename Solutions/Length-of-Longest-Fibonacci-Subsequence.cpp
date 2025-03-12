class Solution {
public:
    int recur(vector<int> &nums,int i,int j,unordered_map<int,int> &cache){
        int req = nums[j] - nums[i];
        if(cache.count(req) && cache[req] <i){
            return recur(nums,cache[req],i,cache) + 1;
        }
        return 2;
    }
    int lenLongestFibSubseq(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int> cache;
        int result =0;
        //mapping
        //  element -> index
        for(int i=0;i<n;i++){
            cache[nums[i]]=i;
        }
        //
        for(int i=1;i<n;i++){
            for(int j=i+1;j<n;j++){
                int ans = recur(nums,i,j,cache);
                result=max(result,ans);
            }
        }
        return result>2 ? result : 0;        
    }
};