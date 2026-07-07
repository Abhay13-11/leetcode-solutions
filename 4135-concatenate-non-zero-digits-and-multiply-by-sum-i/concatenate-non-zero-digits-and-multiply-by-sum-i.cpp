class Solution {
public:
    long long sumAndMultiply(int n) {
        string s="";
        int sum=0;
        while(n>0)
        {
            int dig=n%10;
            sum+=dig;
            if(dig!=0)
            {
                s+=to_string(dig);
            }
            n=n/10;
        }
        if(sum==0) return 0;
        reverse(s.begin(),s.end());
        return 1LL*sum*stoi(s);
    }
};