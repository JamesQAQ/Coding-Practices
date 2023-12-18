class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ans = 0;
        uint32_t base = 1;
        for (int i = 0; i < 32; i++) {
            if ((base << i) & n) ans++;
        }
        return ans;
    }
};