class Solution {
public:
    string removeKdigits(string nums, int k) {
        string ans;
        int n=nums.length();
        for(int i=0;i<n;i++){
            while(k>0 && !ans.empty() && ans.back() > nums[i]){
                ans.pop_back();
                k--;
            }
            ans.push_back(nums[i]);
        }
        //handle from last if k>0
        while (k > 0 && !ans.empty()) {
            ans.pop_back();
            k--;
        }
        //handle for leading 0
        int index=0;
        while(index <ans.size() && ans[index]=='0'){
            index++;
        }
        ans=ans.substr(index);
        return ans==\\ ? \0\:ans;
    }
};