class Solution {
    int solve(vector<int> &prev,int n,vector<int> &dp,int mod)
    {
        if(n < 0) return 1;
        
        if(dp[n]!=-1) return dp[n];
        int total=(2LL*solve(prev,n-1,dp,mod))%mod;
        
        if(prev[n]!=-1) total-=solve(prev,prev[n]-1,dp,mod)%mod;
        return dp[n]=(total+mod)%mod;
    }
public:
    int distinctSubseqII(string s) {
        int mod=1e9+7;
        int n=s.size();
        vector<int> dp(n,-1);
         vector<int> lastind(26,-1);
         vector<int> prev(n,-1);
        for(int i=0;i<n;i++)
        {
              prev[i]=lastind[s[i]-'a'];
            lastind[s[i]-'a']=i;
          
        }
        return (solve(prev,n-1,dp,mod)-1+mod)%mod;
    }
};