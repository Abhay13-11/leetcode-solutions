class Solution {
public:
    int minRotations(string s) {
        int n=s.size();
        int ans=0;
        int prev=0;
        for(int i=0;i<n;i++)
        {
            int dig=s[i]-'0';
            ans+=min(abs(dig-prev)%10,(10-abs(dig-prev))%10);
            prev=dig;
        }
        return ans;
    }
};