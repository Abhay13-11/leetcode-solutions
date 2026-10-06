class Solution {
public:
    int minAddToMakeValid(string s) {
        int ans=0;
        stack<char> st;
        for(char &it : s)
        {
            if(it=='(') st.push('(');
            else
            {
                if(st.empty())
                {
                    ans++;
                }
                else st.pop();
            }
        }
        ans+=st.size();
        return ans;
    }
};