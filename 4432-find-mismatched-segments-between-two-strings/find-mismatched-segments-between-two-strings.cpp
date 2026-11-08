class Solution {
public:
    vector<vector<string>> findMismatchedSegments(string s1, string s2) {
        int n=s1.size();
        vector<vector<string>> ans;
        for(int i=0;i<n;i++)
        {
            int j=i;
           
            while(s1[i]!=s2[i])
            {
                i++;
            }
            if(i-j!=0)
            {
                ans.push_back({s1.substr(j,i-j),s2.substr(j,i-j)});
            }
        }
        return ans;
    }
};