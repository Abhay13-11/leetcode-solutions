class Solution {
    int solve(int i,int prev,int n,vector<int> &nums,vector<vector<int>> &dp)
    {
        if(i==n) return 0;
        if(dp[i][prev]!=-1) return dp[i][prev];
        int notake=solve(i+1,prev,n,nums,dp);
        int take=0;
        if(prev==0 ||  nums[i]>nums[prev-1]) take=1+solve(i+1,i+1,n,nums,dp);

        return dp[i][prev]=max(take,notake);
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
        return solve(0,0,n,nums,dp);
    }
};