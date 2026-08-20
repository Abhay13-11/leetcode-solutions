class Solution {
    int solve(int ind,vector<int> &coins,int amount)
    {
        
        if(amount==0) return 0;
        if(ind==0)
        {
            if(amount%coins[ind]==0) return amount/coins[ind];
             else return 1e9;
        }
           
    

        int notake=solve(ind-1,coins,amount);
        int take=1e9;
        if(amount>=coins[ind]) take=1+solve(ind,coins,amount-coins[ind]);
        return min(take,notake);
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,1e9));
        int ans;
        
        for(int i=0;i<n;i++)
        {
            dp[i][0]=0;
        }
        for(int i=0;i<=amount;i++)
        {
            if(i%coins[0]==0) dp[0][i]=i/coins[0];
        }

        for(int i=1;i<n;i++)
        {
            for(int amt=1;amt<=amount;amt++)
            {
                int notake=dp[i-1][amt];
                int take=1e9;
                if(amt>=coins[i]) take=1+dp[i][amt-coins[i]];
                dp[i][amt]= min(take,notake);
            }
        }
        
        

ans=dp[n-1][amount];

        if(ans>=1e9) return -1;
        return ans;
    }
};