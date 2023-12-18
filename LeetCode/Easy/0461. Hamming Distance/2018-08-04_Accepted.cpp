class Solution {
public:
    int hammingDistance(int x, int y) {
        int ans = 0;
        int val = x ^ y;
        while (val > 0) {
            val -= val & (-val);
            ans++;
        }
        return ans;
    }
};