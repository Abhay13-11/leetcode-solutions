class Solution {
public:
    int countCommas(int n) {
        int nn=n;
        int ans=0;
        int countd=0;
        while(nn>0)
            {
                countd++;
                nn=nn/10;
                
            }
        if(countd<=3)
        {
            return 0;
        }

        while(n>999)
            {
                string ss=to_string(n);
                int com=(ss.size()-1)/3;
                ans+=com;
                n--;
            }
        return ans;
    }
};