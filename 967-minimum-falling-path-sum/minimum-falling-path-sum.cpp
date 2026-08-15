class Solution {
    int mini(int left, int mid, int right) {
        return min(left, min(mid, right));
    }
   

public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 0));
        for (int i = 0; i < m; i++) {
            dp[0][i] = matrix[0][i];
        }
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int left = matrix[i][j];
                if (j - 1 >= 0)
                    left += dp[i - 1][j - 1];
                else
                    left += 1e9;
                int mid = matrix[i][j] + dp[i-1][j];

                int right = matrix[i][j];
                if (j < m - 1)
                    right += dp[i - 1][j + 1];
                else
                    right += 1e9;

                dp[i][j] = mini(left, right, mid);
            }
        }
        int ans=INT_MAX;
        for(int i=0;i<m;i++)
        {
            ans=min(ans,dp[n-1][i]);
        }
        return ans;
    }
};