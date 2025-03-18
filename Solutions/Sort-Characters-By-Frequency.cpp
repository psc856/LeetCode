class Solution {
public:
    string frequencySort(string s) {
        vector<pair<char,int>> mapp(62,{'0',0});
        int n=s.length();
        for(int i=0;i<n;i++){
            int index=static_cast<int>(s[i]);
            if(index>='A' && index <='Z'){
                index-='A';
            }else if(index>='a' && index<='z'){
                index=index-'a'+26;
            }else{
                index=index -'0'+52;
            }
            mapp[index].first=s[i];
            mapp[index].second++;
        }
        sort(mapp.begin(),mapp.end(),[](pair<char,int> &a,pair<char,int> &b){
            return a.second>b.second;
        });
        string ans=\\;
        for(int i=0;i<mapp.size();i++){
            if (mapp[i].second > 0) {
                ans.append(mapp[i].second, mapp[i].first);  // Append all occurrences at once
            }
        }
        return ans;
    }
};