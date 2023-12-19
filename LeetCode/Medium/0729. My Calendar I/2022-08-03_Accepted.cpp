class MyCalendar {
    map<int, int> c;
    
public:
    MyCalendar() {
        c.clear();
    }
    
    bool book(int start, int end) {
        if (!c.empty()) {
            auto it = c.upper_bound(start);
            if (it != c.end()) {
                if (end > it->first) return false;
            }
            if (it != c.begin()) {
                it--;
                if (start < it->second) return false;
            }
        }
        c[start] = end;
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */