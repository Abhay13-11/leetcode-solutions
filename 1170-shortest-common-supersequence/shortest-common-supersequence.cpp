class Solution {
    int solve(int i,int j, string &str1,string &str2,vector<vector<int>> &dp)
    {
        if(i==0 || j==0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(str1[i-1]==str2[j-1]) return dp[i][j]=1+solve(i-1,j-1,str1,str2,dp);

        return dp[i][j]=max(solve(i-1,j,str1,str2,dp),solve(i,j-1,str1,str2,dp));
    }
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int n=str1.size();
        int m=str2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        int ans=solve(n,m,str1,str2,dp);
        string s="";
        
        int i=n;
        int j=m;
        while(i!=0 && j!=0)
        {
            
            if(str1[i-1]==str2[j-1]) {
                
                s+=str1[i-1];
               
                i--;
                j--;
            }
            else if(dp[i-1][j]>dp[i][j-1])
            {
                s+=str1[i-1];
                i--;
            }
            else {
            s+=str2[j-1];
            j--;
            }
        }
        while(i>0)
        {
            s+=str1[i-1];
            i--;
        }
        while(j>0)
        {
            s+=str2[j-1];
            j--;
        }
        reverse(s.begin(),s.end());
        return s;
    }
};