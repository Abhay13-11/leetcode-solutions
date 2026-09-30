class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int ans=0;
        long long pro=1;
        int l=0;
        int mini=INT_MAX;
        for(auto it : nums) mini=min(mini,it);
        if(k<mini) return 0;
        for(int i=0;i<nums.size();i++)
        {
            pro=pro*nums[i];
            while(pro>=k)
            {
                pro=pro/nums[l];
                l++;
            }
            ans+=i-l+1;
        }
        return ans;
    }
};