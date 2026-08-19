class Solution {
    int countt(int ind,int count,vector<int> &arr,int target,vector<vector<int>> &dp)
    {
        if(ind==0)
        {
            if(arr[0]==0 && target==0) return 2;
            if(target==0 || arr[0]==target) return 1;
            return 0;
        }
        if(dp[ind][target]!=0) return dp[ind][target];
        int notake=countt(ind-1,count,arr,target,dp);
        int take=0;
        if(arr[ind]<=target) take= countt(ind-1,count,arr,target-arr[ind],dp);
        
        return dp[ind][target]=take+notake;
    }
public:
    int findTargetSumWays(vector<int>& arr, int diff) {
        int sum=0;
        for(int it : arr) sum+=it;
        int d=sum-diff;
        if(d<0 || d%2==1) return 0;
        d=d/2;
        int n=arr.size();
        vector<vector<int>> dp(n,vector<int>(d+1,0));
        
        return countt(n-1,0,arr,d,dp);
    }
};