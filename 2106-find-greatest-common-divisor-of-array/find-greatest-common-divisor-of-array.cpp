class Solution {
public:
    int findGCD(vector<int>& nums) {
        int small=INT_MAX;
        int large=INT_MIN;
        for(int it : nums) 
        {
            small=min(small,it);
            large=max(large,it);
        }
        if(large%small==0) return small;
        for(int i=small;i>=1;i--)
        {
            if(small%i==0 && large%i==0) return i;
        }
        return 1;
    }
};