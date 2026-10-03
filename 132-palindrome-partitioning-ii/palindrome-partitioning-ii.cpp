class Solution {
    bool ispalin(int low,int high,string &s)
    {
        while(low<=high)
        {
            if(s[low]!=s[high])
            {
                return false;
            }
            low++;
            high--;
        }
        return true;
    }
    // int solve(int i,int n,string &s,vector<int> &dp)
    // {
    //     if(i==n) return 0;
    //     if(dp[i]!=-1) return dp[i];
    //     int count=INT_MAX;
    //     for(int j=i;j<n;j++)
    //     {
    //         int cost=0;
    //         if(ispalin(i,j,s))
    //         {
    //              cost=1+solve(j+1,n,s,dp);
    //             count=min(count,cost);
    //         }
    //     }
    //     return dp[i]=count;
    // }
public:
    int minCut(string s) {
        int n=s.size();

        // through MCM APPROACH
        // vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        // return solve(0,n,s,dp);
        // for(int i=n-1;i>=0;i--)
        // {
        //     for(int j=0;j<n;j++)
        //     {
        //         if(i>j) continue;
        //         if(ispalin(i,j,s)) {dp[i][j]= 0;continue;}
        //         int count=INT_MAX;
        //         for(int k=i+1;k<=j;k++)
        //         {
        //                 int cost=1+dp[i][k-1]+dp[k][j];
        //                 count=min(cost,count);
        //         }
        //       dp[i][j]=count;
        //             }
        // }
        // return dp[0][n-1];
        vector<int> dp(n+1,0);
        // return solve(0,n,s,dp)-1;
        for(int i=n-1;i>=0;i--)
        {
            int count=INT_MAX;
            for(int j=i;j<n;j++)
            {
                int cost=0;
                if(ispalin(i,j,s))
                {
                    cost=1+dp[j+1];
                    count=min(count,cost);
                }
            }
            dp[i]=count;
        }
        return dp[0]-1;
    }
};