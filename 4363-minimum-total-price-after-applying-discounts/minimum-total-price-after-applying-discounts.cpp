class Solution {
public:
    double minPrice(vector<int>& prices, vector<int>& discount) {
        sort(prices.begin(),prices.end());
        sort(discount.begin(),discount.end());
        double ans=0;
        int j=discount.size()-1;
        int n=prices.size()-1;
        for(int i=n;i>=0;i--)
        {
            double p=prices[i];
            if(j>=0)
            {
                p=(p * (100 - discount[j])) / 100.0;
                j--;
            }
            ans+=p;
        }
        return ans;
    }
};