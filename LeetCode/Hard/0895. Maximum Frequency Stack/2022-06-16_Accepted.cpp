struct HeapValue {
    int val;
    int pushCount;
};
 
struct compareValue {
    bool operator()(HeapValue a, HeapValue b) {
        return a.pushCount < b.pushCount;
    }
};

class FreqStack {
    map<int, int> countMap;
    vector< priority_queue<HeapValue, vector<HeapValue>, compareValue> > heapList;
    int pushCount;
    
    priority_queue<HeapValue, vector<HeapValue>, compareValue> emptyHeap;
    
public:
    FreqStack() {
        countMap.clear();
        heapList.clear();
        pushCount = 0;
    }
    
    void push(int val) {
        if (countMap.find(val) == countMap.end()) {
            countMap[val] = 0;
        }
        int count = ++countMap[val];
        
        if (count > heapList.size()) {
            heapList.push_back(emptyHeap);
        }
        heapList[count - 1].push({val, pushCount++});
    }
    
    int pop() {
        int index = heapList.size() - 1;
        int res = heapList[index].top().val;
        heapList[index].pop();
        if (heapList[index].empty()) {
            heapList.pop_back();
        }
        countMap[res]--;
        return res;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */