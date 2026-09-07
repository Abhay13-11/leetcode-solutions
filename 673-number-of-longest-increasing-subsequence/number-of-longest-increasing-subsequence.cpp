class Solution {
public:
    int findNumberOfLIS(vector<int>& arr) {
        int n=arr.size();
        int count=0;
        vector<int> dp(n,1),hash(n,1);
        int maxiele=0;
        for(int i=0;i<n;i++)
        {
            for(int prev=0;prev<i;prev++)
            {
                if(arr[i]>arr[prev])
                {
                    if(dp[i]<dp[prev]+1)
                    {
                        dp[i]=dp[prev]+1;
                        hash[i]=hash[prev];
                    }
                    else if(dp[i]==dp[prev]+1)
                    {
                        hash[i]+=hash[prev];
                    }
                }
            }
            if(maxiele<dp[i])
            {
                maxiele=dp[i];
            }

        }
        for(int i=0;i<n;i++)
        {
            if(dp[i]==maxiele) count+=hash[i];
        }
        return count;
    }
};