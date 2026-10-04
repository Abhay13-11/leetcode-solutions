class Solution {
    vector<int> findpse(vector<int> heights)
    {     
        int n=heights.size();
        stack<int> st;
        vector<int > pse(n);
        for(int i=0;i<n;i++)
    {
        while(!st.empty() && heights[st.top()]>=heights[i])
        {
            st.pop();
        }
        if(st.empty())
        {
            pse[i]=-1;
        }
        else
        {
            pse[i]=st.top();
        }
    st.push(i);    
    }
    return pse;
    }
     vector<int> findnse(vector<int> heights)
    {
        int mini=-1;
        int n=heights.size();
        stack<int> st;
        vector<int > nse(n);
        for(int i=n-1;i>=0;i--)
    {
        while(!st.empty() && heights[st.top()]>heights[i])
        {
            st.pop();
        }
        if(st.empty())
        {
            nse[i]=n;
        }
        else
        {
            nse[i]=st.top();
        }
        st.push(i);
    }
    return nse;
    }
    int lra(vector<int>& heights) {
        vector<int> psee=findpse(heights);
        vector<int> nsee=findnse(heights);
        int area=0;
        for(int i=0;i<heights.size();i++)
        {
            area=max(area,(nsee[i]-psee[i]-1)*heights[i]);
        }      
    return area;    
    }
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int ans=0;
        int n=matrix.size();
        int m=matrix[0].size();
        vector<int> h(m,0);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(matrix[i][j]!='0') h[j]++;
                else h[j]=0;
            }
            ans=max(ans,lra(h));
        }
        return ans;
    }
};