class Solution {
    int solve(int count,int k,int n,int i,bool buy,vector<int> &prices,vector<vector<vector<int>>> &dp)
    {
        if(i==n || count>=k) return 0;
        if(dp[i][buy][count]!=-1) return dp[i][buy][count];
        if(!buy) return dp[i][buy][count]=max(solve(count,k,n,i+1,false,prices,dp),-prices[i]+solve(count,k,n,i+1,true,prices,dp));

        int nosell=solve(count,k,n,i+1,true,prices,dp);
        int sell=-1e9;
        if(count<=k) sell= prices[i]+solve(count+1,k,n,i+1,false,prices,dp);
       return dp[i][buy][count]=max(sell,nosell);
    }
public:
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(2,vector<int>(k,-1)));
        return solve(0,k,n,0,false,prices,dp);
    }
};