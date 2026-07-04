class Solution {
public:
    bool isMiddleElementUnique(vector<int>& nums) {
        int n=nums.size();
        int mid=nums[n/2];
        for(int i=0;i<n;i++)
        {
            if(nums[i]==mid && i!=n/2) return false;
        }
        return true;
    }
};