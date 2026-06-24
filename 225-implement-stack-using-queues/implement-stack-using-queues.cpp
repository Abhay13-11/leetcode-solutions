class MyStack {
public:
    queue<int> qt;
    MyStack() {
        
    }
    
    void push(int x) {
        qt.push(x);
        
    }
    
    int pop() {
        if(qt.empty()) return -1;
        int ele;
        int size=qt.size();
        int count=0;
        while(count!=size-1)
        {
            ele=qt.front();
            qt.pop();
            qt.push(ele);
            count++;
        }
        ele=qt.front();
        qt.pop();
        return ele;

    }
    
    int top() {
        if(qt.empty()) return -1;
        int ele;
        int size=qt.size();
        int count=0;
        while(count!=size)
        {
            ele=qt.front();
            qt.pop();
            qt.push(ele);
            count++;
        }
        return ele;
    }
    
    bool empty() {
        return qt.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */