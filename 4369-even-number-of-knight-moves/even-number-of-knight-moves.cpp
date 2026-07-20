class Solution {
public:
    bool canReach(vector<int>& start, vector<int>& target) {
        int curr=0;
        int next=0;
        if((start[0]+start[1])%2==0) curr=1;
        if((target[0]+target[1])%2==0) next=1;
        if(curr==next) return true;
        return false;

    }
};