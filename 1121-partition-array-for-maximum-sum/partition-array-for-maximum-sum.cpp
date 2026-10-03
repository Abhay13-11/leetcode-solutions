class Solution {
    int maxi(int i,int j,vector<int> &arr)
    {
        int add=0;
        for(int k=i;k<=j;k++)
        {
            add=max(add,arr[k]);
        }
        return add;

    }
    // int solve(int i,int n,vector<int> &arr,int k,vector<int> &dp)
    // {
    //     if(i>=n) return 0;
    //     if(dp[i]!=-1) return dp[i];
    //     int ans=0;
    //     for(int j=i;j<n;j++)
    //     {
    //         if(j-i+1<=k)
    //         {
    //             int cost=maxi(i,j,arr)*(j-i+1)+solve(j+1,n,arr,k,dp);
    //             ans=max(cost,ans);
    //         }
    //     }
    //     return dp[i]=ans;
    // }
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
        vector<int> dp(n+1,0);
        // return solve(0,n,arr,k,dp);
        for(int i=n-1;i>=0;i--)
        {
            int ans=0;
            for(int j=i;j<n;j++)
            {
                if(j-i+1<=k)
                {
                    int cost=maxi(i,j,arr)*(j-i+1)+dp[j+1];
                    ans=max(cost,ans);
                }
            }
             dp[i]=ans;
        }
        return dp[0];
    }
};