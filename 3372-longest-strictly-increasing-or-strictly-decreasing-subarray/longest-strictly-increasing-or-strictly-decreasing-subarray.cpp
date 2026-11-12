class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int ans=1;
        int c=0;
        int i=1;
        int n=nums.size();
        if(n==1) return 1;
        while(i<n)
        {
            while(i<n && nums[i]>nums[i-1])
            {
                c++;
                i++;
            }
            ans=max(ans,c+1);
            c=0;
            while(i<n && nums[i]<nums[i-1])
            {
                c++;
                i++;
            }
            ans=max(ans,c+1);
            c=0;
            if(i < n && nums[i]==nums[i-1]) i++;
        }
        return ans;
    }
};