class Solution {
public:
    bool isUgly(int num) {
        if (num < 1) return false;
        int p[3] = {2, 3, 5};
        for (int i = 0; i < 3; i++) {
            while (num % p[i] == 0) num /= p[i];
        }
        return num == 1;
    }
};