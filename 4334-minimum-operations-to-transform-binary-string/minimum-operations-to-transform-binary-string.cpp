class Solution {
public:
    int minOperations(string s1, string s2) {
        int count=0;
        int n=s1.size();
        for(int i=0;i<n;i++)
        {
            if(s1[i]!=s2[i])
            {
                if(s1[i]=='0') 
                {
                    s1[i]='1';
                    count++;
                }
                else
                {
                    if(i+1<n && s1[i+1]=='1')
                    {
                        s1[i+1]='0';
                        s1[i]='0';
                        count++;
                    }
                    else if(i+1<n)
                    {
                        s1[i]='0';
                        count+=2;
                    }
                    else if(i>=1 && s1[i-1]=='1')
                    {
                        s1[i]='0';
                        count=count+2;
                    }
                    else if(i>=1)
                    {
                        s1[i]='0';
                        count+=2;
                    }
                    else return -1;
                }
            }
        }
        return count;
    }
};