class Solution {
public:
    bool isPerfectSquare(int num) {
        int l = 1, r = 46340;
        while (l <= r) {
            int mid = (l + r) / 2;
            int val = mid * mid;
            if (val == num) return true;
            else if (val < num) l = mid + 1;
            else r = mid - 1;
        }
        return false;
    }
};