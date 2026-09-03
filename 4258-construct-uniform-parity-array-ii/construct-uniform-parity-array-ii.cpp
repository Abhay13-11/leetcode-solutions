class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        if(nums1.size()==1)
        {
            return true;
        }
       int oddc=0;
        int minio=INT_MAX;
        int minie=INT_MAX;
        for(int i=0;i<nums1.size();i++)
            {
                if(nums1[i]%2==1)
                {
                    oddc++;
                minio=min(minio,nums1[i]);}
                else
                {
                    minie=min(minie,nums1[i]);
                }
            }
        if(oddc==0 || oddc==nums1.size())
        {
            return true;
        }
        int flag=0;
        for(int i=0;i<nums1.size();i++)
            {
                if(nums1[i]%2==0)
                {
                    if(nums1[i]<=minio)
                    {

                        flag=1;
                        break;
                    }
                }
            }
        if(flag==0)
        {
            return true;
        } 
        return false;
    }
};