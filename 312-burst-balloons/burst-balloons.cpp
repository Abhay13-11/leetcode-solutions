class Solution {
    int solve(int i,int j,vector<int> &nums,vector<vector<int>> &dp)
    {
        if(i>j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int ans=INT_MIN;
        for(int k=i;k<=j;k++)
        {

            int pro=nums[k];
            if(i>0)  pro*=nums[i-1];
            if(j<nums.size()-1) pro*=nums[j+1];
            pro+=solve(i,k-1,nums,dp)+solve(k+1,j,nums,dp);
            ans=max(ans,pro);
        }
        return dp[i][j]=ans;
    }
public:
    int maxCoins(vector<int>& nums) {
       int n=nums.size();
       vector<vector<int>> dp(n,vector<int>(n,-1));

       return solve(0,nums.size()-1,nums,dp); 
    }
};