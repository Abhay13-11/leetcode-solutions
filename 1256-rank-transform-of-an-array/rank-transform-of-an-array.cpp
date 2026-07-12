class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int count=0;
        map<int,int> mpp;
        for(int it : arr) mpp[it]++;
        vector<int> ans;
        for(auto it : mpp)
        {
            int nu=it.first;
            count++;
            mpp[nu]=count;
        }
        for(int it : arr)
        {
            ans.push_back(mpp[it]);
        }
        return ans;
    }
};