class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        long long ans=0;
        int n=nums.size();
        for(int i=0;i<n;i++ ){
            int smallest=nums[i];
            int greatest=nums[i];
            for(int j=i+1;j<n;j++){
                greatest=max(greatest,nums[j]);
                smallest=min(smallest,nums[j]);
                ans+=greatest-smallest;
            }
        }
        return ans;
    }
};