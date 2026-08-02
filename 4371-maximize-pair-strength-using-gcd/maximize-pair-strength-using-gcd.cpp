class Solution {
public:
    long long maxPairStrength(vector<int>& nums) {
        long long ans=-1;
         int n=nums.size();
         
        for(int i=0;i<n;i++)
        {
            long long maxi=nums[i];
            for(int j=i+1;j<n;j++)
            {
                long long maxi2=nums[j];
                long long pro=maxi*maxi2;
        long long gc=gcd(maxi,maxi2);
        ans=max( pro/(1LL*gc*gc),ans);
            }
        }
        return ans;
    }
};