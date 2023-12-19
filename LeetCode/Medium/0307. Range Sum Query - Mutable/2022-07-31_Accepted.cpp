class NumArray {
    int v[120000];
    int size;
    
public:
    NumArray(vector<int>& nums) {
        size = nums.size();
        build(1, 0, size - 1, nums);
    }
    
    void update(int index, int val) {
        update(1, 0, size - 1, index, val);
    }
    
    int sumRange(int left, int right) {
        return query(1, 0, size - 1, left, right);
    }

private:
    void build(int x, int left, int right, vector<int>& nums) {
        if (left == right) {
            v[x] = nums[left];
            return;
        }
        int mid = (left + right) / 2;
        build(2 * x, left, mid, nums);
        build(2 * x + 1, mid + 1, right, nums);
        v[x] = v[2 * x] + v[2 * x + 1];
    }
    
    void update(int x, int left, int right, int index, int value) {
        if (left == right) {
            v[x] = value;
            return;
        }
        int mid = (left + right) / 2;
        if (index <= mid) {
            update(2 * x, left, mid, index, value);
        } else {
            update(2 * x + 1, mid + 1, right, index, value);
        }
        v[x] = v[2 * x] + v[2 * x + 1];
    }
    
    int query(int x, int left, int right, int l, int r) {
        if (l <= left && right <= r) {
            return v[x];
        }
        int mid = (left + right) / 2;
        int res = 0;
        if (l <= mid) {
            res += query(2 * x, left, mid, l, r);
        }
        if (r >= mid + 1) {
            res += query(2 * x + 1, mid + 1, right, l, r);
        }
        return res;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */