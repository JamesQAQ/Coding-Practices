struct Num {
    int val;
    int pos;
    Num (int _val, int _pos) {
        val = _val;
        pos = _pos;
    }
} ;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        deque<Num> que;
        for (int i = 0; i < k - 1; i++) {
            Num tmp(nums[i], i);
            while (que.size() > 0 && nums[i] >= que[que.size() - 1].val)
                que.pop_back();
            que.push_back(tmp);
        }
        for (int i = k - 1; i < nums.size(); i++) {
            Num tmp(nums[i], i);
            if (que[0].pos < i - k + 1)
                que.pop_front();
            while (que.size() > 0 && nums[i] >= que[que.size() - 1].val)
                que.pop_back();
            que.push_back(tmp);
            ans.push_back(que[0].val);
        }
        return ans;
    }
};
