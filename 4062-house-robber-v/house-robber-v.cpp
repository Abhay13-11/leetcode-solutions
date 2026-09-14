class Solution {
public:
    long long rob(vector<int>& nums, vector<int>& colors) {

        int n = nums.size();

        long long take = nums[0];
        long long skip = 0;

        for (int i = 1; i < n; i++) {

            long long newTake = nums[i] + skip;

            if (colors[i] != colors[i - 1]) {
                newTake = max(newTake,
                              nums[i] + take);
            }

            long long newSkip = max(take, skip);

            take = newTake;
            skip = newSkip;
        }

        return max(take, skip);
    }
};