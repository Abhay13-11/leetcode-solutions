class Solution {
    int solve(int n,vector<int> &cost,vector<int> &dp)
    {
        if(n==1 || n==0) return 0;
        if(dp[n-1]!=-1) return dp[n-1];
      int  first=cost[n-1]+ solve(n-1,cost,dp);
      int second=INT_MAX;
      if(n>=2)
    {  second=cost[n-2]+solve(n-2,cost,dp);}
        return dp[n-1]=min(first,second);
    }
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int> dp(n,-1);
        dp[0]=0;
        return solve(n,cost,dp);
    }
};