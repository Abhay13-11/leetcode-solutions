class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        vector<bool> num(1000,false);
        int ans=0;
        int n=digits.size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                for(int k=0;k<n;k++)
                {
                    if(i==j || j==k || k==i || digits[i]==0 || digits[k]%2!=0) continue;
                    int dig=digits[i]*100+digits[j]*10+digits[k];
                    if(!num[dig])
                    {
                        ans++;
                        num[dig]=true;
                    }
                   
                }
            }
        }
        return ans;
    }
};