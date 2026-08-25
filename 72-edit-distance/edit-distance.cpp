class Solution {
    int solve(int i,int j,string &word1,string &word2)
    {
        if(i==0) return j;
        if(j==0) return i;

        if(word1[i-1]==word2[j-1]) return solve(i-1,j-1,word1,word2);

        return min(1+solve(i,j-1,word1,word2),min(1+solve(i-1,j,word1,word2),1+solve(i-1,j-1,word1,word2)));
    }
public:
    int minDistance(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
      
        vector<int> prev(m+1,0),curr(m+1,0);
    
        for(int j=1;j<=m;j++) prev[j]=j;
      
        for(int i=1;i<=n;i++)
        {
            curr[0]=i;
            for(int j=1;j<=m;j++)
            {
                if(word1[i-1]==word2[j-1]) curr[j]=prev[j-1];
                else curr[j]=min(1+curr[j-1],min(1+prev[j],1+prev[j-1]));
            }
            prev=curr;
        }

        return prev[m];
    }
};