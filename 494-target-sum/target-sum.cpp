class Solution {
    int solve(int ind,int count,vector<int> &nums,int target)
    {
        if(ind==-1 ) return target==0;
        int add=solve(ind-1,count,nums,target+nums[ind]);
        
        int sub=solve(ind-1,count,nums,target-nums[ind]);

        return add+sub;
        
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
       
        return solve(n-1,0,nums,target);
    }
};