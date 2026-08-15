class Solution {
public:
    int maximumLengthSubstring(string s) {
        vector<int> map(26,0);
        int l=0;
        int ans=0;
        for(int i=0;i<s.size();i++)
        {
             map[s[i]-'a']++;
                while(map[s[i]-'a']>2)
                {
                    map[s[l]-'a']--;
                    l++;
                }
               
                 ans=max(ans,i-l+1);
           
        }
        return ans;
    }
};