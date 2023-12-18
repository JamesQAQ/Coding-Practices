class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {
        while (!stk1.empty()) stk1.pop();
        while (!stk2.empty()) stk2.pop();
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        move(stk2, stk1);
        stk1.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        move(stk1, stk2);
        int ret = stk2.top();
        stk2.pop();
        return ret;
    }
    
    /** Get the front element. */
    int peek() {
        move(stk1, stk2);
        return stk2.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return stk1.empty() && stk2.empty();
    }
    
private:
    stack<int> stk1, stk2;
    
    /** Move all elements in s1 to s2 */
    void move(stack<int>& s1, stack<int>& s2) {
        while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = new MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * bool param_4 = obj.empty();
 */