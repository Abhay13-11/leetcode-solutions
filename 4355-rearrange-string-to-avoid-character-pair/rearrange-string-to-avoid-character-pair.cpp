class Solution {
public:
    string rearrangeString(string s, char x, char y) {
        vector<int> map(26,0);
        string ans="";
        for(char &it : s)
        {
            map[it-'a']++;
        }
        if(map[x-'a']==0 || map[y-'a']==0) return s;
        while(map[y-'a'])
        {
            ans+=y;
            map[y-'a']--;
        }
        while(map[x-'a'])
        {
            ans+=x;
            map[x-'a']--;
        }
        for(int i=0;i<26;i++)

        {
            while(map[i])
            {
                ans+='a'+i;
                map[i]--;
            }
        }
        return ans;
    }
};