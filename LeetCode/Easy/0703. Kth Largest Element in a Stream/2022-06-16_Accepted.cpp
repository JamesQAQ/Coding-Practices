class KthLargest {
    int k;
    priority_queue<int> keeper;
    
public:
    KthLargest(int _k, vector<int>& nums) {
        k = _k;
        for (int i = 0; i < nums.size(); i++) {
            add(nums[i]);
        }
    }
    
    int add(int val) {
        if (keeper.size() < k) {
            keeper.push(-val);
        } else if (val > -keeper.top()) {
            keeper.pop();
            keeper.push(-val);
        }
        return -keeper.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */