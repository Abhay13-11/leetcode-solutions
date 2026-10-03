class Solution {
    int operate(int a,int b,char op)
    {
        if(op=='&') return a&b;
         return a|b;
       
    }
public:
    bool parseBoolExpr(string expression) {
        stack<char> logic;
        stack<char> st;
        for(auto it : expression)
        {
            if(it=='&' || it=='|' || it=='!') logic.push(it);
            else if(it=='(' || it=='t' || it=='f' || it==',') 
            {
                if(it!=',') st.push(it);
            }
            else
            {
                char op=logic.top();
                
                logic.pop();
                vector<int> main;
                while(st.top()!='(')
                {
                    if(st.top()=='t') main.push_back(1);
                    else main.push_back(0);
                    st.pop();
                }
                int log=main[0];
                if(op=='!') log=log==1?0:1;
                for(int i=1;i<main.size();i++)
                {
                    log=operate(log,main[i],op);
                }
                st.pop();
                if(log==1) st.push('t');
                else st.push('f');
            }

        }
        if(st.top()=='t') return true;
        return false;
    }
};