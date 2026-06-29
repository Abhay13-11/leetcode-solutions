class Solution {
public:
    long long maxSum(vector<int>& nums, int k, int mul) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        if(k>nums.size()) return -1;
        
      long long ans= 0;
        for(int i=n-1;i>=n-k;i--)
        {
            if(mul>0)
            {
                ans+=1LL*nums[i]*mul;
                mul--;
            }
            else
            {
                ans+=nums[i];
            }
        }
        return ans;
    }
};