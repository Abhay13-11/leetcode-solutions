class Solution {
public:
    long long countCommas(long long n) {
        long long  ans=0;
        long long comma=1;
        long long start=1000;
        if(n>=1000)
        {
            while(start<=n)
                {
                   
            long long last=start*1000-1;
                    if(last>n)
                    {
                        last=n;
                    }
            ans+=(last-start+1)*comma;
            
                start=start*1000;
                comma++;
            
                }
        }
       return ans; 
    }
};