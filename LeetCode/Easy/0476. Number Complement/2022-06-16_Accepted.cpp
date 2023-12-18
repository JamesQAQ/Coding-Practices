class Solution {
public:
    int findComplement(int num) {
        int ans = 0;
        int base = 1;
        while (num) {
            if (num % 2 == 0) ans += base;
            num >>= 1;
            base <<= 1;
        }
        return ans;
    }
};