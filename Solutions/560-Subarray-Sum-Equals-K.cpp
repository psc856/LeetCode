class Solution {
public:
//brute
    int subarraySum(vector<int>& nums, int k) {
        int left=0;
        int sum=0,ans=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            sum=0;
            for(int j=i;j<n;j++){
                sum+=nums[j];
                if(sum==k){
                    ans++;
                }
            }
        }
        return ans;
    }
};