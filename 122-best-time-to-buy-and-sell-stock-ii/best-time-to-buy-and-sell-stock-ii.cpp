class Solution {
    int solve(int n,int ind,int buy,vector<int> &prices,vector<vector<int>> &dp)
    {
        if(ind==n) return 0;
        if(dp[ind][buy]!=-1) return dp[ind][buy];
        if(buy==0)
        {
            return dp[ind][buy]=max(solve(n,ind+1,0,prices,dp),-prices[ind]+solve(n,ind+1,1,prices,dp));

        }
        
            int nosell=solve(n,ind+1,1,prices,dp);
            int sell=prices[ind]+solve(n,ind+1,0,prices,dp);
        
        return dp[ind][buy]=max(sell,nosell);

    }
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        
        vector<vector<int>> dp(n,vector<int>(2,-1));

       
        return solve(n,0,0,prices,dp);
    }
};