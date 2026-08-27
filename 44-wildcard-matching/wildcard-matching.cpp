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
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        return solve(n,m,s,p,dp);
    }
};