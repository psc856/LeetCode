class Solution {
public:
//brute
/*
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
    */


    //Optimised Approach
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> data;
        data[0]=1; //0->difference between sum and k if it's 0 then we have got 1! right?
        int sum=0,ans=0;
        for(auto x:nums){
            sum += x;
            //look for remaining in map;
            if(data.find(sum-k)!=data.end()){
                ans+=data[sum-k];
            }
            //save in data
            data[sum]++;
        }
        return ans;
    }
};

