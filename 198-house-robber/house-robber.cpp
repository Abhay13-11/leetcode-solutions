class Solution {
     int solve(vector<int> &arr,vector<int> &dp,int ind)
    {
        if(ind==0)
        {
            return arr[0];
        }
        if(ind<0)
        {
            return 0;
        }
        if(dp[ind]!=-1) return dp[ind];
        
        int pick=arr[ind]+solve(arr,dp,ind-2);
        
        int nopick=solve(arr,dp,ind-1);
        
        return dp[ind]=max(pick,nopick);
    }
public:
    int rob(vector<int>& arr) {
        
        int n=arr.size();
        vector<int> dp(n,-1);
        return solve(arr,dp,n-1);
        
    }
};