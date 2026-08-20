class Solution {
    int solve(int ind,vector<int> &coins,int amount,vector<vector<int>> &dp)
    {
        if(ind==-1 && amount!=0) return 0;
        if(amount==0) return 1;
        if(ind==0 && amount ==coins[ind]) return 1;
        if(dp[ind][amount]!=-1) return dp[ind][amount];
        int notake=solve(ind-1,coins,amount,dp);
       int take=0;
       if(amount>=coins[ind]) take=solve(ind,coins,amount-coins[ind],dp);
      return dp[ind][amount]=take+notake;
    }
public:
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        return solve(n-1,coins,amount,dp);

    }
};