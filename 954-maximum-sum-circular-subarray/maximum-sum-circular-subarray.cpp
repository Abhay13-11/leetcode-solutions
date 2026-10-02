class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int ans=nums[0];
        int tot=nums[0];
        int sum=nums[0];
        int mini=nums[0];
        int aj=nums[0];
        bool flag=0;
        
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]>=0) flag=1;
            tot+=nums[i];

            sum=max(nums[i],sum+nums[i]);
            ans=max(ans,sum);

            mini=min(nums[i],mini+nums[i]);
            aj=min(aj,mini);

        }
        if(flag==0) return ans;
        return max(ans,tot-aj);

       
    }
};