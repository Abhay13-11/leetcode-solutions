class Solution {
public:
    int countRatioSubarrays(vector<int>& nums, int a, int b) {
       int ans=0;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            int c0=0;
            int c1=0;
            for(int j=i;j<n;j++)
            {
                if(nums[j]%2==0) c0++;
                else c1++;
                if(c1<1) continue;
                if(c0*b<=a*c1) ans++;
            }
        }
        return ans;
    }
};