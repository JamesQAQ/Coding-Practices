class MinStack {
public:
    /** initialize your data structure here. */
    vector<int> stk;
    vector<int> min_val;
    
    MinStack() {
        stk.clear();
        min_val.clear();
    }
    
    void push(int x) {
        if (stk.size() > 0) {
            min_val.push_back(min(x, min_val[min_val.size() - 1]));
        } else {
            min_val.push_back(x);
        }
        stk.push_back(x);
    }
    
    void pop() {
        stk.pop_back();
        min_val.pop_back();
    }
    
    int top() {
        return stk[stk.size() - 1];
    }
    
    int getMin() {
        return min_val[min_val.size() - 1];
    }
    
    int min(int a, int b) {
        return (a < b) ? a : b;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */