class Solution {
public:
    int minMoves(vector<int>& nums) {
        int maxi=0;
        int n=nums.size();
        for(auto it : nums)
        {
            maxi=max(maxi,it);
        }
        int ans=0;
        for(int i=0;i<n;i++)
        {
            ans+=maxi-nums[i];
        }
        return ans;
    }
};