class Solution {
public:
    bool isPowerOfThree(int n) {
        int max_p3 = 1162261467;
        if (n < 1 || n > max_p3) return false;
        return max_p3 % n == 0;
    }
};