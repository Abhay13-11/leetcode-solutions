class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int ans=INT_MAX;
        int mi=INT_MAX;
        int maxi=INT_MIN;
        vector<int> mini(nums.size(),0);
        for(int i=nums.size()-1;i>=0;i--)
            {
              mi=min(mi,nums[i]);
                mini[i]=mi;
            }
        for(int i=0;i<nums.size();i++)
            {
                maxi=max(maxi,nums[i]);
                int score=maxi-mini[i];
                if(score<=k) return i;
                
            }
        return -1;
    }
};