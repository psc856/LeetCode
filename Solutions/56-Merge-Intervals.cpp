class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        //sort the [0] index of vectors in ascending order
        sort(intervals.begin(),intervals.end(),[](const vector<int> &a,const vector<int> &b){
            return a[0]<b[0];
        });
        vector<vector<int>> ans;
        int n=intervals.size();
        if(n==1){
            return intervals;
        }
        int left=0;
        int maxx=INT_MIN;
        for(int i=1;i<n;i++){
            maxx=max(maxx,intervals[left][1]);
            while(i < n && maxx >= intervals[i][0]){
                maxx=max(maxx,intervals[i][1]);
                i++;
            }            
            ans.push_back({intervals[left][0],maxx});
            left=i;
        }
        if(left < n && ans.back()[1]<intervals[left][1]){
            ans.push_back(intervals[left]);
        }
        return ans;
    }
};