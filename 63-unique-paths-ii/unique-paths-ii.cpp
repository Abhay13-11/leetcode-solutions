class Solution {
    int solve(int i,int j,vector<vector<int>> &dp)
    {
        if(i<0 || j<0) return 0;
        if(dp[i][j]==0) return 0;
        if(i==0 & j==0) return 1;
        
        if(dp[i][j]!=-1) return dp[i][j];
        
      int  left=solve(i,j-1,dp);
     int   right=solve(i-1,j,dp);
return dp[i][j]=left+right
;    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
         vector<vector<int>> dp(m,vector<int>(n,-1));
         for(int i=0;i<m;i++)
         {
            for(int j=0;j<n;j++)
            {
                if(mat[i][j]) dp[i][j]=0;
            }
         }
      return  solve(m-1,n-1,dp);
    }
};