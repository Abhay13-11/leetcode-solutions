class Solution {
    int digrange(int num)
    {
        int maxi=0;
        int mini=INT_MAX;
        while(num>0)
        {
            int dig=num%10;
            maxi=max(maxi,dig);
            mini=min(mini,dig);
            num=num/10;
        }
        return maxi-mini;
    }
public:
    int maxDigitRange(vector<int>& nums) {
        int maxi=-1;
        unordered_map<int,vector<int>> mpp;
        for(auto it : nums)
        {
            int digra=digrange(it);
            maxi=max(maxi,digra);
            mpp[digra].push_back(it);
        }
        int ans=0;
        for(int it : mpp[maxi])
        {
            ans+=it;
        }
        return ans;
    }
};