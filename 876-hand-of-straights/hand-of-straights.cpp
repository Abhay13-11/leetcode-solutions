class Solution {
public:
    bool isNStraightHand(vector<int>& nums, int k) {
        if(nums.size()%k!=0) return false;
        map<int,int> mpp;
        for(int it : nums)
        {
            mpp[it]++;
        }
        int count=0;
        priority_queue<int,vector<int>,greater<int>> qt;

        for(auto it : mpp)
        {
            qt.push(it.first);
        }
        vector<int> ap;
        while(!qt.empty())
        {
            int ele=qt.top();
            qt.pop();
            count++;
            if(count>=k)
            {
                mpp[ele]--;
                if(mpp[ele]>0) ap.push_back(ele);
                for(int it : ap) qt.push(it);
                ap.clear();
                count=0;
              
            }
            else
            {
                
                if(count<k && ele+1!=qt.top()) return false;
                mpp[ele]--;
                if(mpp[ele]>0) ap.push_back(ele);

            }
        }
        return true;
    }
};