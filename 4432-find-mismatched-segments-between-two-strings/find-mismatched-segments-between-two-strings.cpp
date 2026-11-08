class Solution {
public:
    vector<vector<string>> findMismatchedSegments(string s1, string s2) {
        int n=s1.size();
        vector<vector<string>> ans;
        for(int i=0;i<n;i++)
        {
            int j=i;
            string a="";
            string b="";
            while(s1[i]!=s2[i])
            {
                a+=s1[i];
                b+=s2[i];
                i++;
            }
            if(a.size()!=0)
            {
                ans.push_back({a,b});
            }
        }
        return ans;
    }
};