#include <queue>

class MedianFinder {
public:
    std::priority_queue<int> max_heap, min_heap; // default max

    // Adds a number into the data structure.
    void addNum(int num) {
        if (max_heap.size() == 0 || num <= max_heap.top())
            max_heap.push(num);
        else
            min_heap.push(-num);
        int limit = (max_heap.size() + min_heap.size() + 1) / 2;
        while (max_heap.size() > limit){
            min_heap.push(-max_heap.top());
            max_heap.pop();
        }
        while (max_heap.size() < limit){
            max_heap.push(-min_heap.top());
            min_heap.pop();
        }
    }

    // Returns the median of current data stream
    double findMedian() {
        int all = max_heap.size() + min_heap.size();
        if (all % 2 == 0)
            return ((double)max_heap.top() - min_heap.top()) / 2;
        else
            return max_heap.top();
    }
};

// Your MedianFinder object will be instantiated and called as such:
// MedianFinder mf;
// mf.addNum(1);
// mf.findMedian();
