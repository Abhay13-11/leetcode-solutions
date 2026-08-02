class Solution {
public:
    int countValidPrefixes(string s) {
        int ans=0;
        long long c0=0;
        long long c1=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='1') c1++;
            else c0++;
            if(abs(c0-c1)<=1 ) ans++;
        }
        return ans;
        }
};