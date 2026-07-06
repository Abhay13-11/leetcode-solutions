class Solution {
    int findsum(vector<int> &temp)
    {
        int maxi=INT_MIN;
        
        for(auto it : temp)
        {
            maxi=max(maxi,it);
        }
        if(maxi<0) return maxi;
        int sum=0;
        for(auto it : temp)
        {
            sum+=it;
            if(sum<0)
            {
                sum=0;
            }
            maxi=max(maxi,sum);
        }
        return maxi;
    }
public:
    int divisibleGame(vector<int>& nums) {
        
        set<int> cand;

for(int x : nums)
{
    for(int d = 2; d * d <= x; d++)
    {
        if(x % d == 0)
        {
            cand.insert(d);
            cand.insert(x / d);
        }
    }

    if(x > 1)
        cand.insert(x);
}

cand.insert(2);
        int n=nums.size();
       
        
        int mod=1e9+7;
        int bestsum=INT_MIN;
            int bestk=2;
        for(int k : cand)
        {
            
            vector<int> temp=nums;
            for(int i=0;i<n;i++)
            {
                if(temp[i]%k!=0) temp[i]=-1*temp[i];
            }
            int sum=findsum(temp);
            if(sum>bestsum)
            {
                bestsum=sum;
                bestk=k;
            }
            else if(sum==bestsum && k<bestk) bestk=k;
            
            
          
        }
       return (int)(((1LL * bestsum * bestk) % mod + mod) % mod);
    }
};