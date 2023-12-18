bool cmp(int i, int j) {
    return i > j;
}

class Solution {
public:
    int thirdMax(vector<int>& nums) {
        vector<int> tmp;
        for (int i = 0; i < nums.size(); i++) {
            if (check(tmp, nums[i])) {
                tmp.push_back(nums[i]);
                stable_sort(tmp.begin(), tmp.end(), cmp);
                if (tmp.size() > 3) tmp.pop_back();
            }
        }
        if (tmp.size() < 3) return tmp[0];
        return tmp[2];
    }
private:
    bool check(vector<int>& tmp, int val) {
        for (int i = 0; i < tmp.size(); i++) {
            if (tmp[i] == val) return false;
        }
        return true;
    }
};