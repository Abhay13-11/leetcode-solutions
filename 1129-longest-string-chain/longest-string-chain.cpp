class Solution {
    bool ispre(string big,string small)
    {
       
        int i=big.size()-1;
        int j=small.size()-1;
        if(big.size()-small.size()!=1) return false;
        int count=0;
        while(i>=0 && j>=0)
        {
            if(big[i]==small[j])
            {
                i--;
                j--;
            }
            else if(count==1) return false;
            else{ count=1;
                i--;}
        }
return true;
    }
public:
    int longestStrChain(vector<string>& words) {
        sort(words.begin(),words.end(),
             [](string &a,string &b){
                 return a.size()<b.size();
             });
        int n=words.size();
        vector<int> dp(n,1);
        int ans=1;
        for(int i=0;i<n;i++)
        {
            for(int prev=0;prev<i;prev++)
            {
                if(ispre(words[i],words[prev]) && dp[i]<dp[prev]+1)
                {
                    dp[i]=dp[prev]+1;
                }
            }
            ans=max(ans,dp[i]);
        }
        return ans;
    }
};