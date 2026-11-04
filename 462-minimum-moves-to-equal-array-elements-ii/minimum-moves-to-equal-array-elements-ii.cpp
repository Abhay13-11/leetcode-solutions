class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int med;
        if(n%2==0)
        {
            int mid=n/2;
            med=(nums[mid]+nums[mid-1])/2;
        }
        else
        {
            med=nums[n/2];
        }
        int ans=0;
        for(auto it: nums)
        {
            ans+=abs(it-med);
        }
        return ans;
    }
};