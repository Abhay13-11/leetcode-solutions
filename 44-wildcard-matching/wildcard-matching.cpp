class Solution {
    bool solve(int i,int j,string &s,string &p,vector<vector<int>> &dp)
    {
        if(i==0)
        {
            if(j==0) return true;
            if(p[j-1]=='*') return dp[i][j]=solve(i,j-1,s,p,dp);
            else return false;
        }
        if(j==0 && i!=0) return false;
       if(dp[i][j]!=-1) return dp[i][j];

        if(p[j-1]=='?' || p[j-1]==s[i-1]) return dp[i][j]=solve(i-1,j-1,s,p,dp);
         if(p[j-1]!=s[i-1] && p[j-1]!='*') return false;

        
            return dp[i][j]=solve(i-1,j,s,p,dp) || solve(i,j-1,s,p,dp);
        
       
    }
public:
    bool isMatch(string s, string p) {
        int n=s.size();
        int m=p.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        
        dp[0][0]=true;
        for(int j=1;j<=m;j++)
        {
            if(p[j-1]=='*') dp[0][j]=dp[0][j-1];
        }

        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(p[j-1]=='?' || p[j-1]==s[i-1]) dp[i][j]=dp[i-1][j-1];
               else if(p[j-1]!=s[i-1] && p[j-1]!='*') dp[i][j]=0;

        
            else dp[i][j]=dp[i-1][j] || dp[i][j-1];
            }
        }
        return dp[n][m];
    }
};