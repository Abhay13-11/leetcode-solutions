class Solution {
public:
    int minimumCost(vector<int>& nums, int k) {
        int mod=1e9+7;
        
        long long cost=0;
        long long resource=k;
        for(int it : nums)
        {
           
                if((resource-it<0) )
                {
                    int need=it-resource;
                    int tot=need%k==0?need/k:need/k+1;
                cost=(cost+tot)%mod;
                
                if(need%k!=0) resource=k-need%k ;
                else resource=0;
                }
            
           else{
  resource=resource-it;
           }
              
            
        }
        return (((1LL*cost*(cost+1))/2)+mod)%mod;
    }
};