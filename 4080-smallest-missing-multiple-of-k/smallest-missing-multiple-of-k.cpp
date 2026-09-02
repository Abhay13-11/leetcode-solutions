class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_map<int,int>  mpp;
        for(int it : nums) mpp[it]=1;
        int i=1;
        while(mpp.find(k*i)!=mpp.end()) i++;
        return k*i;
    }
};