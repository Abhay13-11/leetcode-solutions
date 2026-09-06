class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,1),hash(n,0);
        sort(nums.begin(),nums.end());
        int maxind=0;
       int maxsize=1;
        for(int i=0;i<n;i++)
        {
            hash[i]=i;
            for(int prev=0;prev<i;prev++)
            {
                if(nums[i]%nums[prev]==0 && dp[i]<dp[prev]+1)
                {
                    dp[i]=dp[prev]+1;
                    hash[i]=prev;
                }
            }
            if(dp[i]>maxsize)
            {
                maxsize=dp[i];
                maxind=i;
            }
        }
        vector<int> temp;
        temp.push_back(nums[maxind]);
        while(maxind!=hash[maxind])
        {
           
            maxind=hash[maxind];
             temp.push_back(nums[maxind]);
        }
       
        return temp;

    }
};