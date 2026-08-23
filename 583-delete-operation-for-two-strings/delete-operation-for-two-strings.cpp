class Solution {
    int solve(int i,int j,string &s1,string &s2,vector<vector<int>> &dp)
    {
        if(i==0 || j==0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s1[i-1]==s2[j-1]) return 1+solve(i-1,j-1,s1,s2,dp);

        return dp[i][j]=max(solve(i-1,j,s1,s2,dp),solve(i,j-1,s1,s2,dp));
    }
public:
    int minDistance(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        int step=solve(n,m,word1,word2,dp);        
        return (n+m)-(2*step);
    }
};