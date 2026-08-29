class Solution {
    int solve(int n,int ind,int buy,vector<int> &prices,vector<vector<int>> &dp,int fee)
    {
        if(ind==n) return 0;
        if(dp[ind][buy]!=-1) return dp[ind][buy];
        if(buy==0)
        {
            return dp[ind][buy]=max(solve(n,ind+1,0,prices,dp,fee),-prices[ind]-fee+solve(n,ind+1,1,prices,dp,fee));

        }
        
            int nosell=solve(n,ind+1,1,prices,dp,fee);
            int sell=prices[ind]+solve(n,ind+1,0,prices,dp,fee);
        
        return dp[ind][buy]=max(sell,nosell);

    }
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        
        vector<vector<int>> dp(n,vector<int>(2,-1));

       
        return solve(n,0,0,prices,dp,fee);
    }
};