class Solution {
    int solve(int n,int m,string &text1, string &text2, vector<vector<int>> &dp)
    {
        if(n==-1 || m==-1) return 0;
        if(dp[n][m]!=-1) return dp[n][m];
        if(text1[n]==text2[m]) return 1+solve(n-1,m-1,text1,text2,dp);

        return dp[n][m]=max(solve(n-1,m,text1,text2,dp),solve(n,m-1,text1,text2,dp));
    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size();
        int m=text2.size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return solve(n-1,m-1,text1,text2,dp);
    }
};