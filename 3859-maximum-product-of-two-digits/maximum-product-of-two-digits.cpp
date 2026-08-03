class Solution {
public:
    int maxProduct(int n) {
        int maxi=0;
        int maxi1=0;
        while(n>0)
        {
            int dig=n%10;
            n=n/10;
            if(dig>=maxi)
            {
                maxi1=maxi;
                maxi=dig;
            }
            else if(dig>maxi1)
            {
                maxi1=dig;
            }

        }
        return maxi*maxi1;
    }
};