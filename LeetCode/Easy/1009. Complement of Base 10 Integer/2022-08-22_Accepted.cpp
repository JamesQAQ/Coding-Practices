class Solution {
public:
    int bitwiseComplement(int n) {
        if (n == 0) return 1;
        int ans = 0, c = 1;
        while (n > 0) {
            ans += (1 - n % 2) * c;
            n /= 2;
            c <<= 1;
        }
        return ans;
    }
};