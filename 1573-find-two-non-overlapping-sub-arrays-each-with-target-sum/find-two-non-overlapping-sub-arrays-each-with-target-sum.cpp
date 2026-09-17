class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();

        vector<int> best(n, INT_MAX);

        unordered_map<long long, int> mp;
        mp[0] = -1;

        long long prefix = 0;
        int mini = INT_MAX;
        int ans = INT_MAX;

        for (int i = 0; i < n; i++) {
            prefix += arr[i];

            if (mp.count(prefix - target)) {
                int prev = mp[prefix - target];
                int len = i - prev;

                if (prev >= 0 && best[prev] != INT_MAX)
                    ans = min(ans, len + best[prev]);

                mini = min(mini, len);
            }

            best[i] = mini;
            mp[prefix] = i;
        }

        return ans == INT_MAX ? -1 : ans;
    }
};