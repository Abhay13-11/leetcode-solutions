class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return 1;
        int mini=0;
        int maxi=0;
        for(int i=0;i<n;i++)
        {
            if(nums[maxi]<nums[i]) maxi=i;
            if(nums[mini]>nums[i]) mini=i;
        }
       int ans=INT_MAX;
       ans=min(ans,max(mini,maxi)+1);
       ans=min(ans,n-min(mini,maxi));
       if(maxi<mini)
       {
        ans=min(ans,maxi+1+n-mini);
       }
       else ans=min(ans,mini+1+n-maxi);
       return ans;
    }
};