class Solution {
public:
    int minAdjacentSwaps(vector<int>& nums, int a, int b) {
        int count=0;
        int ans=0;
        int n=nums.size();
    int mod=1e9+7;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]<a)
            {
                ans=(ans+i-count)%mod;
                count++;
            }
        
        }
        count=n-1;
        int lala=0;
         for(int i=n-1;i>=0;i--)
        {
            if(nums[i]<a) lala++;
            if(nums[i]>b)
            {
                ans=(ans+count-i-lala)%mod;
                count--;
            }
        
        }
return ans;
    }
};