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
        
        return gcd(small,large);
    }
};