class Solution {
    int solve(int i,int j,string &s,string &t)
    {
        if(j==0) return 1;
        if(i==0) return 0;
        if(s[i-1]==t[j-1]) return solve(i-1,j-1,s,t)+solve(i-1,j,s,t);

        return solve(i-1,j,s,t);
    }
public:
    int numDistinct(string s, string t) {
        int n=s.size();
        int m=t.size();
        
        vector<double> prev(m+1,0),curr(m+1,0);
        prev[0]=curr[0]=1;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(s[i-1]==t[j-1]) curr[j]=prev[j-1]+prev[j];
                else curr[j]=prev[j];
            }
            prev=curr;
        }

        return (int)prev[m];
    }
};