class Solution {
public:
    int maxValidPairSum(vector<int>& nums, int k) {
        int n=nums.size();
        int ans=-1;
        int best=nums[0];
        for(int i=k;i<n;i++)
        {
            best=max(nums[i-k],best);
            ans=max(ans,best+nums[i]);
        }
        return ans;
        }
};