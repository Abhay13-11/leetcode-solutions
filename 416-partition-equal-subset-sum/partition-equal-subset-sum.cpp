class Solution {
    bool solve(int ind,vector<int> &nums,int target,vector<vector<int>> &dp)
    {
        if(target==0) return true;
        if(ind==0) return target==nums[0];
        if(dp[ind][target]!=-1) return dp[ind][target];
        //notake
        bool notake=solve(ind-1,nums,target,dp);
        //take
        bool take=false;
        if(nums[ind]<=target)
        {
            take=solve(ind-1,nums,target-nums[ind],dp);
        }
        return dp[ind][target]=take || notake;
    }
public:
    bool canPartition(vector<int>& nums) {
        int tot=0;
        for(int it : nums) tot+=it;

        if(tot%2==1) return false;
        vector<vector<int>> dp(nums.size(),vector<int>(tot/2+1,-1));
        return solve(nums.size()-1,nums,tot/2,dp);
    }
};