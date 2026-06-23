class MedianFinder {
public:
priority_queue<int> left;
priority_queue<int, vector<int>, greater<int>> right;


    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(left.size()<=right.size()) left.push(num);
        else
        {
            right.push(num);
        }
        while(left.size() && right.size() &&  left.top()>right.top())
        {
            left.push(right.top());
            right.pop();
            right.push(left.top());
            left.pop();
        }
    }
    
    double findMedian() {
        if(left.size()>right.size()) return left.top();
        return double(left.top()+right.top())/2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */