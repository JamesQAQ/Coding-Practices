class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> ans;
        for (int i = left; i <= right; i++) {
            if (isSelfDividing(i)) ans.push_back(i);
        }
        return ans;
    }

private:
    bool isSelfDividing(int n) {
        int tmp = n;
        while (tmp > 0) {
            int x = tmp % 10;
            if (x == 0 || n % x != 0) return false;
            tmp /= 10;
        }
        return true;
    }
};