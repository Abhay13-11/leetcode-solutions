class Solution {
public:
    int largestInteger(int n, int s) {
        if(s==0) return 0;
        int ans=0;
        int sum=s;
        for(int i=0;i<n;i++)
        {
            if(s==0) 
            {
                ans=ans*10;
            }
           else if(sum<=9)
            {
                ans=ans*10+sum;
                sum=0;

            }
            else
            {
                ans=ans*10+9;
                sum-=9;
            }
        }
        if(sum) return -1;
        return ans;
    }
};