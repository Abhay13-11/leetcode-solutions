class Solution {
    // int solve(int i,int j,int n,vector<vector<int>>& grid,vector<vector<int>> &dp)
    // {
    //     if(i==n-1 ) return grid[i][j];
    //     if(i>=n || j>=n || i<0 || j<0) return 1e9;

    //     if(dp[i][j]!=-1) return dp[i][j];
        
    //     int ans=INT_MAX;
    //     for(int k=0;k<n;k++)
    //     {
    //         if(k!=j)
    //         {
    //             ans=min(ans,grid[i][j]+solve(i+1,k,n,grid,dp));
    //         }
    //     }
    //   return dp[i][j]=ans;
    // }
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int tell=INT_MAX;
        vector<vector<int>> dp(n,vector<int>(n,0));
       
        for(int j=0;j<n;j++)
        {
            dp[n-1][j]=grid[n-1][j];
        }
        
        for(int i=n-2;i>=0;i--)
        {
            for(int j=0;j<n;j++)
            {
                int ans=INT_MAX;
                for(int k=0;k<n;k++)
                {
                    if(k!=j)
                    {
                        ans=min(ans,grid[i][j]+dp[i+1][k]);
                    }
                }
                  dp[i][j]=ans;
             }
        }
         for(int i=0;i<n;i++)
        {
            tell=min(tell,dp[0][i]);
        }
        return tell;
     
    }
};