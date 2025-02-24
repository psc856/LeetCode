class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n=nums.size();
        //max size possible
        int ans=n+1;
        //left pointer from where the subarray is starting
        int left=0;
        //sum variable
        int sum=0;
        for(int right=0;right<n;right++){
            sum+=nums[right];
            //while sum>=target save the ans if applicable and omit the left element and increase left
            while(sum>=target){
                ans=min(ans,right-left+1);
                sum-=nums[left];
                left++;
            }
        }
        //if ans is altered in between then return it else no subarray found
        return ans==n+1?0:ans;
    }
};