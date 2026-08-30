class Solution {
    // int solve(int count,int k,int n,int i,bool buy,vector<int> &prices,vector<vector<vector<int>>> &dp)
    // {
    //     if(i==n || count>=k) return 0;
    //     if(dp[i][buy][count]!=-1) return dp[i][buy][count];
    //     if(!buy) return dp[i][buy][count]=max(solve(count,k,n,i+1,false,prices,dp),-prices[i]+solve(count,k,n,i+1,true,prices,dp));

    //     int nosell=solve(count,k,n,i+1,true,prices,dp);
    //     int sell=-1e9;
    //     if(count<=k) sell= prices[i]+solve(count+1,k,n,i+1,false,prices,dp);
    //    return dp[i][buy][count]=max(sell,nosell);
    // }
public:
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        // vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));
        vector<vector<int>> prev(2,vector<int>(k+1,0)),curr(2,vector<int>(k+1,0));

        
        for(int i=n-1;i>=0;i--)
        {
            for(int buy=0;buy<=1;buy++)
            {
                for(int count=k-1;count>=0;count--)
                {
                    if(!buy)  curr[buy][count]= max(prev[false][count],-prices[i]+prev[true][count]);

                    else
                    {
                            int nosell=prev[true][count];
                            int sell= prices[i]+prev[false][count+1];
                             curr[buy][count]=max(sell,nosell);
                    }
                    
                }
             
            }
            prev=curr;
        }
        return prev[0][0];
        
    }
};