class Solution {
    int solve(int i,int j,int n,vector<vector<int>> &triangle,vector<vector<int>> &dp)
    {
        if(i+1==n) return triangle[i][j];
        if(dp[i][j]!=-1) return dp[i][j];
        int same=triangle[i][j]+solve(i+1,j,n,triangle,dp);
        int update=triangle[i][j]+solve(i+1,j+1,n,triangle,dp);
        return dp[i][j]=min(same,update);
    }
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
       vector<int> front(n,0),curr(n,0);
       for(int i=0;i<n;i++)
       {
        front[i]=triangle[n-1][i];
       }
       for(int i=n-2;i>=0;i--)
       {
        for(int j=i;j>=0;j--)
        {
            int d=triangle[i][j]+front[j];
            int dd=triangle[i][j]+front[j+1];
            curr[j]=min(d,dd);
        }
        front=curr;
       }
       return front[0];
    }
};