class Solution {
    int solve(int count,int n,int i,bool buy,vector<int> &prices,vector<vector<vector<int>>> &dp)
    {
        if(i==n || count>=2) return 0;
        if(dp[i][buy][count]!=-1) return dp[i][buy][count];
        if(!buy) return dp[i][buy][count]=max(solve(count,n,i+1,false,prices,dp),-prices[i]+solve(count,n,i+1,true,prices,dp));

        int nosell=solve(count,n,i+1,true,prices,dp);
        int sell=-1e9;
        if(count<=1) sell= prices[i]+solve(count+1,n,i+1,false,prices,dp);
       return dp[i][buy][count]=max(sell,nosell);
    }
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));
        vector<vector<int>> prev(2,vector<int>(2,-1)),curr(2,vector<int>(2,-1));

        
        for(int i=n-1;i>=0;i--)
        {
            for(int buy=0;buy<=1;buy++)
            {
                for(int count=1;count>=0;count--)
                {
                    if(!buy)  dp[i][buy][count]= max(dp[i+1][false][count],-prices[i]+dp[i+1][true][count]);

                    else
                    {
                            int nosell=dp[i+1][true][count];
                            int sell= prices[i]+dp[i+1][false][count+1];
                             dp[i][buy][count]=max(sell,nosell);
                    }
                    
                }
            }
        }
        return dp[0][0][0];
        
    }
};