class Solution {
public:
    int minimumMountainRemovals(vector<int>& arr) {
        int n=arr.size();
        vector<int> lis(n,1),lds(n,1);
        
        for(int i=0;i<n;i++)
        {
            for(int prev=0;prev<i;prev++)
            {
                if(arr[prev]<arr[i] && lis[i]<lis[prev]+1)
                {
                    lis[i]=lis[prev]+1;
                }
            }
        }
        for(int i=n-1;i>=0;i--)
        {
            for(int prev=n-1;prev>i;prev--)
            {
                if(arr[i]>arr[prev] && lds[i]<lds[prev]+1) lds[i]=lds[prev]+1;
            }
        }
        
        int ans=0;
        for(int i=0;i<n;i++)
        {
            if(lis[i]>1 && lds[i]>1) ans=max(ans,lis[i]+lds[i]-1);
        }
        return n-ans;
    }
};