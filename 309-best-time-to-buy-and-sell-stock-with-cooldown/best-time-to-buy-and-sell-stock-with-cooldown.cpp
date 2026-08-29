class Solution {
    // int solve(int n,int ind,int buy,vector<int> &prices,vector<vector<int>> &dp)
    // {
    //     if(ind>=n) return 0;
    //     if(dp[ind][buy]!=-1) return dp[ind][buy];
    //     if(buy==0)
    //     {
    //         return dp[ind][buy]=max(solve(n,ind+1,0,prices,dp),-prices[ind]+solve(n,ind+1,1,prices,dp));

    //     }
        
    //         int nosell=solve(n,ind+1,1,prices,dp);
    //         int sell=prices[ind]+solve(n,ind+2,0,prices,dp);
        
    //     return dp[ind][buy]=max(sell,nosell);

    // }
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        
        // vector<vector<int>> dp(n+1,vector<int>(2,0));
        vector<int> prev(2,0),curr(2,0);
        int k=0;
       prev[0]=prev[1]=0;
       for(int ind=n-1;ind>=0;ind--)
       {
        for(int buy=0;buy<=1;buy++)
        {
            if(buy==0)
        {
             curr[buy]=max(prev[0],-prices[ind]+prev[1]);

        }
        else {
            
            int nosell=prev[1];
            int sell=prices[ind];
            if(ind+2<n) sell+=k;
        
         curr[buy]=max(sell,nosell);
        }


        }
            k=prev[0];
            prev=curr;
       }
        return prev[0];
    }
};