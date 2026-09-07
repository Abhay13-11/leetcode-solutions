class Solution {
    // bool solve(int i,int j , int n,int m,string &s1,string &s2,string &s3,vector<vector<int>> &dp)
    // {
    //     if(i+j==n+m) return true;
    //     if(dp[i][j]!=-1) return dp[i][j];
    //     int k=i+j;
    //     int prev=false;
    //     if(s1[i]==s3[k]) prev= solve(i+1,j,n,m,s1,s2,s3,dp);
    //     int curr=false;
    //     if(s2[j]==s3[k]) curr= solve(i,j+1,n,m,s1,s2,s3,dp);
    //     return dp[i][j]=prev|| curr;
    // }
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n=s1.size();
        int m=s2.size();
        int z=s3.size();
        if(n+m!=z) return false;
        // vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        vector<int> pre(m+1,0),cur(m+1,0);
        pre[m]=1;
        for(int i=n;i>=0;i--)
        {
            for(int j=m;j>=0;j--)
            {
                if(i==n && j==m) 
                {
                    cur[j]=1;
                    continue;
                }
                int k=i+j;
                int prev=false;
                if(s1[i]==s3[k]) prev=pre[j];
                int curr=false;
                if(s2[j]==s3[k]) curr= cur[j+1];
                cur[j]=prev|| curr;
            }
            pre=cur;
        }
        return pre[0];
    }
};