class Solution {
public:
    int secondsBetweenTimes(string startTime, string endTime) {
        int ans=0;
        long long end=stoi(endTime.substr(0,2))*3600*1LL+stoi(endTime.substr(3,5))*60*1LL+stoi(endTime.substr(6));
        long long strt=stoi(startTime.substr(0,2))*3600*1LL+stoi(startTime.substr(3,5))*60*1LL+stoi(startTime.substr(6));
        return end-strt;

    }
};