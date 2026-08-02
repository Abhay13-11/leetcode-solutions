class Solution {
    bool small(long long strength,vector<int>& monsters,vector<long long> &bot)
    {
        
         for(int i=0;i<monsters.size();i++) 
         {
            if(strength+bot[i]<monsters[i]) return false;
            strength-=monsters[i];
            if(strength<0) strength=0;
         }
         return true;

    }
public:
    long long minInitialStrength(vector<int>& monsters, vector<vector<int>>& boosts) {
     vector<long long> bot(monsters.size(),0);
     vector<long long> diff(monsters.size()+1,0);

        for(auto it : boosts)
        {
            diff[it[0]]+=it[2];
            diff[it[1]+1]-=it[2];
        }
        bot[0]=diff[0];
        for(int i=1;i<bot.size();i++)
        {
            bot[i]=bot[i-1]+diff[i];
        }
            long long ans=LLONG_MAX;
         long long low=0;
         long long high=0;
         for(int it : monsters) high+=it;
         while(low<=high)
         {
            long long mid=(low+high)/2;
            if(small(mid,monsters,bot))
            {
                ans=min(mid,ans);
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
         }
       return ans;   
    }
};