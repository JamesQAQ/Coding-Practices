class Solution {
    bool p[21] = {};

public:
    Solution() {
        p[2] = p[3] = p[5] = p[7] = p[11] = p[13] = p[17] = p[19] = true;
    }
    
    int countPrimeSetBits(int left, int right) {
        int cnt = 0;
        for (int i = left; i <= right; i++) if (isP(i)) cnt++;
        return cnt;
    }

private:
    bool isP(int x) {
        int cnt = 0;
        while (x) {
            if (x % 2 == 1) cnt++;
            x /= 2;
        }
        return p[cnt];
    }
};