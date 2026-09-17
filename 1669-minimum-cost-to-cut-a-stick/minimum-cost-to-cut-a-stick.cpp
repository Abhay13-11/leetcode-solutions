class Solution {
    int solve(int i,int j,vector<int> &cuts,vector<vector<int>> &dp)
    {
       if(i>j) return 0;
       if(dp[i][j]!=-1) return dp[i][j];
        int ans=1e9;
        for(int k=i;k<=j;k++)
        {
            
                
                int steps=cuts[j+1]-cuts[i-1]+solve(i,k-1,cuts,dp)+solve(k+1,j,cuts,dp);
             ans=min(ans,steps);
            
            
        }
       
        return dp[i][j]=ans;
    }
public:
    int minCost(int n, vector<int>& cuts) {
        cuts.insert(cuts.begin(),0);
        cuts.push_back(n);
        sort(cuts.begin(),cuts.end());
        int N=cuts.size();
        vector<vector<int>> dp(N,vector<int>(N,-1));
        return solve(1,N-2,cuts,dp);
    }
};