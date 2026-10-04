class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string,string> mpp;
        for(auto it : knowledge)
        {
            mpp[it[0]]=it[1];
        }
        string ans="";
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='(')
            {
                i++;
                string di="";
                while(s[i]!=')')
                {
                    di+=s[i];
                    i++;
                }
                if(mpp.find(di)!=mpp.end()) ans+=mpp[di];
                else ans+='?';
            }
            else ans+=s[i];
        }
        return ans;
    }
};